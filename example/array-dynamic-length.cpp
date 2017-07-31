/*
# This code is designed in order to show how to use pointer
# to create a array of a certain length
# ATTENTION: The moment the array is created, the length is
# set and cannot be modified
*/

#include <iostream>

using namespace std;

int op;
int len;
int *arr = NULL;

void clear() {
    if (arr != NULL)
        delete []arr;
    else
        cout << "[warning]The array is empty already" << endl;
    arr = NULL;
    cout << "Cleared" << endl;
}

void show() {
    if (arr == NULL) {
        cout << "[invalid move]The array is empty" << endl;
        return;
    }
    for (int i = 0; i < len; ++i) {
        cout << arr[i];
        if (i != len - 1)
            cout << " ";
    }
    cout << endl;
}

void create(int l) {
    if (arr != NULL) {
        cout << "[warning]Existen data will be cleared"  << endl;
        clear();
    }
    arr = new int[l];
    for (int i = 0; i < l; ++i)
        arr[i] = i;
    cout << "The array of length " << l << " is created" << endl;
}

int main() {
    cout << "input a positive number not larger than 10e6 to set the length of the array" << endl;
    cout << "input 0 to show the array" << endl;
    cout << "input -1 to clear the array" << endl;
    cout << "input -2 to quit" << endl;
    while (1) {
        cin >> op;
        switch (op) {
            case -2 : break;
            case -1 :
                clear();
                break;
            case 0 :
                show();
                break;
            default :
                len = op;
                create(len);
                break;
         }
         if (op == -2)
            break;
     }
     return 0;
 }
