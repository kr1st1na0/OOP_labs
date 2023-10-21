#include <vector>

#include "point.hpp"
#include "figure.hpp"
#include "figures.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"

int main() {
    int command = 1;
    Figures figuresArr;
    std::cout << "Comands:"  << std::endl <<
    "1 - create new figure;" << std::endl <<
    "2 - delete the figure;" << std::endl <<
    "3 - print the coordinates of the figures;" << std::endl <<
    "4 - calculate the area of the figures;" << std::endl <<
    "5 - calculate the center of the figures;" << std::endl <<
    "6 - calculate the total area of figures;" << std::endl <<
    "0 - exit." << std::endl;
    while (command) {
        std::cin >> command;
        if (command > 6 || command < 0) {
            std::cout << "Wrong command" << std::endl;
        }
        switch (command) {
            case 1:
                std::cout << "Figures:" << std::endl <<
                "1 - Rectangle" << std::endl <<
                "2 - Rhombus" << std::endl <<
                "3 - Trapezoid" << std::endl;
                int figureComand;
                std::cin >> figureComand;
                Figure *f;
                if (figureComand == 1) {
                    f = new Rectangle(std::cin);
                } else if (figureComand == 2) {
                    f = new Rhombus(std::cin);
                } else if (figureComand == 3) {
                    f = new Trapezoid(std::cin);
                } else {
                    std::cout << "Wrong command" << std::endl;
                }
                figuresArr.addFigure(f);
                break;
            case 2:
                std::cout << "Enter the index" << std::endl;
                int indexComand;
                std::cin >> indexComand;
                figuresArr.deleteFigure(indexComand);
                break;
            case 3:
                for (size_t i = 0; i < figuresArr.getSize(); ++i) {
                    Figure* f = figuresArr.getFigure(i);
                    std::cout << "Coordinates: ";
                    f->print(std::cout);
                }
                break;
            case 4:
                for (size_t i = 0; i < figuresArr.getSize(); ++i) {
                    Figure* f = figuresArr.getFigure(i);
                    std::cout << "Area: " << f->square() << std::endl;
                }
                break;
            case 5:
                for (size_t i = 0; i < figuresArr.getSize(); ++i) {
                    Figure* f = figuresArr.getFigure(i);
                    std::cout << "Center: " << f->center() << std::endl;
                }
                break;
            case 6:
                std::cout << "Totsal area: " << figuresArr.totalArea() << std::endl;
                break;
        }
    }
    return 0;
}


/* Example:
figures: 1 (rectangle), 2 (rhombus), 3 (trapezoid)
0 4 1 6 9 2 8 0
2 5 6 6 5 2 1 1
1 8 4 4 6 4 5 8

Coordinates: (0;4) (1;6) (9;2) (8;0) 
Coordinates: (2;5) (6;6) (5;2) (1;1) 
Coordinates: (1;8) (4;4) (6;4) (5;8) 

Area: 20
Area: 15
Area: 12

Center: (4.5;3)
Center: (3.5;3.5)
Center: (-2;-1.78)

Total area: 47
*/