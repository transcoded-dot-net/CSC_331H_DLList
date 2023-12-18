//
// Created by Eleanor Heaton on 12/16/23.
//

#include "Large_Int.h"
#include "Doubly_Linked_List.h"

void Large_Int::operator+(Large_Int &other) {
    // set initial values
    int valueA = number.iterator_get_value();
    int valueB = other.number.iterator_get_value();
    bool carry = false;
    // get us to starting point
    number.iterator_backwards();
    other.number.iterator_backwards();
    // while loop for until one number will stop existing
    while (number.get_iterator() != number.get_first() ||
    other.number.iterator != other.number.get_first()){ // i hate this line of code, but as of right now can't think of another way to do this :(
    }



}

void Large_Int::operator-(Large_Int &other) {

}

void Large_Int::operator*(Large_Int &other) {

}

void Large_Int::operator/(Large_Int &other) {

}

void Large_Int::operator%(Large_Int &other) {

}

void Large_Int::operator==(Large_Int &other) {

}

void Large_Int::operator<(Large_Int &other) {

}

void Large_Int::operator<=(Large_Int &other) {

}

void Large_Int::operator>(Large_Int &other) {

}

void Large_Int::operator>=(Large_Int &other) {

}

void Large_Int::operator>>(Large_Int &other) {

}

void Large_Int::operator<<(Large_Int &other) {

}

int *Large_Int::get_first() {
    return nullptr;
}

int *Large_Int::get_iterator() {
    return number.iterator;
}

template<class T>
int* Large_Int::get_last() {
    return last;
}
template<class T>
int* Doubly_Linked_List<T>::get_first() {
    return first;
}
template<class T>
int* Doubly_Linked_List<T>::get_iterator() {
    return iterator;
}
