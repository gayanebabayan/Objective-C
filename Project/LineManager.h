#ifndef MS3_LINEMANAGER_H
#define MS3_LINEMANAGER_H

#include <vector>
#include "Task.h"

class LineManager {
private:
   std::vector<Task*> AssemblyLine;
   std::deque<CustomerOrder> ToBeFilled;
   std::deque<CustomerOrder> Completed;
   unsigned int m_cntCustomerOrder;
   size_t AssemblySize;
public:
   LineManager(const std::string& fileName, std::vector<Task*>& T, std::vector<CustomerOrder>& toBeFilled);

   bool run(std::ostream& os);
   void displayCompleted(std::ostream& os) const;
   void validateTasks() const;
};


#endif // !MS3_LINEMANAGER_H
