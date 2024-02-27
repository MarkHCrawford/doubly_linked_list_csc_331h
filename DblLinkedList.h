#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Mark Crawford                                    */     
/* Date: February 24, 2024                                      */    
/* Purpose:  Header for Unsorted Double Linked List             */ 
/* Class: CSC350H, Professor Salvati                            */
/***************************************************************/

#ifndef DBLLINKEDLIST_H
#define DBLLINKEDLIST_H

template <class T>
struct node
{
   T info;
   node<T> *next;
   node<T> *previous;
};

template <class T>
class DblLinkedList 
{
   private:
      node<T> *head;
      node<T> *tail; 
      int length;

   public:
      //Constructor 
      DblLinkedList();

      // Destructor
      ~DblLinkedList();

      //Copy constructor
      DblLinkedList ( const DblLinkedList<T> & other);

      //Overload the assignment operator 
      const DblLinkedList<T> & operator= (const DblLinkedList<T> & other);

      //Returns current length of list
      int getLength();

      // Returns true if list is empty, false otherwise
      bool isEmpty();

      // Insert item at front
      void insertItemFront(T item);

      // Insert item at back
      void insertItemBack(T item);

      //Delete selected item
      void deleteItem(T item);

      //Search list for item
      bool searchItem(T item);

      //Print list, notify if empty
      void printList();

      // Copy for copy constructor
      void copy (const DblLinkedList<T> & other);

      // Destroy list function for destructor
      void destroy();
      
      
    //Iterator class
    class Iterator 
    {
        private:
            node<T>* current;

        public:
            Iterator(node<T>* node) {this->current = node;}

        // overload dereference to return value at location
            T& operator*() { return current->info; }

        // overload increment
            Iterator& operator++() 
            {
                if (current) 
                {
                    current = current->next;
                }
                return *this;
            }

        // overload decrement
            Iterator& operator--() 
            {
                if (current) 
                {
                    current = current->previous;
                }
                return *this;
            }

        // for comparing begin != end
            bool operator!=(const Iterator& other) const 
            {
                return current != other.current;
            }
     };

  // Class methods to obtain iterators
  Iterator setBegin() { return Iterator(head); }
  Iterator setEnd() { return Iterator(tail); }
  Iterator end() { return Iterator(nullptr); }
};

#endif