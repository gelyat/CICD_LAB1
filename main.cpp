#include <iostream>
#include <cmath>
#include <algorithm>
#ifdef _WIN32

#include <windows.h>

#endif

using namespace std;

bool isBetween(int px, int py, int x1, int y1, int x2, int y2) {
    if ((x2 - x1) * (py - y1) != (y2 - y1) * (px - x1)) {
        return false;
    }
    if (x1 != x2) {
        return (px > min(x1, x2) && px < max(x1, x2));
    }
    return (py > min(y1, y2) && py < max(y1, y2));
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

#endif
  //setlocale(LC_ALL, "Russian");
    int kx, ky; // король
    int rx, ry; // ладья
    int bx, by; // слон

    cout << "Введите координаты белого короля (x y): ";
    if (!(cin >> kx >> ky)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    cout << "Введите координаты черной ладьи (x y): ";
    if (!(cin >> rx >> ry)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    cout << "Введите координаты черного слона (x y): ";
    if (!(cin >> bx >> by)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    if (kx < 1 || kx > 8 || ky < 1 || ky > 8 ||
        rx < 1 || rx > 8 || ry < 1 || ry > 8 ||
        bx < 1 || bx > 8 || by < 1 || by > 8) {
        cout << "Ошибка: координаты должны быть от 1 до 8" << endl;
        return 1;
    }

    if ((kx == rx && ky == ry) || (kx == bx && ky == by) || (rx == bx && ry == by)) {
        cout << "Ошибка: фигуры не могут стоять на одной клетке" << endl;
        return 1;
    }

    bool rookThreat = false;
    bool bishopThreat = false;

    if (kx == rx || ky == ry) {
        if (!isBetween(bx, by, rx, ry, kx, ky)) {
            rookThreat = true;
        }
    }

    if (abs(kx - bx) == abs(ky - by)) {
        if (!isBetween(rx, ry, bx, by, kx, ky)) {
            bishopThreat = true;
        }
    }

    if (rookThreat && bishopThreat) {
        cout << "Угроза от ладьи и слона" << endl;
    } else if (rookThreat) {
        cout << "Угроза от ладьи" << endl;
    } else if (bishopThreat) {
        cout << "Угроза от слона" << endl;
    } else {
        cout << "Угрозы нет" << endl;
    }

    return 0;
}
