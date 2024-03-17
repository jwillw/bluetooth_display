#include "led_display.hpp"

LedDisplay led_display(DEVICE_DT_GET(DT_ALIAS(led_strip)));

void LedDisplay::set_image(const led_rgb pixel_value) {
	for (led_rgb &pixel : image) pixel = pixel_value;
}

int LedDisplay::update_display() {
	return led_strip_update_rgb(strip, std::data(image), std::size(image));
}
