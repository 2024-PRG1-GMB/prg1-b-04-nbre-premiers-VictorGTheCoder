
//Created by Victor Giordani
//Date: 3 October 2024


#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void afficher_vector_bool(vector<bool> v) {
    for (bool nb : v) {
        cout << nb << ", ";
    }
    cout << endl;
}

void afficher_vector_bool_en_decimal(vector<bool> v) {
    for (int nb = 0; nb < v.size(); ++nb) {
        if (v[nb]) cout << '\t' << nb << " ";
    }
    cout << endl;
}

void cribleEratosthene(int limite) {
    vector<bool> cribleBoolean(limite, true);
    cribleBoolean[0] = false;
    cribleBoolean[1] = false;


    for (int p = 2; p * p <= limite; ++p) {
        if (cribleBoolean[p]) {
            for (int i = p; i <= limite; i+=p) {
                cribleBoolean[i] = false;
            }
        }
    }
    afficher_vector_bool_en_decimal(cribleBoolean);
}

void afficher_nombre_premier(int limite) {
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
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int limite;
    START:    
    do
    {
        cout << "Saisir un valeur entre 2 et 1000 : ";
        cin >> limite;
    } while (limite < 2 || limite > 1000);

    afficher_nombre_premier(limite);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken " << duration.count() << "us" << endl;

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