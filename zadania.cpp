/*
Ten plik zawiera rzeczywistą logikę (lub definicje) funkcji zadeklarowanych w zadania.h.

Cel:
    * Enkapsuluje (ogranicza bezpośredni dostęp) funkcjonalności zadeklarowanych funkcji.
    * Utrzymuje główny plik (kolokwium.cpp) w czystości poprzez przeniesienie implementacji do osobnego pliku.

Działanie:
Zawiera plik nagłówkowy #include „zadania.h”, dzięki czemu dopasowuje deklaracje funkcji do ich definicji.
*/

#include <iostream>
#include <iomanip>
#include "zadania.h"
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

// Definicje i logika funkcji:
void zadanie1() {
    int dlugosc;
    std::cout << "Podaj dlugosc linii: ";
    std::cin >> dlugosc;

    /*
    // za pomocą pętli
    for (int i = 0; i < dlugosc; i++) {
        std::cout << "*";
    } 
    */

    // za pomocą setfill()
    std::cout << std::setfill('*') << std::setw(dlugosc) << "" << std::endl;

    std::cout << std::endl;
}

void zadanie2() {
    int podstawa_trojakta;
    std::cout << "Podaj dlugosc linii: ";
    std::cin >> podstawa_trojakta;

    for (int i = podstawa_trojakta; i > 0; i-=2) {
        std::cout << std::setfill('*') << std::setw(i) << "" << std::endl;
    }
}

// funkcje do zadania 3
float min(const float* liczby) {
    float min = liczby[0];
    for (int i = 1; i < 5; i++) {
        if (liczby[i] < min) min = liczby[i];
    }
    return min;
}
float max(const float* liczby) {
    float max = liczby[0];
    for (int i = 1; i < 5; i++) {
        if (liczby[i] > max) max = liczby[i];
    }
    return max;
}
float odchylenie_standardowe(const float* liczby, const float srednia) {
    float odchylenie = 0;

    for (int i = 0; i < 5; i++) {
        odchylenie += (liczby[i] - srednia) * (liczby[i] - srednia);
    }

    return sqrt(odchylenie / 5);
}
void zadanie3() {
    float liczby[5];
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        std::cout << "Liczba " << i+1 << ": ";
        std::cin >> liczby[i];
        suma += liczby[i];
    }
    float srednia = suma / 5;

    std::cout << std::endl << "Podstawowe statystyki: " << std::endl;
    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Srednia: " << srednia << std::endl;
    std::cout << "Wartosc minimalna: " << min(liczby) << std::endl;
    std::cout << "Wartosc maksymalna: " << max(liczby) << std::endl;
    std::cout << "Odchylenie standardowe: " << odchylenie_standardowe(liczby, srednia) << std::endl;
}

void zadanie4() {
    float x1, y1, x2, y2;

    std::cout << "Podaj (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Podaj (x2 y2): ";
    std::cin >> x2 >> y2;

    if (x1 == x2 && y1 == y2) {
        std::cout << "Punkty są identyczne. Nie można określić równania prostej." << std::endl;
    }
    else if (x1 == x2) {
        // Linia pionowa: x = x1 = x2
        std::cout << "Równanie prostej: x = " << x1 << std::endl;
    }
    else if (y1 == y2) {
        // Linia pozioma: y = y1 = y2
        std::cout << "Równanie prostej: y = " << y1 << std::endl;
    }
    else {
        // Ogólny przypadek: y = ax + b
        double a = (y2 - y1) / (x2 - x1); // Obliczenie współczynnika kierunkowego
        double b = y1 - a * x1;          // Obliczenie wyrazu wolnego

        std::cout << std::fixed << std::setprecision(2); // Ustawienie precyzji wyświetlania wyników
        std::cout << "Rownanie prostej: y = " << a << "x";
        if (b < 0) std::cout << " " << b << std::endl;
        else std::cout << " + " << b << std::endl;
    }
}

void zadanie5() {
    float a, b, c;

    std::cout << "Podaj a: ";
    std::cin >> a;
    std::cout << "Podaj b: ";
    std::cin >> b;
    std::cout << "Podaj c: ";
    std::cin >> c;

    float delta = (b * b) - (4 * a * c);
    float ekstremum_y = (-delta) / (4 * a);

    if (a > 0) {
        std::cout << "Maksimum: +nieskonczonosc\n" << std::endl;
        std::cout << "Minimum: " << ekstremum_y << std::endl;
    }
    else if(a < 0)
    {
        std::cout << "Maksimum: " << ekstremum_y << std::endl;
        std::cout << "Minimum: -nieskonczonosc\n";
    }
    else
    {
        std::cout << "a = 0, funkcja nie jest funkcja kwadratowa\n";
    }
}

void zadanie6() {
    int wysokosc;
    std::cout << "Podaj wysokosc choinki: ";
    std::cin >> wysokosc;

    int szerokosc = 1 + (2*(wysokosc-2));

    int ilosc_gwiazdek = 1;
    int ilosc_spacji = wysokosc - 2;

    for (int i = 1; i < wysokosc; i++) {
        for (int j = 0; j < ilosc_spacji; j++) {
            std::cout << " ";
        }
        for (int k = 0; k < ilosc_gwiazdek; k++) {
            std::cout << "*";
        }
        ilosc_spacji--;
        ilosc_gwiazdek += 2;
        std::cout << std::endl;
    }

    std::cout << std::setfill(' ') << std::setw(wysokosc - 1) << "#" << std::endl;
    std::cout << std::setfill('-') << std::setw(szerokosc) << "" << std::endl;
}

void zadanie7() {
    int wysokosc;
    std::cout << "Podaj wysokosc tabliczki mnozenia: ";
    std::cin >> wysokosc;
    std::cout << std::endl;

    std::cout << std::setw(6) << "* |";
    for (int i = 1; i <= wysokosc; i++) {
        std::cout << std::setw(4) << i;
    }
    std::cout << std::endl;

    std::cout << std::setfill('-') << std::setw(wysokosc * 4 + 6) << "" << std::setfill(' ') << std::endl;;

    for (int i = 1; i <= wysokosc; i++) {
        std::cout << std::setw(4) << i << " |";
        for (int j = 1; j <= wysokosc; j++) {
            std::cout << std::setw(4) << i*j;
        }
        std::cout << std::endl;
    }
}

void zadanie8() {
    double a, b, c, d, e, f;
    std::cout << "Podaj wspolczynniki ukladu rownan:" << std::endl;
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;
    std::cout << "c: "; std::cin >> c;
    std::cout << "d: "; std::cin >> d;
    std::cout << "e: "; std::cin >> e;
    std::cout << "f: "; std::cin >> f;

    double det_A = a * e - b * d;

    if (det_A != 0) {
        double x = (c * e - b * f) / det_A;
        double y = (a * f - c * d) / det_A;

        std::cout << "Rozwiazanie: x = " << x << ", y = " << y << std::endl;
    }
    else {
        if (a * f - c * d == 0 && b * f - c * e == 0) {
            std::cout << "Uklad ma nieskonczenie wiele rozwiazan." << std::endl;
        }
        else {
            std::cout << "Uklad jest sprzeczny i nie ma rozwiazan." << std::endl;
        }
    }
}

void zadanie9() {
    int liczba;
    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;
    if (liczba < 0) std::cout << "Liczba nie moze byc mniejsza od zera!";
    else {
        for (int i = 1; i <= liczba; i++) {
            char a = i + '0';
            std::cout << std::setfill(a) << std::setw(i) << "" << std::endl;
        }
        for (int i = liczba-1; i >= 1; i--) {
            char a = i + '0';
            std::cout << std::setfill(' ') << std::setw(liczba - i) << "";
            std::cout << std::setfill(a) << std::setw(i) << "" << std::endl;
        }
    }
}

void zadanie10() {
    float start, koniec;
    int ilosc_punktow;

    std::cout << "Start: "; std::cin >> start;
    std::cout << "Koniec: "; std::cin >> koniec;
    std::cout << "Punkty: "; std::cin >> ilosc_punktow;

    if (koniec < start) {
        start += koniec;
        koniec = start - koniec;
        start -= koniec;
    }

    float odstepy = abs(start - koniec) / ((float)ilosc_punktow - 1.0f);

    // Zapisanie pierwszej wartości sinusa
    float poprzedni_sinus = sin(start);

    std::cout << std::setw(10) << std::fixed << std::setprecision(2) << "sin(" << start << ") = " << poprzedni_sinus;
    start += odstepy;

    while (start <= koniec) {
        float aktualny_sinus = sin(start);
        std::cout << std::setw(10) << "sin(" << start << ") = " << aktualny_sinus;

        // Sprawdzenie zmiany znaku
        if ((aktualny_sinus >= 0 && poprzedni_sinus < 0) || (aktualny_sinus < 0 && poprzedni_sinus >= 0)) {
            std::cout << std::endl;
        }

        // Aktualizacja poprzedniego sinusa i start
        poprzedni_sinus = aktualny_sinus;
        start += odstepy;
    }

}

void zadanie14() {
    srand(time(0));
    int length;

    std::cout << "Podaj dlugosc hasla: ";
    std::cin >> length;

    if (length < 4) {
        std::cout << "Haslo musi miec co najmniej 4 znaki." << std::endl;
        return;
    }

    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string special = "!@#$%^&*?_";

    std::string password;
    password += lower[rand() % lower.size()];
    password += upper[rand() % upper.size()];
    password += digits[rand() % digits.size()];
    password += special[rand() % special.size()];

    std::string all_chars = lower + upper + digits + special;
    for (int i = 4; i < length; i++) {
        password += all_chars[rand() % all_chars.size()];
    }

    for (int i = 0; i < password.size(); i++) {
        std::swap(password[i], password[rand() % password.size()]);
    }

    std::cout << "Wygenerowane haslo: " << password << std::endl;
}

void totolotek(int n, int a, int b) {
    if (n <= 0) {
        std::cout << "Liczba wylosowanych liczb musi być większa od 0." << std::endl;
        return;
    }
    if (a > b) {
        std::cout << "Początek przedziału (a) musi być mniejszy lub równy końcowi (b)." << std::endl;
        return;
    }

    random_device rd; // Entropia sprzętowa
    mt19937 gen(rd()); // Generator Mersenne Twister
    uniform_int_distribution<> dist(a, b); // Rozkład równomierny na [a, b]

    std::cout << "Wylosowane liczby: ";
    for (int i = 0; i < n; ++i) {
        std::cout << dist(gen) << " ";
    }
    std::cout << std::endl;
}
void zadanie19() {
    int n, a, b;
    std::cout << "Podaj liczbę losowań (n): "; std::cin >> n;
    std::cout << "Podaj początek przedziału (a): "; std::cin >> a;
    std::cout << "Podaj koniec przedziału (b): "; std::cin >> b;

    totolotek(n, a, b);
}