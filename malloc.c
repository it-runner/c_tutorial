/*	▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ✅ malloc() ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	Funkcja malloc() w języku C służy do dynamicznego przydzielania pamięci w czasie działania programu. 
	Umożliwia ona alokację określonej ilości pamięci na stercie (heap), której rozmiar można ustawić w trakcie działania programu, a nie w czasie kompilacji.

	❓ Jak działa malloc()?

		1. Wywołanie funkcji:
				Program wywołuje malloc() z podaniem rozmiaru pamięci, którą chce zaalokować, np. malloc(100) zarezerwuje 100 bajtów.
		2. Zwracana wartość:  
				Jeśli operacja się powiedzie, malloc() zwraca wskaźnik do początku zaalokowanego fragmentu pamięci.
				Jeśli nie ma wystarczającej ilości dostępnej pamięci, zwraca NULL.
		3. Używanie zaalokowanej pamięci:
				Po zaalokowaniu można korzystać z pamięci, np. przypisując do wskaźnika, odczytując lub zapisując dane.
		4. Zwolnienie pamięci:
				Po użyciu pamięć trzeba zwolnić funkcją free(), aby uniknąć wycieków pamięci.

	🧐 Co się dzieje pod maską?

		malloc() żąda od systemu operacyjnego przydzielenia fragmentu pamięci o żądanym rozmiarze.
		System operacyjny szuka dostępnego kawałka pamięci na stercie i przydziela go.
		malloc() aktualizuje wewnętrzne struktury zarządzania pamięcią, aby wiedzieć, które fragmenty są zajęte, a które wolne.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int *intArr;
	// rezerwujemy pamięc dla 10 elementów typu int:
	intArr = (int*)malloc(sizeof(int) * 10);
	if (!intArr) {
		puts("Memory allocation failed!");
		return 1;
	}

	// korzystanie  zaalokowanej pamięci
	for (int i = 0; i < 10; i++) {
		intArr[i] = i * i;
		printf("%d ", intArr[i]);
	}
	putchar('\n');

	// zwolnienie pamięci
	free(intArr);

	return 0;
}
