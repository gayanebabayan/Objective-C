// Final Project:       MS-1
// File:                Item.h
// Name:                Gayane Babayan
// Seneca Student ID:   107-061-160
// Seneca email:        gbabayan@myseneca.ca
// Date of completion:  08-Nov-2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

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
