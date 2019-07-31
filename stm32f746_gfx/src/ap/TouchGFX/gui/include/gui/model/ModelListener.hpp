#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <stdint.h>

/**
 * ModelListener is the interface through which the Model can inform the currently
 * active presenter of events. All presenters should derive from this class.
 * It also provides a model pointer for the presenter to interact with the Model.
 *
 * The bind function is called automatically.
 *
 * Add the virtual functions Model should be able to call on the active presenter to this class.
 */

namespace touchgfx
{
typedef struct
{
  bool   connected;
  int8_t l_x;
  int8_t l_y;

  int8_t r_x;
  int8_t r_y;

  uint32_t buttons;

} joypad_msg_t;


typedef enum {
  JOY_BTN_L_UP = 0,
  JOY_BTN_L_DOWN,
  JOY_BTN_L_LEFT,
  JOY_BTN_L_RIGHT,

  JOY_BTN_R_UP,
  JOY_BTN_R_DOWN,
  JOY_BTN_R_LEFT,
  JOY_BTN_R_RIGHT,

  JOY_BTN_BACK,
  JOY_BTN_START,
  JOY_BTN_MODE,
  JOY_BTN_VIBRATION,

  JOY_BTN_LT,
  JOY_BTN_LB,

  JOY_BTN_RT,
  JOY_BTN_RB,
} joypad_button;
}


class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    /**
     * Sets the model pointer to point to the Model object. Called automatically
     * when switching screen.
     */
    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateConsole(void) {};
    virtual void addConsoleData(const char *p_data, int32_t length) {};
    virtual void openPort(uint8_t channel, uint32_t baud) {};
    virtual void closePort(uint8_t channel) {};
    virtual void getPortInfo(bool &is_open, uint8_t &channel, uint32_t &baud) {};

    virtual void setPadInfo(touchgfx::joypad_msg_t &pad_msg) {};

protected:
    Model* model;
};

#endif /* MODELLISTENER_HPP */
