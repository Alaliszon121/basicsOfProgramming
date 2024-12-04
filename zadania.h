/*
Plik nag��wkowy jest jak �menu� dla funkcji. Deklaruje on funkcje, z kt�rych mog� korzysta� inne pliki
Cel:
	* Deklarowanie funkcji, aby mog�y by� wsp�dzielone w wielu plikach .cpp.
	* Pomaga w modularyzacji kodu i unikaniu duplikacji.
*/

/*
ALTERNATYWA DLA IFDEF, DEFINE, ENDIF:
	#pragma once // szeroko wspierana alternatywa, jednak nie ze standardu c++
*/

#ifndef ZADANIA_H // Sprawdenie, czy symbol preprocesora ZADANIA_H nie jest ju� zdefiniowany. Je�li jest, kod wewn�trz (mi�dzy #ifndef i #endif) zostanie zignorowany.
#define ZADANIA_H // Je�li ZADANIA_H nie jest jeszcze zdefiniowane, ta linia j� definiuje. Gwarantuje to, �e nast�pnym razem, gdy preprocesor napotka ten plik nag��wkowy, ZADANIA_H b�dzie zdefiniowany, a zawarto�� pliku zostanie pomini�ta

// Deklaracje funkcji tutaj
void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();
void zadanie10();
void zadanie14();
void zadanie19();

#endif // ZADANIA_H
