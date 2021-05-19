#include <io.h>

int cursor_x, cursor_y;

void move_cursor(int x, int y)
{
    cursor_x = x;
    cursor_y = y;
    int cursor_position = y * 80 + x;
    outb(0x3D4, 0x0E);
    outb(0x3D5, cursor_position >> 8);
    outb(0x3D4, 0x0F);
    outb(0x3D5, cursor_position);
}