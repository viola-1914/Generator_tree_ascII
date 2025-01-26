#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Classe représentant un nœud dans l'arbre
class Node {
public:
    string name;  // Nom du nœud
    vector<Node*> children; // Liste des enfants

    // Constructeur
    Node(string name) : name(name) {}

    // Ajouter un enfant au nœud
    void addChild(Node* child) {
        children.push_back(child);
    }
};

// Fonction récursive pour afficher l'arbre avec indentation ASCII
void printTree(Node* node, string prefix = "", bool isLast = true) {
    cout << prefix;
    if (isLast) {
        cout << "\\-- ";
        prefix += "    ";
    } else {
        cout << "|-- ";
        prefix += "|    ";
    }

    cout << node->name << endl;

    for (size_t i = 0; i < node->children.size(); i++) {
        printTree(node->children[i], prefix, i == node->children.size() - 1);
    }
}

int main() {
    // Création des nœuds
    Node* root = new Node("Racine");
    Node* enfant1 = new Node("Enfant1");
    Node* enfant2 = new Node("Enfant2");
    Node* sousEnfant1 = new Node("SousEnfant1");
    Node* sousEnfant2 = new Node("SousEnfant2");

    // Construction de l'arbre
    enfant1->addChild(sousEnfant1);
    enfant1->addChild(sousEnfant2);
    root->addChild(enfant1);
    root->addChild(enfant2);

    // Affichage de l'arbre
    printTree(root);

    // Libération de la mémoire (important pour éviter les fuites)
    delete sousEnfant1;
    delete sousEnfant2;
    delete enfant1;
    delete enfant2;
    delete root;

    return 0;
}
