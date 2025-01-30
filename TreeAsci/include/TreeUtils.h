




#ifndef TREEUTILS_H
#define TREEUTILS_H

#include "Node.h"

// Déclarations de fonctions utilitaires pour manipuler l'arbre

// Libère la mémoire de l'arbre en supprimant tous les nœuds
void deleteTree(Node* node);

// Affiche l'arbre de manière hiérarchique avec indentation
void printTree(Node* node, std::string prefix = "", bool isLast = true);

// Cherche un nœud par son nom dans l'arbre
Node* findNode(Node* node, const std::string& name);

// Ajoute un nouveau nœud sous un parent spécifié
Node* addNode(Node* root);

// Supprime un nœud de l'arbre en se basant sur son nom
void removeNode(Node* parent);

#endif // TREEUTILS_H