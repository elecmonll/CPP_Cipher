//Шифр Цезаря
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <fstream>
using namespace std;

class Caesar {
public:
    stringstream firstStream;
    string strMain, strSurname, strName, strOtch, str33, str32, str31;
    int mainValue = 0, keyOne = 0, keyTwo = 0, keyThree = 0;
    
public:
    void Main();
    void MethodCaesarEncryption(string);
    void MethodCaesarDecryption(string);
    void MethodCaesarUnkey(string);
};
void Caesar::Main() {
    for (char letter = 'А'; letter <= 'Я'; letter++) {
        str33.push_back(letter);
        if (letter == 'Е') {
            str33.push_back('Ё');
        }
    }
    for (char letter = 'А'; letter <= 'Я'; letter++) {
        str32.push_back(letter);
    }
    for (char letter = 'А'; letter <= 'Я'; letter++) {
        str31.push_back(letter);
        if (letter == 'Й') {
            str31.erase(str31.size() - 1);
        }
    }

    int valueAlpha, valueShifr;
    cout << "1. Весь Алфавит: 33\n2. Алфавит без Ё: 32\n3. Алфавит без Ё и Й: 31\nВыберите число: ";
    cin >> valueAlpha;

    cout << "\n1. Зашифровать\n2. Расшифровка\n3. Расшифровка без ключей\nВыберите действие: "; /*\n3.Расшифровка без ключей*/
    cin >> valueShifr;


    cout << "\nВведите ФИО (Пример. ИВАНОВ ИВАН ИВАНОВИЧ): ";
    getline(cin, strMain);
    getline(cin, strMain);
    firstStream << strMain;
    firstStream >> strSurname >> strName >> strOtch;
    firstStream.clear();

    if ((valueShifr == 1) || (valueShifr == 2)) {
        cout << "\nВведите ключи для ФИО.\nКлюч для Фамилии - keyOne: ";
        cin >> keyOne;
        cout << "Ключ для Имени - keyTwo: ";
        cin >> keyTwo;
        cout << "Ключ для Отчества - keyThree: ";
        cin >> keyThree;
    }

    switch (valueAlpha) {
    case 1:
        mainValue = 33 - 1;
        if (valueShifr == 1) {
            MethodCaesarEncryption(str33);
        }
        else if (valueShifr == 2) {
            MethodCaesarDecryption(str33);
        }
        else if (valueShifr == 3) {
            MethodCaesarUnkey(str33);
        }
        break;

    case 2:
        mainValue = 32 - 1;
        if (valueShifr == 1) {
            MethodCaesarEncryption(str32);
        }
        else if (valueShifr == 2) {
            MethodCaesarDecryption(str32);
        }
        else if (valueShifr == 3) {
            MethodCaesarUnkey(str32);
        }
        break;

    case 3:
        mainValue = 31 - 1;
        if (valueShifr == 1) {
            MethodCaesarEncryption(str31);
        }
        else if (valueShifr == 2) {
            MethodCaesarDecryption(str31);
        }
        else if (valueShifr == 3) {
            MethodCaesarUnkey(str31);
        }
        break;
    }
}
void Caesar::MethodCaesarEncryption(string str) {
    int number;
    for (auto& count : strSurname) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i + keyOne;
                if (number > mainValue) {
                    number -= mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    for (auto& count : strName) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i + keyTwo;
                if (number > mainValue) {
                    number -= mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    for (auto& count : strOtch) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i + keyThree;
                if (number > mainValue) {
                    number -= mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    cout << "\nРезультаты: " << strSurname << " " << strName << " " << strOtch << endl;
}
void Caesar::MethodCaesarDecryption(string str) {
    int number;
    for (auto& count : strSurname) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i - keyOne;
                if (number < 0) {
                    number += mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    for (auto& count : strName) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i - keyTwo;
                if (number < 0) {
                    number += mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    for (auto& count : strOtch) {
        for (int i = 0; i < str.size(); i++) {
            if (count == (char)str[i]) {
                number = i - keyThree;
                if (number < 0) {
                    number += mainValue;
                    count = (char)str[number];
                    break;
                }
                count = (char)str[number];
                break;
            }
        }
    }
    cout << "\nРезультаты: " << strSurname << " " << strName << " " << strOtch << endl;
}
void Caesar::MethodCaesarUnkey(string str) {
    ofstream out;
    out.open("C:\\output.txt");
    int number1 = 0, number2 = 0, number3 = 0;
    for (int i = 0; i < mainValue; i++) {
        for (auto& count : strSurname) {
            for (int i1 = 0; i1 < str.size(); i1++) {
                if (count == (char)str[i1]) {
                    number1 = i1 - i;
                    if (number1 < 0) {
                        number1 += mainValue;
                        count = (char)str[number1];
                        break;
                    }
                    count = (char)str[number1];
                    break;
                }
            }
        }
        for (int j = 0; j < mainValue; j++) {

            for (auto& count : strName) {
                for (int i2 = 0; i2 < str.size(); i2++) {
                    if (count == (char)str[i2]) {
                        number2 = i2 - j;
                        if (number2 < 0) {
                            number2 += mainValue;
                            count = (char)str[number2];
                            break;
                        }
                        count = (char)str[number2];
                        break;
                    }
                }
            }
            for (int k = 0; k < mainValue; k++) {

                for (auto& count : strOtch) {
                    for (int i3 = 0; i3 < str.size(); i3++) {
                        if (count == (char)str[i3]) {
                            number3 = i3 - k;
                            if (number3 < 0) {
                                number3 += mainValue;
                                count = (char)str[number3];
                                break;
                            }
                            count = (char)str[number3];
                            break;
                        }
                    }
                }
                out << "\nРезультат " << i << ", " << j << ", " << k << " : " << strSurname << " " << strName << " " << strOtch;
            }
        }
        firstStream << strMain;
        firstStream >> strSurname >> strName >> strOtch;
        firstStream.clear();
    }
    out.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool qual = true;
    char symbol;
    while (qual) {
        Caesar caesar;
        caesar.Main();
        cout << "\nВыйти из программы? д/н: ";
        cin >> symbol;
        cout << endl << endl;
        if (symbol == 'д') {
            qual = false;
        }
    }
    return 0;
}