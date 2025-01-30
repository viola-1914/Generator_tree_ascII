#ifndef NODE_H
#define NODE_H







#include <string>
#include <vector>

// Classe représentant un nœud dans l'arbre
class Node {
public:
    std::string name;  // Nom du nœud
    std::vector<Node*> children; // Liste des pointeurs vers les enfants du nœud

    // Constructeur qui initialise le nœud avec un nom
    Node(std::string name);
    
    // Méthode pour ajouter un enfant au nœud
    void addChild(Node* child);
    
    // Méthode pour supprimer un enfant par son nom
    bool supprimer_enfant(const std::string& nomEnfant);
};

#endif // NODE_H