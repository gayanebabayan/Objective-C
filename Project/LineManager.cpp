#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

// CUSTOM CONSTRUCTOR
// ****************************************************************************************
LineManager::LineManager(const string& fileName, vector<Task*>& T_vect, vector<CustomerOrder>& CO_vect) {
   
   // declare local variable
   string lineRec;
   string token;
   Utilities locObj;
   size_t nextPos = 0;
   bool more = true;

   // copy all the Task into AssemblyLine
   AssemblyLine = T_vect;
   
   // the number of CustomerOrder objects
   m_cntCustomerOrder = CO_vect.size();

   try {
      ifstream myFile;
      myFile.open(fileName);

      if (myFile.fail()) {
         throw "Couldn't open the file";
      }
      else {
         // read each line, till the eof
         while (!myFile.eof()) 
         {
            getline(myFile, lineRec);
            // set delimiter, for extracting tokens
            Utilities::setDelimiter('|');

            // extract the 1st token/Item from the line
            token = locObj.extractToken(lineRec, nextPos, more);

            // loop through the AssemblyLine => basically look for it inside the Inventory
            for (auto& tsk : AssemblyLine)
            {
               // look for the 1st Item name match
               if (token == tsk->getName())                    //e.g. Line1/Token1 - Power Supply
               {
                  if (more) 
                  {
                     // extract 2nd token/Item from the line
                     token = locObj.extractToken(lineRec, nextPos, more);

                     // loop through the AssemblyLine again 
                     for (auto& ntsk : AssemblyLine) 
                     {
                        // look for the 2nd Item name match
                        if (token == ntsk->getName())          //e.g. Line1/Token2 - CPU
                        {
                           // setup m_pNextTask in the Task objects
                           tsk->setNextTask(*ntsk);
                        }
                     }
                  }
               }
            }
            // reset values to parse the next line 
            nextPos = 0;
            more = true;
         }
         // close the file
         myFile.close();

         // loop through and move elements from CO_vect onto ToBeFilled deque
         for(size_t i =0; i < CO_vect.size(); i++)
         { 
            ToBeFilled.push_front(std::move(CO_vect.at(i)));
         }
      }      
   }
   catch (...) 
   {
      cout << "Couldn't opent the file!" << endl;
   }
}

// RUN
// ****************************************************************************************
bool LineManager::run(ostream& os) {

   // loop through to runProcess, moveTask and push onto the Completed deque
   for (size_t j = 0; j < 7; j++) { 

      // if ToBeFilled deque is not empty
      if (!ToBeFilled.empty()) {
         // move to the starting poin
         *AssemblyLine.back() += std::move(ToBeFilled.back());
         ToBeFilled.pop_back();
      }

      // loop through the AssemblyLine and through runProcess fillItem
      for (size_t i = 0; i < AssemblyLine.size(); i++) {
         AssemblyLine.at(i)->runProcess(os);
      }
      
      // loop through the AssemblyLine and move to the next task
      for (size_t i = 0; i < AssemblyLine.size(); i++) {
         AssemblyLine.at(i)->moveTask();
      }
   }
   
   // loop through the AssemblyLine and check for the completed orders
   for (size_t i = 0; i < AssemblyLine.size(); ++i) {
      CustomerOrder order;
      // if orders are filled, move to the Completed deque
      if (AssemblyLine.at(i)->getCompleted(order)) {
         Completed.push_back(std::move(order));
      }
   }
   // returns true if all the orders are completed, otherwise false
   return (Completed.size() == m_cntCustomerOrder);
}

// DISPLAY_COMPLETED
// ****************************************************************************************
void LineManager::displayCompleted(ostream& os) const {
   // iterate through the Completed deque
   for (auto& comp : Completed)
   {
      // display completed orders 
      comp.display(os);
   }
}

// VALIDATE_TASKS
// ****************************************************************************************
void LineManager::validateTasks() const {
   // iterate through the AssemblyLine
   for (auto& tsk : AssemblyLine) {
      // validate each element in the vector
      tsk->validate(std::cout);
   }
}
