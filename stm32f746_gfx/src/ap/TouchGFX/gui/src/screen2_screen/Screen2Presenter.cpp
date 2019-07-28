#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{
}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::updateConsole(void)
{
  view.updateConsole();
}

void Screen2Presenter::addConsoleData(const char *p_data, int32_t length)
{
  view.addConsoleData(p_data, length);
}


