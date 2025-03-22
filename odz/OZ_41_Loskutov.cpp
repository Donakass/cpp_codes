#include <iostream>
#include <string>

using namespace std;

struct Elem {
    char data;
    Elem* next;
};

Elem* p_begin = nullptr;

void createStack(string s) {
    for (char c : s) {
        Elem* new_elem = new Elem;
        new_elem->data = c;
        new_elem->next = p_begin;
        p_begin = new_elem;
    }
    cout << "Стек создан." << endl;
}

void printStack(Elem* p_begin) {
    cout << "Стек: ";
    while (p_begin != nullptr) {
        cout << p_begin->data;
        Elem* temp = p_begin;
        p_begin = p_begin->next;
        delete temp;
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    createStack(s);
    printStack(p_begin);
    return 0;
}