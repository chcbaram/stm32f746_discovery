#ifndef SCREEN_HID_VIEW_HPP
#define SCREEN_HID_VIEW_HPP

#include <gui_generated/screen_hid_screen/Screen_HIDViewBase.hpp>
#include <gui/screen_hid_screen/Screen_HIDPresenter.hpp>

class Screen_HIDView : public Screen_HIDViewBase
{
public:
    Screen_HIDView();
    virtual ~Screen_HIDView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setPadInfo(joypad_msg_t &pad_msg);
protected:

    bool getButtonState(uint32_t button_msg, joypad_button button_key);
};

#endif // SCREEN_HID_VIEW_HPP
