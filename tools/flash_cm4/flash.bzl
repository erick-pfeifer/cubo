"""Bazel macros for flashing a cortex-m4 device binary."""

load("@bazel_skylib//rules:native_binary.bzl", "native_binary")

def _flash_cm4(
        name,
        binary,
        **kwargs):
    data = [binary]
    args = ["$(rootpath " + binary + ")"]

    native_binary(
        name = name,
        src = str(Label("//tools/flash_cm4:flash")),
        args = args,
        data = data + ["@openocd//:all"],
        # Note: out is mandatory in older bazel-skylib versions.
        out = name + ".exe",
        **kwargs
    )

def flash_cm4(
        name,
        binary,
        **kwargs):
    """Flash the binary to a connected cortex-m4 device.

    Args:
      name: The name of this rule.
      binary: The binary target to flash.
      **kwargs: Forwarded to the underlying native_binary rule.
    """
    _flash_cm4(name, binary, **kwargs)
