#pragma once

#ifndef BST_H
#define BST_H

#include <SFML/Graphics.hpp>

// Node structure for the BST
struct Node { 
    int key; 
    Node* left; 
    Node* right; 
    int x, y; // Position for visualization

    Node(int k) : key(k), left(nullptr), right(nullptr), x(0), y(0) {}
};

// BST Class
class BST { 
private: 
    Node* root;

    // Recursive helper functions
    Node* insert(Node* node, int key);
    void calculatePositions(Node* node, int x, int y, int xOffset);
    void drawTree(Node* node, sf::RenderWindow& window, sf::Font& font);

public: 
    BST(); // Constructor
    void insert(int key); // Insert a key into the BST
    void visualize(sf::RenderWindow& window, sf::Font& font); // Visualize the BST
};

#endif
