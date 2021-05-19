#include <lib.h>
#include <cursor.h>

#define PRINTF_COLOR 7

char *video = (char *)0xB8000;

void outb(unsigned short port, unsigned char value)
{
    asm("outb %0, %1"
        :
        :"a"(value),
        "Nd"(port));
}

void outw(unsigned short port, unsigned short value)
{
    asm("outw %0, %1"
        :
        :"a"(value),
        "Nd"(port));
}

unsigned char inb(unsigned short port)
{
    unsigned char value;
    asm("inb %1, %0"
        :"=a"(value)
        :"d"(port));
    return value;
}

void printcol_char(char c, unsigned char fg, unsigned char bg, int x, int y)
{
     unsigned short attrib = (bg << 4) | (fg & 0x0F);
     unsigned short *position;
     position = (unsigned short *)0xB8000 + (y * 80 + x);
     *position = c | (attrib << 8);
}

void printcol_str(char *str, unsigned char fg, unsigned char bg, int x, int y)
{
    int i = 0;
    while (str[i])
    {
        printcol_char(str[i], fg, bg, cursor_x + i, cursor_y);
        i++;
    }
}

char *printcol_int(int value, unsigned char fg, unsigned char bg, int x, int y)
{
    char *str;
    printcol_str(itoa(value, str, 10), fg, bg, cursor_x, cursor_y);
    return str;
}

void printf(char *format, ...)
{
    char c;
    __builtin_va_list va;
    __builtin_va_start(va, format);
    while ((c = *(format++)))
    {
        if (c == '%' & format[0] != 0)
        {
            switch (format[0])
            {
                case 's':
                    printcol_str(__builtin_va_arg(va, char *), PRINTF_COLOR, 0, cursor_x, cursor_y);
                    break;
                case 'd':
                    printcol_int(__builtin_va_arg(va, int), PRINTF_COLOR, 0, cursor_x, cursor_y);
                    break;
            }
        }
    }
}

void clr()
{
    int i = 0;
    while (video[i])
    {
        video[i] = '\0';
        i++;
    }
}