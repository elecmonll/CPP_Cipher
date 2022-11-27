//Шифросиситема RSA
#include <iostream>
#include <windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0) {
            return h;
        }
        a = h;
        h = temp;
    }
}
class RSA {
public:
    string mainStr, alphStr;
    vector<double> firstNumberStr, secondNumberStr, thirdNumberStr;
    double p, q, m, n, e;
    double d;
public:
    void RSA_Main();
    void RSA_Encryption();
    void RSA_Decryption();
    double Number_Simple();
    double Number_d();
};
double RSA::Number_Simple() {
    double randVal = 0 + rand() % 100;
    bool boolVal;
    while(true) {
        boolVal = true;
        if (randVal < 2) {
            boolVal = false;
        }
        if (randVal == 2) {
            boolVal = true;
        }
        for (int i = 2; i < randVal; i++) {
            if (fmod(randVal, i) == 0) {
                boolVal = false;
                break;
            }
        }
        if (boolVal == true) {
            return randVal;
        }
        randVal++;
    }
}
double RSA::Number_d() {
    double d1 = 1 / e;
    return fmod(d1, n);
}
void RSA::RSA_Main() {
    for (char letter = 'А'; letter <= 'Я'; letter++) {
        alphStr.push_back(letter);
        if (letter == 'Е') {
            alphStr.push_back('Ё');
        }
    }
    p = Number_Simple();
    q = Number_Simple();
    m = p * q;
    n = (p - 1) * (q - 1);
    e = Number_Simple();
    while (e < n) {
        if (gcd(e, n) == 1) {
            break;
        }
        else {
            e++;
        }
    }
    d = Number_d();
    cout << p << " " << q << " " << m << " " << n << " " << e << " " << d << endl;
    cout << "Введите текст: "; getline(cin, mainStr);

    RSA_Encryption();
    RSA_Decryption();

    mainStr.clear();
    alphStr.clear();
    firstNumberStr.clear();
    secondNumberStr.clear();
    thirdNumberStr.clear();
}
void RSA::RSA_Encryption() {
    cout << "\nВходное слово: ";
    for (auto value : mainStr) {
        for (int i = 0; i < alphStr.size(); i++) {
            if (value == alphStr[i]) {
                firstNumberStr.push_back(i + 100);
                cout << i + 1 << " ";
            }
        }
    }
    cout << "\nЗашифрованное слово: ";
    for (auto value : firstNumberStr) {
        double result = pow(value, e);
        value = result;
        secondNumberStr.push_back(value);
        result = fmod(result, m);
        cout << result << " ";
    }
}
void RSA::RSA_Decryption() {
    cout << "\n\nРасшифрованное слово: ";
    for (auto value : secondNumberStr) {
        double result = pow(value, d);
        result = fmod(result, m);
        cout << result - 99 << " ";
    }
}
int main() {
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    RSA rsa;
    rsa.RSA_Main();
    return 0;
}