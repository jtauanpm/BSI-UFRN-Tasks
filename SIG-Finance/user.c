#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "validations.h"
#include "useful.h"

// user module
void userMenu()
{
    char op;
    char cpf[12];
    bool isValid = true;

    do
    {
        system("clear||cls");
        printf("\n/////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                       ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///           = = = = = = = =    User Menu    = = = = = = =               ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///                                                                       ///\n");
        printf("///              1. Register new user                                     ///\n");
        printf("///              2. User list                                             ///\n");
        printf("///              3. Update User                                           ///\n");
        printf("///              4. Delete User                                           ///\n");
        printf("///              5. List users alphabetically                             ///\n");
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
            createUser();
            break;
        case '2':
            userList();
            break;
        case '3':
            printf("\nWhich user CPF do you want to be updated: ");
            fgetsS(cpf, 12);
            getchar();
            updateUser(cpf);
            break;
        case '4':
            printf("\nWhich User CPF do you want to be deleted: ");
            fgetsS(cpf, 12);
            getchar();
            deleteUser(cpf);
            break;
        case '5':
            userListAlphabetically();
            break;            
        case '0':
            isValid = false;
            break;
        default:
            printf("\t\t\t============================\n");
            printf("\t\t\t====== Invalid option ======\n");
            printf("\t\t\t============================\n\n");
            printf("\t\t\t>>> Choose a valid option <<<\n");
        }
    } while (isValid);
}

//(create)
void createUser()
{
    User *use;
    use = createUserFill();
    system("clear||cls");

    if (saveUserOk(use, "REGISTER"))
    {
        system("clear||cls");
        if (saveUser(use))
        {
            fileSucess();
        }
    }
    else
    {
        saveCanceled();
    }
    free(use);
}

int saveUser(User *use)
{
    FILE *fp;
    fp = fopen("users.dat", "ab");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }
    fwrite(use, sizeof(User), 1, fp);
    fclose(fp);
    return 1;
}

int saveUserOk(User *use, char *operation)
{
    printf("\n\n");
    printf("\t              = = = = = = %s USER = = = = = =                 \n\n", operation);

    printf("\n\tDo you really want to %s a user named %s ?\n", operation, use->name);
    printf("\n");

    return yesOrNo();
}

//(createFill)
User *createUserFill(void)
{
    User *use;
    use = (User *)malloc(sizeof(User));
    User *useAux;
    bool cpfExists = false;

    printf("\n\n!!!!!!!!!! If any invalid value is entered, the field will be asked again !!!!!!!!!!\n\n");
    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///           = = = = = = = =   Register User   = = = = = = =             ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    do
    {

        printf("///                         User name:                                    ///\n");
        fgetsS(use->name, 41);
    } while (!validateName(use->name));

    do
    {
        printf("///                                                                       ///\n");
        printf("///                         User birth date: (DDMMYYYY)                     ///\n");
        fgetsS(use->birth_date, 9);
        getchar();
    } while (!validateBirthday(use->birth_date));

    printf("///                                                                       ///\n");

    do
    {
        printf("///                         User's CPF:                                   ///\n");
        cpfExists = false;
        fgetsS(use->cpf, 12);
        getchar();
        useAux = findUser(use->cpf);
        if (useAux != NULL)
        {
            if ((strcmp(use->cpf, useAux->cpf) == 0))
            {
                cpfExists = true;
                printf("\n\t\t!!!!!!!! The cpf informed is already registered !!!!!!!!\n");
            }
        }
        free(useAux);
    } while (!validateCPF(use->cpf) || cpfExists);
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    use->deleted = 0;

    return use;
}

// read and show user
int userList()
{
    FILE *fp;
    int count = 0;
    fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }

    User *use;
    use = (User *)malloc(sizeof(User));

    while (fread(use, sizeof(User), 1, fp))
    {
        if (use->deleted != 1)
        {
            printf("\n\t\t= = = = = Registred User = = = = =");
            printf("\nUser name: %s", use->name);
            printf("\nUser Birthday: ");
            printfDate(use->birth_date);
            count += 1;
        }
        else if (use == NULL)
        {
            printf("\t\n= = = = = Non-existent User = = = = =");
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

    free(use);
    fclose(fp);
    return 1;
}

//(update)
void updateUser(char* cpf)
{
    User *use;
    
    printf("/n                 = = = = = = Update User = = = = = =                  \n\n");

    use = findUser(cpf);
    if (use == NULL)
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
            printf("\n           User's Name (only letters): ");
            fgetsS(use->name, 41);
        } while (!(validateName(use->name)));

        do
        {
            printf("\n           Birthday (DDMMAAAA): ");
            scanf("%s", use->birth_date);
            getchar();

        } while (!(validateDate(use->birth_date)));

        if (saveUserOk(use, "UPDATE"))
        {
            system("clear||cls");
            if (resaveUser(use))
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
    free(use);
}

User *findUser(char *cpf)
{
    FILE *fp;
    User *use;

    fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        return NULL;
    }

    use = (User *)malloc(sizeof(User));

    while (fread(use, sizeof(User), 1, fp))
    {
        if ((strcmp(use->cpf, cpf) == 0) && use->deleted == 0)
        {
            fclose(fp);
            return use;
        }
    }
    fclose(fp);
    return NULL;
}

//(delete)
void deleteUser(char* cpf)
{
    User *use;

    use = findUser(cpf);
    if (use == NULL)
    {
        registerNotFound();
    }
    else
    {
        if (saveUserOk(use, "DELETE"))
        {
            use->deleted = 1;
            if (resaveUser(use))
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
    free(use);
}

int resaveUser(User *use)
{
    FILE *fp;
    fp = fopen("users.dat", "r+b");
    bool find = false;

    if (fp == NULL)
    {
        fileError();
        return find;
    }

    User *useRead;
    useRead = (User *)malloc(sizeof(User));

    while (fread(useRead, sizeof(User), 1, fp) && !find)
    {
        if ((strcmp(use->cpf, useRead->cpf) == 0) && useRead->deleted == 0)
        {
            find = true;
            fseek(fp, -1 * sizeof(User), SEEK_CUR);
            fwrite(use, sizeof(User), 1, fp);
        }
    }
    fclose(fp);
    free(useRead);
    return find;
}

// This function physically deletes the logically deleted data from the user module
int physicalDeletionUsers(){

    FILE *fp;
    fp = fopen("users.dat", "rb");
    if (fp == NULL){
        return 0;
    }
    
    FILE *fp2;
    fp2 = fopen("users2.dat", "wb");
    if (fp2 == NULL){
        return 0;
    }

    User* use;
    use = (User*) malloc(sizeof(User));

    while (fread(use, sizeof(User), 1, fp)){
        if (use->deleted != 1){
            fwrite(use,sizeof(User),1,fp2);
        }
    }

    free(use);
    fclose(fp);
    fclose(fp2);
    remove("users.dat");
    rename("users2.dat","users.dat");

    return 1;
}

int userListAlphabetically(void){
    FILE* fp;
    User* newUser;
    User* list;


    fp = fopen("users.dat","rb");
    if (fp == NULL){
        fileError();
        return 0;
    }

    // get list
    list = NULL;
    newUser = (User*) malloc(sizeof(User));

    while (fread(newUser, sizeof(User), 1, fp)){
        if (newUser->deleted == 0){
            if (list == NULL){
                list = newUser;
                newUser->next = NULL;
            }else if (strcmp(newUser->name,list->name) < 0){
                newUser->next = list;
                list = newUser;
            }else{
                User* previous = list;
                User* current = list->next;

                while ((current != NULL) && strcmp(current->name,newUser->name) < 0){
                    previous = current;
                    current = current->next;
                }
                previous->next = newUser;
                newUser->next = current;
            }
        }else{
            free(newUser);
        }
        newUser = (User*) malloc(sizeof(User));
    }
    fclose(fp);

    //show list
    newUser = list;
    while (newUser != NULL){
        printf("\n\t\t= = = = = Registred User = = = = =");
        printf("\nUser name: %s", newUser->name);
        printf("\nUser Birthday: ");
        printfDate(newUser->birth_date);
        newUser = newUser->next;
    }
    printf("\n\n\t\t\t>>> Press ENTER to continue <<<\n");
    getchar();
    
    //free list
    newUser = list;
    while (list != NULL){
        list = newUser->next;
        free(newUser);
        newUser = list;
    }

    return 1;  
}