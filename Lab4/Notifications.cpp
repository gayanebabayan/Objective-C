// Workshop: Lab-4
// File: Notifications.cpp
// Date: 01-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#include "Notifications.h"

using namespace std;

namespace w4 {
   // *******************************************************************************************
   // default constructor
   Notifications::Notifications() {
      m_count = 0;
      m_message = nullptr;
   }

   // *******************************************************************************************
   // copy constructor
   Notifications::Notifications(const Notifications& src) {
      *this = src;
   }

   // *******************************************************************************************
   // move constructor
   Notifications::Notifications(Notifications&& src) {
      *this = move(src);
   }

   // *******************************************************************************************
   // copy assignment operator
   Notifications& Notifications::operator=(const Notifications& other) {
      if (this != &other) {
         delete[] m_message;
         m_count = other.m_count;
         m_message = other.m_message;
      }
      return *this;
   }

   // *******************************************************************************************
   // move assignment operator
   Notifications&& Notifications::operator=(Notifications&& other) {
      if (this != &other) {         
         Message* temp;
         temp = m_message;
         m_message = other.m_message;
         m_count = other.m_count;
         other.m_message = temp;
         // set safe empty state
         other.m_count = 0;
         other.m_message = nullptr;
      }
      return std::move(*this);
   }

   // *******************************************************************************************
   // destructor
   Notifications::~Notifications() {
      delete[] m_message;
   }

   // *******************************************************************************************
   // helper function +=operator
   void Notifications::operator+=(const Message& msg) {
      
      // check the capacity, which is up to MaxNum Message objects
      if (m_count < MaxNum) {
         // create temp object and allocate memory for +1 element
         Message* temp;
         temp = m_message;

         temp = new Message[m_count+1];

         // copy all elements form m_message to temp
         for (int i = 0; i < (m_count); i++) {
            temp[i] = m_message[i];
         }
         // add the new element
         temp[m_count] = msg;

      // deallocate memory of the m_message
      delete[] m_message;

      // assign address of the resized array to the m_message
      m_message = temp;
      }
      m_count++;
   }

   // *******************************************************************************************
   // display function
   void Notifications::display(std::ostream& os) {
      for (int i = 0; i < m_count; i++) {
         m_message[i].display(os);
      }
   }
}