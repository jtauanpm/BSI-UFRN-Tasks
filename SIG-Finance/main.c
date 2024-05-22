#include <stdio.h>
#include <stdbool.h>

#include "screens.h"
#include "transaction.h"
#include "user.h"
#include "type.h"

int main(){
    physicalDeletionUsers();
    welcome();
    about();
    team();

    char op;
    bool isValid = true; 
    
    do{
        op = mainScreen();
        switch (op){
            case '1':
                transactionMenu();
                break;
            case '2':
                userMenu();
                break;
            case '3':
                typeMenu();
                break;
            case '4':
                about();
                team();
                break;
            case '0':
                isValid = false; 
                break;
            default:
                printf("\t\t\t============================\n");
                printf("\t\t\t====== Invalid option ======\n");
                printf("\t\t\t============================\n\n");
                printf("\t\t\t>>>> Choose a valid option <<<<\n");
        }
    }while(isValid);
    printf("\n\t\t\t===================================\n");
    printf("\t\t\t====== The program has ended ======\n");
    printf("\t\t\t===================================\n");

    return 0;
}