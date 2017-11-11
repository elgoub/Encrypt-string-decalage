#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cctype>
#include <iterator>

using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementDecal {

public:

    // Constructeur prenant le decalage voulu en argument
    ChiffrementDecal(int decalage) {
        m_decalage = (decalage % 26);
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    char operator()(char c) {

        if (isalpha(c) && isupper(c)) {
            string::iterator it2 = find(alphabet.begin(), alphabet.end(), c);
            return *(it2 + m_decalage);
        } else {
            return c;
        }
    }

private:

    int m_decalage; // Le decalage a appliquer au texte
    string alphabet;

};


int main() {
    // flux pour afficher le resultat
    ostream_iterator<char> itOut(cout, ", ");
    // Le message a crypter
    string texte("BIENVENUE SUR LE MOOC C++ D'OCR !!");
    // Demande du decalage a l'utilisateur
    cout << "Quel decalage voulez-vous utiliser ? ";
    int decalage;
    cin >> decalage;

    // Creation du foncteur
    ChiffrementDecal foncteur(decalage);

    // Chaine de caracteres pour le message crypte
    string texte_crypte;
    texte_crypte.resize(texte.size());
    transform(texte.begin(), texte.end(), texte_crypte.begin(), foncteur);

    cout << texte_crypte << endl;

    for (string::iterator it = texte_crypte.begin(); it != texte_crypte.end(); ++it) {
        *itOut = *it;
    }

    return 0;
}