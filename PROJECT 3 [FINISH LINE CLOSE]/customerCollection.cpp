#include <iostream>
#include <vector>
#include <string>
#include "customer.h"
#include "customerCollection.h"
#include <iostream>
using namespace std;

int customerCollection::AmountOfPatrons()
{
    // int function that returns size of vector using .size()
    return customers.size();
}
void customerCollection::addCustomer(Customer cust)
{
    // adds object of type Customer class to vector
    customers.push_back(cust);
    return;
}
void customerCollection::editCustomer(int customerID)
{
    string CustomerName;
    int CustomerID;
    int BooksOut;
    float OutstandingPrice;
    // iterates over to find instance of given customerID
    for (size_t i = 0; i < customers.size(); i++)
    {
        // find customer
        if (customers[i].getId() == customerID)
        {
            cout << "-----------------------------------------------" << endl;
            cout << "Old Customer Name: " << customers[i].getNames() << "\n";
            cout << "Old Customer ID: " << customers[i].getId() << "\n";
            cout << "Old Books Out: " << customers[i].getBooksOut() << "\n";
            cout << "Old Outstanding Price: " << customers[i].getOutstandingPrice() << "\n";
            cout << "-----------------------------------------------" << endl;
            cout << "New Customer Name: ";
            getline(cin, CustomerName);
            cout << "New Customer ID: ";
            cin >> CustomerID;
            cout << "New Books Out: ";
            cin >> BooksOut;
            cout << "New Outstanding Price: ";
            cin >> OutstandingPrice;
            cout << "-----------------------------------------------" << endl;
            /// finish setter functions
            customers[i].setNames(CustomerName);
            customers[i].setId(CustomerID);
            customers[i].setBooksOut(BooksOut);
            customers[i].setOutstandingPrice(OutstandingPrice);

            cout << "Customer Information changed!" << "\n";
            cout << "\n";
            return;
        }
    }
    cout << "Customer Not found!\n";
}
void customerCollection::deleteCustomer(int customerID)
{ // Find book we are looking for through vector from customer id

    vector<Customer>::iterator it;
    for (it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->getId() == customerID)
        {
            customers.erase(it);
            cout << "Customer deleted successfully!" << endl;
            return;
        }
    }
    cout << "Customer not found, could not delete." << endl;
}
void customerCollection::findCustomerAndPrint(int customerID)
{ // We are looking through a vector that checks for customer ID Number.

    vector<Customer>::iterator it;
    for (it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->getId() == customerID)
        { // Print customer info
            cout << "Customer found !\n";
            cout << "-----------------------------------------------" << endl;
            cout << "Customer Name: " << it->getNames() << "\n";
            cout << "Customer ID: " << it->getId() << "\n";
            cout << "Books Out: " << it->getBooksOut() << "\n";
            cout << "Outstanding Price: " << it->getOutstandingPrice() << "\n";
            cout << "-----------------------------------------------" << endl;
            return;
        }
    }
    cout << "Customer not found!" << endl;
}
void customerCollection::printCustomer()
{
}

void customerCollection::printAllCustomers()
{

    vector<Customer>::iterator it;
    int i = 0;
    for (it = customers.begin(); it != customers.end(); ++it)
    {
        cout << "Customer " << i + 1 << ":\n";
        cout << "-----------------------------------------------" << endl;
        cout << "Customer Name: " << it->getNames() << "\n";
        cout << "Customer ID: " << it->getId() << "\n";
        cout << "Books Out: " << it->getBooksOut() << "\n";
        cout << "Outstanding Price: " << it->getOutstandingPrice() << "\n";
        cout << "-----------------------------------------------" << endl;
        ++i;
    }
}

bool customerCollection::checkCustomer(int customerID)
{

    vector<Customer>::iterator it;
    for (it = customers.begin(); it != customers.end(); ++it)
    {

        if (it->getId() == customerID)
        {
            cout << "Customer found !\n";
            cout << "-----------------------------------------------" << endl;
            cout << "Customer Name: " << it->getNames() << "\n";
            cout << "Books Out(cannot exceed 6): " << it->getBooksOut() << "\n";
            cout << "Outstanding Price(cannot exceed 0): " << it->getOutstandingPrice() << "\n";
            cout << "-----------------------------------------------" << endl;
            if (it->getBooksOut() <= 6 && it->getOutstandingPrice() == 0)
            {
                cout << "Customer can be Loaned!\n";
                return true;
            }
            else
            {
                cout << "Customer can not be Loaned!\n";
                return false;
            }
        }
    }
    cout << "Customer not found, can not loan\n";
    return false;
}

void customerCollection::updateCustomerAfterSuccesfulLoan(int customerID)
{
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (customers[i].getId() == customerID)
        {
            customers[i].setBooksOut(customers[i].getBooksOut() + 1);
        }
    }
}

void customerCollection::updateCustomerAfterSuccesfulReturn(int customerID)
{
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (customers[i].getId() == customerID)
        {
            cout << customers[i].getBooksOut() << endl;
            customers[i].setBooksOut(customers[i].getBooksOut() - 1);
        }
    }
}
