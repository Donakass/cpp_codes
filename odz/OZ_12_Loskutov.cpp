#include <iostream>
#include <string>
#include <set>

using namespace std;

bool verifyInput(string inp){
    set<char> alphLower = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y', 'z'};
    set<char> alphUpper = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z'};
    if(alphUpper.find(inp[0]) == alphUpper.end()){
        cout << "Первая буква ФИО должна быть заглавной.\n";
        return false;
    }
    for(int i = 1; i < inp.length(); i++){
        if(alphUpper.find(inp[i]) != alphUpper.end()){
            cout << "В строке присутсвуют лишние заглавные буквы.\n";
            return false;
        }else if(alphLower.find(inp[i]) == alphLower.end()){
            cout << "В строке присутсвуют недопустимые символы.\n";
            return false;
        }
    }
    return true;
}

int main(){
    string name, surname, secondname;
    bool f1, f2, f3;
    do{
        cout << "Введите имя: "; getline(cin, name);
        f1 = verifyInput(name);
    }while(!f1);
    do{
        cout << "Введите фамилию: "; getline(cin, surname);
        f2 = verifyInput(surname);
    }while(!f2);
    do{
        cout << "Введите отчество: "; getline(cin, secondname);
        f3 = verifyInput(secondname);
    }while(!f3);
    cout << "Ваше ФИО: " << name << ' ' << surname << ' ' << secondname;
    return 0;
}