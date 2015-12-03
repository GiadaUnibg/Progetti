/*
 * volo.c
 *
 *  Created on: 02/dic/2015
 *      Author: Giada
 */

#include "volo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int num_codice = 0;
static int num_posti = 200;


struct volo{
	int codice;
	char* partenza;
	char* arrivo;
	int numPosti;
};

voloRef mkVolo(char* p, char* a){
	voloRef vr = malloc(sizeof(struct volo));

	vr->codice = ++num_codice;
	vr->partenza = malloc(sizeof(char*) * 50);
	vr->arrivo = malloc(sizeof(char*) * 50);
	strncpy(vr->partenza, p, 50);
	strncpy(vr->arrivo, a, 50);
	vr->numPosti = num_posti;

	return vr;
}

int getCodice(voloRef vr){
	return vr->codice;
}

char* getPartenza(voloRef vr){
	return vr->partenza;
}

char* getArrivo(voloRef vr){
	return vr->arrivo;
}

int getNumeroPosti(voloRef vr){
	return num_posti;
}
