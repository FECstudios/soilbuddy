# 🌱 SoilBuddy

SoilBuddy is a wireless soil moisture sensor I built to monitor my plants without having to constantly check on them. It reads soil moisture levels and hosts a live dashboard over WiFi — no app needed, just open a browser.

> Built with an ESP32, a soil moisture sensor, and a TP4056 for battery charging.

---

## 📹 Demo


<!-- add demo video link here -->

---

## 🖼️ Gallery

<!-- add photos here -->

---

## 📐 Schematics

<img width="3000" height="2585" alt="circuit_image" src="https://github.com/user-attachments/assets/4f74fcf4-ab1a-4eba-a8c0-07eedae82ccc" />

---

## 🧰 Components

- ESP32 WROOM (Type-C, 30 pin)
- TP4056 Li-ion charging module
- Soil moisture sensor board
- Soil moisture sensor probe
- 18650 Li-ion battery

---

## 💻 Code

The code is at [`soilbuddy/codes/working.ino`](../codes/working.ino)

---

## 🔌 Wiring

| Component | Pin | ESP32 Pin |
|-----------|-----|-----------|
| Soil Sensor | VCC | 3V3 |
| Soil Sensor | GND | GND |
| Soil Sensor | AO | D34 |
| TP4056 | OUT+ | VIN |
| TP4056 | OUT- | GND |
| TP4056 | B+ | Battery + |
| TP4056 | B- | Battery - |

---

*Made by [your name] — Zafer College*
