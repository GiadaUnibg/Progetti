/*
 * Tris.cpp
 *
 *  Created on: 30 dic 2015
 *      Author: Giada
 */

#include <iostream>
#include <string.h>
using namespace std;

class Tris{
private:
	int board[3][3];
	int turno;
	int winner;
	bool fineGioco;

public:

	Tris(){
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j] = 0;
			}
		}

		winner = 0;
		fineGioco = false;
		turno = 1;
	}

	void cambiaTurno(){
		if(turno == 1)
			turno = 2;
		else
			turno = 1;
	}

	int stampaTurno(){
		return turno;
	}

	void setBoard(int u){
		int r, c;
	    bool i = false;
	      do{
	        cout<<"Inserisci riga: "<<endl;
	        cin>>r;
	        cout<<"Inserisci colonna: "<<endl;
	        cin>>c;

	        if((r >= 0 && r <= 2) || (c>=0 && c<=2)){
	          if(board[r][c] == 0){
	            board[r][c] = u;
	            i = true;
	          }
	        }
	      }while((r<0 || r>2 || c<0 || c>2) || i == false);
	}

	void stampaBoard(){
		int r, c;
		for(r = 0; r < 3; r++){
			for(c = 0; c < 3; c++){
				cout<< board[r][c]<< " | ";
			}
			cout<<endl;
		}
	}

	void vincita(){
	      if((((board[0][0] == board[0][1] && board[0][1] == board[0][2]) && (board[0][0] == 1 || board[0][0] == 2))
	          || ((board[1][0] == board[1][1] && board[1][1] == board[1][2]) && (board[1][0] == 1 || board[1][0] == 2))
	          || ((board[2][0] == board[2][1] && board[2][1] == board[2][2]) && (board[2][0] == 1 || board[2][0] == 2))
	          || ((board[0][0] == board[1][0] && board[1][0] == board[2][0]) && (board[0][0] == 1 || board[0][0] == 2))
	          || ((board[0][1] == board[1][1] && board[1][1] == board[2][1]) && (board[0][1] == 1 || board[0][1] == 2))
	          || ((board[0][2] == board[1][2] && board[1][2] == board[2][2]) && (board[0][2] == 1 || board[0][2] == 2))
	          || ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] == 1 || board[0][0] == 2))
	          || ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] == 1 || board[0][2] == 2))
	          )
	         )
	        fineGioco = true;
	}

	void casellePiene(){
		if(!(board[0][0] == 0 || board[0][1] == 0 || board[0][2] == 0
		|| board[1][0] == 0 || board[1][1] == 0 || board[1][2] == 0
		|| board[2][0] == 0 || board[2][1] == 0 || board[2][2] == 0))
			fineGioco = true;
	}

	bool fineDelGioco(){
		return fineGioco;
	}

	void setWinner(int w){
		winner = w;
	}

	int vincitore(){
		return winner;
	}
};


int main(){

	Tris tris;

	while(tris.fineDelGioco() != true){
		if(tris.stampaTurno() == 1){
			cout<<endl<<"U1:"<<endl;
			tris.setBoard(1);

			tris.vincita();
			if(tris.fineDelGioco() == true){
				tris.setWinner(1);
			}

			tris.cambiaTurno();
		}
		else{
			cout<<endl<<"U2:"<<endl;
			tris.setBoard(2);

			tris.vincita();
			if(tris.fineDelGioco() == true){
				tris.setWinner(2);
			}

			tris.cambiaTurno();
		}

		tris.stampaBoard();
		tris.casellePiene();
	}

	if(tris.vincitore() == 1)
		cout<<"Vincitore: UTENTE1"<<endl;
	if(tris.vincitore() == 2)
		cout<<"Vincitore: UTENTE2"<<endl;
	if(tris.vincitore() == 0)
		cout<<"Vincitore: PATTA"<<endl;
}
