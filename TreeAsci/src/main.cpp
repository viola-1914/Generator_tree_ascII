#include <iostream>
#include "Node.h"
#include "TreeUtils.h"

int main() {
    // Création du nœud racine de l'arbre
    Node* root = new Node("Chaîne Alimentaire");
    
    // Création de plusieurs nœuds enfants
    Node* Producteurs = new Node("Producteurs");
    Node* Plantes = new Node("Plantes");
    Node* Algues = new Node("Algues");
    Node* Herbivores = new Node("Herbivores");
    Node* Lapin = new Node("Lapin");
    Node* Cerf = new Node("Cerf");
    Node* Carnivores = new Node("Carnivores");
    Node* Loup = new Node("Loup");
    Node* Aigle = new Node("Aigle");
    Node* Omnivores = new Node("Omnivores");
    Node* Homme = new Node("Homme");
    Node* Singe = new Node("Singe");

    // Construction de l'arbre en ajoutant les nœuds enfants
    Producteurs->addChild(Plantes);
    Producteurs->addChild(Algues);
    Herbivores->addChild(Lapin);
    Herbivores->addChild(Cerf);
    Omnivores->addChild(Homme);
    Omnivores->addChild(Singe);
    Carnivores->addChild(Loup);
    Carnivores->addChild(Aigle);
    root->addChild(Producteurs);
    root->addChild(Herbivores);
    root->addChild(Carnivores);
    root->addChild(Omnivores);

    // Boucle principale pour le menu d'interaction avec l'utilisateur
    while (true) {
        std::cout << "\nMenu :\n";
        std::cout << "1. Afficher l'arbre\n"; // Option pour afficher l'arbre
        std::cout << "2. Ajouter un nœud\n"; // Option pour ajouter un nœud
        std::cout << "3. Supprimer un nœud\n"; // Option pour supprimer un nœud
        std::cout << "4. Quitter\n"; // Option pour quitter le programme
        std::cout << "Choisissez une option : ";

        int choice;
        std::cin >> choice; // Lecture du choix de l'utilisateur

        switch (choice) {
            case 1:
                printTree(root); // Afficher l'arbre
                break;
            case 2:
                addNode(root); // Ajouter un nœud
                break;
            case 3:
                removeNode(root); // Supprimer un nœud
                break;
            case 4:
                deleteTree(root); // Libérer la mémoire avant de quitter
                return 0; // Quitter le programme
            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl; // Message d'erreur pour choix invalide
        }
    }

    return 0; // Fin du programme
}