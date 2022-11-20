// Studente: Latina Kevin  | Task 4
#include <iostream>
#include <cstring>
using namespace std;
int main () {

    char word1[101], word2[101] ;
    char exit[5] = "exit";
    int countprefix ;
    int countsuffix ;

    //CICLO INFINITO : TERMINA QUANDO L'UTENTE INSERISCE 'exit' IN UNA DELLE DUE PAROLE
    while (true) {
        countprefix = 0;
        countsuffix = 0;

        //LETTURA PRIMA PAROLA E CONTROLLO DI CONDIZIONE DI USCITA (exit)
        cout << "Inserire la prima parola (inserire exit per uscire): ";
        cin.getline(word1, 101);
        if (strcmp(exit, word1) == 0) {
            cout << "Addio" ;
            return 0 ;
        }

        //LETTURA PRIMA PAROLA E CONTROLLO DI CONDIZIONE DI USCITA (exit)
        cout << "Inserire la seconda parola (inserire exit per uscire): ";
        cin.getline(word2, 101);
        if (strcmp(exit, word2) == 0) {
            cout << "Addio" ;
            return 0 ;
        }
        /*
         * ESECUZIONE QUANDO LA PRIMA PAROLA E' PIU CORTA DELLA SECONDA
         * (countprefix & countsuffix contano quante lettere uguali trova
         * tra prima e seconda parola nei due casi di prefisso e suffisso)
         */

        if (strlen(word1) < strlen(word2)) {

            for (int i = 0; i < strlen(word1); i++) {
                if (word1[i] == word2[i])
                    countprefix++;
                if (word1[i] == word2[(strlen(word2) - strlen(word1) + i)])
                    countsuffix++;
            }

            if (countprefix == strlen(word1))
                cout << "La parola " << word1 << " e ' prefisso di " << word2 << endl;

            if (countsuffix == strlen(word1))
                cout << "La parola " << word1 << " e ' suffisso di " << word2 << endl;



            //ESECUZIONE SIMILIARE CON PRIMA PAROLA PIU LUNGA DELLA SECONDA

        } else if (strlen(word1) > strlen(word2)) {

            for (int i = 0; i < strlen(word2); i++) {
                if (word2[i] == word1[i])
                    countprefix++;
                if (word2[i] == word1[(strlen(word1) - strlen(word2) + i)])
                    countsuffix++;

            }

            if (countprefix == strlen(word2))
                cout << "La parola " << word2 << " e ' prefisso di " << word1 << endl;

            if (countsuffix == strlen(word2))
                cout << "La parola " << word2 << " e ' suffisso di " << word1 << endl;


        } else {
            if (strcmp(word1, word2) == 0) {
                cout << "Le due parole sono uguali." << endl;
                cout << "Reverse: ";
                for (int i = (int) (strlen(word1) - 1); i >= 0; i--)
                    cout << word1[i];
            }
            cout <<endl;
        }


    }

}
