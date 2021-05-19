#ifndef _LIB_H
# define _LIB_H
#endif

#ifdef _LIB_H
# ifndef _DEF_H
#  include <def.h>
# endif

# define RAND_MAX 32767

extern int rand();
extern unsigned randto(unsigned n);
extern unsigned rrand(unsigned to, unsigned hi);
extern void *malloc(size_t size);
extern int atoi(char *str);
extern char *itoa(int value, char *str, int base);
#endif