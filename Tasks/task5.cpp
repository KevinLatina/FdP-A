//Student: Latina Kevin | Matricola : 335157 | task5
#include <iostream>
#include <cstring>
using namespace std;


struct persona {
    char nome[255] ;
    char cognome [255];
    char numero [255];
};

const int MAX = 100;

int main () {
    persona rubrica[MAX];
    int cursor = 0;
    int op;
    bool wrongop;
    char  numeroprovvisorio [254];
    persona p{};
    char nome[254], cognome[254];

    do {

        do {
            wrongop = false;
            cout << " *** Rubrica *** " << endl;
            cout << "\t 1 - Visualizza rubrica " << endl;
            cout << "\t 2 - Inserisci contatto" << endl;
            cout << "\t 3 - Cancella contatto " << endl;
            cout << "\t 4 - Esci  " << endl;
            cout << " \t Scegli operazione: " ;

            cin >> op;
            cin.ignore();

            if (op < 0 || op > 4) {
                cout << "Comando errato! Inserire un valore tra 1 e 4 !" << endl;
                wrongop = true;

            }

        } while (wrongop);


        switch (op) {

            //STAMPA
            case 1: {
                cout << endl;
                if (cursor == 0 )
                    cout << "Rubrica vuota \n " << endl;
                else {
                    cout << "Contatti salvati:  " <<endl;
                    for (int i = 0; i < cursor; i++) {
                        cout << " - " << rubrica[i].nome << "  " << rubrica[i].cognome << "  " << rubrica[i].numero << endl;

                    }
                    cout <<endl;
                }
            }
                break;

                //INSERIMENTO NUOVO CONTATTO (Controllo su contatto gia' presente non ancora implementato)
            case 2: {
                bool numberfail ;
                cout << "Inserisci nome del contatto: ";
                cin.getline (p.nome, 254);
                cout << "Inserisci cognome del contatto: ";
                cin.getline(p.cognome, 254);


                do {

                    numberfail = false;
                    cout << "Inserisci numero di telefono: ";
                    cin >> numeroprovvisorio;
                    cin.ignore();

                    if (strlen(numeroprovvisorio) != 10) {
                        numberfail = true;
                        cout << "Errore! Il numero di telefono deve essere di 10 cifre! " <<endl;
                    }


                    for (int i = 0 ; i < strlen(numeroprovvisorio) ; i++) {
                        if (numeroprovvisorio[i] < 48 || numeroprovvisorio[i] > 57) {
                            numberfail = true;
                            cout << "Errore! Il numero di telefono non puo' contenere lettere!" << endl;
                            break;

                        }
                    }

                    if (!numberfail)
                        for(int i = 0; i < 10; i++) {
                            p.numero[i] = numeroprovvisorio[i];
                        }


                } while (numberfail);

                //ASSEGNAMENTO persona P nell'array rubrica alla cella indicata da cursor
                rubrica[cursor] = p;
                cursor++;
                cout << "\n Contatto aggiunto! \n " << endl;

            }
                break;

            case 3: {
                if (cursor == 0 )
                    cout << "Rubrica vuota \n";
                else {
                    bool deleted = false;

                    cout << "Inserisci il nome del contatto da cancellare: ";
                    cin.getline(nome, 254);
                    cout << "Inserisci il cognome del contatto da cancellare: ";
                    cin.getline(cognome, 254);

                    /*
                     * ELIMINAZIONE CONTATTO: SCORRO ARRAY PER LA LUNGHEZZA DI CONTATTI SALVATI,
                     * SE NE TROVO UNO DA ELIMINARE "COMPRIMO" L'ARRAY VERSO SINISTRA
                     * SOVRASCRIVENDO LA CELLA IN CUI C'E IL CONTATTO DA ELIMINARE E RIFACCIO IL CONTROLLO
                     */
                    for (int i = 0 ; i < cursor; i++ ) {
                        if (strcmp(nome , rubrica[i].nome) == 0 && strcmp (cognome , rubrica[i].cognome) == 0) {
                            deleted = true;
                            for (int j = i ; j < cursor - 1; j++)
                                rubrica[j] = rubrica[j+1];
                            i--;
                            cursor--;
                        }
                    }

                    if (deleted)
                        cout << "\n Contatto eliminato con successo! \n" <<endl;
                    else
                        cout << "\n Contatto non trovato in rubrica! \n" <<endl;
                }

            }
                break;

            default : {}
        }

    } while (op != 4);

    return 0;
}





