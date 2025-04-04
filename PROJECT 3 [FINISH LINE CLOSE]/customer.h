/// CUSTOMER CLASSSS

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;
class Customer
{
public:
    // Set up a constructor in the customer class that takes all relevant customer information
    Customer(string Name, int ID);
    int getId();
    int getOutstandingPrice();
    int getBooksOut();
    string getNames();

    void setId(int newId);
    void setOutstandingPrice(int price);
    void setBooksOut(int count);
    void setNames(string Namey);

private:
    string Name;
    int ID;
    float outstandingPrice;
    int BooksOut;
};
#endif