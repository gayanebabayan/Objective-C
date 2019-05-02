// Workshop: Lab-1
// File: process.cpp
// Date: 10-Sept-2018
// Name: Gayane Babayan


#include <iostream>
#include "process.h"
#include "CString.h"

// stores the turncated version of a string
void process(const char* str, std::ostream& ostr) {
   w1::CString A (str);
   ostr << A << endl;  
}
