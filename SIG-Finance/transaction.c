#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "transaction.h"
#include "type.h"
#include "user.h"
#include "validations.h"
#include "useful.h"

// transaction module
void transactionMenu()
{
    char op;
    long int id;
    long int typeID;
    char cpf[12];
    bool isValid = true;

    do
    {
        printf("\n\n/////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                       ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///           = = = = = = = = Transaction Menu = = = = = = =              ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///                                                                       ///\n");
        printf("///              1. Register new transaction                              ///\n");
        printf("///              2. Transactions list                                     ///\n");
        printf("///              3. Detail transaction                                    ///\n");
        printf("///              4. Update transaction                                    ///\n");
        printf("///              5. Delete transaction                                    ///\n");
        printf("///              6. List transactions by type                             ///\n");
        printf("///              7. List transactions by user                             ///\n");
        printf("///              0. Back to main menu                                     ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\tChoose an option: ");
        scanf("%c", &op);
        getchar();
        system("clear||cls");
        printf("\n");

        switch (op)
        {
        case '1':
            createTransaction();
            break;
        case '2':
            transactionList();
            break;
        case '3':
            printf("\n\tWhich transaction ID you want to see detailed: ");
            scanf("%ld", &id);
            getchar();
            detailTransaction(&id);
            break;
        case '4':
            printf("\nWhich transaction ID do you want to be updated: ");
            scanf("%ld", &id);
            getchar();
            updateTransaction(&id);
            break;
        case '5':
            printf("\nWhich transaction ID do you want to be deleted: ");
            scanf("%ld", &id);
            getchar();
            deleteTransaction(&id);
            break;
        case '6':
            printf("\n\tType the type's ID you want to list: ");
            scanf("%ld", &typeID);
            getchar();
            transactionListByType(&typeID);
            break;
        case '7':
            printf("\nWhat is the CPF of the user you want to see the transactions: ");
            fgetsS(cpf,12);
            // if (strlen(cpf) != 1)
            // {
            //     getchar();
            // }
            filterTransactionsByUser(cpf);
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
    } while (isValid);
}

//(create)
void createTransaction(void)
{

    Transaction *tran;
    tran = createTransactionFill();
    system("clear||cls");

    if (saveTransactionOk(tran, "REGISTER"))
    {
        system("clear||cls");
        if (saveTransaction(tran))
        {
            fileSucess();
        }
    }
    else
    {
        saveCanceled();
    }
    free(tran);
}

//(read)
int transactionList()
{
    FILE *fp;
    int count = 0;
    fp = fopen("transactions.dat", "rb");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }

    Transaction *tran;
    tran = (Transaction *)malloc(sizeof(Transaction));

    while (fread(tran, sizeof(Transaction), 1, fp))
    {
        showTransaction(tran);
        if (tran->deleted == 0)
        {
            count += 1;
        }
    }
    if (count == 0)
    {
        noRegisterFound();
    }
    else
    {
        printf("\n\t\t\t>>> Press ENTER to continue <<<\n\n");
        getchar();
        system("clear||cls");
    }

    free(tran);
    fclose(fp);
    return 1;
}

int saveTransaction(Transaction *tran)
{
    FILE *fp;
    fp = fopen("transactions.dat", "ab");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }
    fwrite(tran, sizeof(Transaction), 1, fp);
    fclose(fp);
    return 1;
}

//(createFill)
Transaction *createTransactionFill(void)
{

    Transaction *tran;
    tran = (Transaction *)malloc(sizeof(Transaction));
    char value[11];
    bool ok;
    Type *type;
    User *user;

    // define id
    tran->id = (fileLen("transactions.dat") / sizeof(Transaction));

    printf("\n\n!!!!!!!!!! If any invalid value is entered, the field will be asked again !!!!!!!!!!\n\n");
    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    do
    {
        printf("\n                 = = = = = = User List = = = = = =                  \n");
        userList();
        printf("\n\n///        User's CPF (enter '0' if you're not a user or enter a valid CPF): ///\n");
        fgetsS(tran->userCPF, 12);
        // if (strlen(tran->userCPF) != 1){
        //     getchar();
        // }
        user = findUser(tran->userCPF);
        if (user == NULL && (strcmp(tran->userCPF, "0") != 0))
        {
            printf("\n\n\t\t\t\t!!!!!!!!! User not found. !!!!!!!!!\n\t\t!!!!!!!!! Enter '0' if you're not a user or enter a valid CPF. !!!!!!!!!\n\n");
            printf("\t\t\t>>> Press ENTER to continue <<<\n\n");
            getchar();
        }
        free(user);
    } while (user == NULL && (strcmp(tran->userCPF, "0") != 0));

    do
    {
        printf("///           Deposit or Withdrawal (d/w):                                ///\n");
        scanf("%c", &tran->DW);
        getchar();

    } while (!(dOrW(tran->DW)));

    do
    {
        ok = true;
        printf("///           Value no signal (532.25):                                    ///\n");
        fgetsS(value, 11);

        for (int i = 0; i < strlen(value) - 1; i++)
        {
            if (isDigitOrPoint(value[i]) == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok == true)
        {
            tran->value = atof(value);
            break;
        }
    } while (true);

    do
    {
        printf("///           Date (DDMMAAAA):                                            ///\n");
        scanf("%s", tran->date);
        getchar();

    } while (!(validateDate(tran->date)));

    do
    {
        printf("///           Time (HH MM):                                               ///\n");
        fgetsS(tran->time, 6);
        getchar();

    } while (!(validateTime(tran->time)));

    printf("///           Description (size=100):                                     ///\n");
    fgetsS(tran->description, 101);

    do
    {
        printf("\n                 = = = = = = Type List = = = = = =                  \n");
        typeList();
        printf("\n///           Choose ID of Type (enter '0' if you dont have an ID or enter a valid ID):      ///\n");
        scanf("%ld", &tran->typeID);
        getchar();
        type = findType(&tran->typeID);
        if (type == NULL && tran->typeID != 0)
        {
            printf("\n\n\t\t\t\t!!!!!!!!! Type not found. !!!!!!!!!\n\t\t!!!!!!!!! Enter '0' if you dont have an ID or enter a valid ID. !!!!!!!!!\n\n");
            printf("\t\t\t>>> Press ENTER to continue <<<\n\n");
            getchar();
        }
        free(type);
    } while (type == NULL && tran->typeID != 0);

    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");

    tran->deleted = 0;
    currentTime(tran->creationDate, tran->creationTime);

    return tran;
}

//(createCheck)
int saveTransactionOk(Transaction *tran, char *operation)
{
    char dw[11];
    tran->DW == 'd' ? strcpy(dw, "DEPOSIT") : strcpy(dw, "WITHDRAWAL");

    printf("\n\n");
    printf("\t            = = = = = = %s TRANSACTION = = = = = =               \n\n", operation);

    if ((strcmp(tran->userCPF, "0") != 0))
    {
        User *user = findUser(tran->userCPF);
        printf("\n\tDo you really want to %s %s of R$ %.3f made by %s ?\n", operation, dw, tran->value, user->name);
    }
    else
    {
        printf("\n\tDo you really want to %s %s of R$ %.3f made by NULL ?\n", operation, dw, tran->value);
    }
    printf("\tID: %ld", tran->id);

    // get the type name
    if (tran->typeID != 0)
    {
        Type *type;
        type = findType(&tran->typeID);
        printf("                           Type: %s", type->name);
        free(type);
    }
    else
    {
        printf("                           Type: NULL");
    }

    printf("\n\t");
    printfDateTime(tran->time, tran->date);
    printf("\tDescription: %s\n", tran->description);
    printf("\n");

    return yesOrNo();
}

//(readByID)
void detailTransaction(long int* id)
{
    Transaction *tran;
    char dw[11];

    tran = findTransaction(id);
    if (tran == NULL || tran->deleted == 1)
    {
        registerNotFound();
    }
    else
    {
        tran->DW == 'd' ? strcpy(dw, "DEPOSIT") : strcpy(dw, "WITHDRAWAL");
        printf("\n\n\t\t= = = = = Registered Transaction = = = = =");
        printf("\nID: %ld\t", tran->id);
        if ((strcmp(tran->userCPF, "0") != 0))
        {
            User *user = findUser(tran->userCPF);
            printf("Made by: %s", user->name);
        }
        else
        {
            printf("Made by: NULL");
        }

        printf("\n%s: $%.3lf", dw, tran->value);
        printf("\n");
        printfDateTime(tran->time, tran->date);
        if (tran->typeID == 0)
        {
            printf("\nType: NULL      ");
        }
        else
        {
            Type *type = findType(&tran->typeID);
            printf("\nType: %s      ", type->name);
            free(type);
        }

        printf("Description: %s", tran->description);
        printf("\nCreation time: %s | Creation date: %s", tran->creationTime, tran->creationDate);
        printf("\n\n\t\t\t>>> Press ENTER to continue <<<");
        getchar();
        system("clear||cls");
    }
    free(tran);

    printf("\n");
}

int transactionListByType(long int* typeID)
{
    Type *type;
    Transaction *tran;

    type = findType(typeID);
    if (type == NULL) {
        noRegisterFound();
        free(type);
        return 0;
    }

    FILE *fp;
    fp = fopen("transactions.dat", "rb");
    if (fp == NULL)
    {
        fileError();
        return 0;
    }
    else
    {
        tran = (Transaction *)malloc(sizeof(Transaction));
        while (fread(tran, sizeof(Transaction), 1, fp))
        {
            if (tran->typeID == *typeID)
            {
                showTransaction(tran);
            }
        }
    }
    free(type);
    free(tran);

    return 1;
}

void showTransaction(Transaction *tran)
{
    if (tran->deleted == 0)
    {
        char dw[11];
        tran->DW == 'd' ? strcpy(dw, "DEPOSIT") : strcpy(dw, "WITHDRAWAL");

        printf("\n\n\t\t= = = = = Registered Transaction = = = = =");
        printf("\nID: %ld\t", tran->id);

        if ((strcmp(tran->userCPF, "0") != 0)){
            User *user = findUser(tran->userCPF);
            printf("       Made by: %s", user->name);
        }
        else{
            printf("       Made by: NULL");
        }
        printf("\n%s: $%.3lf", dw, tran->value);

        if (tran->typeID == 0){
            printf("            Type: NULL");
        }
        else{
            Type *type = findType(&tran->typeID);
            printf("            Type: %s", type->name);
            free(type);
        }
        printf("\n");
        printfDateTime(tran->time, tran->date);
    }
    else if (tran == NULL)
    {
        printf("\t\n= = = = = Non-existent Transaction = = = = =");
    }
}

//(update)
void updateTransaction(long int* id)
{
    Transaction *tran;
    char value[11];
    bool ok;
    Type *type;
    User *user;

    printf("/n/n                 = = = = = = Update Transaction = = = = = =                  \n\n");

    tran = findTransaction(id);

    if (tran == NULL)
    {
        registerNotFound();
    }
    else
    {

        printf("\n\n!!!!!!!!!! If any invalid value is entered, the field will be asked again !!!!!!!!!!\n\n");
        printf("\t\t\t>>> Press ENTER to continue <<<");
        getchar();
        do
        {

            printf("\n                 = = = = = = User List = = = = = =                  \n");
            userList();
            printf("\n\n///        User's CPF (enter '0' if you're not a user or enter a valid CPF): ///\n");
            fgetsS(tran->userCPF, 12);
            // if (strlen(tran->userCPF) != 1)
            // {
            //     getchar();
            // }
            user = findUser(tran->userCPF);
            if (user == NULL && (strcmp(tran->userCPF, "0") != 0))
            {
                printf("\n\n\t\t\t\t!!!!!!!!! User not found. !!!!!!!!!\n\t\t!!!!!!!!! Enter '0' if you're not a user or enter a valid CPF. !!!!!!!!!\n\n");
                printf("\t\t\t>>> Press ENTER to continue <<<\n\n");
                getchar();
            }
            free(user);
        } while (user == NULL && (strcmp(tran->userCPF, "0") != 0));

        do
        {
            printf("\n           Deposit or Withdrawal (d/w): ");
            scanf("%c", &tran->DW);
            getchar();

        } while (!(dOrW(tran->DW)));

        do
        {
            ok = true;
            printf("\n           Value no signal (532.25): ");
            fgetsS(value, 11);

            for (int i = 0; i < strlen(value) - 1; i++)
            {
                if (isDigitOrPoint(value[i]) == 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok == true)
            {
                tran->value = atof(value);
                break;
            }
        } while (true);

        do
        {
            printf("\n           Date (DDMMAAAA): ");
            scanf("%s", tran->date);
            getchar();

        } while (!(validateDate(tran->date)));

        do
        {
            printf("\n           Time (HH MM): ");
            fgetsS(tran->time, 6);
            getchar();

        } while (!(validateTime(tran->time)));

        printf("\n           Description (size=100):\n");
        fgetsS(tran->description, 101);

        do
        {
            printf("\n                 = = = = = = Type List = = = = = =                  \n");
            typeList();
            printf("\n///           Choose ID of Type (enter '0' if you dont have an ID or enter a valid ID):      ///\n");
            scanf("%ld", &tran->typeID);
            getchar();
            type = findType(&tran->typeID);
            if (type == NULL && tran->typeID != 0)
            {
                printf("\n\n\t\t\t\t!!!!!!!!! Type not found. !!!!!!!!!\n\t\t!!!!!!!!! Enter '0' if you dont have an ID or enter a valid ID. !!!!!!!!!\n\n");
                printf("\t\t\t>>> Press ENTER to continue <<<\n\n");
                getchar();
            }
            free(type);
        } while (type == NULL && tran->typeID != 0);

        if (saveTransactionOk(tran, "UPDATE"))
        {
            system("clear||cls");
            if (resaveTransaction(tran))
            {
                fileSucess();
            }
            else
            {
                fileError();
            }
        }
        else
        {
            saveCanceled();
        }
    }
    free(tran);
}

//(delete)
void deleteTransaction(long int* id)
{
    Transaction *tran;

    tran = findTransaction(id);
    if (tran == NULL)
    {
        registerNotFound();
    }
    else
    {
        if (saveTransactionOk(tran, "DELETE"))
        {
            system("clear||cls");
            tran->deleted = 1;
            if (resaveTransaction(tran))
            {
                fileSucess();
            }
            else
            {
                fileError();
            }
        }
        else
        {
            saveCanceled();
        }
    }
    free(tran);
}

int resaveTransaction(Transaction *tran)
{
    FILE *fp;
    fp = fopen("transactions.dat", "r+b");
    bool find = false;

    if (fp == NULL)
    {
        fileError();
        return find;
    }
    Transaction *tranRead;
    tranRead = (Transaction *)malloc(sizeof(Transaction));

    while (fread(tranRead, sizeof(Transaction), 1, fp) && !find)
    {
        if (tranRead->id == tran->id && tranRead->deleted == 0)
        {
            find = true;
            fseek(fp, -1 * sizeof(Transaction), SEEK_CUR);
            fwrite(tran, sizeof(Transaction), 1, fp);
        }
    }
    fclose(fp);
    free(tranRead);
    return find;
}

Transaction *findTransaction(long int *id)
{
    FILE *fp;
    Transaction *tran;

    fp = fopen("transactions.dat", "rb");

    if (fp == NULL)
    {
        fileError();
        return NULL;
    }

    tran = (Transaction *)malloc(sizeof(Transaction));

    while (fread(tran, sizeof(Transaction), 1, fp))
    {
        if (tran->id == *id && tran->deleted == 0)
        {
            fclose(fp);
            return tran;
        }
    }

    fclose(fp);
    return NULL;
}

int filterTransactionsByUser(char* cpf){
    User* user; 

    user = findUser(cpf);
    if (user == NULL){
        noRegisterFound();
        free(user);
        return 0;
    }

    FILE* fp;
    fp = fopen("transactions.dat","rb");
    if (fp == NULL){
        fileError();
        return 0;
    }
    
    Transaction* tran;
    tran = (Transaction*) malloc(sizeof(Transaction));

    while (fread(tran,sizeof(Transaction),1,fp)){
        if (strcmp(tran->userCPF,cpf) == 0){
            showTransaction(tran);
        }
    }
    
    free(user);
    free(tran);

    return 1;
}