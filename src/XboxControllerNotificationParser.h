#ifndef __XBOX_CONTROLLER_NOTIFICATION_PARSER_H__
#define __XBOX_CONTROLLER_NOTIFICATION_PARSER_H__

#include <Arduino.h>

#define XBOX_CONTROLLER_ERROR_INVALID_LENGTH 1

class XboxControllerNotificationParser {
  public:
  XboxControllerNotificationParser();

  bool btnA, btnB, btnX, btnY;
  bool btnShare, btnStart, btnSelect, btnXbox;
  bool btnLB, btnRB, btnLS, btnRS;
  bool btnDirUp, btnDirLeft, btnDirRight, btnDirDown;
  uint16_t joyLHori, joyLVert, joyRHori, joyRVert, trigLT, trigRT;
  uint8_t update(uint8_t* data, size_t length);
  String toString();
};

#endif
