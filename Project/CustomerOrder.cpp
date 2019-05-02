#include <iostream>
#include <iomanip>
#include <string>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

// handle the static fieldWidth
// ****************************************************************************************
size_t CustomerOrder::m_widthField = 0;

// DEFAULT CONSTRUCTOR
// ****************************************************************************************
CustomerOrder::CustomerOrder() {
   m_name = "";
   m_product = "";
   m_cntItem = 0;
   m_widthField = 1;
   m_lstItem = nullptr;
};

// CUSTOM CONSTRUCTOR
// parses single line, exctracts m_name, m_product, 
// allocates memory for m_lstItem and then allocates memory and stores info for each Item
// ****************************************************************************************
CustomerOrder::CustomerOrder(std::string& str) {
   // declare local variables
   string tempLine;
   size_t next_pos = 0;
   bool more = true;
   string token;
   Utilities locObj;
   unsigned int count = 0;

   // assign line info
   tempLine = str;

   try {

      // loop through the line and count number of tokens
      while (more) {
         locObj.extractToken(tempLine, next_pos, more);
         count++;
      }

      // check m_widthField
      if (m_widthField < locObj.getFieldWidth())
         m_widthField = locObj.getFieldWidth();

      // NOW WE KNOW THE SIZE of the m_lstItem array
      m_cntItem = count - 2;

      // allocate memory for the ItemInfo*
      m_lstItem = new ItemInfo*[m_cntItem];

      // START OVER TO PARSE the line AGAIN 
      // reset next_pos and more value back
      next_pos = 0;
      more = true;

      // add values into your data members
      if (more) {
         // extract name
         m_name = locObj.extractToken(tempLine, next_pos, more);

         if (more) {
            // extract product name
            m_product = locObj.extractToken(tempLine, next_pos, more);

            // extract item name, create ItemInfo pointer and place as an array element
            for (unsigned int i = 0; i < m_cntItem && more; i++) {
               token = locObj.extractToken(tempLine, next_pos, more);
               m_lstItem[i] = new ItemInfo(token);
            }
         }
      }
   }
   catch (std::string msg)
   {
      cout << "Exception Handling: " << msg << endl;;
   }

};

// DESTRUCTOR
// first deallocates memory for each element inside the m_lstItem array
// after deallocates memory of the m_lstItem array itself
// ****************************************************************************************
CustomerOrder::~CustomerOrder() {
   // loop through the array of pointers and deallocate all elements
   if (m_lstItem != nullptr)
   {
      for (unsigned int i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i] != nullptr)
            delete m_lstItem[i];
      }
      delete[] m_lstItem;
   }
};

// COPY CONSTRUCTOR
// throws an exception if copying
// ****************************************************************************************
CustomerOrder::CustomerOrder(const CustomerOrder& other) {
   throw "ERROR: Cannot make copies.";
};


// MOVE CONSTRUCTOR
// ****************************************************************************************
CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
   *this = std::move(other);
};


// MOVE ASSIGNMENT OPERATOR
// ****************************************************************************************
CustomerOrder& CustomerOrder::operator= (CustomerOrder&& src) {
   if (this != &src) {
      // create a temp object
      ItemInfo** temp = m_lstItem;

      // copy data members from src to current objwct
      m_lstItem = src.m_lstItem;
      m_name = src.m_name;
      m_product = src.m_product;
      m_cntItem = src.m_cntItem;
      m_widthField = src.m_widthField;

      // set sourse to the safe state
      src.m_lstItem = temp;
      src.m_lstItem = nullptr;
      src.m_cntItem = 0;
   }
   return *this;
};


// getItemFillState
// returns true if Item does NOT exist in the order, otherwise return value of the m_fillState
// ****************************************************************************************
bool CustomerOrder::getItemFillState(std::string str) const {
   bool returnVal = true;

   // loop through to find the item
   for (unsigned int i = 0; i < m_cntItem; i++) {
      if (str == m_lstItem[i]->m_itemName) 
      {
         returnVal = m_lstItem[i]->m_fillState;
      }
   }
   return returnVal;
};

// getOrderFillState 
// returns true if all items fillState is true, otherwise false
// ****************************************************************************************
bool CustomerOrder::getOrderFillState() const {
   unsigned int filled = 0;
   bool result = false;

   // loop through to check if all items are filled
   for (unsigned int i = 0; i < m_cntItem; i++) {
      if (m_lstItem[i]->m_fillState) {
         filled++;
      }
   }
   // checks if all items are filled
   if (filled == m_cntItem)
      result = true;

   return result;
};

// fillItem
// finds the item in the inventory, checks for the quantity, fills the info about that item
// ****************************************************************************************
void CustomerOrder::fillItem(Item& item, std::ostream& os) {

   // loop through the ordered list to find the item
   for (unsigned int i = 0; i < m_cntItem; i++) {

      // check if item names are the same
      if (item.getName() == m_lstItem[i]->m_itemName) {

         // check for the availability in the inventory
         if (item.getQuantity() > 0) {
            item.updateQuantity();
            m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            m_lstItem[i]->m_fillState = true;

            os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
         }
         else {
            os << "Unable to fill" << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
         }
      }
   }
};

// display
// displays the status of the item in the required form
// ****************************************************************************************
void CustomerOrder::display(std::ostream& os) const {
   // local variable 
   //size_t WF = m_widthField; //required for ms2
   size_t WF = 16;      //no requirements for ms3

   os << m_name << " - " << m_product << endl;

   // loop through the item list
   for (unsigned int i = 0; i < m_cntItem; i++) {
      os << "[" << setw(6) << std::setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
      os << setw(WF) << left << m_lstItem[i]->m_itemName << " - ";

      if (m_lstItem[i]->m_fillState)
         os << "FILLED" << endl;
      else
         os << "MISSING" << endl;
   }
};









