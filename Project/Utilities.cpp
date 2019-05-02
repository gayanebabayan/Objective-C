#include <iostream>
#include <string>
#include <cstring>
#include "Utilities.h"

using namespace std;

// handle the static char delimiter
// ****************************************************************************************
char Utilities::m_delimiter = '\0';

// default constructor
// ****************************************************************************************
Utilities::Utilities() {
   // set fieldwidth to default value 1
   setFieldWidth(1);
};

// sets the field width of the current object to the value of the parameter
// ****************************************************************************************
void Utilities::setFieldWidth(size_t pSize) {
   m_widthField = pSize;
};

// returns the field width of the current object
// ****************************************************************************************
size_t Utilities::getFieldWidth() const {
   return m_widthField;
};

// extracts tokens from the first parameter
// ****************************************************************************************
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
   
   // local variables
   string tempLine = str;
   size_t inner_pos;

   // separate the part on the line, which needed to work with 
   tempLine = (tempLine.substr(next_pos, std::string::npos));

   // find next delimiter's position in the templine
   inner_pos = tempLine.find(getDelimiter());

   // check is start_pos and next_pos has the same position
   if (inner_pos == 0) {
      throw "Exception: There are two delimiters with no token between them!";
   }
   else {
      // check for the end of the line
      if (inner_pos != string::npos) {

         // separate word up to the delimiter
         tempLine = tempLine.substr(0, inner_pos);

         // check the widthField and update if needed
         if (getFieldWidth() < tempLine.length())
            setFieldWidth(tempLine.length());

         // consume delimiter and set new position for the next_pos
         next_pos = next_pos + inner_pos + 1;

         more = true;
      }
      else
         more = false;
   }
   return tempLine;
}

// sets the delimiter for this class to the character received
// ****************************************************************************************
void Utilities::setDelimiter(const char pDelim) {
   m_delimiter = pDelim;
};

// returns the delimiter char of the current object
// ****************************************************************************************
const char Utilities::getDelimiter() const {
   return m_delimiter;
};






