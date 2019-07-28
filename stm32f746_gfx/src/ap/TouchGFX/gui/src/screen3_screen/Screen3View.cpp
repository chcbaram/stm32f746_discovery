#include <gui/screen3_screen/Screen3View.hpp>
#include <stdio.h>

Screen3View::Screen3View()
{
  port_index = 0;
  baud_index = 2;
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();

    bool     is_open;
    uint8_t  channel;
    uint32_t baud;

    presenter->getPortInfo(is_open, channel, baud);

    setPortInfo(channel, baud);
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::updateSelectedItem(void)
{
  for (int i=0; i<scrollList1.getNumberOfItems(); i++)
  {
    if (scrollList1.getItem(i) >= 0)
    {
      if (scrollList1ListItems[i].getY() >= 0 && scrollList1ListItems[i].getY() < scrollList1.getDrawableSize())
      {
        baud_index = scrollList1.getItem(i);
      }
    }
  }

  for (int i=0; i<scrollList_Port.getNumberOfItems(); i++)
  {
    if (scrollList_Port.getItem(i) >= 0)
    {
      if (scrollList_PortListItems[i].getY() >= 0 && scrollList_PortListItems[i].getY() < scrollList_Port.getDrawableSize())
      {
        port_index = scrollList_Port.getItem(i);
      }
    }
  }
}

void Screen3View::setPortInfo(uint8_t channel, uint32_t baud)
{
  int index = 0;
  uint32_t baud_tbl[4] = {9600, 19200, 57600, 115200};


  for (int i=0; i<4; i++)
  {
    if (baud_tbl[i] == baud)
    {
      index = i;
      break;
    }
  }

  port_index = channel;
  baud_index = index;

  scrollList_Port.animateToItem(channel, 0);
  scrollList1.animateToItem(index, 0);
}

void Screen3View::clickOpen()
{
  uint32_t baud_tbl[4] = {9600, 19200, 57600, 115200};


  updateSelectedItem();

  presenter->openPort(port_index, baud_tbl[baud_index]);
}

void Screen3View::clickClose()
{

}
