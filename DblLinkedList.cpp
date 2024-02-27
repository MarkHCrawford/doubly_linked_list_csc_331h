#include "DblLinkedList.h"

/***************************************************************/
/* Programmer: Mark Crawford                                    */     
/* Date: February 24, 2024                                      */    
/* Purpose:  Header for Unsorted Double Linked List             */ 
/* Class: CSC350H, Professor Salvati                            */
/***************************************************************/

// Constructor
template <class T>
DblLinkedList<T>::DblLinkedList()
{
   head = nullptr;
   tail = nullptr;
   length = 0;
}

// Destructor
template <class T>
DblLinkedList<T>::~DblLinkedList()
{
    destroy();
}

// Copy Constructor
template <class T>
DblLinkedList<T>::DblLinkedList( const DblLinkedList<T> &other)
{
    copy(other);
}

// Overload equality assignment
template <class T>
const DblLinkedList<T>& DblLinkedList<T>::operator= (const DblLinkedList<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

// Return length of list
template <class T>
int DblLinkedList<T>::getLength()
{
    return length;
}

// True if list is empty
template <class T>
bool DblLinkedList<T>::isEmpty()
{
    return head == nullptr;
}

// Insert item at front of double linked list
template <class T>
void DblLinkedList<T>::insertItemFront(T item)
{
    node<T> *newNode = new node<T>;
    newNode->info = item;
    newNode->next = head;
    newNode->previous = nullptr;
    if (head != nullptr)
    {
        head->previous = newNode;
    }
    head = newNode;
    if (tail == nullptr)
    {
        tail = newNode;
    }
    length++;
}

// Insert item at back of double linked list
template <class T>
void DblLinkedList<T>::insertItemBack(T item) {
    node<T>* newNode = new node<T>;
    newNode->info = item;

    // Handle empty list case
    if (tail == nullptr) {
        newNode->next = nullptr;
        newNode->previous = nullptr;
        head = newNode;
        tail = newNode;
    } else {
        // Regular insertion at the back
        newNode->next = nullptr;
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}

// Delete item from double linked list
template <class T>
void DblLinkedList<T>::deleteItem(T item)
{
    node<T> *current = head;
    node<T> *prev = nullptr;
    bool found = false;
    while (current != nullptr && !found)
    {
        if (current->info == item)
        {
            found = true;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    if (found)
    {
        length--;
        if (prev == nullptr)
        {
            head = current->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            else
            {
                head->previous = nullptr;
            }
            delete current;
        }
        else
        {
            prev->next = current->next;
            if (current->next == nullptr)
            {
                tail = prev;
            }
            else
            {
                current->next->previous = prev;
            }
            delete current;
        }
    }
    else
    {
        cout << "Item not found in list." << endl;
    }
}

// Search for item in double linked list
template <class T>
bool DblLinkedList<T>::searchItem(T item)
{
    node<T> *current = head;
    bool found = false;
    while (current != nullptr && !found)
    {
        if (current->info == item)
        {
            found = true;
        }
        else
        {
            current = current->next;
        }
    }
    return found;
}

// Print the list
template <class T>
void DblLinkedList<T>::printList()
{
    if (!isEmpty())
    {
        node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->info << " ";
            current = current->next;
        }
    }
    else
    {
        cout << "List is empty." << endl;
    }
}

// Copy used for copy constructor
template <class T>
void DblLinkedList<T>::copy(const DblLinkedList<T> &other)
{
    head = tail = nullptr;
    length = 0;
    node<T> *current = other.head;
    while (current != nullptr)
    {
        insertItemBack(current->info);
        current = current->next;
    }
}

// Destroy double linked list
template <class T>
void DblLinkedList<T>::destroy()
{
    node<T> *current = head;
    node<T> *temp;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}
