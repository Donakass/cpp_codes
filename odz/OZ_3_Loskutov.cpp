#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Elem{
    int data;
    Elem* next;
};

Elem* p_begin;
Elem* p;
Elem* h;

void deleteList(){
    while (p_begin != NULL){
        p = p_begin;
        p_begin = p_begin->next;
        delete p;
    }
    h = NULL;
}

void create(){
    if(p_begin){
        char answer;
        cout << "Список уже существует, при создании нового он будет удален. \nВы хотите продолжить? (y/n): ";
        cin >> answer;
        switch(answer){
            case 'y':
                deleteList();
                break;
            break;
            case 'n':
                cout << "Список не был создан" << endl;
                return;
            default:
                cout << "Неправильная опция." << endl;
                return;
        }
    }

    int length;
    cout << "Введите длину списка: ";
    cin >> length;

    if (length < 2) {
        cout << "Длина списка должна быть больше 2" << endl;
        return;
    }

    srand(time(0));
    p_begin = new Elem;
    p_begin->data = rand() % 100 + 1;
    p_begin->next = NULL;
    h = p_begin;

    for (int i = 1; i < length; i++) {
        p = new Elem;
        p->data = rand() % 100 + 1;
        p->next = NULL;
        h->next = p;
        h = p;
    }
}

void addEl(int data, int position){
    Elem* newElem = new Elem;
    newElem->data = data;
    newElem->next = NULL;

    if (position <= 1 || p_begin == NULL) {
        newElem->next = p_begin;
        p_begin = newElem;
        if (h == NULL) {
            h = newElem;
        }
    } else {
        p = p_begin;
        for (int i = 1; i < position - 1 && p->next != NULL; i++) {
            p = p->next;
        }
        newElem->next = p->next;
        p->next = newElem;
        if (newElem->next == NULL) {
            h = newElem;
        }
    }
}

void print(){
    p = p_begin;
    cout << "Список: " << endl;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl << endl;
}

void deleteEl(int position) {
    if (p_begin == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    if (position < 1) {
        cout << "Позиция не может быть меньше одного." << endl;
        return;
    }
    if (position == 1) {
        Elem* temp = p_begin;
        p_begin = p_begin->next;
        delete temp;
        if (p_begin == NULL) {
            h = NULL;
        }
        return;
    } else {
        p = p_begin;
        for (int i = 1; i < position - 1 && p->next != NULL; i++) {
            p = p->next;
        }
        if (p->next == NULL) {
            cout << "Позиция вне диапазона" << endl;
            return;
        }
        Elem* temp = p->next;
        p->next = p->next->next;
        delete temp;
        if (p->next == NULL) {
            h = p;
        }
    }
}


int main(){
    int choice = -1;
    while(choice != 0){
        cout << "Выберите действие:" << ' ';
        cout << "1. Создать список" << ' ';
        cout << "2. Добавить элемент" << ' ';
        cout << "3. Удалить элемент" << ' ';
        cout << "4. Вывести список" << ' ';
        cout << "5. Удалить список" << ' ';
        cout << "0. Выход" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                create();
                print();
                break;
            case 2:
                int data2, position;
                cout << "Введите данные для нового элемента: ";
                cin >> data2;
                cout << "Введите позицию для нового элемента: ";
                cin >> position;
                addEl(data2, position);
                print();
                break;
            case 3:
                int position2;
                cout << "Введите позицию элемента для удаления: ";
                cin >> position2;
                deleteEl(position2);
                print();
                break;
            case 4:
                print();
                cout << endl;
                break;
            case 5:
                deleteList();
                break;
            case 0:
                deleteList();
                break;
            default:
                cout << "Неправильный ввод." << endl;
                break;
        }
    }
    return 0;
}