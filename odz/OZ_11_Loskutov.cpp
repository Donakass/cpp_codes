#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    set<char> toCount = {'1','2','3','4','5','6','7','8','9','0','-','+','*'};
    set<char> lowercase = {'1','2','3','4','5','6','7','8','9','0','-','+','*','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    set<char> uppercase = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string s;
    int c = 0;
    
    while(s.empty()){
        cout << "Введите строку S: "; 
        getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if(lowercase.find(s[i]) == lowercase.end() && uppercase.find(s[i]) == uppercase.end()){
                cout << "Строка содержит недопустимые символы.\n";
                s.clear();
            }
        }
    }

    for(int i = 0; i < s.length(); i++){
        if(toCount.find(s[i]) != toCount.end()){
            c = c + 1;
            cout << s[i];
        }
    }

    cout << "Количество символов '-', '+', '*' и цифр: " << c;
    return 0;
}