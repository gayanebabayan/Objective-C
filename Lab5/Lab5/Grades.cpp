#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"

using namespace std;

namespace sict {
   // one argument constructor
   // *********************************************************************
   Grades::Grades(const string& file_name) {
      try {
         // open a file for reading
         ifstream myFile;
         myFile.open(file_name);

         // create local variable to read the lines
         string lineRec;

         // if fails to open the file
         if (myFile.fail()) {
            // set safe empty state
            setEmpty();
            // throw an error
            throw "Err Msg: File is not opened!"; // >>>> change the throw statement ????
         }
         // if opening file succeeds
         else
         {
            // read and count the lines
            while (getline(myFile, lineRec))
               m_lineNo++;

            // reset in eof error state
            myFile.clear();

            // go back to the file begining
            myFile.seekg(0, ios::beg);

            // local variable for tracking the element's position
            size_t pos;

            // local variables for stdNumber and stdGrade
            string* stdNumber = new string[m_lineNo];
            string* stdGrade = new string[m_lineNo];

            // loop through lines and separate stdNumber, stdGrade
            for (size_t i = 0; i < m_lineNo; i++) {
               getline(myFile, lineRec);

               // look for delimiter to find stdNumber
               if ((pos = lineRec.find(" ")) != string::npos) {
                  // separate and store stdNumber
                  stdNumber[i] = lineRec.substr(0, pos);
                  lineRec.erase(0, pos + 1);
                  // separate and store stdGrade
                  stdGrade[i] = lineRec.substr(0);
               }
            }
            // close the file
            myFile.close();

            // allocate memory for m_stdNum and m_stdGrades
            m_stdNum = new int[m_lineNo];
            m_stdGrade = new double[m_lineNo];

            // copy data from the locals to the current array
            for (size_t j = 0; j < m_lineNo; j++) {
               m_stdNum[j] = std::stoi(stdNumber[j]);
               m_stdGrade[j] = std::stod(stdGrade[j]);
            }

            // deallocate memory of the local arrays
            delete[] stdNumber;
            delete[] stdGrade;
         }
      }
      // error handling for any type of error
      catch (...) {
         cout << "Error Message: Couldn't open the file!" << endl;
      }
   }

   // set safe empty state
   // *********************************************************************
   void Grades::setEmpty() {
      m_lineNo = 0;
      m_stdNum = nullptr;
      m_stdGrade = nullptr;
   }

   // destructor
   // *********************************************************************
   Grades::~Grades() {
      // deallocate memory
      delete [] m_stdNum;
      delete[] m_stdGrade;
   }
   
   // closing scope of the namespace sict
}
