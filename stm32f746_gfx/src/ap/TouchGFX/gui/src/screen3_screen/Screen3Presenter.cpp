#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{
}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::openPort(uint8_t channel, uint32_t baud)
{
  model->openPort(channel, baud);
}

void Screen3Presenter::closePort(uint8_t channel)
{
  model->closePort(channel);
}

void Screen3Presenter::getPortInfo(bool &is_open, uint8_t &channel, uint32_t &baud)
{
  model->getPortInfo(is_open, channel, baud);
}
