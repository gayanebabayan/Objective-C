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

