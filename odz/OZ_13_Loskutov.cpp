#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set<char> signs = {'.', ',', ';', ':', '!', '?', '-', '(', ')', '"'};
    set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l','m', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K','L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    set<char> signsInStr;
    int cVows, cCons = 0;
    int cNums, cLetters = 0;
    string s;
    while(s.empty()){
        cout << "Введите строку s: "; getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if(numbers.find(s[i]) != numbers.end()){
                cNums += 1;
            }else if(vowels.find(s[i]) != vowels.end()){
                cVows += 1;
                cLetters += 1;
            }else if(consonants.find(s[i]) != consonants.end()){
                cCons += 1;
                cLetters += 1;
            }else if(signs.find(s[i]) != signs.end()){
                signsInStr.insert(s[i]);
            }else{
                cout << "В строке есть недопустимый символ.\n";
                s.clear();
            }
        }
    }
    if(cNums > cLetters){
        cout << "Цифр больше, чем букв.\n";
    }else if(cNums < cLetters){
        cout << "Букв больше, чем цифр\n";
    }else{
        cout << "Количество букв равно кол-ву цифр.\n";
    }
    cout << "Кол-во гласных = " << cVows << endl;
    cout << "Кол-во согласных = " << cCons << endl;
    
    if(!(signsInStr.empty())){
        cout << "В строке были следующие знаки ";
        for(char sign : signsInStr){
            cout << sign << ' ';
        }
    }else{
        cout << "В строке не было знаков.\n";
    }
    return 0;
}
