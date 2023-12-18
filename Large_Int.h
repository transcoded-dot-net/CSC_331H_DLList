//
// Created by Eleanor Heaton on 12/16/23.
//

#ifndef DLLIST_ONELASTTRY_LARGE_INT_H
#define DLLIST_ONELASTTRY_LARGE_INT_H


#include "Doubly_Linked_List.h"

class Large_Int {
private:
    bool negative = false;
    Doubly_Linked_List <int> number;
public:
// addition
    void operator+(Large_Int &other);

// subtraction
    void operator-(Large_Int &other);
// multiplication
    void operator*(Large_Int &other);
// division
    void operator/(Large_Int &other);
// remainder
    void operator%(Large_Int &other);

// equals
    void operator==(Large_Int &other);
// less
    void operator<(Large_Int &other);
// less or equal
    void operator<=(Large_Int &other);
// more
    void operator>(Large_Int &other);
// more or equal
    void operator>=(Large_Int &other);

// right shift
    void operator>>(Large_Int &other);
// left shift
    void operator<<(Large_Int &other);

    int* get_last();

    int* get_first();

    int* get_iterator();


};


#endif //DLLIST_ONELASTTRY_LARGE_INT_H
