# Raspberry Pi Pico SN74HC595 LEDs

Made as a learning project to get to know the SN74HC595 a little bit better.

## Wiring

![Fritzing wiring diagram](/Pico-breadboard_fritzing.svg)

![Working demo](/real-life-demo.jpeg)

## Building

For building the project you will also have to clone the `pico-sdk` and set it using the `PICO_SDK_PATH` enviromental variable.

```
git clone https://github.com/raspberrypi/pico-sdk.git
export PICO_SDK_PATH=$(realpath pico-sdk)
```

Building the actual project can be done like this:

```sh
git clone https://github.com/turtureanu/pico-sn74hc595-leds.git
cd pico-sn74hc595-leds
cd src/sn74hc595-leds/build
cmake ..
make
```

## Flashing

1. Hold the BOOTSEL button while plugging in your Raspberry Pi Pico using a data cable.
2. You should now see a `RPI-RP2` volume.
3. Copy the `sn74hc595-leds.uf2` from the `build` folder file to it.
