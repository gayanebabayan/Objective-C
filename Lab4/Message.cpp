// Workshop: Lab-4
// File: Message.cpp
// Date: 01-Oct-2018
// Name: Gayane Babayan
// ID:   107-061-160

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Message.h"

using namespace std;

namespace w4 {
   // *******************************************************************************************
   // default constructor
   Message::Message() {
      m_userName[0] = '\0';
      m_reply[0] = '\0';
      m_tweet[0] = '\0';
   }

   // *******************************************************************************************
   // 2 argument constructor, reads from the file, parses a single line, stores msgs
   Message::Message(std::ifstream& in, char c) {
       
      // local variable for retrieving a record from the file
      string tempLine;
      // local variable for tracking the element's position
      size_t pos;

      // get a single line from the file
      getline(in, tempLine, c);

      // check if single line has either "@" or " " delimiter
      if (((tempLine.find("@")) != string::npos) || ((tempLine.find(" ")) != string::npos)) {

         // check for "@" delimiter
         if ((pos = tempLine.find("@")) != string::npos) {
            // separate the m_userName msg from the string
            m_userName = tempLine.substr(0, pos-1);
            tempLine.erase(0, pos + 1);
            // check for " " delimiter
            if ((pos = tempLine.find(" ")) != string::npos) {
               // separate the m_reply msg from the string
               m_reply = tempLine.substr(0, pos);
               tempLine.erase(0, pos + 1);
               // separate the m_tweet msg from the string
               m_tweet = tempLine.substr(0);
            }
         }
         // check for " " delimiter
         else if ((pos = tempLine.find(" ")) != string::npos) {
            // separate the m_userName msg from the string
            m_userName = tempLine.substr(0, pos);
            tempLine.erase(0, pos + 1);
            // separate the m_tweet msg from the string
            m_tweet = tempLine.substr(0);
         }
      }
   }

   // *******************************************************************************************
   // returns true if the object is in safe empty state
   bool Message::empty() const {
      return (m_userName[0] == '\0' && m_reply[0] == '\0' && m_tweet[0] == '\0');
   }

   // *******************************************************************************************
   // displays the message objects within the container
   void Message::display(std::ostream& os) const {
      // prints msg in a required form
      os << "Message" << endl;
      os << " User  : " << m_userName;
      if (m_reply.length() != 0) {
         os << endl << " Reply : " << m_reply;
      }
      os << endl << " Tweet : " << m_tweet << endl << endl;
   }
}