#include <iostream>
#include <string>
#include <vector>
#include "Loan.h"
#include "LoanCollections.h"
#include "customerCollection.h"
#include "customer.h"
#include "BookCollections.h"
#include "customerCollection.h"
#include <iostream>

using namespace std;

int loanCollection::AmountOfLoans()
{
    // use a function that returns loan vector using .size()

    return loanStorage.size();
}

void loanCollection::addLoan(loan loaning)
{
    // pushes the object of type loan to collection of vector of class vector collections
    loanStorage.push_back(loaning);
}
void loanCollection::editLoan(int loaningID)
{
    // for security reasons not implemented however deleteLoan is probably what you need
}

bool loanCollection::deleteLoan(int loaningID, long long int &superBookID, int &patronID)
{
    // returns true or false and text guiding the user to see if loan exists
    for (int i = 0; i < loanStorage.size(); i++)
    {
        if (loaningID == loanStorage[i].getLoanID())
        {
            cout << "Loan is Found!\n";
            cout << "---------------\n";
            cout << "Book Isbn Number: " << loanStorage[i].getBookID() << "\n";
            cout << "Customer ID Number: " << loanStorage[i].getPatronID() << "\n";
            cout << "Loan ID Number: " << loanStorage[i].getLoanID() << "\n";
            cout << "Loan status:(o - overdue, n - normal) " << loanStorage[i].GetCurrentStatus() << "\n";
            loanStorage.erase(loanStorage.begin() + i);
            cout << "Loan deleted successfully.\n";
            superBookID = loanStorage[i].getBookID();
            patronID = loanStorage[i].getPatronID();
            return true;
        }
    }
    cout << "Loan is not found\n";
    return false;
}
bool loanCollection::findLoanAndPrint(int loaningID)
{
    // checks if the loan exists and returns true or false

    for (int i = 0; i < loanStorage.size(); i++)
    {
        if (loaningID == loanStorage[i].getLoanID())
        {
            cout << "Loan is Found!\n";
            cout << "---------------\n";
            cout << "Book Isbn Number: " << loanStorage[i].getBookID() << "\n";
            cout << "Customer ID Number: " << loanStorage[i].getPatronID() << "\n";
            cout << "Loan ID Number: " << loanStorage[i].getLoanID() << "\n";
            cout << "Loan status:(o - overdue, n - normal) " << loanStorage[i].GetCurrentStatus() << "\n";
            return true;
        }
    }
    cout << "Loan is not found!\n";
    return false;
}
void loanCollection::printAllLoans()
{
    // prints all loans
    for (int i = 0; i < loanStorage.size(); i++)
    {

        cout << "Loan " << i + 1 << endl;
        cout << "---------------\n";
        cout << "Book Isbn Number: " << loanStorage[i].getBookID() << "\n";
        cout << "Customer ID Number: " << loanStorage[i].getPatronID() << "\n";
        cout << "Loan ID Number: " << loanStorage[i].getLoanID() << "\n";
        cout << "Loan status:(o - overdue, n - normal): " << loanStorage[i].GetCurrentStatus() << "\n";
    }
}
void loanCollection::reportLostBook(int loaningID)
{
}