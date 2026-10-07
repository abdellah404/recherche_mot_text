#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Utilisation : ./search MOT" << endl;
        return 1;
    }

    string mot = argv[1];

    ifstream fichier("words_500k.txt");

    if (!fichier) {
        cout << "Erreur ouverture fichier" << endl;
        return 1;
    }

    string contenu(
        (istreambuf_iterator<char>(fichier)),
        istreambuf_iterator<char>()
    );

    auto debut = high_resolution_clock::now();

    size_t position = contenu.find(mot);

    auto fin = high_resolution_clock::now();

    auto temps = duration_cast<microseconds>(fin - debut);

    if (position != string::npos)
        cout << "Mot trouve a la position : " << position << endl;
    else
        cout << "Mot non trouve" << endl;

    cout << "Temps : " << temps.count()
         << " microsecondes" << endl;

    return 0;
}