/********************************************************
 * File: sum.cpp
 *
 * Purpose: Use an STL container to store a list of ints
 *    and compute their sum.
 *******************
*************************************/


#include <iostream>
#include <vector>
#include <list>
// TODO: include any other libraries here

using namespace std;

/*******************************************************
 * Function: promptForValues
 *
 * Purpose: Prompts the user for a list of values and
 * returns the appropriate container (vector or list).
 * The loop stops when the user enters 0.
 *******************************************************/
// TODO: implement this function here

list<int> promptForValues()
{
   list<int> temp;
   int num;
      do
      {
         cin >> num;
         temp.push_back(num);
      }
      while(num != 0);
      return temp;
}

/*vector<int> promptForValues()
{
   vector<int> temp;
   int num;
   do
   {
      cin >> num;
      temp.push_back(num);
   }
   while(num != 0);
   return temp;
}

/*******************************************************
 * Function: computeSum
 *
 * Purpose: Takes a list (vector or list) of integers
 * and uses an interator to traverse it to compute a sum.
 *******************************************************/
// TODO: implement this function here



int computeSum(list<int> data)
{
   int sum = 0;
   for(list<int>::iterator it = data.begin(); it != data.end(); ++it)
   {
      sum += *it;
   }
   return sum;
}    
/*
int computeSum(vector<int> data)
{
   int sum = 0;
   for(vector<int>::iterator it = data.begin(); it != data.end(); ++it)
   {
      sum += *it;
   }
   return sum;
}
/*******************************************************
 * Function: main
 *
 * Purpose: This is the driver for the program. It will
 * call a function to prompt for a list and then to
 * compute the sum.
 *******************************************************/
int main()
{
   cout << "Please enter a list of integers, 0 when done.\n";

   // TODO: declare your container object.
   list <int> data;

   data = promptForValues();
   int sum = computeSum(data);

   cout << "The sum is: " << sum << endl;

   return 0;
}
