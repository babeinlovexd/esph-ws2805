#pragma once
namespace esphome { namespace light { class ColorMode { public: static const ColorMode RGB, COLD_WARM_WHITE, RGB_COLD_WARM_WHITE; }; class LightTraits { public: void set_supported_color_modes(std::vector<ColorMode>) {} void set_min_mireds(float) {} void set_max_mireds(float) {} }; } }
