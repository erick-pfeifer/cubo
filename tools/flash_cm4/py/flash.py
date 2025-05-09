"""Script program target over openocd"""

import subprocess

from python.runfiles import runfiles
import serial.tools.list_ports
from pathlib import Path
import argparse

_OPENOCD_PATH = "openocd/bin/openocd"
_OPENOCD_CONFIG_PATH = "openocd/scripts/board/microchip_same54_xplained_pro.cfg"

# Vendor ID and model ID.
_VENDOR_ID = 0x03EB
_PRODUCT_ID = 0x2111


def get_board_serial() -> str:
    for dev in serial.tools.list_ports.comports():
        if dev.vid == _VENDOR_ID and dev.pid == _PRODUCT_ID:
            return dev.serial_number

    raise IOError("Failed to detect connected board")


def flash(board_serial, binary: Path):
    r = runfiles.Create()
    openocd = r.Rlocation(_OPENOCD_PATH)
    openocd_cfg = r.Rlocation(_OPENOCD_CONFIG_PATH)

    print(f"Board Serial:                {board_serial}")
    print(f"binary Rlocation is:         {binary}")
    print(f"openocd Rlocation is:        {openocd}")
    print(f"openocd config Rlocation is: {openocd_cfg}")
    assert binary is not None
    assert openocd_cfg is not None
    # " \"program build/E54ServoChar.elf verify\" -c \"reset halt\" -c shutdown"
    subprocess.check_call(
        [
            openocd,
            "-f",
            f"{openocd_cfg}",
            "-c",
            f"program {binary} reset exit",
            # "-c",
            # "adapter speed 4000",
            # "-c",
            # "bindto 0.0.0.0",
        ],
    )


def find_elf(binary: Path) -> Path | None:
    """Attempt to find and return the path to an ELF file for a binary.

    Args:
      binary: A relative path to a binary.

    Returns the path to the associated ELF file, or None if none was found.
    """
    if binary.suffix == ".elf" or not binary.suffix:
        return binary
    choices = (
        binary.parent / f"{binary.stem}.elf",
        binary.parent / "bin" / f"{binary.stem}.elf",
        binary.parent / "test" / f"{binary.stem}.elf",
    )
    for choice in choices:
        if choice.is_file():
            return choice

    print(f"Cannot find ELF file to use as a token database for binary: {binary}")
    return None


def extract_args() -> argparse.ArgumentParser:
    """Returns a parser for flashing command-line arguments."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="The target binary to flash")
    return parser


if __name__ == "__main__":
    args = extract_args().parse_args()
    flash(get_board_serial(), args.binary)
