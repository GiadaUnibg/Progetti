/*
 * Tris.h
 *
 *  Created on: 31 dic 2015
 *      Author: Giada
 */

#ifndef C_TRIS_H_
#define C_TRIS_H_

typedef struct TrisStruct * Tris;

Tris mkTris();

void cambiaTurno(Tris t);

int stampaTurno(Tris t);

void setUtente(Tris t, int u);

void stampaBoard(Tris t);

void vincita(Tris t);

void casellePiene(Tris t);

int fineDelGioco(Tris t);

char* vincitore(Tris t);

void setVincitore(Tris t, char* w);

#endif /* C_TRIS_H_ */
