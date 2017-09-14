/***********************************************************************
* Program:
*    Project 2, Monthly Calendar
*    Brother Neff, CS124
* Author:
*    Israel Carvajal
* Summary: 
*    This program will prompt the user for a month and a year, and will 
*    display a month calendar
*    *    Estimated:  4 hrs   
*    Actual:     5.3 hrs
*     I tried to create a function called getMonthName, but I could'nt
*     figure up how to use char*, so I defined month name in displayHeader
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************
 * getMonth()
 *     PROMPT month
 *     GET month
 *************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: "; cin >> month;
   if (month <= 12 && month >= 1)
      return month;
   else
   {
      do
      {
         cout << "Month must be between 1 and 12." << endl;
         cout << "Enter a month number: "; cin >> month;
      }
      while (month > 12 || month < 1);
   }
   return month;
}

/***************************************************
 * getYear
 *     PROMPT year
 *     GET year
 *************************************************/
int getYear()
{
   int year;
   cout << "Enter year: "; cin >> year;
   if (year >= 1753)
      return year;
   else
   {
      do
      {
         cout << "Year must be 1753 or later." << endl;
         cout << "Enter year: "; cin >> year;
      }
      while (year < 1753);
   }
   return year;
}

/**********************************************************************
 * This function will analyze if a year is leap or not
 *    it will be used to in several functions
 **********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 != 0) // if the year not divisible by four it is not leap
      return false;
   if (year % 100 != 0)
      return true;
   return !(year % 400);
}

/***************************************************
 * getNumOfDays()
 *     PROMPT numOfDays
 *     GET numOfDays
 *************************************************/
int getNumOfDaysInYear(int year)
{
   return 365 + isLeapYear(year);
}

/**********************************************************************
*  This function will tell us how many days there are in the month
*   depending on the month number, will be used to display Header
 ***********************************************************************/
int getNumOfDaysInMonth(int month, int year)
{
   if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   if (month == 2)
      return 28 + isLeapYear(year);
   else
      return 31;
}

/**********************************************************************
*  This function will compute the offset to display the calendar
*   table, it will tell us in what day of the week will the fist day of the
*  month start.
***********************************************************************/
int computeOffset(int month, int year)
{
   int sum = 0;
   for (int yr = 1753; yr < year; yr++)
   {
      sum += getNumOfDaysInYear(yr);
   }
   for (int mn = 1; mn < month; mn++)
   {
      sum += getNumOfDaysInMonth(mn, year);
   }
   return sum % 7;
}

/**********************************************************************
*  displayHeader
*  PUT month
*  PUT year
**********************************************************************/
void displayHeader(int month, int year)
{
   cout << endl;
   if (month == 1)
   {
      cout << "January";
   }
   if (month == 2)
   {
      cout << "February";
   }
   if (month == 3)
   {
      cout << "March";
   }
   if (month == 4)
   {
      cout << "April";
   }
   if (month == 5)
   {
      cout << "May";
   }
   if (month == 6)
   {
      cout << "June";
   }
   if (month == 7)
   {
      cout << "July";
   }
   if (month == 8)
   {
      cout << "August";
   }
   if (month == 9)
   {
      cout << "September";
   }
   if (month == 10)
   {
      cout << "October";
   }
   if (month == 11)
   {
      cout << "November";
   }
   if (month == 12)
   {
      cout << "December";
   }
   cout << ", " << year;
   
   
}

/**********************************************************************
* This function is only prototype
**********************************************************************/
void displayTable(int offset, int numOfDaysInMonth)
{
   {
      cout << endl << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu"
           << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr"
           << setw(4) << "Sa" << endl;
   }
   {
      int dow = (offset + 1) % 7;
      for (int i = 0; i < dow; i++)
         cout << "    ";
      for (int dom = 1; dom <= numOfDaysInMonth; dom++)
      {
         cout << setw(4) << dom;
         dow++;
         if (dow % 7 == 0)
            cout << endl;
      }
      if (dow % 7 != 0)
         cout << endl;
   }
}

/**********************************************************************
 * The main function will call all the functions to receive all the input
 * from the user 
**********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   int numOfDaysInMonth = getNumOfDaysInMonth(month, year);
   
   displayHeader(month, year);
   displayTable(offset, numOfDaysInMonth);
   return 0;
}
