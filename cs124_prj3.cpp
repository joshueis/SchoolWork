#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string.h>
using namespace std;
#define MAX_DIGITS 10
#define MAX_WORD_LENGTH 5

const int MAX_NUM_CHOICES = 3 * 3 * 3 * 3 * 3;
void prompt(const char * prompt, char keyFile[]);
void readKeyFile(char * keyFile, char key[][4]);
void showMenu(bool showWelcome);
int getMenuChoice(char key[][4]);

void encode(char key[][4], char * data);
void decode(char key[][4], char * data);
void convert(char key[][4], char * val);
void getOne(char key[][4], char * val);
void getTwo(char key[][4], char * val);
void getThree(char key[][4], char * val);
void getFour(char key[][4], char * val);
void getFive(char key[][4], char * val);
void getWhich(char temp[][MAX_WORD_LENGTH +1],
              int numChoices, char * val, char key[][4]);
/************************************************************
 * This is our driver, it will run our program
 * 
**************************************************************/
int main()
{
   char file[256];
   char msg[] = "Please enter key file: ";
   char key[MAX_DIGITS][4];
   prompt(msg, file);
   readKeyFile(file, key);
   showMenu(true);
   while(getMenuChoice(key));
   
   return 0;
}

/************************************************************
 * This function will prompt the user what we require
 * 
**************************************************************/
void prompt(const char *prompt, char keyFile[])
{
   cout << prompt;
   //cin.ignore();
   cin.getline(keyFile, 256);
   
}

/************************************************************
 * This function will show the welcome menu for the fist time
 * and will show the menu options
 * 
**************************************************************/
void showMenu(bool showWelcome)
{
   if (showWelcome)
   {
      cout << endl;
      cout << "Welcome to icodec" << endl;
      cout << "-----------------" << endl;
   }
   cout << "1. Encode\n"
        << "2. Decode\n"
        << "3. Menu\n"
        << "4. Quit\n";
}

/************************************************************
 * readKeyFile is going to read the file, and store it in 
 * a new char array
**************************************************************/
void readKeyFile(char * keyFile, char key[][4])
{
   ifstream inFile(keyFile);
   if (inFile.fail())
   {
      cout << "Key file does not exist!\n";
      exit(1);
   }
   char temp1;
   char temp2;
   for ( int a = 0; a < MAX_DIGITS; a++)
   {
      key[a][0] = '\0';
      key[a][1] = '\0';
      key[a][2] = '\0';
      key[a][3] = '\0';
   }
   int i = 0;
   while (inFile >> temp1 >> temp2)
   {
      int k = 0;
      while(key[temp2 - '0'][k] != '\0')
      {
         k++;
      }
      key[temp2 - '0'][k] = temp1;
      i++;
   }
   inFile.close();
   if (i != 26)
   {
      cout << "Key file is formatted incorrectly.\n";
      exit(1);
   }
}

/************************************************************
 * this function decides what are we doing depending on the
 * users imput, it will call all the other options 
 * 
**************************************************************/
int getMenuChoice(char key[][4])
{
   char num = '0';
   char data[256];

   cout << "> ";
   cin >> num;
   cin.ignore();

   switch (num)
   {
      case '1':
         prompt("Please enter message to encode: ", data);
         encode(key, data);
         cout << "\nEncoded message: " << data << endl;
         break;
      case '2':
         prompt("Please enter message to decode: ", data);
         decode(key, data);
         cout << "\nDecoded message: " << data << endl;
         break;
      case '3':
         cout << "\n";
         showMenu(false);
         break;
      case '4':
         return 0;
      default:
         cout << "You entered an invalid option\n";
         break;
   }
   return 1;
}

/******************************************************************
 * This function will read the message from the user and will
 * return the corresponding number for each letter, by using our key
 * 
**************************************************************/
void encode(char key[][4], char * data)
{
   for (int i = 0; data[i]; i++)
   {
      // cerr << data[i];
      if (data[i] != ' ')
      {
         for (int j = 0; j < 10; j++)
         {
            for (int k = 0; k < 4; k++)
            {
               if (toupper(data[i]) == key[j][k])
                  data[i] = j + '0';
            }
         }
      }
      else
         data[i] = ' ';
   }
}

/************************************************************
 * This function will decode the user's message
 * 
**************************************************************/
void decode(char key[][4], char * data)
{
   convert(key, data);
}

/************************************************************
 * This function will  
 * 
**************************************************************/
void convert(char key[][4], char * val)
{
   int count = 0;
   for (int i = 0;i < strlen(val); i++)
   {
      if (val[i] == ' ')
         count++;
   }
   count++;
   char words[count][MAX_WORD_LENGTH];
   int a = 0;
   int b = 0;
   for (int i = 0; i < strlen(val); i++)
   {
      if (val[i] == ' ')
      {
         words[b][a] = '\0';
         a = 0;
         b++;
      }
      else
      {
         words[b][a] = val[i];
         a++;
      }
   }
   words[b][a] = '\0';
   //cout << words[0] << endl << strlen(words[0]) << endl;
   
   for (int i = 0; i < count; i++)
   {
      //  cout << ' ';
      int wrdlngth = strlen(words[i]);
      
      cout << "\nValues for " << words[i] << ":\n";

      switch (wrdlngth)
      {
         case 1:
            getOne(key,words[i]);
            break;
         case 2:
            getTwo(key, words[i]);
            break;
         case 3:
            getThree(key, words[i]);
            break;
         case 4:
            getFour(key, words[i]);
            break;
         case 5:
            getFive(key, words[i]);
            break;
         default:
            cout << "1=N/A" << endl;
            break;
      }
   }
   int j = 0;
   for (int i = 0; i < count; i++, j++)
   {
      for (int k = 0; words[i][k]; k++, j++)
      {
         val[j] = words[i][k];
      }
      if (i != count - 1)
         val[j] = ' ';
      else
         val[j] = '\0';
   }
}
/********************************************************************
 * This function will compare a number (one leeter word) with the key,
 * and will return the possible options for that number.
 * 
**************************************************************/
void getOne(char key[][4], char val[])
{
   char temp[MAX_NUM_CHOICES][MAX_WORD_LENGTH +1];
   int numChoices = 0;

   char * key0 = key[val[0] - '0'];
   
   for (int i = 0; key0[i]; i++)
   {
      temp[numChoices][0] = key0[i];
      temp[numChoices][1] = '\0';
      numChoices++;
   }
   getWhich(temp, numChoices,val, key);
   
}

/************************************************************
 * This function will compare a two digit number (two leeters word)
 * with the key, and will return the possible options for that number.
 * 
**************************************************************/
void getWhich(char temp[][MAX_WORD_LENGTH +1],
              int numChoices,
              char * val,
              char key[][4])
{
   int userChoice;
   char decodedMsg[256];
   int size = 0;
   int wordSize = 0;
   for (int i = 0; i < numChoices; i++)
   {
      wordSize = 0;
      if(i == 0)
         cout << " ";
      if(i < 9)
         wordSize++;
      else if(i < 99)
         wordSize += 2;
      else
         wordSize += 3;
      wordSize += (2 + strlen(temp[i]));
      // size += wordSize;
      // cout << i + 1 << "-" << temp[i] << " ";
      if ((size + wordSize) > 80)
      {
         size = 0;
         cout << endl;
      }
      cout << i + 1 << "-" << temp[i];
      if (i != numChoices - 1)
         cout << " ";
      size += wordSize;
   }
   cout << endl << "Choose: > ";
   cin >> userChoice;
   
   for ( int i = 0; i < strlen(val); i++)
   {
      val[i] = temp[userChoice - 1][i];
   }
}

/************************************************************
 * This function will compare a two digit number (two letters word)
 * with the key, and will return the possible options for that number.
 * 
**************************************************************/
void getTwo(char key[][4], char * val)
{
   char temp[MAX_NUM_CHOICES][MAX_WORD_LENGTH +1];
   int numChoices = 0;
   
   char * key0 = key[val[0] - '0'];
   char * key1 = key[val[1] - '0'];
  
   for (int i = 0; key0[i]; i++)
      for (int j = 0; key1[j]; j++)
      {
         temp[numChoices][0] = key0[i];
         temp[numChoices][1] = key1[j];
         temp[numChoices][2] = '\0';
         numChoices += 1;
      }
   
   getWhich(temp, numChoices,val, key);
}

/************************************************************
 * This function will compare a three digit number (three letters word)
 * with the key, and will return the possible options for that number.
 * 
**************************************************************/
void getThree(char key[][4], char * val)
{
   char temp[MAX_NUM_CHOICES][MAX_WORD_LENGTH +1];
   int numChoices = 0;
   
   char * key0 = key[val[0] - '0'];
   char * key1 = key[val[1] - '0'];
   char * key2 = key[val[2] - '0'];
   for (int i = 0; key0[i]; i++)
      for (int j = 0; key1[j]; j++)
         for (int k = 0; key2[k]; k++)
         {
            temp[numChoices][0] = key0[i];
            temp[numChoices][1] = key1[j];
            temp[numChoices][2] = key2[k];
            temp[numChoices][3] = '\0';
            numChoices += 1;
         }
   getWhich(temp, numChoices,val, key);
}

/************************************************************
 * This function will compare a four digit number (four letters word)
 * with the key, and will return the possible options for that number.
 * 
**************************************************************/
void getFour(char key[][4], char * val)
{
   char temp[MAX_NUM_CHOICES][MAX_WORD_LENGTH +1];
   int numChoices = 0;
   
   char * key0 = key[val[0] - '0'];
   char * key1 = key[val[1] - '0'];
   char * key2 = key[val[2] - '0'];
   char * key3 = key[val[3] - '0'];
   for (int i = 0; key0[i]; i++)
      for (int j = 0; key1[j]; j++)
         for (int k = 0; key2[k]; k++)
            for (int l = 0; key3[l]; l++)
         {
            temp[numChoices][0] = key0[i];
            temp[numChoices][1] = key1[j];
            temp[numChoices][2] = key2[k];
            temp[numChoices][3] = key3[l];
            temp[numChoices][4] = '\0';
            numChoices += 1;
         }
   getWhich(temp, numChoices,val, key);
}

/************************************************************
 * This function will compare a five digit number (five letters word)
 * with the key, and will return the possible options for that number.
 * 
**************************************************************/
void getFive( char key[][4], char * val)
{
   char temp[MAX_NUM_CHOICES][MAX_WORD_LENGTH +1];
   int numChoices = 0;
   
   char * key0 = key[val[0] - '0'];
   char * key1 = key[val[1] - '0'];
   char * key2 = key[val[2] - '0'];
   char * key3 = key[val[3] - '0'];
   char * key4 = key[val[4] - '0'];
   for (int i = 0; key0[i]; i++)
      for (int j = 0; key1[j]; j++)
         for (int k = 0; key2[k]; k++)
            for (int l = 0; key3[l]; l++)
               for (int m = 0; key4[m]; m++)
         {
            temp[numChoices][0] = key0[i];
            temp[numChoices][1] = key1[j];
            temp[numChoices][2] = key2[k];
            temp[numChoices][3] = key3[l];
            temp[numChoices][4] = key4[m];
            temp[numChoices][5] = '\0';
            numChoices += 1;
         }
   getWhich(temp, numChoices,val, key);
}
