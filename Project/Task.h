#include "Item.h"
#include "CustomerOrder.h"
#include <deque>

#ifndef MS3_TASK_H
#define MS3_TASK_H

class Task :public Item {
private:
   std::deque<CustomerOrder> m_orders;          // looks it should be deque
   Task* m_pNextTask;                           // pointing to the next Task
public:
   Task(const std::string& str);                // custom constructor
   
   Task(const Task& other) = delete;            // prevent from copying
   Task(Task&& other) = delete;                 // prevent from moving

   Task& operator=(const Task& src) = delete;   // prevent from assign   
   Task& operator=(Task&& src) = delete;        // prevent from move assign

   void runProcess(std::ostream& os);
   bool moveTask();
   void setNextTask(Task& T);
   bool getCompleted(CustomerOrder& C);
   void validate(std::ostream& os);

   Task& operator+=(CustomerOrder&& C);
};
#endif // !MS3_TASK_H
