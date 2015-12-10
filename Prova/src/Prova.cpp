//============================================================================
// Name        : Prova.cpp
// Author      : Giada
// Version     :
// Copyright   :
// Description : Progetto cyclone
//============================================================================

#include "volo.h"
#include <iostream>
using namespace std;

volo inserisciVolo(char* p, char* a);
void visualizzaVoli(volo* v, int c);

int main() {

	volo* voli;
	int c = 0;
	int scelta = 0;

	do{
		cout<<"Scegli menu\n"<< endl;

			cout<<"1- Inserisci volo \n"
					"2- Visualizza voli \n"
					"3- Prenota volo \n"
					"0- Esci \n"<< endl;
			do{
				cin >> scelta;
				if(scelta < 0)
					cout<<"Inserisci un valore corretto!"<< endl;
			}while(scelta < 0);

			switch(scelta){
				case 0:
					cout << "Uscita" << endl;
					break;
				case 1:
					char p[30];
					char a[30];
					cout<<"Inserisci volo" << endl<<endl;
					cout<<"Inserisci partenza" << endl;
					cin>> p;
					cout<< endl <<"Inserisci arrivo" << endl;
					cin>> a;

					//voli[c++] =
					inserisciVolo(p, a);

					break;
				case 2:
					cout<<"Visualizza voli" << endl;
					//visualizzaVoli(voli, c);
					break;
				case 3:
					cout<<"Prenota volo" << endl;
					break;
				default:
					cout<<"Nessuna operazione possibile" << endl;
					break;
			}
	}while(scelta != 0);

		return 0;
}

volo inserisciVolo(char* p, char* a){
	volo v;
	v.setVolo(p, a);
	return v;
}

void visualizzaVoli(volo* v, int c){
	int i;
	for (i = 0; i < c; ++i) {
		cout<<"Volo: "<< v[i].getCodice()
				<< ", Partenza da: " << v[i].getPartenza()
				<<", Arrivo a: " << v[i].getArrivo()
				<< ", Numero posti: " << v[i].getNumPosti() <<endl;
	}
}
