#include "customer.h"
#include "customerCollection.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Customer::Customer(string Namey, int IDy)
{
    Name = Namey;
    ID = IDy;
    outstandingPrice = 0;
    BooksOut = 0;
}
int Customer::getId()
{
    return ID;
}
int Customer::getOutstandingPrice()
{
    return outstandingPrice;
}
int Customer::getBooksOut()
{
    return BooksOut;
}
string Customer::getNames()
{
    return Name;
}

void Customer::setId(int newId)
{
    ID = newId;
}
void Customer::setOutstandingPrice(int price)
{
    outstandingPrice = price;
}
void Customer::setBooksOut(int count)
{
    BooksOut = count;
}
void Customer::setNames(string Namey)
{
    Name = Namey;
}
