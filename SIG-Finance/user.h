///////////////////////////////////////////////////////////////////////////////
///                              Developed by:                              ///
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///             Lucas Canto           &           Jonathan Maia             ///
///             @lucascantodev                    @jtauanpm                 ///
///                                                                         ///
///        Repository: https://github.com/lucascantodev/SIG-Finance         ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

typedef struct user User;

struct user {
    char cpf[12];
    char name[41];
    char birth_date[9];
    short int deleted;
    User* next;
};

//CRUD: User
void userMenu(void);
void createUser(void);
User* createUserFill(void);
int userList(void);
void updateUser(char* cpf);
void deleteUser(char* cpf);
int saveUser(User* use);
int saveUserOk(User *use, char* operation);
User* findUser(char* cpf);
int resaveUser(User *use);
int physicalDeletionUsers();
int userListAlphabetically(void);
