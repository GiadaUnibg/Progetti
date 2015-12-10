/*
 * volo.h
 *
 *  Created on: 09 dic 2015
 *      Author: Giada
 */

#ifndef VOLO_H_
#define VOLO_H_

class volo{

public:
	volo();
	void setVolo(char*, char*);
	int getCodice();
	char* getPartenza();
	char* getArrivo();
	int getNumPosti();

private:
	int codice;
	char* partenza;
	char* arrivo;
	int numPosti;

};


#endif /* VOLO_H_ */
