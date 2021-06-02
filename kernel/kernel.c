#include <io.h>
#include <lib.h>
#include <def.h>
#include <bool.h>
#include <math.h>
#include <string.h>
#include <keyboard.h>
#include <cursor.h>
#include <tmp.h>
#include <ksys.h>

#include "kernel.h"

#define SHELL_INPUT_COLOR 9

#define COMMAND_ERR "Error: Unknown Command"

char *strr(char *str, char *output, int x, int y)
{
    int i;
    for (i = x + 1; i < y; i++)
    {
        output[i - (x + 1)] = str[i];
    }
    return output;
}

char *command(char *str, int commandlen)
{
    int i;
    char *output = malloc(sizeof(output));
    for (i = 0; i < commandlen; i++)
    {
        output[i] = str[i];
    }
    return output;
}

void clr_command()
{
    int i;
    for (i = 0; i < 80 * 25 * 2; i++)
    {
        video[i] = '\0';
    }
    cursor_y = -1;
}

void calc()
{
    int i;
    char op;
    int tmp_enter_presses;
    int tmp_i;
    bool tmp_bool;
    char *tmp_str = malloc(sizeof(tmp_str));
    char *num1_str;
    char *num2_str;
    int num1, num2;
    int output;
    tmp_enter_presses = 0;
    tmp_str_keyboard = malloc(sizeof(tmp_str_keyboard));
    tmp_num = 0;
    tmp_i = 0;
    tmp_bool = true;
    output = 0;
    move_cursor(0, cursor_y + 1);
    do
    {
        if (enter_press_bool == false)
        {
            printcol_char(getsc(), SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
            printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x + 1, cursor_y);
            move_cursor(cursor_x + 1, cursor_y);
            if (esc_press_bool == true)
            {
                esc_press_bool = false;
                shell_input();
                break;
            }
        }
        else
        {
            for (i = tmp_num; i < 81 - strlen(tmp_str_keyboard); i++)
            {
                move_cursor(i + strlen(tmp_str_keyboard), cursor_y);
                printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
            }
            tmp_bool = false;
            enter_press_bool = false;
            tmp_enter_presses++;
            move_cursor(tmp_num, cursor_y + 1);
            if (tmp_enter_presses == 1)
            {
                if (isint(tmp_str_keyboard))
                {
                    num1_str = tmp_str_keyboard;
                    num1 = atoi(num1_str);
                }
                else
                {
                    printf("%s", "Error: Invalid Integer");
                    cursor_y++;
                    shell_input();
                    break;
                }
            }
            if (tmp_enter_presses == 2)
            {
                if (isint(tmp_str_keyboard))
                {
                    num2_str = tmp_str_keyboard;
                    num2 = atoi(num2_str);
                }
                else
                {
                    op = tmp_str_keyboard[0];
                    switch (op)
                    {
                        case 'a':
                            output = factorial(num1);
                            break;
                        default:
                            printf("%s", "Error: Invalid Switch");
                            cursor_y++;
                            shell_input();
                            break;
                    }
                    printf("%d", output);
                    for (i = tmp_num; i < 81 - strlen(itoa(output, tmp_str, 10)); i++)
                    {
                        move_cursor(i + strlen(itoa(output, tmp_str, 10)), cursor_y);
                        printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
                    }
                    tmp_enter_presses -= 2;
                    move_cursor(tmp_num, cursor_y + 1);
                }
            }
            if (tmp_enter_presses == 3)
            {
                op = tmp_str_keyboard[0];
                switch (op)
                {
                    case 'a':
                        output = num1 + num2;
                        break;
                    case 'b':
                        output = num1 - num2;
                        break;
                    case 'c':
                        output = num1 * num2;
                        break;
                    case 'd':
                        output = num1 / num2;
                        break;
                    case 'e':
                        output = pow(num1, num2);
                        break;
                    case 'f':
                        output = rrand(num1, num2);
                        break;
                    default:
                        printf("%s", "Error: Invalid Switch");
                        cursor_y++;
                        shell_input();
                        break;
                }
                printf("%d", output);
                for (i = tmp_num; i < 81 - strlen(itoa(output, tmp_str, 10)); i++)
                {
                    move_cursor(i + strlen(itoa(output, tmp_str, 10)), cursor_y);
                    printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
                }
                tmp_enter_presses -= 3;
                move_cursor(tmp_num, cursor_y + 1);
            }
            clear_str(tmp_str_keyboard);
        }
    }
    while (TRUE);
}

void shell_input()
{
    int i;
    char *tmp_output = malloc(80);
    bool tmp_bool;
    tmp_num = 2;
    esc_press_bool = false;
    tmp_bool = true;
    printcol_str(">  ", SHELL_INPUT_COLOR, 0, 0, cursor_y);
    move_cursor(tmp_num, cursor_y);
    do
    {
        if (enter_press_bool == false)
        {
            printcol_char(getsc(), SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
            printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x + 1, cursor_y);
            move_cursor(cursor_x + 1, cursor_y);
        }
        else
        {
            for (i = tmp_num; i < 81 - strlen(tmp_str_keyboard); i++)
            {
                move_cursor(i + strlen(tmp_str_keyboard), cursor_y);
                printcol_char(' ', SHELL_INPUT_COLOR, 0, cursor_x, cursor_y);
            }
            tmp_bool = false;
            enter_press_bool = false;
            if (strequ(command(tmp_str_keyboard, 4), "echo"))
            {
                if ((strlen(tmp_str_keyboard) == 4) | (strlen(tmp_str_keyboard) == 5 & tmp_str_keyboard[4] == ' '))
                {
                    printf("%s", "Usage: echo 'String'");
                    cursor_y++;
                }
                else if (tmp_str_keyboard[4] == ' ')
                {
                    if (tmp_str_keyboard[5] == '\'' & tmp_str_keyboard[strlen(tmp_str_keyboard) - 1] == '\'' & strlen(tmp_str_keyboard) > 7)
                    {
                        clear_str(tmp_output);
                        strr(tmp_str_keyboard, tmp_output, 5, strlen(tmp_str_keyboard) - 1);
                        printf("%s", tmp_output);
                        cursor_y++;
                    }
                    else
                    {
                        printf("%s", "echo: Error");
                        cursor_y++;
                    }
                }
                else
                {
                    printf("%s", COMMAND_ERR);
                    cursor_y++;
                }
            }
            else if (strequ(tmp_str_keyboard, "clr"))
            {
                clr_command();
            }
            else if (strequ(command(tmp_str_keyboard, 9), "cursorset"))
            {
                if ((strlen(tmp_str_keyboard) == 9) | (strlen(tmp_str_keyboard) == 10 & tmp_str_keyboard[9] == ' '))
                {
                    printf("%s", "Usage: cursorset cursorcode");
                    cursor_y++;
                }
                else if (tmp_str_keyboard[9] == ' ')
                {
                    if (tmp_str_keyboard[10] == '0')
                    {
                        outb(0x3D4, 0x0A);
                        outb(0x3D5, 0x0D);
                    }
                    else if (tmp_str_keyboard[10] == '1')
                    {
                        outb(0x3D4, 0x0A);
                        outb(0x3D5, 0x00);
                    }
                    else
                    {
                        printf("%s", "cursorset: Error");
                        cursor_y++;
                    }
                }
                else
                {
                    printf("%s", COMMAND_ERR);
                    cursor_y++;
                }
            }
            else if (strequ(tmp_str_keyboard, "reboot"))
            {
                reboot();
            }
            else if (strequ(tmp_str_keyboard, "shutdown"))
            {
                shutdown();
            }
            else if (strequ(tmp_str_keyboard, "calc"))
            {
                calc();
            }
            else
            {
                printf("%s", COMMAND_ERR);
                cursor_y++;
            }
            printcol_str(">  ", SHELL_INPUT_COLOR, 0, 0, cursor_y);
            move_cursor(tmp_num, cursor_y + 1);
        }
    }
    while (TRUE);
}

int k_main()
{
    move_cursor(0, 0);
    clr();
    shell_input();
    return 0;
}
