// Final Project:       MS-2
// File:                CostomerOrder.h
// Name:                Gayane Babayan
// Seneca Student ID:   107-061-160
// Seneca email:        gbabayan@myseneca.ca
// Date of completion:  23-Nov-2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.#pragma once

#ifndef MS2_CUSTOMER_ORDER_H
#define MS2_CUSTOMER_ORDER_H

#include <iostream>
#include "Item.h"

// ItemInfo struct
struct ItemInfo
{
   std::string m_itemName;
   unsigned int m_serialNumber = 0;
   bool m_fillState = false;

   ItemInfo(std::string src) :m_itemName(src) {};
};

// CustomerOrder class
class CustomerOrder {
private:
   std::string m_name;
   std::string m_product;
   unsigned int m_cntItem;
   ItemInfo** m_lstItem;
   static size_t m_widthField;
public:
   CustomerOrder();                          // constructor
   CustomerOrder(std::string& str);          // custom constructor
   ~CustomerOrder();                         // destructor

   CustomerOrder(const CustomerOrder& other);                        // copy constructor: throws an exception if copying
   CustomerOrder& operator= (const CustomerOrder& src) = delete;     // prevents assigning

   CustomerOrder(CustomerOrder&& other) noexcept;                    // move constructor
   CustomerOrder& operator= (CustomerOrder&& src);                   // move assignment operator

   bool getItemFillState(std::string str) const;
   bool getOrderFillState() const;
   void fillItem(Item& item, std::ostream& os);
   void display(std::ostream& os) const;
};



#endif // !MS2_CUSTOMER_ORDER_H

