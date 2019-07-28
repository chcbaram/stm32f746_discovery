#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>



void ScrollableContainerText::scrollDown(int deltaY)
{
  doScroll(0, deltaY);
}

Screen2View::Screen2View()
{
  textArea_Console.setXY(0, 0);
  textArea_Console.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
  textArea_Console.setLinespacing(0);
  textArea_ConsoleBuffer[0] = 0;
  textArea_Console.setWildcard(textArea_ConsoleBuffer);
  textArea_Console.resizeToCurrentText();
  textArea_Console.setTypedText(TypedText(T_SINGLEUSEID4));


  scrollableContainer_Text.setPosition(0, 0, 480, 272);
  scrollableContainer_Text.setScrollbarsColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
  scrollableContainer_Text.setScrollbarPadding(1);
  scrollableContainer_Text.setScrollbarWidth(3);
  scrollableContainer_Text.setScrollbarsAlpha(255);
  scrollableContainer_Text.setScrollbarsPermanentlyVisible();

  scrollableContainer_Text.add(textArea_Console);

  remove(buttonWithIcon_Home);
  remove(buttonWithIcon_Menu);
  remove(buttonWithIcon_Setup);

  add(scrollableContainer_Text);

  add(buttonWithIcon_Home);
  add(buttonWithIcon_Menu);
  add(buttonWithIcon_Setup);

  scroll_enable = true;
  menu_enable = true;
  console_length = 0;
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

    textArea_Console.setPosition(0, 0, 480, 0);
    textArea_Console.setWideTextAction(WIDE_TEXT_WORDWRAP);

    for (int i=0; i<TEXTAREA_CONSOLE_SIZE; i++)
    {
      textArea_ConsoleBuffer[i] = 0;
    }

    Unicode::strncpy(&textArea_ConsoleBuffer[0], "_", 1);
    textArea_ConsoleBuffer[1] = 0;
    updateConsole();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::addString(const char *p_buf)
{
}

void Screen2View::addChar(uint8_t ch)
{
}

void Screen2View::addConsoleData(const char *p_data, int32_t length)
{
  int copy_length;

  if (length <= 0)
  {
    if (console_length >= abs(length))
    {
      if (console_length > 0 && textArea_ConsoleBuffer[console_length-1] != '\n')
      {
        console_length += length;
        Unicode::strncpy(&textArea_ConsoleBuffer[console_length], "_", 1);
        textArea_ConsoleBuffer[console_length + 1] = 0;
      }
    }

    return;
  }


  if (console_length + length > (TEXTAREA_CONSOLE_SIZE-2))
  {
    copy_length = console_length - ((console_length + length) - (TEXTAREA_CONSOLE_SIZE-2));
    Unicode::strncpy(&textArea_ConsoleBuffer[0], &textArea_ConsoleBuffer[length], copy_length);

    console_length = copy_length;
  }


  Unicode::strncpy(&textArea_ConsoleBuffer[console_length], (const char *)p_data, length);
  Unicode::strncpy(&textArea_ConsoleBuffer[console_length + length], "_", 1);

  textArea_ConsoleBuffer[console_length + length + 1] = 0;

  console_length += length;
}

void Screen2View::updateConsole(void)
{
  if (scroll_enable == true)
  {
    if (textArea_Console.getTextHeight() > 272)
    {
      textArea_Console.setXBaselineY(0, -(textArea_Console.getTextHeight()-textArea_Console.getHeight()));
      textArea_Console.setY(-(textArea_Console.getTextHeight()-272));
    }
    if (textArea_Console.getTextHeight() != textArea_Console.getHeight())
    {
      textArea_Console.resizeHeightToCurrentText();
    }
  }

  textArea_Console.invalidate();
}

void Screen2View::handleTickEvent(void)
{
}

void Screen2View::clickMenu()
{
  if (menu_enable == true)
  {
    buttonWithIcon_Home.clearMoveAnimationEndedAction();
    buttonWithIcon_Home.startMoveAnimation(480, 0, 6, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);

    buttonWithIcon_Setup.clearMoveAnimationEndedAction();
    buttonWithIcon_Setup.startMoveAnimation(480, 0, 6, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
    menu_enable = false;
  }
  else
  {
    buttonWithIcon_Home.clearMoveAnimationEndedAction();
    buttonWithIcon_Home.startMoveAnimation(420, 0, 6, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);

    buttonWithIcon_Setup.clearMoveAnimationEndedAction();
    buttonWithIcon_Setup.startMoveAnimation(420, 55, 6, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
    menu_enable = true;
  }
}
