#include "Node.h"

// Constructeur qui initialise le nœud avec un nom donné
Node::Node(std::string name) : name(name) {}

 // Ajoute un enfant à la liste des enfants du nœud
void Node::addChild(Node* child) {
    children.push_back(child); // Ajoute le pointeur vers l'enfant dans le vecteur
}

// Supprime un enfant de la liste par son nom
bool Node::supprimer_enfant(const std::string& nomEnfant) {
    for (size_t i = 0; i < children.size(); i++) {
        // Vérifie si le nom de l'enfant correspond à celui à supprimer
        if (children[i]->name == nomEnfant) {
            delete children[i]; // Libère la mémoire allouée à l'enfant
            children.erase(children.begin() + i); // Supprime l'enfant de la liste
            return true; // Retourne vrai si la suppression a réussi
        }
    }
    return false; // Retourne faux si l'enfant n'existe pas
}