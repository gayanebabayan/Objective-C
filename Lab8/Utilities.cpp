// Workshop: Lab-8
// File: Utilities.cpp
// Date: 15-Nov-2018
// Name: Gayane Babayan
// ID:   107-061-160


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{  
   // builds a list of products using raw pointers
   // ******************************************************************************
   List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
   {
      // declare local variable
      List<Product> priceList;

      // loop through the description list
      for (size_t d = 0; d < desc.size(); d++) {

         // inner loop through the price list
         for (size_t p = 0; p < price.size(); p++) {

            // check if Price code and Description code are equal
            if (price[p].code == desc[d].code) {
               
               //create a new product - allocate memory
               Product* product = new Product(desc[d].desc, price[p].price);
               product->validate();

               // add product to the list
               priceList += product;

               // deallocate memory
               delete product;
               product = nullptr;
            }
         }
      }

      // return the list
      return priceList;
   }
  

   // builds a list of products using smart pointers
   // ******************************************************************************
   List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
   {
      // declare local variable
      List<Product> priceList;

      // loop through the description list
      for (size_t d = 0; d < desc.size(); d++) {

         // inner loop through the price list
         for (size_t p = 0; p < price.size(); p++) {
            
            // check if Price code and Description code are equal
            if (price[p].code == desc[d].code) {
               std::unique_ptr<Product> product(new Product(desc[d].desc, price[p].price));
               product->validate();

               // add product to the list
               priceList += product;
            }
         }
      }
      return priceList;
   }

   // namespace scope
}