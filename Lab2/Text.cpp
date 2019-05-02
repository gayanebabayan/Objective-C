// Workshop: Lab-2
// File: Text.cpp
// Date: 16-Sept-2018
// Name: Gayane Babayan

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>   
#include "Text.h"  

using namespace std;

namespace w2 {

   // default constructor
   //***************************************************************************************************************
   Text::Text() {
      setEmpty();
   }

   // one argument constructor
   //***************************************************************************************************************
   Text::Text(const string& file_name) {

      // open a file for reading
      ifstream myFile_in;
      myFile_in.open(file_name);

      // create temp string to pass the line
      string tempText;

      // if succeeds, then read and count lines from the file
      if (!myFile_in.fail()) {
         while (getline(myFile_in, tempText))
            m_lineNo++;

         // we have lineNo, we can allocate the memory
         m_strArray = new string[m_lineNo];

         // reset in eof error state
         myFile_in.clear();

         // go back to the begining of file
         myFile_in.seekg(0, ios::beg);

         // store the lines inside the array
         for (int i = 0; i < m_lineNo; i++)
            getline(myFile_in, m_strArray[i]);

         // close the file
         myFile_in.close();
      }
      else
         // set to a safe empty state
         setEmpty();
   }
   
   // copy constructor
   //***************************************************************************************************************
   Text::Text(const Text& other) {
      *this = other;
   }

   // move constructor
   //***************************************************************************************************************
   Text::Text(Text&& other) {
      *this = std::move(other);
   }

   // copy assignment operator
   //***************************************************************************************************************
   Text& Text::operator= (const Text& src) {
      
      // check if it is not self assignment 
      if (this != &src) {
         // deallocate memory
         delete[] m_strArray;

         // set safe empty state
         setEmpty();

            // get the lineNo of records from the size() member function
            m_lineNo = src.size();
            m_strArray = new string[m_lineNo];

            for (int i = 0; i < m_lineNo; i++) 
               m_strArray[i] = src.m_strArray[i];
      }
      // return current object
      return *this;
   }

   // move assignment operator
   //***************************************************************************************************************
   
   Text& Text::operator= (Text&& src) {
      
      // check if it is not self assignment      
      if (this != &src) {
         // create a temp object
         string* temp = m_strArray;

         // copy data members from src to current object
         m_strArray = src.m_strArray;
         m_lineNo = src.m_lineNo;
         
         src.m_strArray = temp;

         // set src to safe empty state
         src.setEmpty();            
      }
      // return current object
      return *this;
   }

   // destructor
   //***************************************************************************************************************
   Text::~Text() {
      delete[] m_strArray;   
   }

   // size(): returns the number of records of text data
   //***************************************************************************************************************
   size_t Text::size() const {
      return m_lineNo;                                     
   }

   // setEmpty(): sets to a safe empty state
   //***************************************************************************************************************
   void Text::setEmpty() {
      m_strArray = nullptr;
      m_lineNo = 0;
   }
}
