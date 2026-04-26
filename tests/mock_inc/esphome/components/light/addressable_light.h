#pragma once
namespace esphome { namespace light { class ESPColorView { public: ESPColorView(uint8_t*,uint8_t*,uint8_t*,uint8_t*,uint8_t*,const void*) {} }; class AddressableLight : public LightOutput { public: virtual int32_t size() const = 0; virtual void clear_effect_data() = 0; protected: void mark_shown_() {} const void* correction_; }; } }
