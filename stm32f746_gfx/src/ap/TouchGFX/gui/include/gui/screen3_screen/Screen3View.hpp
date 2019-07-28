#ifndef SCREEN3_VIEW_HPP
#define SCREEN3_VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <stdio.h>


class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollList1UpdateItem(baud_list& item, int16_t itemIndex)
    {
      item.setBaudIndex(itemIndex);
    }
    virtual void scrollList_PortUpdateItem(port_list& item, int16_t itemIndex)
    {
      item.setPort(itemIndex);
    }
    virtual void clickOpen();
    virtual void clickClose();


    void updateSelectedItem(void);
    void setPortInfo(uint8_t channel, uint32_t baud);

protected:
    int16_t baud_index;
    uint8_t port_index;
};

#endif // SCREEN3_VIEW_HPP
