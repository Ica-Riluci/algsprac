/*
# This code is to show the construction of a linked list
# [by Ica Riluci]
*/
#include <iostream>

using namespace std;

int ccnter = 0, scnter = 0;

class nodec {
public :
    nodec() : prev(this), next(this) {}

public :
    nodec *next, *prev;
    int data;
};

struct nodes {
    int data;
    struct nodes *next, *prev;
    nodes() {
        next = this;
        prev = this;
    }
};

void insertd(int d, int index = 0) {
    nodec *ptrc = guardc;
    struct nodes *ptrs = guards;
    for (int i = 0; i < index; ++i) {
        if (ptrc->next == guard) {
            cout << "[invalid move]index not in range" << endl;
            return;
        }
        ptrc = ptrc->next;
        ptrs = ptrs->next;
    }
    nodec *newptrc = new nodec();
    newptrc.data = d;
    newptrc->prev = ptrc;
    newptrc->next = ptrc->next;
    ptrc->next->prev = newptrc;
    ptrc->next = newptrc;
    struct nodes *newptrs = new nodes();
    newptrs.data = d;
    newptrs->prev = ptrs;
    newptrs->next = ptrs;
    ptrs->next->prev = newptrs;
    ptrs->next = newptrs;
}

nodec *guardc = new nodec();
struct nodes *guards = new nodes();

int main() {
    //only an example
    return 0;
}
