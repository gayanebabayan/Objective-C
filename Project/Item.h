#include "Utilities.h"        

#ifndef MS1_ITEM_H
#define MS1_ITEM_H

class Item {
private:
   std::string m_name;
   std::string m_description;
   unsigned int m_serialNumber;
   unsigned int m_quantity;
   static size_t m_widthField;
public:
   Item(const std::string& str);
   const std::string& getName() const;
   const unsigned int getSerialNumber() ;
   const unsigned int getQuantity();
   void updateQuantity();
   void display(std::ostream& os, bool full) const;
};

#endif // !MS1_ITEM_H
