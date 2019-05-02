// Workshop: Lab-9
// File: w9.cpp
// Date: 17-Nov-2018
// Name: Gayane Babayan
// ID:   107-061-160

// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
   cout << "Command Line: " << argv[0];
   for (int i = 1; i < argc; i++)
      cout << " " << argv[i];
   cout << endl << endl;

   if (argc != 4)
   {
      cerr << endl << "***Incorrect number of arguments***" << endl;
      return 1;
   }

   char key = argv[3][0];

   try {
      w9::SecureData sd(argv[1], key, &cout);
      sd.backup(argv[2]);

      sd.restore(argv[2], key);
      cout << sd << std::endl;

   }
   catch (const std::string& msg) {
      cout << msg << std::endl;
   }

   return 0;
}
