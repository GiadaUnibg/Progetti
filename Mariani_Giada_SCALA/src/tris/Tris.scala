/**
 * @author Mariani Giada
 * 
 * Progetto Info 3 - A.
 * Gioco del tris.
 * 
 */

package tris

/*
 * Importazione 
 */
import scala.collection.mutable.HashMap

/*
 * TRIS
 */
object Tris {

  /*
   * MAIN 
   */
  def main(args: Array[String]): Unit = {

    //DICHIARAZIONE VARIABILI
    val utenti = List ("UTENTE1", "UTENTE2")
    val coordinate = List(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val vincitore = List("UTENTE1", "UTENTE2", "PATTA")
    var winner = "PATTA"
    var fineGioco = false
    var board: Array[String] = new Array[String](9) 
    var turno = 1
    
    //STAMPA TURNO
    def stampaTurno(t: Int){
      if(t == 1) println("Turno utente 1")
      else
        println("Turno utente 2")
    }
    
    //CAMBIO DEL TURNO
    def cambiaTurno(t:Int){
      if(t == 1) turno = 2
      else turno = 1
    }
    
    //SCELTA COORDINATE UTENTE 1 
    def sceltaUtente1(){
      var c = 1
      var i = false
      do{
        println("U1: Inserisci casella da scegliere \n(0-1-2\n3-4-5\n6-7-8)\n")
        c = readInt
        if(c >= 0 && c <= 8){
          if(board(c) == null){
            board(c) = "UTENTE1"
            i = true
          }
        }
      }while((c < 0 || c > 8) || i == false)
    }
    
    //SCELTA COORDINATE UTENTE 2
    def sceltaUtente2(){
      var c = 1
      var i = false
      do{
        println("U2: Inserisci casella da scegliere \n(0-1-2\n3-4-5\n6-7-8)\n")
        c = readInt
        if(c >= 0 && c <= 8){
          if(board(c) == null){
            board(c) = "UTENTE2"
            i = true
          }
        }
      }while((c < 0 || c > 8) || i == false)
    }

    //FUNZIONE VINCITA
    def vincita(){
      if(
          (
              ((board(0) == board(1) && board(1) == board(2)) && (board(0) == "UTENTE1" || board(0) == "UTENTE2"))
          || ((board(3) == board(4) && board(4) == board(5)) && (board(3) == "UTENTE1" || board(3) == "UTENTE2"))
          || ((board(6) == board(7) && board(7) == board(8)) && (board(6) == "UTENTE1" || board(6) == "UTENTE2"))
          || ((board(0) == board(3) && board(3) == board(6)) && (board(0) == "UTENTE1" || board(0) == "UTENTE2"))
          || ((board(1) == board(4) && board(4) == board(7)) && (board(1) == "UTENTE1" || board(1) == "UTENTE2"))
          || ((board(2) == board(5) && board(5) == board(8)) && (board(2) == "UTENTE1" || board(2) == "UTENTE2"))
          || ((board(0) == board(4) && board(4) == board(8)) && (board(0) == "UTENTE1" || board(0) == "UTENTE2"))
          || ((board(2) == board(4) && board(4) == board(6)) && (board(2) == "UTENTE1" || board(2) == "UTENTE2"))
          )
         ){
        fineGioco = true
      }
    }

    //FUNZIONE CASELLE PIENE - PATTA
    def casellePiene(){
      if(board(0) == null || board(1) == null || board(2) == null ||  
         board(3) == null || board(4) == null || board(5) == null ||
         board(6) == null || board(7) == null || board(8) == null )
        fineGioco = false
      else
        fineGioco = true
    }
    
    //STAMPA BOARD
    def stampaBoard(){
      var i = 0
      
      for(i <- 0 to 2){
         print(board(i) + " | ")
      }
      
      println()
      
      for(i <- 3 to 5){
         print(board(i) + " | ")
      }
      
      println()
      
      for(i <- 6 to 8){
         print(board(i) + " | ")
      }
      
      println()
      println()
    }

    
    //FUNZIONAMENTO DEL GIOCO
    board.foreach { x => null }
    
    while(fineGioco == false){
      
      stampaBoard()
      stampaTurno(turno)
      
      if(turno == 1){
        sceltaUtente1()
        vincita()
        if(fineGioco == true)
          winner = "UTENTE1"
        cambiaTurno(turno)
      }
      else{
        sceltaUtente2()
        vincita()
        if(fineGioco == true)
          winner = "UTENTE2"
        cambiaTurno(turno)
      }
      
      casellePiene()
    }
    
    println("Vincitore: " + winner)
  }
}