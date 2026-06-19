# 🌱 SoilBuddy

SoilBuddy is a wireless soil moisture sensor I built to monitor my plants without having to constantly check on them. It reads soil moisture levels and hosts a live dashboard over WiFi, no app needed, just open a browser.

> Built with an ESP32, a soil moisture sensor, and a TP4056 for battery charging.

---

## Demo




---

## 🖼️ Gallery

<div align="center">
<table>
<tr>
<td><img width="250" src="https://github.com/user-attachments/assets/82bd563f-afa1-41e7-b363-583506a4f0f4" /></td>
<td><img width="250" src="https://github.com/user-attachments/assets/26c00d7c-4a46-4bb4-813d-6ae5b6c0c6d0" /></td>
<td><img width="250" src="https://github.com/user-attachments/assets/b8f6034a-440b-4038-8273-d0208b6e4565" /></td>
</tr>
</table>
</div>


---

## Schematics

<img width="3000" height="2585" alt="circuit_image" src="https://github.com/user-attachments/assets/4f74fcf4-ab1a-4eba-a8c0-07eedae82ccc" />

---

## Components

- ESP32 WROOM (Type-C or MicroUSB, 30 pin)
- TP4056 Li-ion charging module
- Soil moisture sensor board
- Soil moisture sensor probe
- 18650 Li-ion battery

---

## Code

1. Open [`soilbuddy/codes/working.ino`](../codes/working.ino) in Arduino IDE
2. Find these lines and change them to your WiFi credentials:

```cpp
// ---- WiFi credentials ----
const char* ssid     = "wifiname";
const char* password = "wifipassword";
```

3. Flash the code to your ESP32 WROOM board

---

## Wiring

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

Made by Kuzey (@craftfec) and Derin (@derinozel5)
