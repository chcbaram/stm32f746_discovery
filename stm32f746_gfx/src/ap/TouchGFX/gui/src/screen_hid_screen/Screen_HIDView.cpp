#include <gui/screen_hid_screen/Screen_HIDView.hpp>
#include <touchgfx/Color.hpp>


Screen_HIDView::Screen_HIDView()
{

}

void Screen_HIDView::setupScreen()
{
    Screen_HIDViewBase::setupScreen();
}

void Screen_HIDView::tearDownScreen()
{
    Screen_HIDViewBase::tearDownScreen();
}

void Screen_HIDView::setPadInfo(joypad_msg_t &pad_msg)
{

  Unicode::snprintf(textArea_L_XBuffer, TEXTAREA_L_X_SIZE, "%d", pad_msg.l_x);
  Unicode::snprintf(textArea_L_YBuffer, TEXTAREA_L_Y_SIZE, "%d", pad_msg.l_y);
  Unicode::snprintf(textArea_R_XBuffer, TEXTAREA_R_X_SIZE, "%d", pad_msg.r_x);
  Unicode::snprintf(textArea_R_YBuffer, TEXTAREA_R_Y_SIZE, "%d", pad_msg.r_y);


  Unicode::snprintf(textArea_L_UBuffer, TEXTAREA_L_U_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_L_UP));
  Unicode::snprintf(textArea_L_DBuffer, TEXTAREA_L_D_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_L_DOWN));
  Unicode::snprintf(textArea_L_LBuffer, TEXTAREA_L_L_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_L_LEFT));
  Unicode::snprintf(textArea_L_RBuffer, TEXTAREA_L_R_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_L_RIGHT));

  Unicode::snprintf(textArea_R_UBuffer, TEXTAREA_R_U_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_R_UP));
  Unicode::snprintf(textArea_R_DBuffer, TEXTAREA_R_D_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_R_DOWN));
  Unicode::snprintf(textArea_R_LBuffer, TEXTAREA_R_L_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_R_LEFT));
  Unicode::snprintf(textArea_R_RBuffer, TEXTAREA_R_R_SIZE, "%d", getButtonState(pad_msg.buttons, JOY_BTN_R_RIGHT));

  textArea_L_X.invalidate();
  textArea_L_Y.invalidate();
  textArea_R_X.invalidate();
  textArea_R_Y.invalidate();

  textArea_L_U.invalidate();
  textArea_L_D.invalidate();
  textArea_L_R.invalidate();
  textArea_L_L.invalidate();

  textArea_R_U.invalidate();
  textArea_R_D.invalidate();
  textArea_R_R.invalidate();
  textArea_R_L.invalidate();

  if (pad_msg.connected == true)
  {
    Unicode::snprintf(textArea_ConnectedBuffer, TEXTAREA_CONNECTED_SIZE, "Connected");
    textArea_Connected.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 255));
  }
  else
  {
    Unicode::snprintf(textArea_ConnectedBuffer, TEXTAREA_CONNECTED_SIZE, "Disconnected");
    textArea_Connected.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
  }
  textArea_Connected.invalidate();
}

bool Screen_HIDView::getButtonState(uint32_t button_msg, joypad_button button_key)
{
  bool ret = false;

  if (button_msg & (1<<button_key))
  {
    ret = true;
  }

  return ret;
}
