/*  STRUCT 

Vorremmo "Modellare" una persona 
* NOME		 char nome [32]
* COGNOME	 char cognome [32] 
* ETA        int eta  	


persona_me_stesso 

nome   		|    "Vincenzo"
cognome     |	 "Arceri"
eta         |	  29


struct {
	t0 id0;        t = tipo  id = identificatore  x = nome della struct;
	t1 id1;
	t2 id2;
	.
	.
	.
	tn idn;

} x ;

*/


#include <iostream>
using namespace std ; 

int main () {

 struct {
   
   char nome[30];
   char cognome[30] ; 
   int eta;

 } me_stesso;



 // struct con dichiarazione

  struct {
   
   char nome[30];
   char cognome[30] ; 
   int eta;

 } me_stesso = {  "Vincenzo" , "Arceri" , 30 } ;

 ________________________________________________________________________________________


//DICHIARAZIONE DI UN NUOVO TIPO STRUCT !! IMPORTANTE !! (va fatto fuori dal MAIN)

 struct persona {
   
   char nome[30];
   char cognome[30] ; 
   int eta;

 };

#include <iostream>
using namespace std ; 

int main () {

 persona me_stesso = { "Vincenzo" , "Arceri" , 30} ;
 person  ciccio = {"Ciccio" , "Pastrengo " , 45} ;

 //ACCESSO AI VARI CAMPI DELLA STRUCT TRAMITE NOTAZIONE PUNTO = nomestruct.campo

 cout << me_stesso.nome << endl;
 cout << me_stesso.cognome << endl;
 cout << me_stesso.eta << endl;


	return 0;
}