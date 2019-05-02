// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;
using namespace std;

int main(int argc, char* argv[]) {

   std::cout << "Command Line: ";
   for (int i = 0; i < argc; i++)
      std::cout << argv[i] << ' ';
   std::cout << std::endl;

   if (argc == 1) {
      std::cerr << "\n*** Insufficient number of arguments ***\n";
      std::cerr << "Usage: " << argv[0] << " fileName \n";
      return 1;
   }
   else if (argc != 2) {
      std::cerr << "\n*** Too many arguments ***\n";
      std::cerr << "Usage: " << argv[0] << " fileName \n";
      return 2;
   }


   
   //TODO: Update the main functions as per the specifications here
   try {
      // creates an object grades
      Grades grades(argv[1]);

      // lambda expression, returns appropriate gradeLetter
      const char* (*letter)(double) = [](double numerGr) {           //another option =>:    auto letter = [](double numerGr) {
         if (numerGr >= 90) { return convert(Aplus); }
         else if (numerGr >= 80) { return convert(A); }
         else if (numerGr >= 75) { return convert(Bplus); }
         else if (numerGr >= 70) { return convert(B); }
         else if (numerGr >= 65) { return convert(Cplus); }
         else if (numerGr >= 60) { return convert(C); }
         else if (numerGr >= 55) { return convert(Dplus); }
         else if (numerGr >= 50) { return convert(D); }
         else if (numerGr >= 0)  { return convert(F); }
         else {
            throw "Some error occurs!";                           // ask about the error handling staff ?
         }
      };

      /*
      // lambda expression, returns appropriate gradeLetter
      const char* (*letter)(double) = [](double numerGr) {           //another option =>:    auto letter = [](double numerGr) {

 
         // checks to handle F grade
      //   if (numerGr < 50) { cout << "    "; }

         // checks for the rest of the grades
         if (numerGr >= 90) { return convert(Aplus); }
         else if (numerGr >= 80) { return convert(A); }
         else if (numerGr >= 75) { return convert(Bplus); }
         else if (numerGr >= 70) { return convert(B); }
         else if (numerGr >= 65) { return convert(Cplus); }
         else if (numerGr >= 60) { return convert(C); }
         else if (numerGr >= 55) { return convert(Dplus); }
         else if (numerGr >= 50) { return convert(D); }
         else {
            throw "Some error occurs!";                           // ask about the error handling staff ?
         }
      };
   */   

      // display stdNumber, stdGrade and gradeLetter
      grades.displayGrades(std::cout, letter);

   }
   catch (...) {
      // catches the thrown error message
      //cout << "Error msg: Something went wrong while converting the numeric grades!" << endl;
      cout << '\0' << endl;
   }

   
   



       
   return 0;
}