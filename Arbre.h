#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include <iostream>

using namespace std;

// Définition du noeud en tant que struct
template <typename T>
struct Noeud
{
    T donnees;
    Noeud <T>* gauche;
    Noeud <T>* droit;
};

// Définition de la classe Liste
template <class T>
class Arbre
{
    private:
        Noeud <T>* racine;
        int compteur;
        Noeud <T>* CreerNoeud (const T& valeur);
        void detruire (Noeud <T>* ptr); // Fonction d'aide
        void inserer (const T& value, Noeud <T>*& ptr); // Fonction d'aide
        void infixe (Noeud <T>* ptr) const; // Fonction d'aide
        void prefixe (Noeud <T>* ptr) const; // Fonction d'aide
        void postfixe (Noeud <T>* ptr) const; // Fonction d'aide
        Noeud <T>* successeur (Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide
        Noeud <T>* predecesseur (Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide
        void supprimer (Noeud <T>* ptr, Noeud <T>* parent); // Fonction d'aide
        Noeud <T>* recherche (const T& value, Noeud <T>* ptr, Noeud <T>*& parent) ; // Fonction d'aide
        int occurecene_arbre(Noeud<T>*arbre,int n);
        T max_arbre(Noeud<T>* noeud);
        void Aff_Arbre_horiz(Noeud<T> *node, int Niv);
    public:
        Arbre ();
        ~Arbre ();
        void inserer (const T& value);
        void detruire ();
        void supprimer (const T& value);
        Noeud <T>* recherche (const T& value) ;
        void infixe () const;
        void prefixe () const;
        void postfixe () const;
        int taille () const;
        bool estVide () const;
        void Aff_Arbre_horiz();
        int occurecene_arbre(int n);
        T max_arbre();
        bool Search(T val);
};



#endif // ARBRE_H_INCLUDED
