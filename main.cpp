/*
Created by Victor Giordani
Date: 3 October 2024
*/

#include <iostream>

using namespace std;


int main() {
    int limite;

    START:    
    do
    {
        cout << "Saisir un valeur entre 2 et 1000 : ";
        cin >> limite;
    } while (limite < 2 || limite > 1000);

    const int nombre_par_ligne = 5;
    int nb_actuellement_affiche = 0;

    for (int nombre_test = 2; nombre_test <= limite; nombre_test++) {
        bool est_premier = true;
        for (int diviseur = 2; diviseur * diviseur <= nombre_test; diviseur++) {
            if (nombre_test % diviseur == 0) {
                est_premier = false;
                break;
            }
        }

        if (est_premier) {
            cout << "\t" << nombre_test << " ";
            nb_actuellement_affiche++;
            if (nb_actuellement_affiche == nombre_par_ligne)
            {
                cout << endl;
                nb_actuellement_affiche = 0;
            }
        }
    }
    cout << endl;

    char restartProgram;
    do
    {
        cout << "Voulez vous recommencez [O/N] : ";
        cin >> restartProgram;
    } while (restartProgram != 'N' && restartProgram != 'O');
    
    if (restartProgram == 'O')
        goto START;

    return EXIT_SUCCESS; 
}
