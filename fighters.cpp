#ifndef TESTS
#include <iostream>
#include <string>

#include "fighters.h"

#include <cstdlib>

using namespace std;


int main(){


    Fighter* fighter[10] = {0};


    while(1){

        int iMenuSelect = 0;


        // menuedesign mit auswahl

        cout << "\nMenu: " << endl;
        cout << " _________________________" << endl;
        cout << "/ \\                       \\" << endl;
        cout << "\\_|                       |" << endl;
        cout << "  |  1. CREATE FIGHTER    |" << endl;
        cout << "  |  2. PICK 2 FIGHTERS   |" << endl;
        cout << "  |  3. LAST MAN STANDING |" << endl;
        cout << "  |  4. VIEW FIGHTERS     |" << endl;
        cout << "  |  5. DELETE FIGHTER    |" << endl;
        cout << "  |  6. MANUAL/INFO       |" << endl;
        cout << "  |  7. QUIT              |" << endl;
        cout << "  |                       |" << endl;
        cout << "  |  _____________________|_" << endl;
        cout << "  \\_/______________________/" << endl;
        cout << "\nBitte benuetzen sie die Menuepunkte(Nummern) um zu navigieren: ";

        cin >> iMenuSelect;
        cout << "\n";

        switch(iMenuSelect){
            case 1: //create fighter
            {

                create(fighter);

                break;
            }
            case 2: //pick fighter
            {
                pick(fighter);

                break;
            }
            case 3: //last man standing
            {
                int fighterAmount = 0;

                for(int i=0; i<10; i++){


                    if(fighter[i] != 0){

                        fighterAmount++;
                    }

                    cout << fighter[i] << endl;
                    cout << "amount: "<< fighterAmount << endl;
                }

                if(fighterAmount>= 2){
                    lastManStanding(fighter);
                }else{
                    cout << "Keine oder nur ein Kaempfer vorhanden, bitte erstellen sie Kaempfer." << endl;
                }

                break;
            }
            case 4: //view fighter
            {
                view(fighter);

                break;
            }
            case 5: //delete fighter
            {
                int loeschen=0;

                view(fighter);

                cout << "Welcher Kaempfer soll geloescht werden: " << endl;
                cin >> loeschen;



                fighter[loeschen-1]= nullptr;

                delete fighter[loeschen-1];

                cout << "Kaempfer Nummer " << loeschen << " wurde geloescht." << endl;

                break;

            }
            case 6: //manual
            {

                cout << "Menu: \n1. CREATE FIGHTER: Anzahl der Kaempfer die erstellt werden eingeben(1-10).\n    Dannach folgt eine Eingabeaufforderung fuer den Namen und der Klasse jedes Kaempfers." << endl;
                cout << "2. PICK 2 FIGHTERS: Kaempfer Nummer eins und zwei muessen gewaehlt werden.\n    Dannach kaempfen die zuvor gewaehlten Kaempfer bis einer stirbt. " << endl;
                cout << "3. LAST MAN STANDING: Alle Kaempfer kaempfen gegeneinander bis nur noch einer uebrig ist." << endl;
                cout << "4. VIEW FIGHTERS: Auflistung aller Kaempfer" << endl;
                cout << "5. DELETE FIGHTER: Loeschen eines einzelnen Kaempfers." << endl;
                cout << "6. MANUAL/INFO: Anleitung fuer den Nutzer." << endl;
                cout << "7. QUIT: Programm wird beendet. \n" << endl;

                break;
            }
            case 7: //quit
            {return 0;}

            default:   //exception handling
            {
                cout << "Eingabe nicht gueltig!" << endl;
            }

        }
    }


    return 0;
}

#endif
