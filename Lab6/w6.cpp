// Workshop 6 - STL Containers
// w6.cpp

// Date: 30-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

   std::cout << "Command Line: ";
   for (int i = 0; i < argc; i++) {
      std::cout << argv[i] << ' ';
   }
   std::cout << std::endl;
   if (argc != 2) {
      std::cerr << "\n***Incorrect number of arguments***\n";
      return 1;
   }
   std::ifstream productList(argv[1]);
   if (!productList) {
      std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
      return 2;
   }
   std::cout << std::fixed << std::setprecision(2);
   
   // TODO: Define a variable of type vector named "products"
   std::vector <w6::iProduct*> products;

   std::cout << "====================================\n";
   std::cout << "Reading data from the file\n";
   std::cout << "====================================\n";
   {
      // TODO: Read from the file one record at a time and create a product.

      // local variable for listing the records
      int record = 0;
      
      // read lines of the file 
      while (productList.good()) {
         
         // incrementing the record 
         record++;  

         // errorHandling: handles the thrown exception
         try 
         {
            // get either new Product or new TaxableProduct
            w6::iProduct* prod = w6::readProduct(productList);

            // check if it has content
            if (prod != nullptr ) {
               // add new product to prodVector
               products.push_back(prod);
               // print the message about the success
               std::cout << "Processing record " << record << ": done!" << std::endl;
            }
            // reaches end of the file
            else if (prod == nullptr){
               std::cout << "Processing record " << record << ": no such record! Reached the end of the file!" << std::endl;
            }
         }
         // chatches the thrown exception
         catch (const char* msg) {
            std::cout << "Processing record " << record << ": " << msg << std::endl;
         }
      // end of the WHILE scope
      }

      // end of the TODO scope
   }
   std::cout << "====================================\n";
   std::cout << std::endl;
   std::cout << "====================================\n";
   std::cout << "Printing the content of the vector\n";
   std::cout << "====================================\n";
   double total = 0.0;
   std::cout << "      Product No         Taxable\n";     // spaces are required on the submission output
   std::cout << "------------------------------------\n";
   for (auto i = 0u; i < products.size(); i++) {
      total += products[i]->getPrice();
      std::cout << *products[i];
   }
   std::cout << "------------------------------------\n";
   std::cout << std::setw(22) << "Total: ";
   std::cout << std::setw(10) << total << std::endl;
   std::cout << "====================================\n";

   return 0;
   // end of the MAIN scope
}

