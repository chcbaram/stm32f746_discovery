/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/port_listBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

port_listBase::port_listBase()
{
    setWidth(171);
    setHeight(35);

    textArea1.setXY(117, 5);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", TypedText(T_SINGLEUSEID10).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(TypedText(T_SINGLEUSEID9));

    add(textArea1);
}

void port_listBase::initialize()
{
	
}