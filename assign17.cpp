/***********************************************************************
* Program:
*    Assignment 17, Ceasar Cipher
*    Brother Burton, CS165
* Author:
*    Israel Carvajal
* Summary: 
*    This program is designed to store a secret message.  The message
*    is encrypted using the Caesar Cipher: a simple cipher that simply
*    adds 3 to ASCII value of the message.  For example, if the plain-text
*    message is "SECRET", the cipher text is "VHFUHW" because
*                 'V' = 'S' + 3
*                 'H' = 'E' + 3
*                 ...
*    Thus, if I am to decrypt the message, I simply subtract three from
*    each letter.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.0 hrs
*      It was hard to remeber how to pass the char array, and set the second
*      condition in the for loop as i did
************************************************************************/

#include <iostream>
using namespace std;
int getKey(int & key);
bool keyCorrect(int key);
void convert(char  * message, int key);
void display(char  message[]);

/**********************************************************************
 * MAIN: This function calls 4 functions:
 *    getKey:     Prompt the user for the secret key
 *    keyCorrect: Determines if the user's guess is correct
 *    convert:    Convert our cipher text to plain text so the world can see
 *    display:    Display the converted message
 ***********************************************************************/
int main()
{
   // the key the user will guess
   int key;
   // the top secret message
   char message[] = "Fdhvdu#Flskhu#zdv#lqyhqwhg#durxqg#93EF";  

   // keep looping until the user guesses the key (ssshh!!  it is '3')
   do
      getKey(key);
   while (!keyCorrect(key));

   // convert the top secret message to the plain-text message
   convert(message, key);

   // show the user
   display(message);
      
   return 0;
}
int getKey(int & key)
{
   cout << "Please enter the key to decrypt the message: ";
   cin >> key;
}
bool keyCorrect(int key)
{
   if (key == 3)
   {
      return true;
   }
   else
      cout << "Incorrect!  Try again\n";
      return false;
}
void convert(char message[], int key)
{
   for (int i = 0; message[i]; i++)
   {
      message[i] = message[i] - key;
   }
}
void display(char message[])
{
   cout << "The translated message is: \"";
   for (int i = 0; message[i]; i++)
   {
      cout << message[i];
   }
   cout << "\"\n"; 
}
