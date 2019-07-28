#ifndef BAUD_LIST_HPP
#define BAUD_LIST_HPP

#include <gui_generated/containers/baud_listBase.hpp>

class baud_list : public baud_listBase
{
public:
    baud_list();
    virtual ~baud_list() {}

    virtual void initialize();

    void setBaudIndex(int16_t baud_num)
    {
      Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", getBaud(baud_num));
    }

    int16_t getBaudIndex(uint32_t baud)
    {
      int16_t ret = -1;

      switch(baud)
      {
        case 9600:
          ret = 0;
          break;

        case 19200:
          ret = 1;
          break;

        case 57600:
          ret = 2;
          break;

        case 115200:
          ret = 3;
          break;
      }

      return ret;
    }

    uint32_t getBaud(int16_t index)
    {
      uint32_t ret = 57600;
      uint32_t baud_tbl[4] = {9600, 19200, 57600, 115200};

      if (index < 4)
      {
        ret = baud_tbl[index];
      }

      return ret;
    }
protected:
};

#endif // BAUD_LIST_HPP
