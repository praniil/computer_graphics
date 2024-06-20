#include <SFML/Graphics.hpp>
#include <cmath>

// Function to draw a point using symmetry
void plotPoints(sf::RenderWindow &window, int xc, int yc, int x, int y) {
    sf::Vertex points[4];
    points[0] = sf::Vertex(sf::Vector2f(xc + x, yc + y), sf::Color::White);
    points[1] = sf::Vertex(sf::Vector2f(xc - x, yc + y), sf::Color::White);
    points[2] = sf::Vertex(sf::Vector2f(xc + x, yc - y), sf::Color::White);
    points[3] = sf::Vertex(sf::Vector2f(xc - x, yc - y), sf::Color::White);
    
    window.draw(points, 4, sf::Points);
}

void midpointEllipse(sf::RenderWindow &window, int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;
    float a2 = a * a;
    float b2 = b * b;
    float decision = b2 - (a2 * b) + (0.25 * a2);

    // Region 1
    float dx = 2 * b2 * x;
    float dy = 2 * a2 * y;
    while (dx < dy) {
        plotPoints(window, xc, yc, x, y);
        if (decision < 0) {
            x++;
            dx = dx + (2 * b2);
            decision = decision + dx + b2;
        } else {
            x++;
            y--;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            decision = decision + dx - dy + b2;
        }
    }

    // Region 2
    decision = (b2) * ((float)(x + 0.5) * (x + 0.5)) + (a2) * ((float)(y - 1) * (y - 1)) - (a2 * b2);
    while (y >= 0) {
        plotPoints(window, xc, yc, x, y);
        if (decision > 0) {
            y--;
            dy = dy - (2 * a2);
            decision = decision + a2 - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            decision = decision + dx - dy + a2;
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Midpoint Ellipse Algorithm");

    // Ellipse parameters
    int xc = 400; 
    int yc = 300; 
    int a = 200;  
    int b = 100;  

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        midpointEllipse(window, xc, yc, a, b);
        window.display();
    }

    return 0;
}
