#include <SFML/Graphics.hpp>
#include "BST.h"

// Node structure for the BST
// struct Node { 
//     int key; 
//     Node* left; 
//     Node* right; 
//     int x, y; // Position for visualization

//     Node(int k) : key(k), left(nullptr), right(nullptr), x(0), y(0) {}
// };

// BST Class
// class BST { 
// private: 
//     Node* root;

// Recursive function to insert a key into the BST
Node* BST::insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Recursive function to calculate positions for each node
void BST::calculatePositions(Node* node, int x, int y, int xOffset) {
    if (!node) return;

    node->x = x;
    node->y = y;

    // Recur for left and right children
    calculatePositions(node->left, x - xOffset, y + 100, xOffset / 2);
    calculatePositions(node->right, x + xOffset, y + 100, xOffset / 2);
}

// Recursive function to draw the BST
void BST::drawTree(Node* node, sf::RenderWindow& window, sf::Font& font) {
    if (!node) return;

    // Draw edges (lines)
    if (node->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(node->x, node->y)),
            sf::Vertex(sf::Vector2f(node->left->x, node->left->y))
        };

    window.draw(line, 2, sf::Lines);

}

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(node->x, node->y)),
            sf::Vertex(sf::Vector2f(node->right->x, node->right->y))
        };
        window.draw(line, 2, sf::Lines);
    }

    // Draw node (circle)
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(node->x - 20, node->y - 20); // Center the circle
    window.draw(circle);

    // Draw node value (text)
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(node->key));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(node->x - 10, node->y - 15); // Center the text
    window.draw(text);

    // Recur for left and right children
    drawTree (node->left, window, font);
    drawTree(node->right, window, font);
}

BST::BST() : root(nullptr) {}

// Insert a key into the BST

void BST::insert(int key) {

    root = insert(root, key);
}

// Visualize the BST
void BST::visualize(sf::RenderWindow& window, sf::Font& font) {
    if (!root) return;
  
    // Calculate positions for each node
    calculatePositions(root, 400, 50, 100); // Start at root (400, 50) with offset 200
    
    // Draw the tree
    drawTree(root, window, font);
}
