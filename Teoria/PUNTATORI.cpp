//PUNTATORI 

/* Operatore di indirizzo (referencing) 
  			 x
  			[5]
  		 0x7ffee7c6f86c
  		 
 x - accesso al valore della variabile tramite il suo nome
 &x accesso all'indirizzio della variabile

 in C e C++ permette di manipolare sia i nomi che gli indirizzi di memoria come qualsiasi altro tipo di dato ; 	

*/ 

//Esercizio : ottenere  indirizzo di memoria di una variabile

int main () {

    int x = 5;
    int* p = &x;
    cout << "valore di x: " << x << endl;
    cout << "Indirizzo: " < p  <<endl;

    return 0;
}
/* OUTPUT
5         la variabile p punta a x: la variabile p contiene l'indirizzo di memoria di x 
0x7ffe... la variabile p e' allocata a sua volta ad un altro indirizzo di memoria */


/* &x 

- Se x e' di tipo int, &X e' di tipo _puntatore_ a int 
- Puntatore a tipo: si dichiara utilizzando il carattere * come suffisso al tipo di dato.

es. int *    puntatore a int
    float*   puntatore a float

es. int -> contiene valori interi , occupa 4 byte
    int * -> contiene intidirri di memoria i quali contengono interi , occupa 4 byte (su macchine da 32bit) e occupa 8 byte (su macchine a 64bit)  */

// OPERATORE DI DEREFERENCING

/* Come riferirsi a x tramite p ??

  *p  (cio'  a cui punta p)     

valuta al nome della variabile puntata da p

esempio

  p               x              q
[   ] --------> [ 5 ]         [  5  ]


int x = 5;
int*p = &x;
int q = *p;
*p = 7;


 p               x              q
[   ] --------> [ 7 ]         [  5  ]    x passa a 7 , q rimane 5;


esempio 

int i ;
int* p = &i;

for (i = 0 ; i < 10 ; i ++) 
   cout << *p  << endl;
return 0;

cosa dara' in output?? stampa da 0 a 9;


____________


int i = 5; 
int* p1 = &i;
int * p2 = &i;

cout << *p1 << " " << *p2 <<endl;
*p1 = *p1 + 1 ; 
cout << *p1 << "  " <<*p2 <<endl;
return0;

cosa stampa?


p1      i     p2
[]     [5]    []

output : 55

p1      i     p2
[]     [6]    []

output : 66



//PUNTATORI A PUNTATORI

-Un tipo puntatore puo puntare a qualsiasi tipo, anche ad un altro puntatore

int i = 42;
int* p1 = &i;
int** p2 = &p1;
int*** p3 = &p2;
**p2 = 3;

(*(*p2)) -> (*p1) -> x 


//PUNTATORE E ARRAY

int voti [4] = {27 , 30 , 18 , 19} 

- In C++ gli array sono implementati tramite puntatori
- voti e' un puntatore costante a interi del primo elemento dell'array


voti
 [] -------> [27]                                   Notazione vettoriale                Deferenziazzione
             [30]                                         voti[0]                            *voti
             [18]
             [19]



//ARITMETICA DEI PUNTATORI

E possibile effettuare delle operazioni aritmetiche sui puntatori

-Dato un puntatore p di tipo T:

 p + 1  Il risultato e' il puntatore p incrementato di un numero pari alla dimensione N del tipo T

 p - 1  Il risultato e' il puntatore p decrementato di un numero pari alla dimensione N del tipo T


es. int voti[4] = { 27, 30 ,18 ,19}

array di interi    [27] [30] [18] [19]
                   4bit 4bit 4bit 4bit

incrementa l'indirizzo di 4bit (perche e' int) * N
*voti = 27
*(voti +1) = 30
*(voti + 3) = 19

--------------------------------
int a[5] = {1 ,2 ,3 ,4 ,5} ;
int* p = a;  
++(*p);
++p;
++(*(p+2));
a++; //errore  a compile time
--------------------------------

//PUNTATORI NULLI

-Un puntatore inizializzato punta a qualche posizione specifica della memoria
-Un puntatore non inizializatto punta ad una posizione aleatoria della memoria

int* x;

-E`importante assegnare sempre un valore ai puntatori !!!
-Puntatore nullo: non indirizza a nessuna zona valida della memoria

int* x = NULL;                    int* x = 0; 
----------------------------------
es.
int x = 5 , y = 5;
int* p1 = &x; // p1 punta a x
int* p2 = &y;
*p1 = *p2 + 1; //cio a cui punta p1 (x che vale 5 ) viene aggiornato a cio a cui punta p2 + 1 (y che vale 5 + 1)
cout << x << "  " <<y;

stampa 6 e 5;
-------------------------------

int a1[3] = {2 , 7 ,8};
int a2[3] = {3 , 5 ,9};
cout << *(a1 + 1) + *a2;


*/





int* p;  //notazione indica puntatore p di tipo int
p = &x;  //referencing dell'indirizzo di memoria di x in p
cout << *p;  //dereferencing , indica cosa punta a p


int v[5] = {5 ,4 ,20 ,17 ,1};
cout << *v + *v*(v + 4) ; 

task5 PER CANCELLARE CONTATTO NON ELIMINARE, BASTA NON STAMPARE.