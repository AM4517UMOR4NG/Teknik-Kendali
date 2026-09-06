# 💡 Smart LED Dimmer with LDR Sensor (Arduino Uno)

An automated ambient-light-responsive LED dimmer system built on Arduino Uno and simulated via [Wokwi](https://wokwi.com/). The project dynamically adjusts LED brightness based on readings from a Light Dependent Resistor (LDR).

---

## 📌 How It Works

LED brightness is driven by PWM (*Pulse Width Modulation*) using thresholding and linear interpolation via `map()`:

* **Dark (`LDR < 300`)**: Full brightness (`255`).
* **Ambient / Transition (`300 ≤ LDR ≤ 700`)**: Inversely proportional brightness (`0–255`).
* **Bright (`LDR > 700`)**: LED completely off (`0`).

---

## 🛠️ Components & Hardware

| Component | Identifier / Value | Function |
| :--- | :--- | :--- |
| **Arduino Uno** | `uno1` | Main microcontroller |
| **Red LED** | `led1` | PWM-controlled light output |
| **LDR Sensor** | `ldr1` (Module) | Light intensity detection |
| **Current-limiting Resistor** | 220 Ω (`r1`) | Protects the LED |
| **Pull-down Resistor** | 10 kΩ (`r2`) | Voltage divider reference for LDR output |

---

## 🔌 Wiring & Pinout

### LED Circuit
* **Arduino Pin 9 (PWM)** ➔ 220 Ω Resistor ➔ **LED Anode (+)**
* **LED Cathode (-)** ➔ **Arduino GND**

### LDR Sensor Circuit
* **Sensor VCC** ➔ **Arduino 5V**
* **Sensor GND** ➔ **Arduino GND**
* **Signal Pin (S)** ➔ **Arduino Analog Pin A0**
* **Signal Pin (S)** ➔ 10 kΩ Resistor ➔ **Arduino GND**

---

## 📂 Project Structure

```text
├── diagram.json      # Wokwi circuit elements and wiring configuration
├── wokwi.toml        # Wokwi simulation environment parameters
└── src/
    └── main.cpp      # Arduino firmware logic (or ldr_led.ino)
