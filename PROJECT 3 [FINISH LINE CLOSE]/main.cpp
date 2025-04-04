/*
Name : ENEOJO UNWUCHOLA
COURSE : CSCE 1040 SECTION 003/315
ASSIGNMENT/PROJECT 3
DATE: APRIL 4TH 2025
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
// including all header files
#include "Book.h"
#include "BookCollections.h"
#include "customer.h"
#include "customerCollection.h"
#include "Loan.h"
#include "LoanCollections.h"
using namespace std;

// globals
BookCollection BookStorage;         // for book collections
customerCollection customerStorage; // for customer collections
loanCollection loanStorage;         // for loan collections

void BookMenu()
{
    char userSelection = 'Y';
    int userChoice;
    // Vars for case 1
    string Authorname;
    string BookName;
    long long int ISBN_NUM;
    int LibraryID;
    float costOfBook;
    char currentStatus;

    // Vars for case 2
    long long int isbn_Number;
    do
    {
        int userChoice;
        cout << "\n-------------------\n";
        cout << "Book Menu\n";
        cout << "1. Add a Book\n";
        cout << "2. Edit a Book information\n";
        cout << "3. Delete Book \n";
        cout << "4. Find a book and print book information\n";
        cout << "5. Display All Books\n";
        cout << "6. Return back to Main Menu\n";
        cout << "-------------------\n";
        cout << "Select a numerical option from the Book menu: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
        case 1: /// Add A book
        {
            cout << "\nADDING BOOOK\n";
            cout << "-------------------\n";
            cout << "Enter Author Name: ";
            getline(cin, Authorname);

            cout << "Enter Book Name: ";
            getline(cin, BookName);

            cout << "ENTER Isbn number: ";
            cin >> ISBN_NUM;

            cout << "Enter The Cost of the book: ";
            cin >> costOfBook;

            cout << "Enter status  - i for In, o - out, r - repair, l - lost: ";
            cin >> currentStatus;
            cin.ignore();
            // populate newly declared object of type Book class with info from the user
            Book newBook(Authorname, BookName, ISBN_NUM, costOfBook, currentStatus); // object created of Book class
            // pushback the new object from the book class  in the vector
            BookStorage.addBook(newBook); // calling function to collect that object book which adds to book to library
            cout << "\n";
            break;
        }

        case 2:
        {
            cout << "\nEDITING BOOK INFORMATION\n";
            cout << "-------------------\n";
            cout << "Enter the ISBN number of the book you wish to modify: ";
            cin >> isbn_Number;
            // Find book we are looking through array that checks for unique isbn number
            // Use function that prompts user for new information
            BookStorage.editWholeBookInformation(isbn_Number); // puts user through a modified creating book process
            cout << "\n";
            break;
        }

        case 3:
        {
            cout << "\nDELETING BOOOK\n";
            cout << "-------------------\n";
            cout << "Enter the ISBN number of the book you wish to delete: ";
            cin >> isbn_Number;
            // Find book we are looking for through vector that has all books
            BookStorage.deleteBook(isbn_Number); // finds object existence then erases it
            cout << "\n";
            break;
        }

        case 4:
        {
            cout << "\nFINDING BOOK\n";
            cout << "-------------------\n";
            cout << "Enter the ISBN number of the book you wish to find: ";
            // Prompt for isbn number
            cin >> isbn_Number;
            BookStorage.printBookInformation(isbn_Number); // uses isbn to find book
            cout << "\n";

            break;
        }

        case 5:
        {
            cout << "\nDISPLAYING ALL BOOK INFORMATION\n";
            BookStorage.printAllBooks(); // calls function that iterates over vector printing all object info
            cout << "--------------------------------\n";

            cout << "\n";

            break;
        }

        case 6:
        {
            return;
        }
        default:
            cout << "\nInvalid Selection\n";
            break;
        }
        cout << "Do you wish to Continue with Book Menu (Y/N): ";
        cin >> userSelection;
        cin.ignore();
    } while (userSelection == 'Y' || userSelection == 'y');
}

void CustomerMenu()
{

    char userSelection = 'Y';
    int userChoice;
    // Vars for case 1
    string CustomerName;
    int CustomerId;

    // Vars for case 2
    long long int customer_ID;
    do
    {
        int userChoice;
        cout << "\n-------------------\n";
        cout << "Customer Menu\n";
        cout << "1. Add a Customer\n";
        cout << "2. Edit Customer information\n";
        cout << "3. Delete Customer \n";
        cout << "4. Find a customer and print customer information\n";
        cout << "5. Displaying all customer information\n";
        cout << "6. Return back to Main Menu\n";
        cout << "-------------------\n";
        cout << "Select a numerical option from the Customer menu: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
        case 1:
        {
            cout << "\nADDING CUSTOMER\n";
            cout << "-------------------\n";
            cout << "Enter Customer Name: ";
            getline(cin, CustomerName);
            cout << "Enter New Unique Customer ID Number: ";
            cin >> CustomerId;
            // Populate object using constructor
            Customer customer(CustomerName, CustomerId);
            // add object to vector delcared in customer collection class
            customerStorage.addCustomer(customer);
            cout << "\nCustomer Added!\n";
            cout << "\n";
            break;
        }

        case 2:
        {
            cout << "\nEDITING CUSTOMER INFORMATION\n";
            cout << "-------------------\n";
            // prompt for customer Id number
            cout << "Enter Unique Customer ID Number you wish to change: ";
            cin >> CustomerId;
            cin.ignore();
            // Then use function that changes all the information of that customer
            customerStorage.editCustomer(CustomerId);

            cout << "-------------------\n";
            cout << "\n";

            break;
        }

        case 3:
        {
            cout << "\nDELETING CUSTOMER REGISTRATION\n";
            cout << "-------------------\n";
            cout << "Enter Unique Customer ID Number" << endl;
            cin >> CustomerId;
            cin.ignore();
            // call function that find that customer object and deletes it using erase or so
            customerStorage.deleteCustomer(CustomerId);
            cout << "-------------------\n";
            cout << "\n";
            break;
        }

        case 4:
        {
            cout << "\nFINDING CUSTOMER IN DATABASE....\n";
            cout << "-------------------\n";
            // checks for customer ID Number.
            cout << "Enter Unique Customer ID Number" << endl;
            cin >> CustomerId;
            cin.ignore();
            // function iterates over vector filled with objects looking for that id number
            customerStorage.findCustomerAndPrint(CustomerId);
            cout << "\n";

            break;
        }

        case 5:
        {
            cout << "\nDISPLAYING ALL CUSTOMER INFORMATION\n";
            cout << "--------------------------------\n";
            customerStorage.printAllCustomers();

            cout << "\n";

            break;
        }

        case 6:
        {
            return;
            break;
        }

        default:
            cout << "\nInvalid Selection\n";
            break;
        }
        cout << "Do you wish to Continue with Customer Menu (Y/N): ";
        cin >> userSelection;
        cin.ignore();
    } while (userSelection == 'Y' || userSelection == 'y');
}

void LoanMenu()
{
    char userSelection = 'Y';
    int userChoice;

    // Vars for case 1
    int customerID;
    int LoanId;
    bool canCustomerLoan;
    bool isBookLoanable;

    // Vars for case 2
    long long int Book_ID;

    // Vars for deleting loan
    bool loanfound;

    // vars for editing loan
    bool loanIsFound;

    do
    {
        cout << "\n-------------------\n";
        cout << "Loan Menu\n";
        cout << "1. Add a Loan\n";
        cout << "2. Edit Loan information\n";
        cout << "3. Delete Loan\n";
        cout << "4. Find a loan and print loan information\n";
        cout << "5. Print all loans information\n";
        cout << "6. Return back to Main Menu\n";
        cout << "-------------------\n";
        cout << "Select a numerical option from the Loan menu: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
        case 1:
        {

            cout << "\nADDING LOAN\n";
            cout << "-------------------\n";
            cout << "Enter Customer ID of person what wishes to take a loan: ";
            cin >> customerID;
            canCustomerLoan = customerStorage.checkCustomer(customerID);
            if (canCustomerLoan == 0)
            {
                break;
            }
            // First its ask user which book it wants to loan, it is then searched using the isbn Number in vector
            cout << canCustomerLoan << endl;
            cout << "Enter Isbn of Book that you wish to loan: ";
            cin >> Book_ID;
            isBookLoanable = BookStorage.checkBook(Book_ID);
            if (isBookLoanable == 0)
            {
                break;
            }
            cout << isBookLoanable << endl;

            cout << "Enter a unique LoanID for this loan: ";
            cin >> LoanId;
            // object from class loan is being made
            loan newloan(Book_ID, customerID, LoanId);
            // calls function that pushes it to loancollection
            loanStorage.addLoan(newloan);
            BookStorage.editBookStatus(Book_ID, 'o');
            customerStorage.updateCustomerAfterSuccesfulLoan(customerID);
            // both sections we give out the loan booked ,change the book status too out  and increment the books out

            cout << "Success Book is Loaned\n";
            cout << "-----------------\n";

            // cout << "\nLoan Added!\n";
            //  cout << "\n";
            break;
        }

        case 2:
        {
            cout << "\nEDITING LOAN INFORMATION\n";
            cout << "-------------------\n";
            cout << "Enter Unique Loan ID Number you wish to change: ";
            cin >> LoanId;
            // first find loan using loan ID
            loanIsFound = loanStorage.findLoanAndPrint(LoanId);
            if (loanIsFound == 0)
            {

                break;
            }
            cout << "Unfortunately to avoid fraud and ensure security your not allowed to change contents of loan\n";
            cout << "However you can delete the loan to update customer and book status\n";

            cout << "-------------------\n";
            cout << "\n";
            break;
        }

        case 3:
        {
            long long int superBookID = 0;
            int patronID = 0;

            cout << "\nDELETING LOAN REGISTRATION\n";
            cout << "-------------------\n";
            cout << "Enter Unique Loan ID Number" << endl;
            cin >> LoanId;
            // void deleteLoan(int loaningID, long long int &superBookID, int patronID);
            loanfound = loanStorage.deleteLoan(LoanId, superBookID, patronID);
            if (loanfound == 0)
            {

                break;
            }
            BookStorage.editBookStatus(superBookID, 'i');
            customerStorage.updateCustomerAfterSuccesfulReturn(patronID);
            cout << "Book is sucessfully returned and customer information updated\n";

            cout << "-------------------\n";
            cout << "\n";
            break;
        }

        case 4:
        {
            cout << "\nFINDING LOAN IN DATABASE....\n";
            cout << "-------------------\n";
            cout << "Enter Unique Loan ID Number" << endl;
            cin >> LoanId;
            cin.ignore();

            loanStorage.findLoanAndPrint(LoanId);
            cout << "\n";
            break;
        }

        case 5:
        {
            cout << "\nPRINTING ALL LOANS IN DATABASE....\n";
            cout << "-------------------\n";
            // Find loan we are looking for through an vector or if num where stored
            loanStorage.printAllLoans();
            cout << "\n";
            break;
        }

        case 6:
        {
            return;
            break;
        }

        default:
            cout << "\nInvalid Selection\n";
            break;
        }
        cout << "Do you wish to Continue with Loan Menu (Y/N): ";
        cin >> userSelection;
        cin.ignore();
    } while (userSelection == 'Y' || userSelection == 'y');
}

int main()
{

    int num;
    char userSelection = 'Y';

    /// VARS FOR CASE 2
    string CustomerName;
    int CustomerId;
    // no need for outstanding price automatically a zero
    // no need to enter Books Out

    /// VARS FOR CASE 3

    do
    {
        cout << "\n";
        cout << "Enter Selection" << endl;
        cout << "--------------------------------\n";
        cout << "1. Book Menu" << endl;
        cout << "2. Customer Menu" << endl;
        cout << "3. Loan/Check-out Menu" << endl;
        cout << "4. Close the Program" << endl;
        cout << "--------------------------------\n";
        cout << "Select a numerical option from the Main menu: ";
        cin >> num;
        cin.ignore();

        switch (num)
        {
        case 1:
        {
            BookMenu(); // calls book menu
            break;
        }

        case 2:
        {
            CustomerMenu(); // calls Customer Menu
            break;
        }

        case 3:
        {
            LoanMenu(); // calls loan Menu
            break;
        }

        case 4:
        {
            cout << "\nThanks for using program\n"; // ends program
            return 0;

            break;
        }

        default:
            cout << "Invalid selection" << "\n";
            cout << "\n";
            break;
        }

        cout << "Do you wish to go back to MAIN MENU screen (Y/N): ";
        cin >> userSelection;
        cin.ignore();

    } while (userSelection == 'Y' || userSelection == 'y');

    cout << "\nThanks for using program\n";
    return 0;
}
