



## Using USBIP for remote connections

# On windows
winget install usbipd (https://github.com/dorssel/usbipd-win)

usbipd list
- find item on the lis
- copy VID:PID
- usbipd bind --i=<VID:PID>

# On Guest VM (Linux)

sudo modprobe usbip-core
sudo modprobe usbip-host
sudo modprobe vhci-hcd

- To load on boot
sudo echo "usbip-core" | sudo tee -a /etc/modules
sudo echo "usbip-host" | sudo tee -a /etc/modules
sudo echo "vhci-hcd" | sudo tee -a /etc/modules

usbip list --remote=<HOST_NAME>
sudo usbip attach --remote=<HOST_NAME> --busid=<BUSID>
