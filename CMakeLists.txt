cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(bluetooth_display)

target_sources(app
PRIVATE
	src/main.cpp
	src/ots.cpp
	src/led_display.cpp
)
