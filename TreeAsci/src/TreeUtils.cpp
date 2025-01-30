#include "TreeUtils.h" // Assurez-vous que ce fichier est correct
#include <iostream>

// Libère la mémoire de l'arbre de manière récursive
void deleteTree(Node* node) {
    if (node == nullptr) return; // Vérification pour éviter les pointeurs nuls
    for (Node* child : node->children) {
        deleteTree(child); // Appel récursif pour libérer tous les enfants
    }
    delete node; // Libère le nœud actuel
}

// Affiche l'arbre avec une indentation pour montrer la hiérarchie
void printTree(Node* node, std::string prefix , bool isLast ) {
    if (node == nullptr) return; // Vérification pour éviter les pointeurs nuls
    std::cout << prefix; // Affiche le préfixe pour l'indentation
    if (isLast) {
        std::cout << "\\-- "; // Indicateur pour le dernier enfant
        prefix += "    "; // Ajoute de l'espace pour les sous-enfants
    } else {
        std::cout << "|-- "; // Indicateur pour un enfant intermédiaire
        prefix += "|    "; // Ajoute une barre pour les sous-enfants
    }
    std::cout << node->name << std::endl; // Affiche le nom du nœud

    // Appel récursif pour afficher les enfants
    for (size_t i = 0; i < node->children.size(); i++) {
        printTree(node->children[i], prefix, i == node->children.size() - 1);
    }
}

// Recherche un nœud par son nom dans l'arbre
Node* findNode(Node* node, const std::string& name) {
    if (node == nullptr) return nullptr; // Vérification pour éviter les pointeurs nuls
    // Vérifie si le nœud actuel correspond au nom recherché
    if (node->name == name) {
        return node; // Retourne le nœud trouvé
    }
    // Itère sur les enfants pour chercher le nœud
    for (Node* child : node->children) {
        Node* result = findNode(child, name);
        if (result != nullptr) {
            return result; // Retourne le nœud trouvé dans les enfants
        }
    }
    return nullptr; // Retourne nul si le nœud n'est pas trouvé
}

// Fonction pour ajouter un nœud
Node* addNode(Node* root) {
    std::string parentName, childName;
    std::cout << "Entrez le nom du parent sous lequel ajouter le nouveau nœud : ";
    std::cin >> parentName; // Demande le nom du parent

    Node* parentNode = findNode(root, parentName); // Recherche le parent
    if (parentNode) {
        std::cout << "Entrez le nom du nouveau nœud : ";
        std::cin >> childName; // Demande le nom du nouveau nœud
        Node* newNode = new Node(childName); // Crée le nouveau nœud
        parentNode->addChild(newNode); // Ajoute le nouveau nœud au parent
        return newNode; // Retourne le nouveau nœud
    } else {
        std::cout << "Nœud parent '" << parentName << "' non trouvé." << std::endl; // Message d'erreur
        return nullptr; // Retourne nul si le parent n'est pas trouvé
    }
}

// Supprime un nœud par son nom
void removeNode(Node* parent) {
    std::string name;
    std::cout << "Entrez le nom du nœud à supprimer : ";
    std::cin >> name; // Demande le nom du nœud à supprimer
    // Tente de supprimer le nœud et donne un retour à l'utilisateur
    if (parent != nullptr && parent->supprimer_enfant(name)) {
        std::cout << "Nœud '" << name << "' supprimé." << std::endl; // Confirmation de la suppression
    } else {
        std::cout << "Nœud '" << name << "' non trouvé." << std::endl; // Message d'erreur
    }
}