#include <io.h>
#include <lib.h>
#include <bool.h>
#include <string.h>
#include <cursor.h>
#include <tmp.h>

bool capslock_press_bool, numlock_press_bool, enter_press_bool, esc_press_bool;
char *tmp_str_keyboard;

char sctoc(char scancode)
{
    switch (scancode)
    {
        case 0x01:
            cursor_x--;
            esc_press_bool = true;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x02:
            tmp_str_keyboard[cursor_x - tmp_num] = '1';
            return '1';
            break;
        case 0x03:
            tmp_str_keyboard[cursor_x - tmp_num] = '2';
            return '2';
            break;
        case 0x04:
            tmp_str_keyboard[cursor_x - tmp_num] = '3';
            return '3';
            break;
        case 0x05:
            tmp_str_keyboard[cursor_x - tmp_num] = '4';
            return '4';
            break;
        case 0x06:
            tmp_str_keyboard[cursor_x - tmp_num] = '5';
            return '5';
            break;
        case 0x07:
            tmp_str_keyboard[cursor_x - tmp_num] = '6';
            return '6';
            break;
        case 0x08:
            tmp_str_keyboard[cursor_x - tmp_num] = '7';
            return '7';
            break;
        case 0x09:
            tmp_str_keyboard[cursor_x - tmp_num] = '8';
            return '8';
            break;
        case 0x0A:
            tmp_str_keyboard[cursor_x - tmp_num] = '9';
            return '9';
            break;
        case 0x0B:
            tmp_str_keyboard[cursor_x - tmp_num] = '0';
            return '0';
            break;
        case 0x0C:
            tmp_str_keyboard[cursor_x - tmp_num] = '-';
            return '-';
            break;
        case 0x0D:
            tmp_str_keyboard[cursor_x - tmp_num] = '=';
            return '=';
            break;
        case 0x0E:
            cursor_x -= (cursor_x > tmp_num ? 2 : 1);
            tmp_str_keyboard[cursor_x - tmp_num + 1] = 0x00;
            return 0x00;
            break;
        case 0x0F:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x10:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'Q' : 'q');
            return (capslock_press_bool ? 'Q' : 'q');
            break;
        case 0x11:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'W' : 'w');
            return (capslock_press_bool ? 'W' : 'w');
            break;
        case 0x12:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'E' : 'e');
            return (capslock_press_bool ? 'E' : 'e');
            break;
        case 0x13:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'R' : 'r');
            return (capslock_press_bool ? 'R' : 'r');
            break;
        case 0x14:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'T' : 't');
            return (capslock_press_bool ? 'T' : 't');
            break;
        case 0x15:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'Y' : 'y');
            return (capslock_press_bool ? 'Y' : 'y');
            break;
        case 0x16:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'U' : 'u');
            return (capslock_press_bool ? 'U' : 'u');
            break;
        case 0x17:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'I' : 'i');
            return (capslock_press_bool ? 'I' : 'i');
            break;
        case 0x18:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'O' : 'o');
            return (capslock_press_bool ? 'O' : 'o');
            break;
        case 0x19:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'P' : 'p');
            return (capslock_press_bool ? 'P' : 'p');
            break;
        case 0x1A:
            tmp_str_keyboard[cursor_x - tmp_num] = '[';
            return '[';
            break;
        case 0x1B:
            tmp_str_keyboard[cursor_x - tmp_num] = ']';
            return ']';
            break;
        case 0x1C:
            enter_press_bool = true;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x1D:
            tmp_str_keyboard[cursor_x - tmp_num] = '^';
            return '^';
            break;
        case 0x1E:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'A' : 'a');
            return (capslock_press_bool ? 'A' : 'a');
            break;
        case 0x1F:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'S' : 's');
            return (capslock_press_bool ? 'S' : 's');
            break;
        case 0x20:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'D' : 'd');
            return (capslock_press_bool ? 'D' : 'd');
            break;
        case 0x21:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'F' : 'f');
            return (capslock_press_bool ? 'F' : 'f');
            break;
        case 0x22:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'G' : 'g');
            return (capslock_press_bool ? 'G' : 'g');
            break;
        case 0x23:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'H' : 'h');
            return (capslock_press_bool ? 'H' : 'h');
            break;
        case 0x24:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'J' : 'j');
            return (capslock_press_bool ? 'J' : 'j');
            break;
        case 0x25:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'K' : 'k');
            return (capslock_press_bool ? 'K' : 'k');
            break;
        case 0x26:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'L' : 'l');
            return (capslock_press_bool ? 'L' : 'l');
            break;
        case 0x27:
            tmp_str_keyboard[cursor_x - tmp_num] = ';';
            return ';';
            break;
        case 0x28:
            tmp_str_keyboard[cursor_x - tmp_num] = '\'';
            return '\'';
            break;
        case 0x29:
            tmp_str_keyboard[cursor_x - tmp_num] = '`';
            return '`';
            break;
        case 0x2A:
            tmp_str_keyboard[cursor_x - tmp_num] = '~';
            return '~';
            break;
        case 0x2B:
            tmp_str_keyboard[cursor_x - tmp_num] = '\\';
            return '\\';
            break;
        case 0x2C:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'Z' : 'z');
            return (capslock_press_bool ? 'Z' : 'z');
            break;
        case 0x2D:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'X' : 'x');
            return (capslock_press_bool ? 'X' : 'x');
            break;
        case 0x2E:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'C' : 'c');
            return (capslock_press_bool ? 'C' : 'c');
            break;
        case 0x2F:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'V' : 'v');
            return (capslock_press_bool ? 'V' : 'v');
            break;
        case 0x30:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'B' : 'b');
            return (capslock_press_bool ? 'B' : 'b');
            break;
        case 0x31:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'N' : 'n');
            return (capslock_press_bool ? 'N' : 'n');
            break;
        case 0x32:
            tmp_str_keyboard[cursor_x - tmp_num] = (capslock_press_bool ? 'M' : 'm');
            return (capslock_press_bool ? 'M' : 'm');
            break;
        case 0x33:
            tmp_str_keyboard[cursor_x - tmp_num] = ',';
            return ',';
            break;
        case 0x34:
            tmp_str_keyboard[cursor_x - tmp_num] = '.';
            return '.';
            break;
        case 0x35:
            tmp_str_keyboard[cursor_x - tmp_num] = '/';
            return '/';
            break;
        case 0x36:
            tmp_str_keyboard[cursor_x - tmp_num] = '~';
            return '~';
            break;
        case 0x37:
            tmp_str_keyboard[cursor_x - tmp_num] = '*';
            return '*';
            break;
        case 0x38:
            tmp_str_keyboard[cursor_x - tmp_num] = '@';
            return '@';
            break;
        case 0x39:
            tmp_str_keyboard[cursor_x - tmp_num] = ' ';
            return ' ';
            break;
        case 0x3A:
            cursor_x--;
            capslock_press_bool = capslock_press_bool == true ? false : true;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x3B:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x3C:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x3D:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x3E:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x3F:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x40:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x41:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x42:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x43:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x44:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x45:
            cursor_x--;
            numlock_press_bool = numlock_press_bool == true ? false : true;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x46:
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x47:
            tmp_str_keyboard[cursor_x - tmp_num] = '7';
            return '7';
            break;
        case 0x48:
            tmp_str_keyboard[cursor_x - tmp_num] = '8';
            return '8';
            break;
        case 0x49:
            tmp_str_keyboard[cursor_x - tmp_num] = '9';
            return '9';
            break;
        case 0x4A:
            tmp_str_keyboard[cursor_x - tmp_num] = '-';
            return '-';
            break;
        case 0x4B:
            tmp_str_keyboard[cursor_x - tmp_num] = '4';
            return '4';
            break;
        case 0x4C:
            tmp_str_keyboard[cursor_x - tmp_num] = '5';
            return '5';
            break;
        case 0x4D:
            tmp_str_keyboard[cursor_x - tmp_num] = '6';
            return '6';
            break;
        case 0x4E:
            tmp_str_keyboard[cursor_x - tmp_num] = '+';
            return '+';
            break;
        case 0x4F:
            tmp_str_keyboard[cursor_x - tmp_num] = '1';
            return '1';
            break;
        case 0x50:
            tmp_str_keyboard[cursor_x - tmp_num] = '2';
            return '2';
            break;
        case 0x51:
            tmp_str_keyboard[cursor_x - tmp_num] = '3';
            return '3';
            break;
        case 0x52:
            tmp_str_keyboard[cursor_x - tmp_num] = '0';
            return '0';
            break;
        case 0x53:
            tmp_str_keyboard[cursor_x - tmp_num] = '.';
            return '.';
            break;
        case 0x57:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        case 0x58:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
            break;
        default:
            cursor_x--;
            tmp_str_keyboard[cursor_x - tmp_num] = 0x00;
            return 0x00;
    }
}

char getsc()
{
    char c;
    outb(0x60, 0x00);
    do
    {
        if (inb(0x60) != c)
        {
            c = inb(0x60);
            if (c > 0)
            {
                return sctoc(c);
            }
        }
    }
    while (TRUE);
}
