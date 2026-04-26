#pragma once
namespace esphome { namespace light { class LightTraits; class LightState; class LightOutput : public Component { public: virtual void write_state(LightState*) = 0; virtual LightTraits get_traits() = 0; }; } }
