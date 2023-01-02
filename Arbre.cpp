
#include"Arbre.h"


// Constructeur
template <class T>
Arbre <T> :: Arbre(){racine =0, compteur =0;}

// Destructeur
template <class T>
Arbre <T> :: ~Arbre ()
{
    detruire(racine);
}
// La fonction d'aide (Récursive) appelée par le destructeur
template <class T>
void Arbre <T> :: detruire (Noeud <T>* ptr)
{
    if (!ptr){return;}

    detruire (ptr -> gauche); // détruire le sous-arbre gauche
    detruire (ptr -> droit); // détruire le sous-arbre droit
    delete ptr; // détruire la racine
}

// La fonction d'aide (Récursive) appelée par la fonction membre inserer
template <class T>
void Arbre <T> :: inserer (const T& valeur, Noeud <T>*& ptr)
{
    // si l'arbre vide, inserer comme racine
    if (!ptr){
        ptr = CreerNoeud (valeur);
        return;
    }
    // si la valeur est inférieure à la valeur de racine,
    // insérer le noeud dans le sous-arber gauche
    else if (valeur < ptr -> donnees){
        inserer (valeur, ptr -> gauche);
    }
    // Sinon, insérer le noeud dans le sous-arber droit
    else{
        inserer (valeur, ptr -> droit);
    }
}

// Fonction d'aide (Récursive) appeler par la fonction membre recherche
template <class T>
Noeud <T>* Arbre <T> :: recherche (const T& valeur, Noeud <T>* ptr, Noeud <T>*& parent)
{
    if (!ptr){
        //Arbre est vide
        return NULL;
    }
    else if ((ptr->donnees) == valeur){
        // la valeur recherchée est stockée dans la racine
        return ptr;
    }
    else if (valeur < (ptr->donnees)){
        parent=ptr;
        // la valeur recherchée est dans le sous-arbre gauche
        return recherche (valeur, ptr->gauche, parent);
    }
    else{
        parent=ptr;
        // sinon, la valeur recherchée est dans le sous-arbre droit
        return recherche (valeur, ptr->droit, parent);
    }
}
/**
Cette méthode permet de renvoyer le successeur
 d’un nœud qui est le nœud avec la valeur minimale
  dans son sous-arbre droit. Cette méthode utilisée
   lorsque l'on veut supprimer un nœud avec deux enfants

Cette méthode utilisait un paramètre parent
 (passé en référence) utilisé pour stocker le parent du nœud en question.
**/

template <class T>
Noeud <T>* Arbre <T> :: successeur (Noeud <T>* ptr, Noeud <T>*& parent) const{
    if (!ptr){return NULL;}

    Noeud <T>* courant = ptr;
    while (courant->gauche != 0){
        parent = courant;
        courant = courant -> gauche;

    }
    return courant;
}

/**

Cette méthode permet de renvoyer le prédécesseur
 d’un nœud qui est le nœud avec la valeur maximale
  dans son sous-arbre gauche. Cette méthode utilisée
   lorsque l'on veut supprimer un nœud avec deux enfants.

Cette méthode utilisait un paramètre parent
 (passé en référence) utilisé pour stocker
  le parent du nœud en question.
**/

template <class T>
Noeud <T>* Arbre <T> :: predecesseur (Noeud <T>* ptr, Noeud <T>*& parent) const{
    if (!ptr){return NULL;}

    Noeud <T>* courant = ptr;
    while (courant->droit != 0){
        parent = courant;
        courant = courant -> droit;
    }
    return courant;
}

template <class T>
void Arbre <T> :: supprimer (Noeud <T>* ptr, Noeud <T>* parent){

    if (ptr->gauche == 0 && ptr->droit == 0)
    {
        if (ptr != racine)
        {
            if (parent->gauche == ptr)
                parent->gauche = NULL;
            else
                parent->droit = NULL;
        }
        else
            racine = NULL;

        delete ptr;
    }
    else if (ptr->gauche && ptr->droit)
    {
        Noeud <T>* pere = ptr;
        // ici vous pouvez utiliser le prédécesseur aussi
        Noeud <T>* succ  = successeur(ptr->droit, pere);
        int val = succ->donnees;
        supprimer(succ, pere);
        ptr->donnees = val;
    }
    else
    {
        Noeud <T>* enfant = (ptr->gauche)? ptr->gauche: ptr->droit;
        if (ptr != racine)
        {
            if (ptr == parent->gauche)
                parent->gauche = enfant;
            else
                parent->droit = enfant;
        }

        else
            racine = enfant;

        delete ptr;
    }
}

/**
Cette méthode est appelée par la méthode publique supprimer après avoir localisé le nœud
**/
template <class T>
void Arbre <T> :: supprimer (const T& valeur)
{
    Noeud <T>* parent = 0;
    Noeud <T>* del = recherche(valeur, racine, parent);
    if(del == 0){
        cout << "Le noeud n'appartient pas a l'arbre" << endl;
    }
    else{
        supprimer(del, parent);
    }
}

// Fonction d'aide (Récursive) appeler par la fonction infixe
template <class T>
void Arbre <T> :: infixe (Noeud <T>* ptr) const
{
    if (!ptr){return;}

    infixe (ptr -> gauche);
    cout << ptr -> donnees << '\t';
    infixe (ptr -> droit);
}

// Fonction d'aide (Récursive) appeler par la fonction prefixe
template <class T>
void Arbre <T> :: prefixe (Noeud <T>* ptr) const
{
    if (!ptr){return;}

    cout << ptr -> donnees << '\t';
    prefixe (ptr -> gauche);
    prefixe (ptr -> droit);
}

// Fonction d'aide (Récursive) appeler par la fonction postfixe
template <class T>
void Arbre <T> :: postfixe (Noeud <T>* ptr) const
{
    if (!ptr){return;}

    postfixe (ptr -> gauche);
    postfixe (ptr -> droit);
    cout << ptr -> donnees << '\t';
}

template <class T>
Noeud <T>* Arbre <T> :: CreerNoeud (const T& valeur){
    Noeud <T>* temp = new Noeud <T>;
    temp -> donnees = valeur;
    temp -> gauche = NULL;
    temp -> droit = NULL;
    return temp;
}
// Inserer un noeud
template <class T>
void Arbre <T> :: inserer (const T& valeur)
{
    inserer (valeur, racine);
    compteur++;
}

// Rechercher un noeud
template <class T>
Noeud <T>* Arbre <T> :: recherche (const T& valeur)
{
    Noeud <T>* parent = 0;
    return recherche (valeur, racine,parent);
}

// Parcours infixe
template <class T>
void Arbre <T> :: infixe () const
{
    infixe(racine);
}

// Parcours prefixe
template <class T>
void Arbre <T> :: prefixe () const
{
    prefixe(racine);
}

// Parcours postfixe
template <class T>
void Arbre <T> :: postfixe () const
{
    postfixe(racine);
}
 // Nombre de noeud dans l'arbre
template <class T>
int Arbre <T> :: taille () const
{
    return compteur;
}

template <class T>
bool Arbre <T> :: estVide () const
{
    return (compteur == 0);
}

//afficher l arbre horizontalement
template<class T>
void Arbre<T>::Aff_Arbre_horiz(Noeud<T> *node, int Niv)
{
    int esp;
    if (node)
    {
        Aff_Arbre_horiz(node->droit, Niv + 1);
        cout<<endl;
        for (esp = 0; esp < Niv; esp++)
            cout<<"\t";
        cout << node->donnees;
        Aff_Arbre_horiz(node->gauche, Niv + 1);
    }
}

template<class T>
void Arbre<T>:: Aff_Arbre_horiz()
{
  Aff_Arbre_horiz(racine,0);
}


///le maximum de l'arbre
template<class T>
T Arbre<T>:: max_arbre(Noeud<T>* noeud)
{
    Noeud<T>*q=0 ;
    if(!noeud)
    {
        printf("arbre vide !\n");
        exit(0);
    }
   for(q=noeud;q->droit;q=q->droit);
   return  q->donnees;
}
template<class T>
T Arbre<T>:: max_arbre()
{
    return max_arbre(racine);
}

///le nombre d occurence d un element  dans un arbre

template<class T>
int Arbre<T>::occurecene_arbre(Noeud<T>*arbre,int n)
{
    if(!arbre) return 0;
    if(arbre->donnees==n) return 1+occurecene_arbre(arbre->gauche,n)+occurecene_arbre(arbre->droit,n);
   return occurecene_arbre(arbre->gauche,n)+occurecene_arbre(arbre->droit,n);
}

template<class T>
int Arbre<T>::occurecene_arbre(int n)
{
    return occurecene_arbre(racine,n);
}


template<class T>
bool Arbre<T>::Search(T val)
{
// Calling Search() operation
// and passing root node
    Noeud<T> * result = recherche( val);
// If value is found then return true
// else return false
    return result != nullptr;
}
