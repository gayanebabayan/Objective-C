#include <iostream>
#include "CString.h"

using namespace std;

extern const int maxChar;
static int incrementNo = 0;

namespace w1 {
   
   // stores an empty string
   void CString::setEmpty(int i) {
      m_string[i] = '\0';
   }

   // constructor which stores first max characters of the string 
   CString::CString (const char* S) {
      int i;

      if (S != nullptr && S[0] != 0) {
         for (i = 0; i < maxChar; i++) {
            m_string[i] = S[i];
         }
         setEmpty(i);
      }
      else
         setEmpty(0); 
   }

   // displays the string stored in CString object
   void CString::display(ostream& ostr) const {
      ostr << m_string;
   }

   // inserts the stored string into the ostream and increments that number
   ostream& operator<< (ostream& ostr, const CString& S) {
      ostr << incrementNo << ": ";
      S.display(ostr);
      incrementNo++;
      return ostr;
   }
}
