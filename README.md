# ESPHome WS2805 External Component

This is an external component for ESPHome that provides support for **WS2805** 5-channel (RGB + Warm White + Cold White) LED strips.

ESPHome's built-in `AddressableLight` primarily maps to a maximum of 4 channels (RGBW). Since WS2805 requires 5 channels (40 bits per pixel) for RGBCCT support, this component exposes the entire strip as a standard `RGB_COLD_WARM_WHITE` light output using the [NeoPixelBus](https://github.com/Makuna/NeoPixelBus) library.

This maps perfectly to the Home Assistant UI, providing correct RGB color selection and CCT (Color Temperature) control without jumping sliders.

## Usage in ESPHome

To use this component, you can include it directly from GitHub using the `external_components` block.

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/babeinlovexd/esph-ws2805
      ref: main
    components: [ ws2805 ]

light:
  - platform: ws2805
    name: "My WS2805 Strip"
    pin: 4 # The GPIO pin your data line is connected to
    num_leds: 100 # Total number of LEDs on the strip
    # Optional advanced configurations:
    gamma_correct: 2.8 # Default is 2.8
    restore_mode: RESTORE_DEFAULT_OFF # Action on boot
```

## Features
- **Full RGBCCT control:** Allows setting Red, Green, Blue, Cold White, and Warm White channels simultaneously.
- **Hardware Agnostic (NeoPixelBus):** Uses the highly optimized Makuna `NeoPixelBus` library under the hood (`NeoWs2805Method`).
- **Brightness Scaling:** Proper mapping and scaling of the 5 channels relative to overall brightness.

---

## Deutsche Version (German)

# ESPHome WS2805 Externe Komponente

Dies ist eine externe Komponente für ESPHome, die Unterstützung für **WS2805** 5-Kanal (RGB + Warmweiß + Kaltweiß) LED-Streifen bietet.

Das integrierte `AddressableLight` von ESPHome unterstützt standardmäßig maximal 4 Kanäle (RGBW). Da WS2805 für die RGBCCT-Unterstützung 5 Kanäle (40 Bit pro Pixel) benötigt, stellt diese Komponente den gesamten Streifen als Standard-`RGB_COLD_WARM_WHITE`-Lichtausgang bereit. Dabei wird die [NeoPixelBus](https://github.com/Makuna/NeoPixelBus)-Bibliothek verwendet.

Dies lässt sich perfekt in die Home Assistant-Benutzeroberfläche integrieren und ermöglicht eine korrekte RGB-Farbauswahl sowie die Steuerung der Farbtemperatur (CCT) ohne springende Schieberegler.

## Nutzung in ESPHome

Um diese Komponente zu verwenden, können Sie sie direkt über den `external_components`-Block von GitHub einbinden.

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/babeinlovexd/esph-ws2805
      ref: main
    components: [ ws2805 ]

light:
  - platform: ws2805
    name: "Mein WS2805 LED-Streifen"
    pin: 4 # Der GPIO-Pin, an den die Datenleitung angeschlossen ist
    num_leds: 100 # Gesamtanzahl der LEDs auf dem Streifen
    # Optionale erweiterte Konfigurationen:
    gamma_correct: 2.8 # Standardwert ist 2.8
    restore_mode: RESTORE_DEFAULT_OFF # Verhalten beim Start
```

## Funktionen
- **Vollständige RGBCCT-Steuerung:** Ermöglicht die gleichzeitige Steuerung der Kanäle für Rot, Grün, Blau, Kaltweiß und Warmweiß.
- **Hardware-unabhängig (NeoPixelBus):** Nutzt die stark optimierte Makuna `NeoPixelBus`-Bibliothek im Hintergrund (`NeoWs2805Method`).
- **Helligkeitsskalierung:** Korrekte Zuordnung und Skalierung der 5 Kanäle im Verhältnis zur Gesamthelligkeit.
