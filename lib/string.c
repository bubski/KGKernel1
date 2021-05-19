#include <lib.h>
#include <bool.h>

int strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

int strequ(char *s1, char *s2)
{
    int i = 0;
    int ret;
    while (s1[i])
    {
        if (strlen(s1) == strlen(s2))
        {
            if (s1[i] == s2[i])
            {
                ret = TRUE;
            }
            else
            {
                ret = FALSE;
                break;
            }
        }
        else
        {
            ret = FALSE;
        }
        i++;
    }
    return ret;
}

int isint(char *str)
{
    int i = 0;
    int ret;
    while (str[i])
    {
        if (str[i] >= '0' & str[i] <= '9')
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
            break;
        }
        i++;
    }
    return ret;
}

void clear_str(char *str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = '\0';
        i++;
    }
}