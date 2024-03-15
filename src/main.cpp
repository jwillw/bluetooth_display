#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/logging/log.h>

#include "ots.hpp"

LOG_MODULE_REGISTER(led_display);

constexpr char             DEVICE_NAME[]   = CONFIG_BT_DEVICE_NAME;
constexpr uint8_t          DEVICE_NAME_LEN = sizeof(DEVICE_NAME) - 1;
constexpr bt_le_adv_param *bt_param        = BT_LE_ADV_CONN;

static const bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
};

static const bt_data sd[] = {
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_OTS_VAL)),
};

int main() {
	int err;
	err = bt_enable(nullptr);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)\n", err);
		return 0;
	}
	err = ots_init();
	if (err) {
		LOG_ERR("OTS init failed (err %d)\n", err);
		return 0;
	}
	err = bt_le_adv_start(bt_param, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
	return 0;
}
