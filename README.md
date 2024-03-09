## Setup

Initialize your project by running the following shell commands
from your cloned projects root.

```shell
python -m venv ~/.pyvenv/zephyr
source ~/.pyvenv/zephyr/bin/activate
pip install west
west update
```

Build and flash using west.

```shell
west build -b esp32_devkitc_wroom .
west flash
```
