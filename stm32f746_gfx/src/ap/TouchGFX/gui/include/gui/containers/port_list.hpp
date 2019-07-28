#ifndef PORT_LIST_HPP
#define PORT_LIST_HPP

#include <gui_generated/containers/port_listBase.hpp>

class port_list : public port_listBase
{
public:
    port_list();
    virtual ~port_list() {}

    virtual void initialize();

    void setPort(int16_t port_num)
    {
      Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "UART%d", port_num + 1);
    }
protected:
};

#endif // PORT_LIST_HPP
