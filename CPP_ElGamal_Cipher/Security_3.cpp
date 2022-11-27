//Шифросистема Эль-Гамаля
#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
#define randMax 10000
using namespace std;

class ShifrGam {
public:
    long long p, //Простое число
        g, //Любое число
        x, //Закрытый ключ
        y, //Открытое число
        M, //Открытое сообщение
        k, //Сессионный ключ
        r, //Часть шифратекста
        e, //Часть шифратекста
        M1; //Расшифрованное сообщение
public:
    void Main(); //Главный метод
    void keyGeneration(); //Метод генерации ключей
    void encryptionGam(); //Метод шифрования
    void decryptionGam(); //Метод дешифровки
    long long simpleNumber(); //Метод поиска простого числа
    long long gNumber(); //Метод нахождения значения g
    long long xNumber(); //Метод нахождения значения x
    long long modPower(long long, long long, long long); //Метод a^b mod n
    long long modMulti(long long, long long, long long); //Метод a*b mod n
};
void ShifrGam::Main() {
    keyGeneration();
    encryptionGam();
    decryptionGam();
}
void ShifrGam::keyGeneration() {
    p = simpleNumber();
    g = gNumber();
    x = xNumber();
    y = modPower(g, x, p);
    cout << "Открытые ключи: " << p << ", " << g << ", " << y << "\t" << "Закрытый ключ: " << x << endl;
}
void ShifrGam::encryptionGam() {
    cout << "Введите число: "; cin >> M;
    while (true) {
        if (M < p) {
            break;
        }
        else {
            cout << "Ошибка! Введите число: "; cin >> M;
        }
    }
    long long buf = p - 2;
    k = 1 + rand() % buf;
    r = modPower(g, k, p);
    e = modMulti(modPower(y, k, p), M, p);
    cout << "Зашифрованное сообщение: " << r << " " << e << endl;
}
void ShifrGam::decryptionGam() {
    M1 = modMulti(e, modPower(r, p - 1 - x, p), p);
    cout << "Расшифрованное сообщение: " << M1 << endl;
}
long long ShifrGam::simpleNumber() {
    long long randVal = 1 + rand() % randMax;
    bool boolVal;
    while (true) {
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
long long ShifrGam::gNumber() {
    while (true) {
        long long g1 = 1 + rand() % randMax;
        if ((1 < g1) && (g1 < (p - 1))) {
            return g1;
        }
    }
}
long long ShifrGam::xNumber() {
    while (true) {
        long long x1 = 1 + rand() % randMax;
        if ((1 < x1) && (x1 < (p - 1))) {
            return x1;
        }
    }
}
long long ShifrGam::modPower(long long a, long long b, long long n) {
    long long tmp = a;
    long long sum = tmp;
    for (long long i = 1; i < b; i++) {
        for (long long j = 1; j < a; j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}
long long ShifrGam::modMulti(long long a, long long b, long long n) {
    long long sum = 0;
    for (long long i = 0; i < b; i++) {
        sum += a;
        if (sum >= n) {
            sum -= n;
        }
    }
    return sum;
}
int main() {
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ShifrGam shifrGam;
    shifrGam.Main();
    return 0;
}