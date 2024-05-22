///////////////////////////////////////////////////////////////////////////////
///                              Developed by:                              ///
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///             Lucas Canto           &           Jonathan Maia             ///
///             @lucascantodev                  @jonathan-tauan             ///
///                                                                         ///
///        Repository: https://github.com/lucascantodev/SIG-Finance         ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

typedef struct transaction Transaction;

struct transaction{
    long int id;
    char DW;
    double value;
    char date[9];
    char time[6];
    char description[101];
    char creationDate[11];
    char creationTime[6];
    char deleted;
    
    char userCPF[12];
    long int typeID;
};


//CRUD: Transactions
void transactionMenu(void);
void createTransaction(void);
int transactionList(void);
void detailTransaction(long int* id);
void updateTransaction(long int* id);
void deleteTransaction(long int* id);
int saveTransactionOk(Transaction* tran, char* operation);
Transaction* createTransactionFill(void);
int saveTransaction(Transaction* tran);
Transaction* findTransaction(long int* id);
int resaveTransaction(Transaction* tran);
void showTransaction(Transaction* tran);
int filterTransactionsByUser(char* cpf);
int transactionListByType(long int* typeID);

