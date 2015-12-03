/*
 * prenotazione.h
 *
 *  Created on: 02/dic/2015
 *      Author: Giada
 */

#ifndef PRENOTAZIONE_H_
#define PRENOTAZIONE_H_


typedef struct prenotazione * prenRef;


prenRef mkPrenotazione(char* c, int v, int np);

char* getPrenotazione(prenRef pr);

int getCodiceVoloPrenotazione(prenRef pr);

int getNumPostiPrenotati(prenRef pr);

#endif /* PRENOTAZIONE_H_ */
