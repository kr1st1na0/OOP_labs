#include <vector>

#include "point.hpp"
#include "figure.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"

int main() {
    int comand = 1;
    std::vector<Figure*> figures;
    std::cout << "Comands:"  << std::endl <<
    "1 - create new figure;" << std::endl <<
    "2 - delete the figure;" << std::endl <<
    "3 - print the coordinates of the figures;" << std::endl <<
    "4 - calculate the area of the figures;" << std::endl <<
    "5 - calculate the center of the figures;" << std::endl <<
    "6 - calculate the total area of figures;" << std::endl <<
    "0 - exit." << std::endl;
    while (comand) {
        std::cin >> comand;
        if (comand > 6 || comand < 0) {
            std::cout << "Wrong comand" << std::endl;
        }
        switch (comand) {
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
                    std::cout << "Wrong comand" << std::endl;
                }
                figures.push_back(f);
                break;
            case 2:
                std::cout << "Enter the index" << std::endl;
                int indexComand;
                std::cin >> indexComand;
                if (indexComand >= figures.size()) {
                    std::cout << "Index is greater than the array size" << std::endl;
                } else {
                    delete figures[indexComand];
                    figures.erase(figures.begin() + indexComand);
                }
                break;
            case 3:
                for (const auto &f : figures) {
                    std::cout << "Coordinates: ";
                    f->print(std::cout);
                }
                break;
            case 4:
                for (const auto &f : figures) {
                    std::cout << "Area: " << f->square() << std::endl;
                }
                break;
            case 5:
                for (const auto &f : figures) {
                    std::cout << "Center: " << f->center() << std::endl;
                }
                break;
            case 6:
                double result = 0;
                for (const auto &f : figures) {
                    result += f->square();
                }
                std::cout << "Total area: " << result << std::endl;
                break;
        }
    }
    return 0;
}


/* Example:
figures: 1 (rectangle), 2 (rhombus), 3 (trapezoid)

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