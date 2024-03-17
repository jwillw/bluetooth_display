#ifndef LED_DISPLAY_HPP
#define LED_DISPLAY_HPP

#include <zephyr/device.h>
#include <zephyr/drivers/led_strip.h>

#include <array>

class LedDisplay {
	static constexpr size_t ROW_LENGTH = 15;
	static constexpr size_t ROW_COUNT  = 15;

	const device *const strip;

	std::array<led_rgb, ROW_LENGTH * ROW_COUNT> image;

public:
	LedDisplay(const device *strip) : strip(strip){};

	void set_image(led_rgb pixel_value);
	int  update_display();
};

extern LedDisplay led_display;

#endif  // LED_DISPLAY_HPP
