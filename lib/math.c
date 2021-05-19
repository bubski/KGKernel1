int pow(int x, int y)
{
    int i;
    int tmp_x;
    tmp_x = x;
    if (x > 0)
    {
        for (i = 0; i < y - 1; i++)
        {
            x *= tmp_x;
        }
    }
    return x;
}

int factorial(int x)
{
    int i;
    int output = 1;
    if (x == 0)
    {
        output = 1;
    }
    else if (x > 0)
    {
        for (i = 2; i < x + 1; i++)
        {
            output *= i;
        }
    }
    else
    {
        output = '\0';
    }
    return output;
}