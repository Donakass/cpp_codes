#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <string>

using namespace std;

struct Element {
    int value;
    Element* next;
};

void menu(){
    cout << "Выберите действие:" << endl;
    cout << "1. Создать список" << endl;
    cout << "2. Распечатать список" << endl;
    cout << "3. Удаление всего списка" << endl;
    cout << "4. Добавить элемент в список" << endl;
    cout << "5. Удалить элемент из списка" << endl;
    cout << "0. Выход" << endl;
}

void printList(Element* head) {
    Element* current = head;
    cout << endl;
    if(current){ 
        cout << "Cписок: " << endl;   
        while(current != nullptr){
            cout << current->value << " ";
            current = current->next;
        }
    }else{
        cout << "Список пуст" << endl;
    }
    cout << endl << endl;
}

void deleteList(Element* &head) {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp;
    }
}

void createList(Element* &head, int n) {
    cout << endl;
    if (head != nullptr) {
        string answer;
        cout << "Список уже существует, при создании нового он будет удален. \nВы хотите продолжить? (y/n): ";
        cin >> answer;
        if (answer == "y") {
            deleteList(head);
            head = nullptr;
        } else {
            cout << "Создание списка отменено" << endl << endl;
            return;
        }
    }
    if(n >= 0){    
        head = new Element;
        Element* current = head;
        for(int i = 0; i < n; i++){
            current->value = rand() % 100;
            if(i != n - 1){
                current->next = new Element;
                current = current->next;
            } else {
                current->next = nullptr;
            }
        }
        cout << "Список создан" << endl << endl;
        printList(head);
    } else {
        cout << "Количество элементов должно быть неотрицательным" << endl;
    }
    
}

void createElementInPosition(Element* &head, int value, int position){
    Element* current = head;
    if (position < 1) {
        cout << "Позиция должна быть больше 0" << endl;
        return;
    }
    if(current){
        if(position == 1){
            Element* newElement = new Element;
            newElement->value = value;
            newElement->next = head;
            head = newElement;
        } else {
            for(int i = 0; i < position; i++){
                if(i == position - 2){
                    Element* newElement = new Element;
                    newElement->value = value;
                    newElement->next = current->next;
                    current->next = newElement;
                    break;
                }
                if(current->next == nullptr){
                    cout << "Позиция вне диапазона, элемент будет добавлен в конец." << endl;
                    Element* newElement = new Element;
                    newElement->value = value;
                    newElement->next = nullptr;
                    current->next = newElement;
                    break;
                }
                current = current->next;
            }
        }
    } else {
        cout << "Список пуст, будет создан список из одного элемента" << endl;
        head = new Element;
        head->value = value;
        head->next = nullptr;
    }
    cout << "Элемент добавлен" << endl;
    cout << endl;
    printList(head);
}                
        
void deleteElementInPosition(Element* &head, int position){
    Element* current = head;
    if (position < 1) {
        cout << "Позиция должна быть больше 0" << endl;
        return;
    }
    if(current){
        if(position == 1){
            Element* temp = head;
            head = head->next;
            delete temp;
        } else {
            for(int i = 0; i < position; i++){
                if(i == position - 2){
                    Element* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    break;
                }
                if(current->next == nullptr){
                    cout << "Позиция вне диапазона" << endl;
                    break;
                }
                current = current->next;
            }
        }
    } else {
        cout << "Список пуст" << endl;
    }

    printList(head);
}

int main(){
    int choice = -1;
    Element* head = nullptr;
    srand(time(0)); 

    while(choice != 0){
        menu();
        cin >> choice;
        switch(choice){
            case 1: {
                int n;
                cout << endl;
                cout << "Введите количество элементов: ";
                cin >> n;
                createList(head, n);
                break;
            }
            case 2: {
                Element* current = head;
                printList(head);
                break;
            }
            case 3: {
                deleteList(head);
                head = nullptr;
                cout << endl << "Список удален" << endl;
                break;
            }
            case 4: {
                int value, position;
                cout << endl;
                cin >> value;
                cout << endl << "Введите позицию элемента: ";
                cin >> position;
                createElementInPosition(head, value, position);
                break;
            }
            case 5: {
                int position;
                cout << endl;
                cout << "Введите позицию элемента для удаления: ";
                cin >> position;
                deleteElementInPosition(head, position);
                cout << "Элемент удален" << endl;
                break;
            }
            case 0: {
                deleteList(head);
                return 0;
            }
        }
    }
}