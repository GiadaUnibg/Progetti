/*
 * volo.h
 *
 *  Created on: 02/dic/2015
 *      Author: Giada
 */

#ifndef VOLO_H_
#define VOLO_H_

typedef struct volo * voloRef;

voloRef mkVolo(char* p, char* a);

int getCodice(voloRef v);

char* getPartenza(voloRef v);

char* getArrivo(voloRef v);

int getNumeroPosti(voloRef v);

#endif /* VOLO_H_ */
