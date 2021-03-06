#include <iostream>
#include <string>
#include <cstring>

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

using namespace std;

namespace sict {
   // define the enum Letter type
   enum Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

   // template function which returns a gradeLetter
   template <typename T>
   const char* convert(const T& enumLetter) {
      // local variable for a grade
      const char* gradeLetter = nullptr;        // do I need to delete(take care of) the created pointer ?

      // selects an appropriate gradeLetter
      switch (enumLetter) {
      case Letter::Aplus:
         gradeLetter = "A+  ";
         break;
      case Letter::A:
         gradeLetter = "A   ";
         break;
      case Letter::Bplus:
         gradeLetter = "B+  ";
         break;
      case Letter::B:
         gradeLetter = "B   ";
         break;
      case Letter::Cplus:
         gradeLetter = "C+  ";
         break;
      case Letter::C:
         gradeLetter = "C   ";
         break;
      case Letter::Dplus:
         gradeLetter = "D+  ";
         break;
      case Letter::D:
         gradeLetter = "D   ";
         break;
      case Letter::F:
         gradeLetter = "F   ";
         break;
      default:
         gradeLetter = "No relevant grade!";
      }
      // returns the grade's letter
      return gradeLetter;
   }
}
#endif // !SICT_LETTER_H
