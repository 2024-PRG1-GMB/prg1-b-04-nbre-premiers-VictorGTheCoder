/*
Created by @VictorGTheCoder
Date: 3 October 2024
*/

#include <iostream>

using namespace std;


int main() {
    int         limite;
    const int   nombre_par_ligne = 5;
    int         compteur_affichage = 0;

    START:    
    do
    {
        cout << "Saisir un valeur entre 2 et 1000 : ";
        cin >> limite;
    } while (limite < 2 || limite > 1000);


    // Afficher les nombres premiers jusqu'à la limite
    for (int nombre = 2; nombre <= limite; nombre++) {
        bool est_premier = true;
        for (int diviseur = 2; diviseur * diviseur <= nombre; diviseur++) {
            if (nombre % diviseur == 0) {
                est_premier = false;
                break;
            }
        }

        if (est_premier) {
            cout << "\t" << nombre << " ";
            compteur_affichage++;
            if (compteur_affichage == nombre_par_ligne)
            {
                cout << endl;
                compteur_affichage = 0;
            }
        }
    }
    cout << endl;

    char reponse;
    do
    {
        cout << "Voulez-vous recommencez [O/N] : ";
        cin >> reponse;
    } while (reponse != 'N' && reponse != 'O');
    
    if (reponse == 'O')
        goto START;

    return EXIT_SUCCESS; 
}
