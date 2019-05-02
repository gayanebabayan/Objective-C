// Linkage, Storage Duration, Namespaces, and OS Interface

#include <iostream>
#include <fstream>
#include "process.h"
#include "CString.h"

using namespace std;
using namespace w1;

int main(int argc, char* argv[]) {

   std::ofstream ofs("Lab1Output.txt");

   ofs << "Command Line : ";
   for (int i = 0; i < argc; i++) {
      ofs << argv[i] << ' ';
   }
   if (argc < 2) {
      ofs << "\nInsufficient number of arguments\n";
      return 1;
   }

   /****
   TO DO:  Add code here that will print out the max characters stored
   by your CString object
   *****/
   ofs << endl << "Maximum number of characters stored: " << maxChar << endl;

   for (int i = 1; i < argc; i++) {
      process(argv[i], ofs);
   }

   int WaitKey;
   std::cin >> WaitKey;

   ofs.close();
   return 0;
}
