//
//Created by Eleanor Heaton on 9/25/23.
//

#include "Doubly_Linked_List.h"
#include <iostream>
template <class T>
Doubly_Linked_List<T> ::Doubly_Linked_List() {
    length = 0;
}

template<class T>
Doubly_Linked_List<T>::~Doubly_Linked_List() {
    destroy();
}

template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List(Doubly_Linked_List<int> &other) {
    copy (other);
}

template<class T>
Doubly_Linked_List<T> & Doubly_Linked_List<T>::operator=(Doubly_Linked_List<int> &other) {
    if ( this != &other )
    {
        destroy ();
        copy (other);
    }
    return *this;
}

template<class T>
int Doubly_Linked_List<T>::get_length() {
    return length;
}

template<class T>
bool Doubly_Linked_List<T>::is_empty() {
    return length==0;
}

template<class T>
void Doubly_Linked_List<T>::insert_item(T item) {
    iterator = new node<T>;
    iterator->info = item;
    if (is_empty()){ // creation of first item in list
        first = iterator;
        last = iterator;
    }

    else if (length == 1) { //
        last = iterator;
        first->previous = last;
        first->next = last;
        last->previous = first;
        last->next = first;
    }
    else {
        iterator->next = first;
        iterator->previous = last;

        node<T>* replacement = last;
        replacement->previous = last->previous;
        last = iterator;
        last->previous = replacement;
        first->previous = last;
        replacement->next = last;


    }
    length++;
}

template<class T>
void Doubly_Linked_List<T>::delete_item(T item) {
    if ( is_empty() || !search_item(item))
        cout<<"LIST EMPTY OR ITEM NOT IN THE LIST\n";
    else {
        if (item == first->info){
            if (length == 1) {
                first == NULL;
                last==NULL;
            }
            else if (length >= 2) {
                iterator = first;
                first = first->next;
                delete iterator;
                first->next = NULL;
                first->previous = NULL;
                last->next = first;
            }
        }

        else {
            if (length == 2){
                first->next = NULL;
                first->previous = NULL;
                delete last;
                last = first;
            }
            else {
                iterator = first->next;
                while (iterator->info != item) {
                    iterator_forward();
                }
                node<T> * temporary_pointer = iterator;
                iterator_forward();
                iterator->previous = temporary_pointer->previous;
                iterator = temporary_pointer->previous;
                iterator->next = temporary_pointer-> next;
                delete temporary_pointer;
            }
        }
        length--;
    }
}

template<class T>
bool Doubly_Linked_List<T>::search_item(T item) {
    iterator = first;
    if(iterator != NULL){
        if (iterator->info == item)
            return true;
        else if (iterator_next_check())
            iterator_forward();
        while (iterator != first)
        {
            if (iterator->info == item )
                return true;
            iterator_forward();
        }
    }


    return false;
}

template<class T>
void Doubly_Linked_List<T>::print_list() {
    if ( is_empty())
        cout<<"\nEMPTY LIST\n";
    else
    {
        cout<<"\nLIST :";
        iterator = first;
        iterator_print_value();
        iterator_forward();
        while ( iterator != first && iterator != NULL)
        {
            iterator_print_value();
            iterator_forward();
        }
    }
}

template<class T>
void Doubly_Linked_List<T>::print_list_backwards() {
    if ( is_empty())
        cout<<"\nEMPTY LIST\n";
    else
    {
        cout<<"\nLIST :";
        iterator = last;
        iterator_print_value();
        iterator_backwards();
        while ( iterator != last && iterator != NULL)
        {
            iterator_print_value();
            iterator_backwards();
        }
    }
}

template<class T>
void Doubly_Linked_List<T>::copy(Doubly_Linked_List<int> &other) {
length = other.length;
    if ( other.is_empty() )
        first = NULL;
    else{
        first = other.first;
        if (length != 1) {
            other.iterator = other.first->next;
            while (other.iterator != first){
                insert_item(other.iterator->info);
                other.iterator_forward();
            }
        }
    }
}

template<class T>
void Doubly_Linked_List<T>::destroy() {
    while (first!=NULL) {
        iterator = first;
        first = first->next;
        delete iterator;
    }
}

template<class T>
void Doubly_Linked_List<T>::iterator_forward() {
if (iterator_next_check())
    iterator = iterator->next;
}

template<class T>
void Doubly_Linked_List<T>::iterator_backwards() {
    if (iterator_previous_check())
        iterator = iterator->previous;
}

template<class T>
bool Doubly_Linked_List<T>::iterator_next_check() {
    if (iterator->next != NULL)
        return true;
    return false;
}

template<class T>
bool Doubly_Linked_List<T>::iterator_previous_check() {
    if (iterator->previous != NULL)
        return true;
    return false;
}

template<class T>
void Doubly_Linked_List<T>::iterator_print_value() {
    cout << iterator->info << " ";
}

template<class T>
bool Doubly_Linked_List<T>::iterator_null_check() {
    if (iterator != NULL)
        return true;
    return false;
}

template<class T>
int Doubly_Linked_List<T>::iterator_get_value() {
    return iterator->info;
}
template<class T>
int Doubly_Linked_List<T>::get_last() {
    return last;
}
template<class T>
int Doubly_Linked_List<T>::get_first() {
    return first;
}
template<class T>
friend int Doubly_Linked_List<T>::get_iterator() {
    return iterator;
}


