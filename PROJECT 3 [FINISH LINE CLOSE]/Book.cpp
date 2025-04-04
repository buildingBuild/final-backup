#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

Book::Book(string Authorname, string BookName, long long int ISBN_NUM, float costOfBook, char currentStatus)
{
    this->Authorname = Authorname;
    this->BookName = BookName;
    this->ISBN_NUM = ISBN_NUM;
    this->costOfBook = costOfBook;
    this->currentStatus = currentStatus;
}

string Book::GetBookTitle() const
{

    return BookName;
}
string Book::GetAuthorName() const
{
    return Authorname;
}
long long int Book::GetIsbnNumber() const
{
    return ISBN_NUM;
}
float Book::GetCost() const
{
    return costOfBook;
}
char Book::GetCurrentStatus() const
{
    return currentStatus;
}

void Book::setBookName(string BookNamey)
{
    BookName = BookNamey;
}

void Book::setAuthorName(string AuthName)
{
    Authorname = AuthName;
}
void Book::setIsbnNumber(long long int ISBN_Number)
{
    ISBN_NUM = ISBN_Number;
}
void Book::setCost(float costBook)
{
    costOfBook = costBook;
}
void Book::setCurrentStatus(char stat)
{
    currentStatus = stat;
}
