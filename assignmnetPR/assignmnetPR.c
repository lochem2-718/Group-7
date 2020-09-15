#include <stdio.h>
#include <stdbool.h>

bool is_digit(char c)
{
    int intval = c - '0';
    return intval < 10 && intval >= 0;
}

bool is_valid(char *numstring)
{
    char *curr_char = numstring;
    while (*curr_char != '\0' && (is_digit(*curr_char) || *curr_char == '.' || *curr_char == '-'))
    {
        curr_char++;
    }
    return *curr_char == '\0';
}

bool characteristic(char numString[], int *c)
{
    int index = 0;
    int signValue = 1;
    int cval = 0;

    //validate numstring
    if (!is_valid(numString))
    {
        return false;
    }

    //find sign of numstring and find start index of number
    while (numString[index] != '\0' && numString[index] != '.')
    {
        if (numString[index] == '-')
        {
            signValue = -1;
        }

        if (is_digit(numString[index]))
        {
            cval = (cval * 10) + (numString[index] - '0');
        }

        index++;
    }

    *c = cval * signValue;

    return true;
}

bool mantissa(char numString[], int *numerator, int *denominator)
{
    int index = 0;
    int dvalue = 1;
    int nvalue = 0;

    //validate numstring
    if (!is_valid(numString))
    {
        return false;
    }

    //get to '.' or end of string
    while (numString[index] != '\0')
    {
        if (numString[index] == '.')
        {
            index++;

            while (is_digit(numString[index]))
            {
                dvalue *= 10;
                nvalue = (nvalue * 10) + (numString[index] - '0');

                index++;
            }
        }

        index++;
    }

    *numerator = nvalue;
    *denominator = dvalue;

    return true;
}

int main()
{
    int c = 0;
    int n = 0;
    int d = 0;
    char number[] = "   ----12.5987907  ";

    if (characteristic(number, &c) && mantissa(number, &n, &d))
    {
        printf("characteristic: %d\n", c);
        printf("numerator: %d\n", n);
        printf("denominator: %d\n", d);
        return 0;
    }
    else
    {
        fprintf(stderr, "The string was invalid!\n\n");
        return 42 + 27;
    }
}