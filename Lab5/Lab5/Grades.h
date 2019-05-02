// Workshop: Lab-5
// File: Grades.h
// Date: 06-Oct-2018
// Name: Gayane Babayan

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iostream>
#include <iomanip>
#include "Letter.h"

using namespace std;

namespace sict {

   // declare Grades class
   class Grades {
   private:
      int* m_stdNum = nullptr;
      double* m_stdGrade = nullptr;
      size_t m_lineNo = 0;
      void setEmpty();
   public:
      // one arg constructor, destructor
      Grades(const string& file_name);
      ~Grades();

      // prohibits copying, moving and assigning
      Grades(const Grades& other) = delete;
      Grades(Grades&& other) = delete;
      Grades& operator =(const Grades& src) = delete;
      Grades& operator =(Grades&& src) = delete;

      // template function, displays stdNum, stdGrade, gradeLetter
      template <typename F>
      void displayGrades(ostream& os, F lambdaExp) const {
         // declare local variable
         string letter;

         // display m_stdNum, m_stdGrade and gradeLetter
         for (size_t i = 0; i < m_lineNo; i++) {
            // call lambdaExp function to return the letter
            letter = lambdaExp(m_stdGrade[i]);

            // display stdNum, stdGrade, gradeLetter
            os << setprecision(2) << fixed << "   " << m_stdNum[i] << " " << m_stdGrade[i] << " " << letter << endl;
            /*os << setw(10) << m_stdNum[i] << " ";
            os.setf(std::ios::fixed);
            os.precision(2);
            os << m_stdGrade[i] << " ";
            os.unsetf(std::ios::fixed);
            os << letter << endl;*/
         }
      }
   };

   // closing scope of the namespace sict
}
#endif // !SICT_LETTER_H
