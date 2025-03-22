#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

int monthToNumber(string month)
{
    string months[] = {
        "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"
    };

    for (int i = 0; i < 12; ++i)
    {
        if (month == months[i])
        {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    date curDate;
    string s;
    bool isCorrect = false;

    while(!isCorrect){
        int loc;
        cout << "Введите дату в формате дд мм гггг (1 января 2025): ";
        getline(cin, s);

        loc = s.find(' ');
        if(s.substr(0, loc).length() == 1){
            curDate.day = stoi('0' + s.substr(0, loc));
        }else{
            curDate.day = stoi(s.substr(0, loc));
        }

        s = s.substr(loc + 1);
        loc = s.find(' ');

        curDate.month = monthToNumber(s.substr(0, loc));
        s = s.substr(loc + 1);

        curDate.year = stoi(s);

        if(curDate.day < 1 or curDate.day > 31 or curDate.month < 1 or curDate.month > 12 or curDate.year < 2000 or curDate.year > 2025){
            cout << "Дата введена некорректно, попробуйте еще раз." << endl;
        }else{
            isCorrect = true;
        }
    };
    s = to_string(curDate.year) + ':' + to_string(curDate.month) + ':' + to_string(curDate.day);
    
    cout << setfill('0') << curDate.year << ":"
    << setw(2) << curDate.month << ":"
    << setw(2) << curDate.day << endl;
    return 0;
}