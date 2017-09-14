/**********************************************************
 * File: employee.cpp
 *
 * Description: Practicing polymorphism
 *********************************************************/
#include <iostream>
#include <string>
using namespace std;
const int NUM_OF_EMPLOYEES = 3;
// Add your classes here

class Employee
{
protected:
   string name;
public:
   virtual void display()
   {
      cout << name;
   }
   string getName()
   {
      return name;
   }
   void setName(string name)
   {
      this->name = name;
   }
};

class PartTime : public Employee
{
private:
   int wage;
public:
   void display()
   {
      Employee::display();
      cout << " - $" << wage << "/hour" << endl;

   }
   int getWage () const { return wage;}
   void setWage(int wage) { this->wage = wage; }

};

class FullTime : public Employee
{
private:
   int salary;
public:
   void display()
   {
      Employee::display(); cout << " - $" << salary << "K/year" << endl;

   }
   int getSalary () const { return salary;}
   void setSalary(int salary) { this->salary = salary; }

};
/**********************************************************
 * Function: main
 *
 * Description: Prompts for 3 employees and then outputs
 * their information.
 *********************************************************/

int main()
{
   Employee *employees [NUM_OF_EMPLOYEES];

   for (int i = 0; i < NUM_OF_EMPLOYEES; i++)
   {
      char employeeType;
      cout << "Enter the employee type (p/f): ";
      cin >> employeeType;

      string name;
      cout << "Enter name: ";
      cin >> name;

      int rate;
      cout << "Enter rate: ";
      cin >> rate;


      if (employeeType == 'p')
      {
         PartTime *first = new PartTime;
         first->setWage(rate);
         first->setName(name);
         employees[i] = first;
         // create a part-time employee here and add it to the array

      }
      else
      {
         FullTime *first = new FullTime;
         first->setSalary(rate);
         first->setName(name);
         employees[i] = first;


         // create a full-time employee here and add it to the array
      }

      cout << endl;
   }

   for (int i = 0; i < NUM_OF_EMPLOYEES; i++)
   {
      employees[i]->display();
      // call the display method for each employee
   }
   delete *employees;
   // Don't foget to delete all of your employees here!

   return 0;
}

// end of file
