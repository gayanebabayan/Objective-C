// Final Project:       MS-3
// File:                Task.cpp
// Name:                Gayane Babayan
// Seneca Student ID:   107-061-160
// Seneca email:        gbabayan@myseneca.ca
// Date of completion:  29-Nov-2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "Task.h"

using namespace std;

// CUSTOM CONSTRUCTOR            
// ****************************************************************************************
Task::Task(const std::string& str) :Item(str) {
   m_pNextTask = nullptr;
}

// RUN_PROCESS
// ****************************************************************************************
void Task::runProcess(std::ostream& os) {

   // check if there is any CustomerOrder in m_orders deque
   if (!m_orders.empty()) {

      // verify fill status of the last CustomerOrder
      if (!m_orders.back().getOrderFillState()) {
         // fills order with the Item, if order contains Item
         (m_orders.back().fillItem(*this, os));
      }
   }
}

// MOVE_TASK
// returns false if m_orders queue is empty
// ****************************************************************************************
bool Task::moveTask() {
   // define local variable
   bool empty = false;

   // if m_order is NOT empty
   if (!m_orders.empty()) {

      // check for the current Item orders fill state and m_pNextTask
      if (m_orders.back().getItemFillState(this->getName()) && m_pNextTask) {
            *m_pNextTask += std::move(m_orders.back());              // move last CustomerOrder to the next task
            m_orders.pop_back();                                     // remove last CustomerOrder from the m_orders
      }
      // m_orders is not empty
      empty = true;
   }
   return empty;
}

// SET_NEXT_TASK
// ****************************************************************************************
void Task::setNextTask(Task& T) {
   m_pNextTask = &T;
}

// GET_COMPLETED
// returns FALSE if m_orders is EMPTY
// ****************************************************************************************
bool Task::getCompleted(CustomerOrder& C) {
   // declare local variable
   bool empty = true;

   // check if m_order is empty
   if (m_orders.empty()) {
      empty = false;
   }
   else {
         // move last CustomerOrder to the parameter C
         C = std::move(m_orders.back());
         m_orders.pop_back();
   }
   return empty;
}

// VALIDATE
// ****************************************************************************************
void Task::validate(std::ostream& os) {
   os << getName() << " --> ";

   // check for m_pNextTask
   if (m_pNextTask == nullptr)
      os << "END OF LINE" << endl;
   else
      os << m_pNextTask->getName() << endl;
}

// OPERATOR +=
// moves parameter onto the front of CustomerOrder queue
// ****************************************************************************************
Task& Task::operator+=(CustomerOrder&& C) {
   m_orders.push_front(std::move(C));
   return *this;
}




