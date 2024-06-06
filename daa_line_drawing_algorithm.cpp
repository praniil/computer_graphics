#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

void dda_algorithm(sf::RenderWindow& window, float x1, float x2, float y1, float y2) {
    sf::Image pixel;
    pixel.create(800, 600, sf::Color::Black);

    int dx = x2 - x1;
    int dy = y2 - y1;

    float steps = std::max(abs(dx), abs(dy));

    float x_inc = dx / steps;
    float y_inc = dy / steps;

    for (int i = 0; i <= steps; i++) {
        pixel.setPixel(x1, y1, sf::Color::White);
        x1 += x_inc;
        y1 += y_inc;
    }

    sf::Texture texture;
    texture.loadFromImage(pixel);
    sf::Sprite sprite(texture);

    window.clear();  // Clear the window before drawing the sprite
    window.draw(sprite);
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DDA Line Drawing Algorithm");
    bool point_entered = false;
    float x1, y1, x2, y2;

    std::cout << "Enter the first point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the second point (x2, y2): ";
    std::cin >> x2 >> y2;

    while (window.isOpen()) {
        dda_algorithm(window, x1, x2, y1, y2);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
