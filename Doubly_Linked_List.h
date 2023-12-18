#include <iostream>
using namespace std;

//
// Created by Eleanor Heaton on 9/25/23.
//

#ifndef DLLIST_ONELASTTRY_DOUBLY_LINKED_LIST_H
#define DLLIST_ONELASTTRY_DOUBLY_LINKED_LIST_H


template <class T>
struct node
{
    T info;
    node<T> *next;
    node<T> *previous;
};

template <class T>
class Doubly_Linked_List
{
private:
    node<T> *first;
    node<T> *last;
    node<T> *iterator = *last;
    int length;
public:
    //Constructor 
    Doubly_Linked_List();
    // Destructor
    ~Doubly_Linked_List();
    //Copy constructor
    explicit Doubly_Linked_List (Doubly_Linked_List<int> &other);
    //Overload the assignment operator
    Doubly_Linked_List<T> & operator= (Doubly_Linked_List<int> &other);
    //Returns current length of list
    int get_length();
    // Returns true if list is empty, false otherwise
    bool is_empty();
    // Inserts parameter item
    void insert_item(T item);
    //If list is not empty and parameter item is in the list,
    //removes item from the list and decrements length.
    //If list is empty or item is not in the list, prints error
    void delete_item(T item);
    //Returns true if parameter item is in the list, false otherwise
    bool search_item(T item);
    //Print all items in the list. Print message if list is empty.
    void print_list();
    //Print all items in the list (starting at end and going backwards). Print message if list is empty.
    void print_list_backwards();
    // function to copy a list
    void copy (Doubly_Linked_List<int> &other);
    // Destroy list function
    void destroy();
    // walks iterator forward
    void iterator_forward();

    //walks iterator backwards
    void iterator_backwards();


    //checks if next is null
    bool iterator_next_check();
    //checks if previous is null
    bool iterator_previous_check();

    // prints value of info
    void  iterator_print_value();

    // returns value of info
    int iterator_get_value();

    // checks if iterator is null
    bool iterator_null_check();


   friend int* get_last();

   friend int* get_first();

   friend int* get_iterator();
};




#endif //DLLIST_ONELASTTRY_DOUBLY_LINKED_LIST_H
