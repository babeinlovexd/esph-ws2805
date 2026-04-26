#pragma once
namespace esphome { namespace light { class LightState { public: void current_values_as_rgbww(float*,float*,float*,float*,float*,bool) {} struct { ColorMode get_color_mode() const { return ColorMode::RGB; } } current_values; }; } }
