#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "BookCollections.h"
using namespace std;

void BookCollection::addBook(Book bo)
{
    // vector push_back that adds object of type book
    Books.push_back(bo);
}

void BookCollection::editBookStatus(long long int isbn, char newStatus)
{
    for (int i = 0; i < Books.size(); i++)
    {

        if (Books[i].GetIsbnNumber() == isbn)
        {

            Books[i].setCurrentStatus(newStatus);
            return;
        }
    }
}
void BookCollection::deleteBook(long long int isbn)
{
    vector<Book>::iterator it;
    for (it = Books.begin(); it != Books.end(); ++it)
    {
        if (it->GetIsbnNumber() == isbn)
        {
            // use the vector function .erase()

            Books.erase(it);
            cout << "Book deleted successfully." << endl;
            return;
        }
    }
    cout << "Book not found, could not delete." << endl;
}

void BookCollection::findBook(long long int isbn)
{

    // At each index element we can check if the isbn number matches the one user gave and if it matches then its successful

    for (int i = 0; i < Books.size(); i++)
    {

        if (Books[i].GetIsbnNumber() == isbn)
        {
            cout << "Book is Found" << endl;
            return;
        }
    }
    // if its not successful then book is not there
    cout << "Could Not find Book" << endl;
}
void BookCollection::printBookInformation(long long int isbn)
{
    for (int i = 0; i < Books.size(); i++)
    {

        if (Books[i].GetIsbnNumber() == isbn)
        {
            cout << "BOOK FOUND!\n";
            cout << "-----------------------------------------------" << endl;
            cout << "Book Title: " << Books[i].GetBookTitle() << "\n";
            cout << "Book Price: " << Books[i].GetCost() << "\n";
            cout << "Author Name: " << Books[i].GetAuthorName() << "\n";
            cout << "Current Status: " << Books[i].GetCurrentStatus() << "\n";
            cout << "-----------------------------------------------" << endl;
            return;
        }
    }
    cout << "Could Not Find Book" << endl;
    return;
}

int ::BookCollection::getVectorSize()
{
    return Books.size();
}

void BookCollection::editWholeBookInformation(long long int isbn)
{
    // PROMPTS FOR NEW VALUES
    string Authorname;
    string BookName;
    long long int ISBN_NUM;
    int LibraryID;
    float costOfBook;
    char currentStatus;
    for (size_t i = 0; i < Books.size(); i++)
    {
        // WHEN FOUND DISPLAY OLD INFORMATION
        if (Books[i].GetIsbnNumber() == isbn)
        {

            cout << "-----------------------------------------------" << endl;
            cout << "Old Book Title: " << Books[i].GetBookTitle() << "\n";
            cout << "Old Book Price: " << Books[i].GetCost() << "\n";
            cout << "Old Author Name: " << Books[i].GetAuthorName() << "\n";
            cout << "Old Current Status " << Books[i].GetCurrentStatus() << "\n";
            cout << "Old ISBN Number " << Books[i].GetIsbnNumber() << "\n";
            cout << "-----------------------------------------------" << endl;

            cout << "\n-----------------------------------------------\n";
            cout << "New Book Title: ";
            cin.ignore();
            getline(cin, BookName);
            cout << "New Book Price: ";
            cin >> costOfBook;
            cin.ignore();
            cout << "New Author Name: ";
            getline(cin, Authorname);
            cout << "New Current Status ";
            cin >> currentStatus;
            cout << "New ISBN number: ";
            cin >> ISBN_NUM;
            cin.ignore();
            cout << "-----------------------------------------------" << endl;

            Books[i].setAuthorName(Authorname);
            Books[i].setBookName(BookName);
            Books[i].setCurrentStatus(currentStatus);
            Books[i].setCost(costOfBook);
            Books[i].setIsbnNumber(ISBN_NUM);

            cout << "Book Information changed!" << "\n";
            cout << "\n";
            return;
        }
    }
    cout << "\nBook is not found\n";
    return;
}

void BookCollection::printAllBooks()
{
    // implement code for where there are no Books found later on
    // iterates over vector size printing each object information
    for (int i = 0; i < Books.size(); i++)
    {
        cout << "Book " << i + 1 << ":\n";
        cout << "-----------------------------------------------" << endl;
        cout << "Book Title: " << Books[i].GetBookTitle() << "\n";
        cout << "Book Price: " << Books[i].GetCost() << "\n";
        cout << "Author Name: " << Books[i].GetAuthorName() << "\n";
        cout << "Current Status: " << Books[i].GetCurrentStatus() << "\n";
        cout << "ISBN number: " << Books[i].GetIsbnNumber() << "\n";
        cout << "-----------------------------------------------" << endl;
    }
    cout << "DISPLAYED ALL BOOKS!\n";
}

bool BookCollection::checkBook(long long int isbn)
{

    for (int i = 0; i < Books.size(); i++)
    {

        if (Books[i].GetIsbnNumber() == isbn)
        {
            cout << "BOOK FOUND!\n";
            cout << "-----------------------------------------------" << endl;
            cout << "Book Title: " << Books[i].GetBookTitle() << "\n";
            cout << "Book Price: " << Books[i].GetCost() << "\n";
            cout << "Current Status: - i for In, o - out, r - repair, l - lost: " << Books[i].GetCurrentStatus() << "\n";
            cout << "-----------------------------------------------" << endl;

            if (Books[i].GetCurrentStatus() == 'i' || Books[i].GetCurrentStatus() == 'I')
            {
                // If the book is found we then check the status of the book if the book is out,in repair or
                cout << "Book can be loaned!\n";
                return true;
            }
            else
            {
                cout << "Book is not available at the moment but is found\n";
                return false;
            }
        }
    }
    cout << "Could Not Find Book, can not be loaned" << endl;
    return false;
}
