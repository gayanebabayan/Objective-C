// Workshop: Lab-2
// File: Text.h
// Date: 16-Sept-2018
// Name: Gayane Babayan

#ifndef ICT_TEXT_H_
#define ICT_TEXT_H_

#include <string>
using namespace std;

namespace w2 {

   class Text {
   private:
      size_t m_lineNo = 0;
      string* m_strArray = nullptr;
      void setEmpty();                          // sets object to a safe empty state
   public:
      Text();                                   // default constructor
      ~Text();                                  // destructor

      Text(const string& file_name);            // one argument constructor 
      
      Text& operator= (const Text& src);        // copy assignment operator
      Text& operator= (Text&& src);             // move assignment operator

      Text(const Text& other);                  // copy constructor
      Text(Text&& other);                       // move constructor    
      size_t size() const;                      // member function returns number of records of text data
   };
}
#endif 

