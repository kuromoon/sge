#ifndef SGE_SGE_INPUT_H
#define SGE_SGE_INPUT_H

#include <stdbool.h>

typedef enum
{
    SGE_MOUSE_BUTTON_LEFT,
    SGE_MOUSE_BUTTON_RIGHT,
    SGE_MOUSE_BUTTON_SCROLL,
    SGE_MOUSE_BUTTON_COUNT
} sge_mouse_button_t;

typedef enum
{
    SGE_KEYBOARD_KEY_COUNT
} sge_keyboard_key_t;

typedef struct
{
    double x_pos;
    double y_pos;
    bool buttons[SGE_MOUSE_BUTTON_COUNT];
} sge_input_mouse_t;

typedef struct
{
    bool keys[SGE_KEYBOARD_KEY_COUNT];
} sge_input_keyboard_t;

typedef struct
{
    sge_input_mouse_t* mouse;
    sge_input_keyboard_t* keyboard;
} sge_input_core_data_t;


#endif  // SGE_SGE_INPUT_H
