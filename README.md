
## Configure Presubmit (under construction, tidy coming soon)

1. (For Linux only) Add bazelisk executable to PATH, or move it to
 `/usr/local/bin/`.
1. Run `bazelisk run //tools/presubmit/py:presubmit` to install the `git-hook`
 for pushing with `git push`.
1. (optional) During local development, periodically run
 `bazelisk run @pigweed//pw_presubmit/py:format` to format code (Note: this
  command only covers files tracked by the git project).



## Using USBIP for remote connections

### On windows
winget install [usbipd](https://github.com/dorssel/usbipd-win).

- Get list of devices

```
$ usbipd list
```

- Find target device on the list
- Copy VID:PID
- Then bind the device with:

```
$ usbipd bind --i=<VID:PID>
```

### On Guest VM (Linux)

```
sudo modprobe usbip-core
sudo modprobe usbip-host
sudo modprobe vhci-hcd
```

- To load on boot

```
$ sudo echo "usbip-core" | sudo tee -a /etc/modules
$ sudo echo "usbip-host" | sudo tee -a /etc/modules
$ sudo echo "vhci-hcd" | sudo tee -a /etc/modules
```

- Connection commands

```
$ usbip list --remote=<HOST_NAME>
$ sudo usbip attach --remote=<HOST_NAME> --busid=<BUSID>
```
