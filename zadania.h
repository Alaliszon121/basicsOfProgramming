/*
Plik nag³ówkowy jest jak „menu” dla funkcji. Deklaruje on funkcje, z których mog¹ korzystaæ inne pliki
Cel:
	* Deklarowanie funkcji, aby mog³y byæ wspó³dzielone w wielu plikach .cpp.
	* Pomaga w modularyzacji kodu i unikaniu duplikacji.
*/

/*
ALTERNATYWA DLA IFDEF, DEFINE, ENDIF:
	#pragma once // szeroko wspierana alternatywa, jednak nie ze standardu c++
*/

#ifndef ZADANIA_H // Sprawdenie, czy symbol preprocesora ZADANIA_H nie jest ju¿ zdefiniowany. Jeœli jest, kod wewn¹trz (miêdzy #ifndef i #endif) zostanie zignorowany.
#define ZADANIA_H // Jeœli ZADANIA_H nie jest jeszcze zdefiniowane, ta linia j¹ definiuje. Gwarantuje to, ¿e nastêpnym razem, gdy preprocesor napotka ten plik nag³ówkowy, ZADANIA_H bêdzie zdefiniowany, a zawartoœæ pliku zostanie pominiêta

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
