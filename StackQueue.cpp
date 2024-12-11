#include "StackQueue.h"

// Visualize the stack and queue with SFML
void StackQueue::visualize(sf::RenderWindow& window, sf::Font& font) {
    // Visualize Stack
    int xOffset = 100;
    int yOffset = 100;
    int ySpacing = 40;

    // Draw stack
    for (size_t i = 0; i < stack.size(); ++i) {
        // Stack visualization (draw a circle and label)
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(xOffset, yOffset + (i * ySpacing));

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(stack[i]));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(xOffset + 25, yOffset + (i * ySpacing) - 10); // Label inside the circle

        window.draw(circle);
        window.draw(text);
    }

    // Visualize Queue
    xOffset = 300; // Change x offset for queue
    // Draw queue
    for (size_t i = 0; i < queue.size(); ++i) {
        // Queue visualization (draw a circle and label)
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(xOffset, yOffset + (i * ySpacing));

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(queue[i]));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(xOffset + 25, yOffset + (i * ySpacing) - 10); // Label inside the circle

        window.draw(circle);
        window.draw(text);
    }
}
