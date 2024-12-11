#include <SFML/Graphics.hpp>
#include "Heap.h"
using namespace std;

void visualizeHeap(const vector<int>& heap, sf::RenderWindow& window) 
{
    for (size_t i = 0; i < heap.size(); ++i) {
        sf::CircleShape node(20);
        node.setFillColor(sf::Color::Blue);
        node.setPosition(100 + i * 50, 100);
        window.draw(node);

        sf::Text value;
        value.setString(to_string(heap[i]));
        value.setPosition(110 + i * 50, 110);
        window.draw(value);
    }
}
