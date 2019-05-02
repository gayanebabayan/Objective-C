#include <iostream>
#include <iomanip>
#include <string>
#include "Item.h"

using namespace std;

// handle the static fieldWidth
// ****************************************************************************************
size_t Item::m_widthField = 0;

// custom constructor: sets values of data members by calling an extractToken()
// ****************************************************************************************
Item::Item(const std::string& str) {
   // declare local variables
   string tempLine;
   size_t next_pos = 0;
   bool more = true;
   string word;
   Utilities locObj;

   // assign line info
   tempLine = str;

   try {
      // call extractToken() unless more becomes false
      if (more) {
         // extract Name
         m_name = locObj.extractToken(tempLine, next_pos, more);

         if (more) {
            // extract Number, cast it into unsigned int
            word = locObj.extractToken(tempLine, next_pos, more);
            m_serialNumber = std::stoi(word);

            if (more) {
               // extract Quantity, cast it into unsigned int
               word = locObj.extractToken(tempLine, next_pos, more);
               m_quantity = std::stoi(word);

               if (more) {
                  // extract Description
                  m_description = locObj.extractToken(tempLine, next_pos, more);
               }
            }
         }
      }
   }
   catch (std::string msg)
   {
      cout << "Exception Handling:" << msg << endl;
   }

   // check m_widthField 
   if (m_widthField < locObj.getFieldWidth())
      m_widthField = locObj.getFieldWidth();
};

// returns the name of the current object
// ****************************************************************************************
const std::string& Item::getName() const {
   return m_name;
}

// returns next serial number to be used and increments m_serialNumber
// ****************************************************************************************
const unsigned int Item::getSerialNumber() {
   return m_serialNumber++;
};

// returns the remaining quantity of the current object
// ****************************************************************************************
const unsigned int Item::getQuantity() {
   return m_quantity;
};

// substracts 1 from the available quantity
// ****************************************************************************************
void Item::updateQuantity() {
   m_quantity--;
};

// displays items in short or full format
// ****************************************************************************************
void Item::display(std::ostream& os, bool full) const
{
   // declare local variables
   size_t width = m_widthField;

   // check is full is true
   if (full) {
      os << setw(width) << left << getName();
      os << " [" << setw(6) << std::setfill('0') << right << m_serialNumber << "]" << setfill(' ');
      os << " Quantity: " << setw(width) << left << m_quantity;
      os << " Description: " << setw(width) << left << m_description << endl;
   }
   else {
      os << setw(width) << left << getName();
      os << " [" << setw(6) << std::setfill('0') << right << m_serialNumber << "]" << setfill(' ') << endl;
   }
};





