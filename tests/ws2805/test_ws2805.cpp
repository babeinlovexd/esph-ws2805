#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include "ws2805_light.h"

namespace esphome {
namespace light {
const ColorMode ColorMode::RGB{};
const ColorMode ColorMode::COLD_WARM_WHITE{};
const ColorMode ColorMode::RGB_COLD_WARM_WHITE{};
}
}

#include "ws2805_light.cpp"

using namespace esphome::ws2805;

void test_encoder_callback() {
    LedParams params;
    params.bit0 = { .duration0 = 400, .level0 = 1, .duration1 = 850, .level1 = 0 };
    params.bit1 = { .duration0 = 850, .level0 = 1, .duration1 = 400, .level1 = 0 };
    params.reset = { .duration0 = 0, .level0 = 1, .duration1 = 3000, .level1 = 0 };

    uint8_t data[] = { 0xA5 };
    size_t size = 1;
    size_t symbols_written = 0;
    size_t symbols_free = 10;
    rmt_symbol_word_t symbols[10];
    bool done = false;

    size_t written = WS2805LightOutput::ws2805_encoder_callback(data, size, symbols_written, symbols_free, symbols, &done, &params);
    assert(written == 8);
    assert(!done);
    assert(symbols[0].duration0 == params.bit1.duration0);
    assert(symbols[1].duration0 == params.bit0.duration0);

    written = WS2805LightOutput::ws2805_encoder_callback(data, size, 0, 7, symbols, &done, &params);
    assert(written == 0);

    symbols_written = 8;
    written = WS2805LightOutput::ws2805_encoder_callback(data, size, symbols_written, symbols_free, symbols, &done, &params);
    assert(written == 1);
    assert(done);
    assert(symbols[0].duration1 == params.reset.duration1);

    std::cout << "WS2805 encoder tests passed!" << std::endl;
}

int main() {
    test_encoder_callback();
    return 0;
}
