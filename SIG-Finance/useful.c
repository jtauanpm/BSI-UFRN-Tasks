// Useful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "useful.h"

// ref: http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/
void currentTime(char *dateString, char *hourString)
{
    //              size = 6 (HH:MM) size = 11 (DD/MM/YYYY)
    struct tm *creationTime;

    time_t seconds;

    time(&seconds);

    creationTime = localtime(&seconds);

    int day = creationTime->tm_mday;
    sprintf(dateString, "%d", day);
    strcat(dateString, "/");

    int month = creationTime->tm_mon + 1;
    char monS[3];
    sprintf(monS, "%d", month);
    strcat(strcat(dateString, monS), "/");

    int year = creationTime->tm_year + 1900;
    char yearS[5];
    sprintf(yearS, "%d", year);
    strcat(dateString, yearS);

    int hour = creationTime->tm_hour;

    sprintf(hourString, "%d", hour);

    int min = creationTime->tm_min;
    char minS[3];
    sprintf(minS, "%d", min);

    if (min < 10)
    {
        strcat(strcat(strcat(hourString, ":"), "0"), minS);
    }
    else
    {
        strcat(strcat(hourString, ":"), minS);
    }
}

void fileError(void)
{
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\t\t!! error: COULD NOT OPEN FILE !!\n");
    printf("\t\t!! The file may not exist yet !!\n");
    printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
}

void fileSucess(void)
{
    printf("\n\t\t////////////////////////\n");
    printf("\t\t// Saved Successfully //\n");
    printf("\t\t////////////////////////\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
}

void saveCanceled(void)
{
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\t\t<<<<<<<< Save Canceled >>>>>>>");
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
}

void invalidOption(void)
{
    printf("\t\t\t============================\n");
    printf("\t\t\t====== Invalid option ======\n");
    printf("\t\t\t============================\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
    
    printf("\n\n\t\t\t>>> Choose a valid option <<<\n");
}

void fgetsS(char *string, long int stringSize)
{
    // get sdtin with fgets and remove "\n"
    fgets(string, stringSize, stdin);
    string[strcspn(string, "\n")] = 0;
}

int fileLen(char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "rb");

    if (fp == NULL)
    {
        return 1;
    }
    int len;
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);

    return len;
}

void registerNotFound(void)
{
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\t\t!!    ID is not registered.   !!\n");
    printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
}

void printfDateTime(char *time, char *date)
{
    printf("Time: %c%c:%c%c | %c%c/%c%c/%c%c%c%c", time[0],
           time[1], time[3], time[4], date[0], date[1],
           date[2], date[3], date[4], date[5], date[6], date[7]);
}

void printfDate(char *date)
{
    printf("%c%c/%c%c/%c%c%c%c", date[0], date[1],
           date[2], date[3], date[4], date[5], date[6], date[7]);
}

void noRegisterFound(void)
{
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\t\t!!    No register found.      !!\n");
    printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
    system("clear||cls");
}

int yesOrNo()
{
    char yn;

    do
    {
        printf("Type (y) for yes or (n) for no: \n");
        scanf("%c", &yn);
        getchar();
        system("clear||cls");

        if (yn == 'y')
        {
            return 1;
        }
        else if (yn == 'n')
        {
            return 0;
        }
    } while (1);
}