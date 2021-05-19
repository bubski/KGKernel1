#ifndef _BOOL_H
# define _BOOL_H
#endif

#ifdef _BOOL_H
# define TRUE (1 == 1)
# define FALSE (1 == 0)

typedef enum
{
    true = (1 == 1),
    false = (1 == 0)
} bool;
#endif