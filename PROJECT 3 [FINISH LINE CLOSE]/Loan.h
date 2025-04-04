#ifndef LOAN_H
#define LOAN_H

class loan
{

public:
    loan(long long int isbn_num, int PatronID, int loaningid);
    int getLoanID();
    char GetCurrentStatus();
    void setCurrenStatus(char s);
    int getLoanTime();
    long long int getBookID();
    int getPatronID();

private:
    int LoanID;
    long long int BookID;
    int PatronID;
    char loanStatus; // Current Status (overdue, normal)
    time_t loanTime;
};

#endif