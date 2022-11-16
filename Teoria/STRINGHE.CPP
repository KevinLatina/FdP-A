//Stringhe

/* Array di caratteri che terminano con \0
  es. 'h' 'e' 'l' 'l' 'o' \0   e' una stringa
       'h' 'e' 'l' 'l' 'o  non e' una stringa perche manca \0
       'h' 'e' 'l' 'l' 'o  \0 'o' 'o' \0 'o'  e' una stringa ed e' fino al primo \0
       dichiarazione:
       char str[6] = { 'h' , 'e' , 'l' , 'l' , 'o' , \ };
       char str [] = { 'h' , 'e' , 'l' , 'l' , 'o' , \ };    N.B. = non e' obbligatorio dichiarare la lunghezza dell'array di caratteri se lo dichiaro esplicitamente
       char str [] = "hello" ;  modo piu veloce per dichiarare un array di stringhe dove la  lunghezza viene inferita dal compilatore e viene messo automaticamente il carattere \0
        DIFFERENZA TRA " " e ' ' : i due apici riconoscono una stringa, i singoli dei caratteri.

        getline da iostream:
        s.getline (str , l , d )
        s = stream di inpunt come "cin"
        str = stringa (array di caratteri
        l = numeri di caratteri da leggere dallo stream (n - 1)
        d= parametro opzionale che indica il carettere delimitarore della stringa cioe quello per il quale si interrompe la lettura * se assente si assume che il valore sia \n (a capo)
        SEMANTICA = estrai da s un carattere allal volta e memorizzali in str finche non incontri il carattere d oppure non leggi l - 1 caratteri (l'ultimo serve per lo 0 )


        LIBRERIA CSTRING____
        strlen (s) : lunghezza della stringa s
        strcpy (s , r )  : copia il contenuto della stringa r nella stringa s (fare attenzione alla lunghezza delle due stringhe)
        strcat (s, , r)  : Concatena la stringa r alla stringa s = modifica contenuto della variabile s
                             l'array in cui viene memorizzata la stringa risultante deve poter contenere la concatenazione delle due stringhe
        strcmp (s , r ) : Confronte due stringhe e ritora : valore   0 se le stringhe sono uguali
                                                            valore < 0 se la stringa  s precede lessicograficamente r
                                                            valore > 0 se le stringa r precede lessicograficamente s

           char s[20] ;
           char r[] =  "helloworld" 

ESERCIZIO codifiva una frase: scrivi programma che legge frase da tastiera lunga al piu 100 caratteri. il programma deve
 stampare frase letta
 costruire codifica della frase tale che :
 ognu vocale e' seguita da'f' (se la vocale e' maiuscola) oppure da 'F' ( se la vocale e' minuscola)
 */


#include <iostream>
using namespace std;
int main () {
    char str [101] ;
    cout << "Inserire frase di al massimo 100 caratteri:  "  << endl;
    cin.getline (str , 101 , '\n') ;

    int lenght = 0 ;
    for (int i = 0 ; str[i] != '\0' ; i++ )
        lenght++;

    char codifica [2 * lenght + 1] ;

    int next = 0;
    for (int i = 0 ; str[i] != '\0' ; i++) {
         codifica[next] = str[i];
         next++;
        if (str[i] == 'a' ||
            str[i] == 'e' ||
            str[i] == 'i' ||
            str[i] == 'o' ||
            str[i] == 'u')
        {
            codifica[next] = 'f' ;
            next++;
        } else if (str[i] == 'A'   ||
                  str[i] == 'E' ||
                  str[i] == 'I' ||
                  str[i] == 'O' ||
                  str[i] == 'U') {
        codifica[next] = 'F';
        next++;
        }

    }

    codifica[next] = '\0' ;

    cout << "La stringa originale e':  " <<str <<endl;
    cout << "Codifica:  " <<codifica ;



    return 0;
}