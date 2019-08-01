/*
 * ap.cpp
 *
 *  Created on: 2019. 6. 14.
 *      Author: HanCheol Cho
 */




#include "ap.h"



void apInit(void)
{
  cmdifOpen(_DEF_UART1, 57600);
  //uartOpen(_DEF_UART1, 57600);
}

void apMain(void)
{
  uint32_t pre_time;
  usb_hid_joy_msg_t joy_msg;


  usbHidStart();


  while(1)
  {
    cmdifMain();

    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);


      usbHidJoyCurrentRead(&joy_msg);

      //printf("%d %d 0x%08X \r\n", (int)joy_msg.l_x, (int)joy_msg.l_y, (int)joy_msg.buttons);
    }

    usbHidUpdate();
  }
}

