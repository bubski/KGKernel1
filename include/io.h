#ifndef _IO_H
# define _IO_H
#endif

#ifdef _IO_H
extern char *video;

extern void outb(unsigned short port, unsigned char value);
extern void outw(unsigned short port, unsigned short value);
extern unsigned char inb(unsigned short port);
extern void printcol_char(char c, unsigned char fg, unsigned char bg, int x, int y);
extern void printcol_str(char *str, unsigned char fg, unsigned char bg, int x, int y);
extern char *printcol_int(int value, unsigned char fg, unsigned char bg, int x, int y);
extern void printf(char *str, ...);
extern void clr();
#endif