// Workshop: Lab-4
// File: Message.h
// Date: 01-Oct-2018
// Name: Gayane Babayan

#ifndef CIST_MESSAGES_H
#define CIST_MESSAGES_H

#include <iostream>
using namespace std;

namespace w4 {
   // declare Message class
   class Message {
   private:
      string m_userName;
      string m_reply;
      string m_tweet;
   public:
      Message();
      Message(std::ifstream& in, char c);
      bool empty() const;
      void display(std::ostream& os) const;
   };
}

#endif 
