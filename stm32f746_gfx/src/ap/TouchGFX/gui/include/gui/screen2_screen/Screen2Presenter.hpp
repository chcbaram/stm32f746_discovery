#ifndef SCREEN2_PRESENTER_HPP
#define SCREEN2_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen2View;

class Screen2Presenter : public Presenter, public ModelListener
{
public:
    Screen2Presenter(Screen2View& v);

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

    virtual ~Screen2Presenter() {};

    virtual void updateConsole(void);
    virtual void addConsoleData(const char *p_data, int32_t length);

private:
    Screen2Presenter();

    Screen2View& view;
};


#endif // SCREEN2_PRESENTER_HPP
