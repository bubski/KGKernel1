int atoi(char *str)
{
    int i;
    int output = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        output *= 10;
        output += str[i];
        output -= '0';
    }
    return output;
}

char *itoa(int value, char *str, int base)
{
    char *output;
    char *ptr;
    char *low;
    if (base < 2 | base > 36)
    {
        *str = '\0';
        return str;
    }
    output = ptr = str;
    if (value < 0 & base == 10)
    {
        *ptr++ = '-';
    }
    low = ptr;
    do
    {
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    }
    while (value);
    *ptr-- = '\0';
    while (low < ptr)
    {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return output;
}