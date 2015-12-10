/*
 ============================================================================
 Name        : Mariani_Giada_Cyclone.c
 Author      : Giada
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "volo.h"
#include "prenotazione.h"
voloRef inserisciVolo(){
	char* p;
	char* a;

	printf("Partenza: ");
	scanf("%s", p);
	printf("Arrivo: ");
	scanf("%s", a);

	voloRef vr = mkVolo(p, a);

	return vr;
}

void visualizzaVoli(voloRef* vr){
	int i = 0;
	while(*vr){
		printf("Volo: %d ", getCodice(vr[i]));
		printf("Partenza: %s ", getPartenza(vr[i]));
		printf("Arrivo %s ", getArrivo(vr[i]));
		printf("Numero posti disponibili %d ", getNumeroPosti(vr[i]));
		i++;
	}
}


int main(void) {

	voloRef* vr;
	int scelta = 0;
	int cont = 0;

	//do{
		printf("1- Inserisci volo \n"
				"2- Visualizza voli \n"
				"3- Prenota volo \n"
				"0- Esci \n");

		scanf("%d", &scelta);

		printf("Scelta %d", scelta);
		/*switch(scelta){
		case 0:
			printf("Uscita");
			break;
		case 1:
			vr[cont] = inserisciVolo();
			cont++;
			printf("Volo inserito");
			break;
		case 2:
			visualizzaVoli(vr);
			break;
		case 3:
			break;
		default:
			printf("Operazione non possibile");
			break;
		}
	//}while(scelta != 0);*/

	return EXIT_SUCCESS;
}
