#include <SFML/Graphics.hpp>
#include <iostream>

void draw_circle_points(sf::Image &image, int xc, int yc, int x, int y) {
    // Draw points in all eight octants
    image.setPixel(xc + x, yc + y, sf::Color::White);
    image.setPixel(xc - x, yc + y, sf::Color::White);
    image.setPixel(xc + x, yc - y, sf::Color::White);
    image.setPixel(xc - x, yc - y, sf::Color::White);
    image.setPixel(xc + y, yc + x, sf::Color::White);
    image.setPixel(xc - y, yc + x, sf::Color::White);
    image.setPixel(xc + y, yc - x, sf::Color::White);
    image.setPixel(xc - y, yc - x, sf::Color::White);
}

void midpoint_circle_algorithm(sf::RenderWindow &window, int radius, int xc, int yc) {
    sf::Image pixel;
    pixel.create(800, 600, sf::Color::Black);
    
    int x1 = 0;
    int y1 = radius;
    int decision_parameter = 1 - radius;
    draw_circle_points(pixel, xc, yc, x1, y1);
    while(y1 > x1) {
        if (decision_parameter < 0) {
            decision_parameter = decision_parameter + 2 * x1 + 3;
            x1 = x1 + 1;
        } else {
            decision_parameter = decision_parameter + 2 * x1 - 2 * y1 + 5;
            x1 = x1 + 1;
            y1 = y1 - 1;
        }
        draw_circle_points(pixel, xc, yc, x1, y1);
    }

    sf::Texture texture;
    texture.loadFromImage(pixel);
    sf::Sprite sprite(texture);

    window.clear(); 
    window.draw(sprite);
    window.display();
}

int main() {
    int radius;
    std::cout << "enter the radius of the circle" << std::endl;
    std::cin >> radius;
    int xc, yc;
    std::cout  << "enter the center of circle" << std::endl;
    std::cin >> xc >> yc;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Midpoint Circle Drawing Algorithm");
    while(window.isOpen()) {
        midpoint_circle_algorithm(window, radius, xc, yc);
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}