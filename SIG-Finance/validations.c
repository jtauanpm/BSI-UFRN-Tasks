// Validations

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "validations.h"

// To be validated, the name must contain some letter and only letters and spaces
int validateName(char *name)
{
    if (!containsLetter(name))
    {
        return 0;
    }

    for (int i = 0; i < strlen(name) - 1; i++)
    {
        if (!isLetter(name[i]))
        {
            if (!isSpace(name[i]))
            {
                return 0;
            }
        }
    }
    return 1;
}

// check if is deposit or withdrawal
int dOrW(char DW)
{
    if (DW == 'd' || DW == 'w')
    {
        return 1;
    }
    return 0;
}

int isLetter(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}

int isSpace(char c)
{
    if (c == 32)
    {
        return 1;
    }
    return 0;
}

int containsLetter(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (isLetter(string[i]))
        {
            return 1;
        }
    }
    return 0;
}

// checks if all the digits of the CPF are the same
int equalsDigitCPF(int *cpf)
{
    int i;
    int first = cpf[0];

    for (i = 0; i < 10; i++)
    {
        if (first != cpf[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// Inspired by George Henrique Wurthmann: https://wurthmann.blogspot.com/2012/12/funcao-em-linguagem-c-validador-de-cpf.html#:~:text=Fun%C3%A7%C3%A3o%20em%20C%20para%20validar%20o%20CPF%3A%20H%C3%A1,loop%20que%20faz%20o%20calculo%20do%20segundo%20d%C3%ADgito.
int validateCPF(char *cpf)
{
    int cpfInteger[12];
    int i;
    int sum = 0;
    int digit1;
    int digit1Final;
    int digit2;
    int digit2Final;
    int finalValue;

    if (strlen(cpf) != 11)
    {
        return 0;
    }

    // Using ASCII Table -> char to int
    for (i = 0; i < 11; i++)
    {
        cpfInteger[i] = cpf[i] - 48;
    }

    if (equalsDigitCPF(cpfInteger))
    {
        return 0;
    }

    // First digit
    for (i = 0; i < 9; i++)
    {
        sum = sum + cpfInteger[i] * (10 - i);
    }
    digit1Final = sum % 11;
    if ((digit1Final == 0) || (digit1Final == 1))
    {
        digit1 = 0;
    }
    else
    {
        digit1 = 11 - digit1Final;
    }

    // Second digit
    sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum = sum + cpfInteger[i] * (11 - i);
    }
    finalValue = (sum / 11) * 11;
    digit2Final = sum - finalValue;
    if ((digit2Final == 0) || (digit2Final == 1))
    {
        digit2 = 0;
    }
    else
    {
        digit2 = 11 - digit2Final;
    }

    // Final validation of both digits
    if ((digit1 == cpfInteger[9]) && (digit2 == cpfInteger[10]))
    {
        return 1;
    }
    return 0;
}

int isDigit(char d)
{

    if (d >= '0' && d <= '9')
    {
        return 1;
    }
    return 0;
}

int isDigitOrPoint(char d)
{

    if (d == '.')
    {
        return 1;
    }
    else if ((d >= '0' && d <= '9'))
    {
        return 1;
    }
    return 0;
}

int leapYear(int year)
{
    // If the year is divided by 4 and the result is exact it is a leap year
    // And if the year is divided by 100 and the result is other than 0, it is not a leap year
    // Or if the year is divided by 400 and the result is exact, that year is a leap year
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return 1;
    }
    // Otherwise, it will return 0
    else
    {
        return 0;
    }
}

// Inspired by: https://pt.stackoverflow.com/questions/213423/verificar-se-uma-data-%c3%a9-v%c3%a1lida-ou-n%c3%a3o-em-c
int isDate(int day, int month, int year)
{
    int finalDay;
    // If the year is less than 0 or the month is less than 1 or the month is more than 12, it will return 1
    if (year < 0 || month < 1 || month > 12)
    {
        return 0;
    }
    // If the month is February, and the year is leap, the last day will equal 29
    if (month == 2)
    {
        if (leapYear(year))
            finalDay = 29;
    }
    // Otherwise, the end day will equal 28
    else
    {
        finalDay = 28;
    }
    // If the month is April, June, September or January, the final day of these months will equal 30
    if (month == 4 || month == 6 || month == 9 || month == 1)
    {
        finalDay = 30;
    }
    // Otherwise, the end day will equal 31
    else
    {
        finalDay = 31;
    }
    // If the day is less than 1 or the day is more than the finalDay, it will return 0
    if (day < 1 || day > finalDay)
    {
        return 0;
    }
    return 1;
}

int validateDate(char *date)
{
    int size;
    int day, month, year;

    // 'size' receives 'date', now they're equal
    size = strlen(date);
    if (size != 8)
    {
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (!isDigit(date[i]))
        {
            return 0;
        }
    }
    // Converting from char to int
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[2] - '0') * 10 + (date[3] - '0');
    year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + (date[7] - '0');

    if (!isDate(day, month, year))
    {
        return 0;
    }
    return 1;
}

// format: HH MM
int validateTime(char *time)
{
    char hour[3];
    char minute[3];
    char *sep;

    sep = strtok(time, " ");
    strcpy(hour, sep);

    sep = strtok(NULL, " ");
    strcpy(minute, sep);

    for (int i = 0; i < 2; i++)
    {
        if (!isDigit(hour[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (!isDigit(minute[i]))
        {
            return 0;
        }
    }

    if (hour[0] > '2')
    {
        return 0;
    }

    if (minute[0] > '5')
    {
        return 0;
    }

    int hourInt = atoi(hour);

    if (hourInt >= 24)
    {
        return 0;
    }

    return 1;
}

int validateBirthday(char *birth_date)
{
    if (!validateDate(birth_date))
    {
        return 0;
    }

    struct tm *creationTime;
    time_t seconds;
    time(&seconds);
    creationTime = localtime(&seconds);

    int day = creationTime->tm_mday;
    int month = creationTime->tm_mon + 1;
    int year = creationTime->tm_year + 1900;

    int day_converted = (birth_date[0] - '0') * 10 + (birth_date[1] - '0');
    int month_converted = (birth_date[2] - '0') * 10 + (birth_date[3] - '0');
    int year_converted = (birth_date[4] - '0') * 1000 + (birth_date[5] - '0') * 100 + (birth_date[6] - '0') * 10 + (birth_date[7] - '0');

    if (year_converted > year)
    {
        return 0;
    }

    if (year_converted == year && month_converted > month)
    {
        return 0;
    }

    if (year_converted == year && month_converted == month && day_converted > day)
    {
        return 0;
    }

    if (year_converted <= year - 102)
    {
        return 0;
    }

    return 1;
}