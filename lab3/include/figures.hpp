#pragma once

#include "figure.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"

class Figures {
    public:
        Figures(); //* Default constructor
        size_t getSize() const;

        Figures(const size_t &n, unsigned char t); //* Fill constructor  
        Figures(const std::initializer_list<unsigned char> &t, size_t flag); //* Initializer list constructor  

        void addFigure(Figure *figure);
        void deleteFigure(size_t ind);
        double totalArea() const;
        Figure* getFigure(size_t ind);    

        ~Figures() noexcept; //* Destructor
    private:
        size_t size;
        Figure** figures;
};