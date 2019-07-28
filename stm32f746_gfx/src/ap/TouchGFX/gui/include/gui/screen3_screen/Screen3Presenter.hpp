#ifndef SCREEN3_PRESENTER_HPP
#define SCREEN3_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen3View;

class Screen3Presenter : public Presenter, public ModelListener
{
public:
    Screen3Presenter(Screen3View& v);

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

    virtual ~Screen3Presenter() {};

    virtual void openPort(uint8_t channel, uint32_t baud);
    virtual void closePort(uint8_t channel);
    virtual void getPortInfo(bool &is_open, uint8_t &channel, uint32_t &baud);

private:
    Screen3Presenter();

    Screen3View& view;
};


#endif // SCREEN3_PRESENTER_HPP
