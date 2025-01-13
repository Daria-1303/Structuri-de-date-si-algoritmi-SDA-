/*
Se consideră un tablou de structuri de forma:
	            struct agenda {
                    char nume[25];
                    char telefon[10];
                    int an;
                    int venit;
                };

Fiind dat tabloul cu dimensiunea N, se cere implementarea a câte o funcție pentru:

a) Mutarea pe ultimele poziții din vector a primelor două persoane cu un venit mai mic de 1000.

b) Sortarea eficientă, în ordine alfabetică a numelor, a persoanelor cu vârsta între 30 și 40 de ani.

Notă: Se consideră un exemplu de tablou cu minimum 5 astfel de structuri și se va exemplifica cum va arăta tabloul după 

apelul fiecărei funcții.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct agenda {
	char nume[25];
	char telefon[10];
	int an;
	int venit;
}Agenda_t;

void citesteDateFisier(Agenda_t *agende, FILE *fin) {
	for (int i = 0; i < N; i++) {
		fscanf(fin, "%s", agende[i].nume);
		fscanf(fin, "%s", agende[i].telefon);
		fscanf(fin, "%d", &agende[i].an);
		fscanf(fin, "%d", &agende[i].venit);
	}
}

void afiseazaDateAgende(Agenda_t* agende) {
	for (int i = 0; i < N; i++) {
		printf("Nume : % s - Telefon %s - An %d - Venit %d\n", agende[i].nume, agende[i].telefon, agende[i].an, agende[i].venit);
	}

	printf("---------------------------------------------------------------\n");
}

void cerintaA_mutaPersoane(Agenda_t* agende) {
	int nrPersoaneMutate = 2;

	for (int i = 0; i < N && nrPersoaneMutate > 0; i++) {
		if (agende[i].venit < 1000) {
			// aici facem swap 
			Agenda_t tmp = agende[i];

			if (nrPersoaneMutate == 2) {
				agende[i] = agende[N - 1];
				agende[N - 1] = tmp;
			}
			else {
				agende[i] = agende[N - 2];
				agende[N - 2] = tmp;
			}

			nrPersoaneMutate--;
		}
	}
}

void swap(Agenda_t* a, Agenda_t* b) {
	Agenda_t tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
	pt dimensiuni mici ale lui N, folosirea Selection sort se dovedeste a fi eficienta
	complexitatea algoritmului este O(n^2)

	Intr-adevar pentru dimensiuni mari ale lui N, ar fi mai eficient sa folosim un algoritm de sortare mai eficient
	precum QuickSort, MergeSort, dar pentru dimensiuni mici, Selection sort este suficient de eficient
*/

void cerintaB_sortareNume(Agenda_t* agende) {
	int i, j, min;

	for (i = 0; i < N - 1; i++) {
		if (agende[i].an >= 30 && agende[i].an <= 40) {
			min = i;
		}
		else {
			continue;
		}

		for (j = i + 1; j < N; j++) {
			if (agende[j].an >= 30 && agende[j].an <= 40) {
				if (strcmp(agende[j].nume, agende[min].nume) < 0) {
					min = j;
				}
			}
		}

		swap(&agende[i], &agende[min]);
	}
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Numar insuficient de argumente");
		exit(1);
	}

	Agenda_t agende[N];

	FILE* fin = fopen(argv[1], "r");

	if (fin == NULL) {
		printf("Fisierul nu a putut fi deschis");
		exit(1);
	}

	citesteDateFisier(agende, fin);

	printf("Date initiale\n");
	afiseazaDateAgende(agende);

	printf("Cerinta A : \n");
	cerintaA_mutaPersoane(agende);
	afiseazaDateAgende(agende);

	printf("Cerinta B : \n");
	cerintaB_sortareNume(agende);
	afiseazaDateAgende(agende);

	return 0;
}