## Setup

Install [Zepyhr SDK](https://github.com/zephyrproject-rtos/sdk-ng/tags).

```shell
cd ~/.local/opt/
wget link/to/sdk.tar.xz
tar xvf sdk.tar.xz && rm sdk.tar.xz
cd sdk
./setup.sh -t target -c
```

Initialize your project by running the following shell commands
from your cloned projects root.

```shell
python -m venv ~/.pyvenv/zephyr
source ~/.pyvenv/zephyr/bin/activate
pip install west
west update
west blobs fetch hal_espressif
```

Build and flash using west.

```shell
west build -b esp32_devkitc_wroom .
west flash
```
