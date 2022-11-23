#include <iostream>
#include <cstring>
using namespace std;

/* FUNZIONE SEPARA: Utilizzo countalpha e countnum per contare
 * quante lettere e numeri trovo nella stringa e restituire il loro valore
 * alle variabili lenghtalpha e lenghtnum del main  che vengono utilizzate
 * per sapere fin dove stampare gli array sAlpha ed sNum del main
 */

bool separa (char s[]  , char alpha [] , char num [] , int& countalpha , int&countnum) {

    if (strlen(s) == 0 )
        return false;

    else {

        for (int i = 0; s[i] != '\0'; i++) {
            if (isalpha(s[i])) {
                alpha[countalpha] = s[i];
                countalpha++;
            }

            else if (isdigit(s[i])) {
                num[countnum] = s[i];
                countnum++;
            }

        }
        return true;
    }
}

void stampa (char array [] , int lenght) {
    for (int i = 0 ; i < lenght; i++)
        cout << array[i] << "  ";
    cout << endl;
}

int main () {

    char str[101];
    int lenghtalpha = 0;
    int lenghtnum = 0;
    char sAlpha[100];
    char sNum[100];

    // INPUT STRINGA
    cout << "Inserisci stringa:  ";
    cin.getline(str, 101);

    // CONTROLLO SULL'INSERIMENTO DELLA STRINGA
    if (cin.fail()){
        cin.ignore(5000 , '\n' );
        cin.clear();
    }

    // CHIAMATA A FUNZIONE SEPARA
    if (separa(str, sAlpha, sNum, lenghtalpha, lenghtnum)) {

        if (lenghtalpha != 0) {
            cout << "Caratteri alfabetici: " << endl;
            stampa (sAlpha , lenghtalpha);
        }

        if (lenghtnum != 0){
            cout << "Caratteri numerici:  " << endl;
            stampa(sNum , lenghtnum);
        }

    }
    else
        cout << "Stringa vuota." ;

    return 0;
}