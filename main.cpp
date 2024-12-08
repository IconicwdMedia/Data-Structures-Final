// Winston Doss

#include "Heap.h"
#include "BST.h"
#include "StackQueue.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class Menu {
    private:
        int selectedItemIndex;
        sf::Font font;
        vector<sf::Text> menuItems;

    public:
        Menu(float width, float height, const vector<string>& options) {
            if (!font.loadFromFile("../arial.ttf")) {
                cerr << "Failed to load font!\n";
            }

            for (size_t i = 0; i < options.size(); ++i) {
                sf::Text text;
                text.setFont(font);
                text.setString(options[i]);
                text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
                text.setPosition(sf::Vector2f(width / 2 - 50, height / (options.size() + 1) * (i + 1)));
                menuItems.push_back(text);
            }

            selectedItemIndex = 0;
        }

        void draw(sf::RenderWindow& window) {
            for (const auto& item : menuItems) {
                window.draw(item);
            }
        }

        void moveUp() {
            if (selectedItemIndex - 1 >= 0) {
                menuItems[selectedItemIndex].setFillColor(sf::Color::White);
                selectedItemIndex--;
                menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
            }
        }

        void moveDown() {
            if (selectedItemIndex + 1 < menuItems.size()) {
                menuItems[selectedItemIndex].setFillColor(sf::Color::White);
                selectedItemIndex++;
                menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
            }
        }

        int getSelectedItemIndex() const {
            return selectedItemIndex;
        }

        string browseFile() {
            cout << "Simulating file selection... (default: sample.txt)\n";
            return "sample.txt";
        }
};

int main() {

    // Display
    sf::RenderWindow window(sf::VideoMode(800, 600), "ADT Visualization");
    
    // Menu
    vector<string> menuOptions = {"Heap", "BST", "Stack & Queue"};
    Menu menu(window.getSize().x, window.getSize().y, menuOptions);

    // Heap
    vector<int> heap = {10, 20, 30, 40, 50};

    // BST
    sf::Font font;
    if (!font.loadFromFile("../arial.ttf")) {
        return -1; // Error loading font
    }

    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // StackQueue
        // Creating instance
    StackQueue sq;

    // Perform stack and queue operations
    sq.push(10);
    sq.push(20);
    sq.push(30);
    sq.enqueue(40);
    sq.enqueue(50);
    sq.enqueue(60);

    // Perform operations: popping stack and dequeuing queue
    sq.pop();      // Pops 30 from the stack
    sq.dequeue();  // Dequeues 40 from the queue

    bool showHeap = true;
    bool showBST = false;       
    bool showStackQueue = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                showHeap = !showHeap; // Toggle visualization
            }
        }

        // Handle arrow key navigation
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.moveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    menu.moveDown();
                }

                // Handle enter key selection
                if (event.key.code == sf::Keyboard::Enter) {
                    int selectedItem = menu.getSelectedItemIndex();
                    if (selectedItem == 0) {
                        // Show Heap
                        showHeap = true;
                        showBST = false;
                        showStackQueue = false;
                    } else if (selectedItem == 1) {
                        // Show BST
                        showHeap = false;
                        showBST = true;
                        showStackQueue = false;
                    } else if (selectedItem == 2) {
                        // Show Stack & Queue
                        showHeap = false;
                        showBST = false;
                        showStackQueue = true;
                    }
                }
            }

        window.clear();

        if (showHeap) {
            visualizeHeap(heap, window);
        } else if (showBST) {
            tree.visualize(window, font);
        } else if (showStackQueue) {
            sq.visualize(window, font);
        }

        // Draw menu if not selecting visualization
        if (!showHeap && !showBST && !showStackQueue) {
            menu.draw(window);
        }

        window.display();
    
    }
    return 0;
}
