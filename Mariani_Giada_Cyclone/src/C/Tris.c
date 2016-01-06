/*
 ============================================================================
 Name        : Tris.c
 Author      : Mariani Giada
 Version     :
 Description : Gioco del Tris. Progetto Cyclone
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Tris.h"

struct TrisStruct{
	int board[3][3];
	int turno;
	int fineGioco;
	char* winner;
};

void cambiaTurno(Tris tris){
		if(tris->turno == 1)
			tris->turno = 2;
		else
			tris->turno = 1;
	}

int stampaTurno(Tris tris){
	return tris->turno;
}

void setUtente(Tris tris, int u){
	int r, c;
	int i = 0;
		do{
			printf("Inserisci riga: \n");
			scanf("%d" , &r);
			printf("Inserisci colonna: \n");
			scanf("%d" , &c);

		if((r >= 0 && r <= 2) || (c>=0 && c<=2)){
		  if(tris->board[r][c] == 0){
			tris->board[r][c] = u;
			i = 1;
		  }
		}
	  }while((r<0 || r>2 || c<0 || c>2) || i == 0);
}

void stampaBoard(Tris tris){
	int r, c;
	for(r = 0; r < 3; r++){
		for(c = 0; c < 3; c++){
			printf( "%d | ", tris->board[r][c]);
		}
		printf("\n");
	}
}

void vincita(Tris tris){
	if((((tris->board[0][0] == tris->board[0][1] && tris->board[0][1] == tris->board[0][2])
			&& (tris->board[0][0] == 1 || tris->board[0][0] == 2))
	  || ((tris->board[1][0] == tris->board[1][1] && tris->board[1][1] == tris->board[1][2])
			&& (tris->board[1][0] == 1 || tris->board[1][0] == 2))
	  || ((tris->board[2][0] == tris->board[2][1] && tris->board[2][1] == tris->board[2][2])
			&& (tris->board[2][0] == 1 || tris->board[2][0] == 2))
	  || ((tris->board[0][0] == tris->board[1][0] && tris->board[1][0] == tris->board[2][0])
			&& (tris->board[0][0] == 1 || tris->board[0][0] == 2))
	  || ((tris->board[0][1] == tris->board[1][1] && tris->board[1][1] == tris->board[2][1])
			&& (tris->board[0][1] == 1 || tris->board[0][1] == 2))
	  || ((tris->board[0][2] == tris->board[1][2] && tris->board[1][2] == tris->board[2][2])
			&& (tris->board[0][2] == 1 || tris->board[0][2] == 2))
	  || ((tris->board[0][0] == tris->board[1][1] && tris->board[1][1] == tris->board[2][2])
			&& (tris->board[0][0] == 1 || tris->board[0][0] == 2))
	  || ((tris->board[0][2] == tris->board[1][1] && tris->board[1][1] == tris->board[2][0])
			&& (tris->board[0][2] == 1 || tris->board[0][2] == 2))
	 ))
		tris->fineGioco = 1;
}

void casellePiene(Tris tris){
	if(!(tris->board[0][0] == 0 || tris->board[0][1] == 0 || tris->board[0][2] == 0
	|| tris->board[1][0] == 0 || tris->board[1][1] == 0 || tris->board[1][2] == 0
	|| tris->board[2][0] == 0 || tris->board[2][1] == 0 || tris->board[2][2] == 0))
		tris->fineGioco = 1;
}

int fineDelGioco(Tris tris){
	return tris->fineGioco;
}

char* vincitore(Tris tris){
	return tris->winner;
}

void setTurno(Tris tris){
	tris->turno = 1;
}

void setBoard(Tris tris){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			tris->board[i][j] = 0;
		}
	}
}

void setWinner(Tris tris){
	tris->winner = (char*)malloc(sizeof(char)*10);
	strcpy(tris->winner,"PATTA");
	//tris->winner = 0;
}

void setVincitore(Tris tris, char* w){
	strcpy(tris->winner,w);
	//tris->winner = w;
}

void setFineGioco(Tris tris){
	tris->fineGioco = 0;
}

int main(void) {
	//struct Tris tris;
	Tris tris = (Tris)malloc(sizeof(struct TrisStruct));

	setTurno(tris);
	setBoard(tris);
	setWinner(tris);
	setFineGioco(tris);

	while(fineDelGioco(tris) != 1){
		if(stampaTurno(tris) == 1){
			printf("U1: \n");
			setUtente(tris,1);

			vincita(tris);
			if(fineDelGioco(tris) == 1){
				char u1[] = "UTENTE1";
				setVincitore(tris, u1);
			}

			cambiaTurno(tris);
		}
		else{
			printf("U2: \n");
			setUtente(tris,2);

			vincita(tris);
			if(fineDelGioco(tris) == 1){
				char u2[] = "UTENTE2";
				setVincitore(tris, u2);
			}

			cambiaTurno(tris);
		}

		stampaBoard(tris);
		casellePiene(tris);
	}

	printf("Vincitore: %s", vincitore(tris));

	return EXIT_SUCCESS;
}
