#include <iostream>
#include "Loan.h"
#include "LoanCollections.h"
#include <string>
#include <vector>
using namespace std;

loan::loan(long long int isbn_num, int customerID, int loaningid)
{
    BookID = isbn_num;
    PatronID = customerID;
    LoanID = loaningid;
    loanStatus = 'n';
    loanTime = time(0);
}

int loan::getLoanID()
{
    return LoanID;
}
long long int loan::getBookID()
{
    return BookID;
}

char loan::GetCurrentStatus()
{
    return loanStatus;
}

void loan::setCurrenStatus(char s)
{
    s = loanStatus;
}

int loan::getPatronID()
{
    return PatronID;
}
