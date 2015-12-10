/*
 * volo.cpp
 *
 *  Created on: 09 dic 2015
 *      Author: Giada
 */

#include "volo.h"
#include <iostream>
using namespace std;

static int num_codice = 0;
static int num_posti = 200;

volo::volo(){
	codice = numPosti = 0;
	partenza = arrivo = "";
}

void volo::setVolo(char* p, char* a){

	this->codice = ++num_codice;
	this->numPosti = num_posti;

	this->partenza = p;
	this->arrivo = a;
}

int volo::getCodice(){
	return this->codice;
}

char* volo::getPartenza(){
	return this->partenza;
}

char* volo::getArrivo(){
	return this->arrivo;
}

int volo::getNumPosti(){
	return this->numPosti;
}
