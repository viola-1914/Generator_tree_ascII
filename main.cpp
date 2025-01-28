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

    //supprimer un enfant par nom
    bool supprimer_enfant(const string& nomEnfant){
        for(size_t i=0; i<children.size(); i++){
            if(children[i]->name ==nomEnfant) {
            delete children[i]; //liberer la mémoire
            children.erase(children.begin() + i); //supprimer de la liste
            return true; // l'enfant est supprimer
            }
        }
        return false; // l'enfant n'hesite pas 
    }
};

// Fonction pour libérer la mémoire de l'arbre
void deleteTree(Node* node) {
    for (Node* child : node->children) {
        deleteTree(child); // Appel récursif pour libérer les enfants
    }
    delete node; // Libérer le nœud actuel
}
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

// Fonction pour ajouter un noeud
Node* addNode(Node* parent) {
    string name;
    cout << "Entrez le nom du nouveau nœud : ";
    cin >> name;
    Node* newNode = new Node(name);
    parent->addChild(newNode);
    return newNode;
}



// supprimé un noeud
void removeNode(Node* parent) {
    string name;
    cout << "Entrez le nom du nœud à supprimer : ";
    cin >> name;
    if (parent->supprimer_enfant(name)) {
        cout << "Nœud '" << name << "' supprimé." << endl;
    } else {
        cout << "Nœud '" << name << "' non trouvé." << endl;
    }
}

int main() {
    // Création du noeud racine
    Node* root = new Node("Racine");
      while (true)
      {
        /* code */
     

        cout << "\nMenu :\n";
        cout << "1. Afficher l'arbre\n";
        cout << "2. Ajouter un nœud\n";
        cout << "3. Supprimer un nœud\n";
        cout << "4. Quitter\n";
        cout << "Choisissez une option : ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                printTree(root);
                break;
            case 2: {

                
               addNode(root);
                break;
                 }
            case 3:
                removeNode(root);
                break;
            case 4:
                // Libération de la mémoire avant de quitter
                 deleteTree(root); // Vous pouvez étendre cela pour libérer tous les nœuds
                return 0;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    }


    return 0;
}
