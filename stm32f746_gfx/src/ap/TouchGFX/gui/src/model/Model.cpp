#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "hw.h"
#include "ring.h"


char line_buffer[2048];
ring_node_t q_line;
#endif


Model::Model() : modelListener(0)
{
#ifndef SIMULATOR
  ringCreate(&q_line, 2048);
#endif

  port_open = false;
  port_channel = 0;
  port_baud = 57600;
}

void Model::openPort(uint8_t channel, uint32_t baud)
{
#ifndef SIMULATOR
  uartOpen(channel, baud);
#endif

  port_open = true;
  port_channel = channel;
  port_baud = baud;
}

void Model::closePort(uint8_t channel)
{
#ifndef SIMULATOR
  uartClose(channel);
#endif

  port_open = false;
}

void Model::getPortInfo(bool &is_open, uint8_t &channel, uint32_t &baud)
{
  is_open = port_open;
  channel = port_channel;
  baud = port_baud;
}


void Model::tick()
{
#ifndef SIMULATOR
  updateConsole();
  updatePad();
#endif
}

void Model::updateConsole(void)
{
#ifndef SIMULATOR
  bool update = false;
  uint8_t data[128];
  uint8_t ch;
  int read_length;
  int index;

  if (port_open == true)
  {
    while(uartAvailable(_DEF_UART1) > 0)
    {
      read_length = constrain(uartAvailable(_DEF_UART1), 0, 128);

      index = 0;
      for (int i=0; i<read_length; i++)
      {
        ch = uartRead(_DEF_UART1);;
        if (ch == '\r')
        {

        }
        else if (ch == 0x08)
        {
          if (index > 0)
          {
            index--;
          }
          else
          {
            modelListener->addConsoleData((const char *)NULL, -1);
            update = true;
          }
        }
        else
        {
          data[index++] = ch;
        }
      }

      if (index > 0)
      {
        modelListener->addConsoleData((const char *)data, index);
        update = true;
      }
    }

    if (update == true)
    {
      modelListener->updateConsole();
    }
  }
#endif
}

void Model::updatePad(void)
{
#ifndef SIMULATOR
  touchgfx::joypad_msg_t pad_msg;
  usb_hid_joy_msg_t joy_msg;


  usbHidJoyCurrentRead(&joy_msg);

  pad_msg.connected = usbHidJoyIsConnected();

  pad_msg.l_x = joy_msg.l_x;
  pad_msg.l_y = joy_msg.l_y;
  pad_msg.r_x = joy_msg.r_x;
  pad_msg.r_y = joy_msg.r_y;
  pad_msg.buttons = joy_msg.buttons;


  modelListener->setPadInfo(pad_msg);
#endif
}
