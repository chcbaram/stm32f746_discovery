#ifndef SCREEN_HID_PRESENTER_HPP
#define SCREEN_HID_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_HIDView;

class Screen_HIDPresenter : public Presenter, public ModelListener
{
public:
    Screen_HIDPresenter(Screen_HIDView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen_HIDPresenter() {};

    virtual void setPadInfo(touchgfx::joypad_msg_t &pad_msg);

private:
    Screen_HIDPresenter();

    Screen_HIDView& view;
};


#endif // SCREEN_HID_PRESENTER_HPP
