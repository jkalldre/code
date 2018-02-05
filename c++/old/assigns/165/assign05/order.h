// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"


/*****************************************************
* Order will hold all the variables and members for
* any given order initiated by the user.
*****************************************************/
class Order
{
   private:
    Product product;
    int quantity;
    Customer customer;
    
   public:
    Order();
    Order(Product p, int q, Customer c);
    
/*****************************************************
* these are my simple getter and setter functions that
* the other files and functions will use to access and
* modify the private functions of tis class.
*****************************************************/
    Product getProduct()
    {
       return product;
    }
    void setProduct(Product p)
    {
       product = p;
    }
    
    int getQuantity()
    {
       return quantity;
    }
    void setQuantity(int q)
    {
       quantity = q;
    }
    
    Customer getCustomer()
    {
       return customer;
    }
    void setCustomer(Customer c)
    {
       customer = c;
    }
    
    string getShippingZip()
    {
       Address temp = customer.getAddress();
       return temp.getZip();
    }
    
    float getTotalPrice()
    {
       return (product.getTotalPrice() * quantity);
    }
    void displayShippingLabel()
    {
       customer.display();
    }
    void displayReceipt();
    
};

#endif
