#include <vector>

#include "include/figure.hpp"
#include "include/figures.hpp"
#include "include/rectangle.hpp"
#include "include/rhombus.hpp"
#include "include/trapezoid.hpp"

int main() {
    int command;
    Figures<double> figuresArr;
    std::cout << "Comands:"  << std::endl <<
    "1 - create new figure;" << std::endl <<
    "2 - delete the figure;" << std::endl <<
    "3 - calculate the area ant the center of the figures;" << std::endl <<
    "4 - calculate the total area of the figures;" << std::endl <<
    "0 - exit." << std::endl;
    while (true) {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command > 6 || command < 0) {
            std::cout << "Wrong command" << std::endl;
        }
        if (command == 1) {
            std::unique_ptr<Figure<double> > f;
            std::cout << "Figures:" << std::endl <<
            "1 - Rectangle" << std::endl <<
            "2 - Rhombus" << std::endl <<
            "3 - Trapezoid" << std::endl;
            int figureComand;
            std::cin >> figureComand;
            double x, y;
            if (figureComand == 1) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 4; ++i) {
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Rectangle<double>>(points);
            } else if (figureComand == 2) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 4; ++i) {
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Rhombus<double>>(points);
            } else if (figureComand == 3) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 4; ++i) {
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Trapezoid<double>>(points);
            } else {
                std::cout << "Wrong command" << std::endl;
            }
            figuresArr.addFigure(std::move(f));
        } else if (command == 2) {
            std::cout << "Enter the index" << std::endl;
            int indexComand;
            std::cin >> indexComand;
            figuresArr.deleteFigure(indexComand);
        } else if (command == 3) {
            for (size_t i = 0; i < figuresArr.getSize(); ++i) {
                auto f = figuresArr.getFigure(i);
                std::cout << "Area: " << f->square() << std::endl;
                std::cout << "Center: (" << f->center().first << "," << f->center().second << ")" << std::endl;
            }
        } else if (command == 4) {
            std::cout << "Total area: " << figuresArr.totalArea() << std::endl;
        } else if (command == 0) {
            break;
        }
    }
    return 0;
}


/* Example:
figures: 1 (rectangle), 2 (rhombus), 3 (trapezoid)
1 1 1 3 6 3 6 1
1 6 4 10 7 6 4 2
1 1 2 4 4 4 5 1

Area: 10
Area: 24
Area: 9

Center: (2.5;1)
Center: (3;4)
Center: (3;1.5)

Total area: 43
*/