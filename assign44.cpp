/***********************************************************************
 * Program:
 *    Assignment 44, Linked lists
 *    Brother Burton, CS165
 * Author:
 *    Israel Carvajal
 * Summary:
 *    A linked list is similar to an array except adding items to the middle
 *    and removing items from the middle are much easier.  This assignment is
 *    meant to demonstrate linked lists.  Your job with this assignment is to
 *    convert the double linked list into a template linked list.
 *
 *    Estimated:  0.5 hrs
 *    Actual:     0.3 hrs
 *      Please describe briefly what was the most difficult part
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// simple linked list node
template <class T>
struct Node
{
   T  data;
   Node<T> * pNext;
};

/**************************************
 * REMOVE FROM HEAD
 * Remove the first item in a linked list
 *************************************/
template <class T>
void removeFromHead(Node<T> * & pHead)
{
   // 0. do nothing if there is nothing to do
   if (pHead == NULL)
      return;
   
   // 1. remember the second item
   Node<T> * pSave = pHead->pNext;

   // 2. delete the head
   delete pHead;

   // 3. make the head point to the second item
   pHead = pSave;
}

/**************************************
 * REMOVE
 * Remove a node from the list
 *************************************/
template <class T>
void remove(Node<T> * pPrevious)
{
   // 0. if the list is empty or there is just one item, use removeFromHead
   if (pPrevious == NULL || pPrevious->pNext == NULL)
      return;
   
   // 1. save the location of the item before the one we are deleting
   Node<T> * pDelete = pPrevious->pNext;

   // 2. update the pointer of pPrevious->pNext
   pPrevious->pNext = pDelete->pNext;

   // 3. delete the pointer at pDelete
   delete pDelete;
}

/**************************************
 * ADD TO HEAD
 * Add a new node to the head of the linked list
 **************************************/
template <class T>// <class I>
void addToHead (Node<T> * & pHead, T data)
{
   // 1. allocate and initialize create a new node
   Node<T> * pNew = new Node<T>;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. put pHead in line after the new node
   pNew->pNext = pHead;                  // set pNext, the old head of the list

   // 3. finally, pNew is the new head
   pHead = pNew;                         // pNew is the new head.  Note that
}                                        //    pHead is a pointer by-reference

/**************************************
 * ADD
 * Add an item to a linked list
 *************************************/
template <class T>// <class I>
void add(Node<T> * pNode,  T data)
{
   // 0. if the list is empty, use addToHead()
   if (pNode == NULL)
      return;
   
   // 1. create a new node
   Node<T> * pNew = new Node<T>;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. fix the pNext pointer from pNew to the spot after it in the list
   pNew->pNext = pNode->pNext;

   // 3. finally get pNode->pNext to point to pNew instead of the old node
   pNode->pNext = pNew;
}

/**********************************************
 * FIND NODE
 * Looking for a node based on the index.  Note
 * that the index is 1's based.  If there are
 * six items, then the valid indicies are 1..6.
 * Return pHead if no node exists there
 **********************************************/
template <class T>
Node <T>* findNode(Node<T> * pHead, int index)
{
   // search through the linked list
   for (Node<T> * p = pHead; p; p = p->pNext)
      if (--index == 0)                  // if we are at the desired spot...
         return p;                       // ...return the value

   return pHead;                         // return pHead if no node exists
}

/*****************************************
 * DISPLAY
 * Display the contents of a linked list
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const Node<T> * pHead)
{
   for (const Node<T> * p = pHead; p; p = p->pNext)
      out << p->data << ' ';
   return out;
}

/****************************************
 * EMPTY
 * Empty a linked list by deleting each Node
 ****************************************/
template <class T>
void empty(Node<T> * & pHead)
{
   for (Node<T> * p = pHead; p; p = p->pNext)
      delete p;
   pHead = NULL;
}

/************************************
 * FILL
 * Fill a linked list with user data
 ************************************/
template <class T>
void fill(Node<T> * & pHead)
{
   cout << "Enter five values to put in the linked list\n";

   // loop through the list
   for (int i = 1; i <= 5; i++)
   {
      // fetch the data
      T data;
      cout << "#" << i << ": ";
      cin  >> data;

      // insert onto the list
      if (i == 1 || pHead == NULL)
         addToHead(pHead, data);
      else
         add(findNode(pHead, i - 1), data);
   }
}

/**********************************************************************
 * MAIN
 * A simple driver program meant to exercise our linked list
 ***********************************************************************/
int main()
{
   int    position;            // the position of the node to be added/deleted
   string data;                // the data to be added to the list
   
   // first, create a linked list of data;
   Node<string> * pHead = NULL;
   fill(pHead);

   // next, display the contents of the list
   cout << "\n\tlist: " << pHead << endl;

   // delete an item
   cout << "Which item do you want to remove? ";
   cin  >> position;
   if (position == 1)
      removeFromHead(pHead);
   else
      remove(findNode(pHead, position - 1));

   // add an item
   cout << "\n\tlist: " << pHead << endl;
   cout << "Please specify a value: ";
   cin  >> data;
   cout << "Index after which " << data << " will be inserted: ";
   cin  >> position;
   if (position == 0 || pHead == NULL)
      addToHead(pHead, data);
   else
      add(findNode(pHead, position), data); 

   // the final state of the list
   cout << "\n\tlist: " << pHead << endl;
   
   // finally, delete the nodes
   empty(pHead);
   
   return 0;
}
