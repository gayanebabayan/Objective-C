#ifndef CIST_NOTIFICATIONS_H
#define CIST_NOTIFICATIONS_H

#include "Message.h"

namespace w4 {
   // declare max number of elements
   const size_t MaxNum = 10;
   
   // declare Notifications class
   class Notifications {
   private:
      Message* m_message;
      int m_count;
   public:
      Notifications();
      Notifications(const Notifications& src);
      Notifications(Notifications&& src);
      Notifications& operator=(const Notifications& other);
      Notifications&& operator=(Notifications&& other);
      ~Notifications();
      void operator+=(const Message& msg);      
      void display(std::ostream& os);
   };
}

#endif 
