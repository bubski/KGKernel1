#ifndef _KEYBOARD_H
# define _KEYBOARD_H
#endif

#ifdef _KEYBOARD_H
extern bool capslock_press_bool, numlock_press_bool, enter_press_bool, esc_press_bool;
extern char *tmp_str_keyboard;

extern char sctoc(char scancode);
extern char getsc();
#endif