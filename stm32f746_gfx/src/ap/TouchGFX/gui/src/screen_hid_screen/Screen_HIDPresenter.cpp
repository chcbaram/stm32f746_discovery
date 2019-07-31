#include <gui/screen_hid_screen/Screen_HIDView.hpp>
#include <gui/screen_hid_screen/Screen_HIDPresenter.hpp>

Screen_HIDPresenter::Screen_HIDPresenter(Screen_HIDView& v)
    : view(v)
{
}

void Screen_HIDPresenter::activate()
{

}

void Screen_HIDPresenter::deactivate()
{

}

void Screen_HIDPresenter::setPadInfo(joypad_msg_t &pad_msg)
{
  view.setPadInfo(pad_msg);
}
