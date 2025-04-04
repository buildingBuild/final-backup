#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H
#include "customer.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace std;
class customerCollection
{
public:
    int AmountOfPatrons();
    void addCustomer(Customer cust);
    void editCustomer(int customerID);
    void deleteCustomer(int customerID);
    void findCustomerAndPrint(int customerID);
    void printCustomer();
    void printAllCustomers(); // creating a function in the book class that has the contents in output predefined and displaying that information

    bool checkCustomer(int customerID);
    void updateCustomerAfterSuccesfulLoan(int customerID);
    void updateCustomerAfterSuccesfulReturn(int customerID);

private:
    // Declare a new a list(vector) of the customer collection class
    vector<Customer> customers;
};

#endif