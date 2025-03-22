#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct queue{
    int data;
    queue* next;
};

void addPerson(queue*& head, queue*&end, int value) {
    queue* newPerson = new queue;
    newPerson->data = value;
    newPerson->next = nullptr;

    if (head == nullptr) {
        head = newPerson;
        end = newPerson;
    } else {
        end->next = newPerson;
        end = newPerson;
    }
}

void removePerson(queue*& head){
    queue* temp = head;
    head = head->next;
    delete temp;
}

void printQueue(queue* head) {
    queue* temp = head;
    cout << "Очередь: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    queue* head = nullptr;
    queue* end = nullptr;
    int n;
 
    do {
        cout << "Введите изначальное количество человек в очереди (1 <= n <= 50): ";
        cin >> n;
    } while ((n < 1) || (n > 50));

    for(int i = 1; i < n+1; i++){
        addPerson(head, end, i);
    }

    printQueue(head);

    int c = 0;

    while (head != nullptr) {
        int r = rand() % 4;
        if (r == 0) {     
            n = n + 1;
            addPerson(head, end, n);
            printQueue(head);
        } else {
            removePerson(head);
            printQueue(head);
        }
        c++;
    }

    cout << "Очередь закончилась спустя " << c << " операций." << endl;
    return 0;
}