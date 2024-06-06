#include <SFML/Graphics.hpp>
#include <iostream>

void bresenham(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
    sf::Image pixel;
    pixel.create(800, 600, sf::Color::Black);
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    if(dx < 0) {
        dx = -dx;
    }
    int dy = y2 - y1;
    if(dy < 0) {
        dy = -dy;
    }
    std::cout << "dy: " << dy << std::endl;
    std::cout << "dx: " << dx << std::endl;
    float slope = (float)dy / (float)dx;
    std::cout << "slope: " << slope << std::endl;
    if (slope <= 1) {
        int p = 2 * dy - dx;
        while (x <= x2) {
            x++;
            pixel.setPixel(x, y, sf::Color::White);
            if (p < 0) {
                p = p + 2 * dy;
            } else {
                p = p + 2 * dy - 2 * dx;
                y++;
            }
        }
    }
    else {
        std::cout << "in else" << std::endl;
        int p2 = 2 * dx - dy;
        while(y <= y2) {
            y++;
            pixel.setPixel(x, y, sf::Color::White);
            if(p2 < 0) {
                p2 = p2 + 2 * dx;
            } else {
                p2 = p2 + 2 * dx - 2 * dy;
                x++;
            }
        }
    }

    sf::Texture texture;
    texture.loadFromImage(pixel);
    sf::Sprite sprite(texture);

    window.clear(); 
    window.draw(sprite);
    window.display();
}

int main () {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bresenham Line Drawing Algorithm");
    int x1 = 100;
    int y1 = 100;
    int x2 = 300;
    int y2 = 200;
    while (window.isOpen()) {
        bresenham(window, x1, y1, x2, y2);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0; 
}
