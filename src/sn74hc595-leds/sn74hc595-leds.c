#include "pico/stdlib.h"

const uint latchPin = 1; // also called RCLK
const uint clockPin = 0; // SCLK
const uint dataPin = 2; // SER

// Data should be 8 bits long (one byte)
// But depending on what we want to do, we could send more data and daisy chain the SIPOs
// That said, we only have one SIPO and 8 LEDs
const uint8_t data1 = 0b10101010; // pattern 1
const uint8_t data2 = 0b01010101; // pattern 2

// update clock
void tick() {
    gpio_put(clockPin, 1);
    gpio_put(clockPin, 0);
}

void writeData(uint data) {
    // disable "output"
    gpio_put(latchPin, 0);

    // write each bit of data serially
    // set up the data/output to be displayed
    for(int i = 0; i < 8; i++) {
        gpio_put(dataPin, (data >> i) & 1);
        tick();
    }

    // enable "output"
    gpio_put(latchPin, 1);
}

int main() {
    // Initialize GPIO pins
    gpio_init(latchPin);
    gpio_set_dir(latchPin, GPIO_OUT);

    gpio_init(clockPin);
    gpio_set_dir(clockPin, GPIO_OUT);

    gpio_init(dataPin);
    gpio_set_dir(dataPin, GPIO_OUT);

    while (1) {
        writeData(data1);
        sleep_ms(250);
        writeData(data2);
        sleep_ms(250);
    }
}