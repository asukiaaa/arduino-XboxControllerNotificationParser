# arduino-XboxControllerNotificationParser

A library for arduino to parse notification from a xbox series X or S controller.

## Setup

### Arduino IDE

Open library manager (Sketch -> Include library -> Manager libraries) then search `XboxControllerNotificationParser` and install it.

### PlatformIO

Add `XboxControllerNotificationParser` as lib_deps in platformio.ini like this.

```
lib_deps = XboxControllerNotificationParser
```

## Usage

Include.
```cpp
#include <XboxControllerNotificationParser.h>
```

With using NimBLE-Arduino.
```cpp
XboxControllerNotificationParser xboxNotif;

void notifyCB(NimBLERemoteCharacteristic* pRemoteCharacteristic, uint8_t* pData,
              size_t length, bool isNotify) {
  xboxNotif.update(pData, length);
}
```

Print info.
```cpp
Serial.print(xboxNotif.toString());
```

You can call these variables like this.
```cpp
if (xboxNotif.btnA) {
  Serial.println("A is pressed");
}
```

Variable | type | role
--- | --- | ---
btnA | bool | State of A button.
btnB | bool | State of B button.
btnX | bool | State of X button.
btnY | bool | State of Y button.
btnLB | bool | State of left back button.
btnRB | bool | State of right back button.
btnSelect | bool | State of select button.
btnStart | bool | State of start button.
btnXbox | bool | State of xbox button.
btnShare | bool | State of share button.
btnLS | bool | State of left stick button.
btnRS | bool | State of right stick button.
btnDirUp | bool | State of direction up button.
btnDirRight | bool | State of direction right button.
btnDirLeft | bool | State of direction left button.
btnDirDown | bool | State of direction down button.
joyLHori | uint16_t | Value of horizontal directoin of left joystick.<br />min: 0 (left). max: 0xffff (right).
joyLVert | uint16_t | Value of vertical directoin of left joystick.<br />min: 0 (up). max: 0xffff (down).
joyRHori | uint16_t | Value of horizontal directoin of right joystick.<br />min: 0 (left). max: 0xffff (right).
joyRVert | uint16_t | Value of vertical directoin of right joystick.<br />min: 0 (up). max: 0xffff (down).
trigLT | uint16_t | Value of left triger.<br />min: 0. max: 0x3ff.
trigRT | uint16_t | Value of right triger.<br />min: 0. max: 0x3ff.

## License

MIT

## References

- [ESP32とXboxのコントローラーをBLEで接続する方法](https://asukiaaa.blogspot.com/2021/01/communicate-esp32-and-xbox-controller-on-ble.html)
- [NimBLE-Arduino](https://github.com/h2zero/NimBLE-Arduino)
- [xpadneo](https://github.com/atar-axis/xpadneo)
- [hid-xpadneo.c](https://github.com/atar-axis/xpadneo/blob/master/hid-xpadneo/src/hid-xpadneo.c)
