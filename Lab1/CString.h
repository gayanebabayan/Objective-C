// Workshop: Lab-1
// File: CString.h
// Date: 10-Sept-2018
// Name: Gayane Babayan
// ID:   107-061-160

// header guards for the "CString.h"
#ifndef SICT_CSTRING_H_
#define SICT_CSTRING_H_

const int maxChar = 3; 
using namespace std;

namespace w1 { 
   // declare the class CString
   class CString {
      private:
         char m_string[maxChar + 1];
         void setEmpty(int i);
      public:
         CString(const char* S);
         void display(ostream&) const;
   };

   // helper operator<<
   ostream& operator<< (ostream&, const CString&);
}
#endif 
