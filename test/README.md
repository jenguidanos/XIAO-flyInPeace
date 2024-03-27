
# FLY IN PEACE UNITTESTS

This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html


## HOW TO

For running googletest unittest just open a platformio CLI (use platformio quick access bar icon) and run:

```bash 
pio test -e native
```

This will run only the *native* envitonment in platformio ini file

```ini

[env]
test_framework = googletest

[env:native]
platform = native

[env:seeed_xiao_esp32c3]
platform = espressif32
board = seeed_xiao_esp32c3
framework = arduino
lib_ldf_mode = deep
lib_deps = 
	robtillaart/MS5611@^0.3.9
	google/googletest@^1.12.1
	denyssene/SimpleKalmanFilter@^0.1.0
	majicdesigns/MD_AD9833@^1.2.4
	adafruit/Adafruit NeoPixel@^1.12.0

```