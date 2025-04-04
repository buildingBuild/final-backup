#ifndef LOANCOLLECTION_H
#define LOANCOLLECTION_H
#include "Loan.h"
#include "customer.h"
#include "customerCollection.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace std;

class loanCollection
{
public:
    int AmountOfLoans();
    void addLoan(loan loaning);
    void editLoan(int loaningID);
    bool deleteLoan(int loaningID, long long int &superBookID, int &patronID);
    bool findLoanAndPrint(int loaningID);
    void printCustomer(int loaningID);
    void reportLostBook(int loaningID);
    void printAllLoans();
    bool checkCustomer(int customerID);

private:
    vector<loan> loanStorage;
};

#endif