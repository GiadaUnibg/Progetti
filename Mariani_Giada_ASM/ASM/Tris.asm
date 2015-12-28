//*****************************//
//** --- GIOCO DEL TRIS --- **//
//****************************//

asm Tris

import StandardLibrary

signature:
// DOMAINS
	domain Coordinate subsetof Integer
	enum domain Utenti = {UTENTE1 | UTENTE2}
	enum domain Turno = {TURNO_UTENTE1 | TURNO_UTENTE2}
	enum domain Winner = {VINCITORE_UTENTE1 | VINCITORE_UTENTE2 | PATTA}

	
// FUNCTIONS
	controlled board: Prod(Coordinate, Coordinate) -> Utenti
	controlled turno: Turno
	controlled winner: Winner
	monitored sceltaRigaUtente: Coordinate 		//Riga scelta dall'utente
	monitored sceltaColonnaUtente: Coordinate 	//Colonna scelta dall'utente
	derived vincitore: Utenti -> Boolean
	derived fineGioco: Boolean

definitions:
// DOMAIN DEFINITIONS
	domain Coordinate = {1..3}
	
// FUNCTION DEFINITIONS
	function vincitore($s in Utenti) =
		(exist $r in Coordinate with (forall $c in Coordinate with board($r, $c) = $s)) or
		(exist $c2 in Coordinate with (forall $r2 in Coordinate with board($r2, $c2) = $s)) or
		(forall $d in Coordinate with board($d, $d) = $s) or
		(forall $d1 in Coordinate with board($d1, 4 - $d1) = $s)

	function fineGioco =
		(exist $s in Utenti with vincitore($s)) or
		(forall $r in Coordinate, $c in Coordinate with isDef(board($r, $c)))
		
// RULE DEFINITIONS
	rule r_sceltaUtente1 =
		let ($r = sceltaRigaUtente, $c = sceltaColonnaUtente) in
			if(isUndef(board($r, $c))) then
				par
					board($r, $c) := UTENTE1
					turno := TURNO_UTENTE2
				endpar
			endif
		endlet

	rule r_sceltaUtente2 =
		choose $r in Coordinate, $c in Coordinate with isUndef(board($r, $c)) do
			par
				board($r, $c) :=  UTENTE2
				turno := TURNO_UTENTE1
			endpar
			
// INVARIANTS
	invariant inv_win over vincitore:  not(vincitore(UTENTE1) and vincitore(UTENTE2))

// MAIN RULE
	main rule r_Main =
		if(not(fineGioco)) then
			if(turno = TURNO_UTENTE1) then
				r_sceltaUtente1[]
				//if(vincitore)
					//winner := VINCITORE_UTENTE1
				//endif
			else
				r_sceltaUtente2[]
			endif
		//else
			//if(vincitore) then
				//if(turno = TURNO_UTENTE1)
					//winner := VINCITORE_UTENTE1
				//else
					//winner := VINCITORE_UTENTE2
				//endif
			//endif
		endif
		
// INITIAL STATE
default init s0:
	function turno = TURNO_UTENTE1
	function winner = PATTA
