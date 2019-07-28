#ifndef SCREEN2_VIEW_HPP
#define SCREEN2_VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>


class ScrollableContainerText : public touchgfx::ScrollableContainer
{
public:
  virtual void scrollDown(int deltaY);
};


class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void addString(const char *p_buf);
    void addChar(uint8_t ch);
    void updateConsole(void);
    void handleTickEvent(void);

    void addConsoleData(const char *p_data, int32_t length);
    virtual void clickMenu();

protected:
    touchgfx::TextAreaWithOneWildcard textArea_Console;

    static const uint16_t TEXTAREA_CONSOLE_SIZE = 1024;
    touchgfx::Unicode::UnicodeChar textArea_ConsoleBuffer[TEXTAREA_CONSOLE_SIZE];
    ScrollableContainerText scrollableContainer_Text;
    bool scroll_enable;
    bool menu_enable;

    int console_length;
};

#endif // SCREEN2_VIEW_HPP
