#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class BookCollection
{
public:
    void addBook(Book bo);
    void editBookStatus(long long int isbn, char newStatus);
    void deleteBook(long long int isbn);
    void findBook(long long int isbn);
    void printBookInformation(long long int isbn);
    int getVectorSize();
    void editWholeBookInformation(long long int isbn);
    void printAllBooks();
    bool checkBook(long long int isbn);

private:
    // Declare a new a list(vector) of the bookCollection class

    vector<Book> Books;
};

#endif
