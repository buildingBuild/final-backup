#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <vector>
using namespace std;
class Book
{
public:
    void Print() const;
    string GetAuthorName() const;
    string GetBookTitle() const;
    long long int GetIsbnNumber() const;
    float GetCost() const;
    char GetCurrentStatus() const;
    void setAuthorName(string AuthName);
    void setIsbnNumber(long long int ISBN_NUM);
    void setCost(float costBook);
    void setCurrentStatus(char stat);
    void setBookName(string BookNamey);

    // constructors
    // Set up a constructor in the Book class that takes all relevant book information
    Book(string Authorname, string BookName, long long int ISBN_NUM, float costOfBook, char currentStatus);

private:
    string Authorname;
    string BookName;
    long long int ISBN_NUM;
    int LibraryID;
    float costOfBook;
    char currentStatus;
};

#endif