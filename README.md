# Raspberry Pi Pico SN74HC595 LED example

![Fritzing wiring diagram](/Pico-breadboard_fritzing.svg)

Made as a learning project to get to know the SN74HC595 a little bit better.

## Building

```sh
git clone https://github.com/turtureanu/rpi-sn74hc595-leds.git
cd rpi-sn74hc595-leds
cd src/sn74hc595-leds/build
cmake ..
make
```

## Flashing

1. Hold the BOOTSEL button while plugging in your Raspberry Pi Pico using a data cable.
2. You should now see a `RPI-RP2` volume.
3. Copy the `sn74hc595-leds.uf2` from the `build` folder file to it.
