/*
 * prenotazione.c
 *
 *  Created on: 02/dic/2015
 *      Author: Giada
 */

#include "prenotazione.h"

struct prenotazione{
	char* codicePrenotazione;
	int codice;
	int numPosti;
};

prenRef mkPrenotazione(char* c, int v, int np){
	prenRef pr = malloc(sizeof(struct prenotazione));

	pr->codicePrenotazione = malloc(sizeof(char*)*10);
	strncpy(pr->codicePrenotazione, c, 10);
	pr->codice = v;
	pr->numPosti = np;

	return pr;
}

char* getPrenotazione(prenRef pr){
	return pr->codicePrenotazione;
}

int getCodiceVoloPrenotazione(prenRef pr){
	return pr->codice;
}

int getNumPostiPrenotati(prenRef pr){
	return pr->numPosti;
}
