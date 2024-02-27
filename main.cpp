#include "DblLinkedList.cpp"
#include <iostream>

using namespace std;


/***************************************************************/
/* Programmer: Mark Crawford                                    */     
/* Date: February 24, 2024                                      */    
/* Purpose:  Main for Unsorted Double Linked List               */
/* Class: CSC350H, Professor Salvati                            */ 
/***************************************************************/



// Prototypes for test functions
void displayMenu();
void displayList(DblLinkedList<int> &list);
void insertItemFront(DblLinkedList<int> &list, int item);
void insertItemBack(DblLinkedList<int> &list, int item);
void deleteItem(DblLinkedList<int> &list, int item);
void searchItem(DblLinkedList<int> &list, int item);
void getLength(DblLinkedList<int> &list);
void isEmpty(DblLinkedList<int> &list);
void testCopy(DblLinkedList<int> &list);
void testAssignment(DblLinkedList<int> &list);
void stepForward(DblLinkedList<int> &list);
void stepBackward(DblLinkedList<int> &list);


int main()
{
    DblLinkedList<int> list;
    int choice;
    int item;

// Loop displays menu, gets user choice, continues until exit
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayList(list);
                break;
            case 2:
                cout << "Enter item to insert at front: ";
                cin >> item;
                insertItemFront(list, item);
                break;
            case 3:
                cout << "Enter item to insert at back: ";
                cin >> item;
                insertItemBack(list, item);
                break;
            case 4:
                cout << "Enter item to delete: ";
                cin >> item;
                deleteItem(list, item);
                break;
            case 5:
                cout << "Enter item to search for: ";
                cin >> item;
                searchItem(list, item);
                break;
            case 6:
                getLength(list);
                break;
            case 7:
                isEmpty(list);
                break;
            case 8:
                testCopy(list);
                break;
            case 9:
                testAssignment(list);
                break;
            case 10:
                stepForward(list);
                cout << "Stepped forward" << endl;
                break;
            case 11:
                stepBackward(list);
                cout << "Stepped backward" << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);





    return 0;
}


// Menu to be displayed
void displayMenu()
{
    cout << "\nSelect option and press enter: " << endl;
    cout << "1. Display List" << endl;
    cout << "2. Insert Item at beginning" << endl;
    cout << "3. Insert item at end" << endl;
    cout << "4. Delete Item" << endl;
    cout << "5. Search Item" << endl;
    cout << "6. Get Length" << endl;
    cout << "7. Is Empty" << endl;
    cout << "8. Test Copy" << endl;
    cout << "9. Test Assignment" << endl;
    cout << "10. Step Forward" << endl;
    cout << "11. Step Backward" << endl;
    cout << "0. Exit\n" << endl;
}


// Print current list values
void displayList(DblLinkedList<int> &list)
{
    list.printList();
}


// Front insert
void insertItemFront(DblLinkedList<int> &list, int item)
{
    list.insertItemFront(item);
}


// Back insert
void insertItemBack(DblLinkedList<int> &list, int item)
{
    list.insertItemBack(item);
}


// Delete selected item
void deleteItem(DblLinkedList<int> &list, int item)
{
    list.deleteItem(item);
}


// Search for item
void searchItem(DblLinkedList<int> &list, int item)
{
    if (list.searchItem(item))
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }
}

// Get current list length
void getLength(DblLinkedList<int> &list)
{
    cout << "Length of list: " << list.getLength() << endl;
}

// Check if list is empty
void isEmpty(DblLinkedList<int> &list)
{
    if (list.isEmpty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }
}

// Test copy constructor
void testCopy(DblLinkedList<int> &list)
{
    DblLinkedList<int> copy(list);
    cout << "Original list: " << endl;
    list.printList();
    cout << "Copied list: " << endl;
    copy.printList();
}

// Test overloaded equality assignment
void testAssignment(DblLinkedList<int> &list)
{
    DblLinkedList<int> copy;
    copy = list;
    cout << "Original list: " << endl;
    list.printList();
    cout << "Copied list: " << endl;
    copy.printList();
}


// Step forward
void stepForward(DblLinkedList<int> &list)
{
   DblLinkedList<int>::Iterator iter = list.setBegin();
    for (iter; iter != list.end(); ++iter)
    {
        cout << "Current data: " << *iter << endl;
    }
}

// Step backward
void stepBackward(DblLinkedList<int> &list)
{
    DblLinkedList<int>::Iterator iter = list.setEnd();
    for (iter; iter != list.end(); --iter)
    {
        cout << "Current data: " << *iter << endl;
    }
}