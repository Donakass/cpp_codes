#include <iostream>

using namespace std;

struct circle {
    int data;
    circle* next;
};

void createCircle(circle*& head, int n) {
    if (n <= 0) return;

    circle* last = nullptr;
    for (int i = 0; i < n; i++) {
        circle* kid = new circle;
        kid->data = i + 1;
        if (head == nullptr) {
            head = kid;
        } else {
            last->next = kid;
        }
        last = kid;
    }
    last->next = head;
}

void printCircle(circle* head, int n) {
    circle* temp = head;
    cout << "Круг: ";
    for (int c = 0; c < n; c++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << ' ';
}

void playGame(circle*& head, int k, int n) {
    circle* temp = head;
    while (n > 1) {
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        circle* toDelete = temp->next;
        if (toDelete == head) {
            head = toDelete->next;
        }
        temp->next = toDelete->next;
        delete toDelete;
        n--;
        temp = temp->next;
        printCircle(head, n);
        cout << "Ведущий: " << temp->data << endl;
    }
    cout << "Победитель: " << head->data << endl;
}

int main() {
    int k;
    int n;

    do {
        cout << "Введите размер считалочки (k): ";
        cin >> k;
        cout << "Введите количество человек в круге (n): ";
        cin >> n;
    } while (n < k);

    circle* head = nullptr;
    createCircle(head, n);
    printCircle(head, n);
    cout << endl;
    playGame(head, k, n);

    return 0;
}