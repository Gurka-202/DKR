//#ifndef QUADRILATER
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <string>
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Quadrilateral {
public:
    virtual ~Quadrilateral() {}

    
    virtual double getArea() const = 0;

   
    virtual double getPerimeter() const = 0;

    virtual std::string toString() const = 0;

    
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& quad) {
        os << quad.toString();
        return os;
    }
};

// Розрахунок прямокутників 
class Rectangle : public Quadrilateral {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    std::string toString() const override {
        return "Rectangle: width=" + std::to_string(width) + ", height=" + std::to_string(height);
    }
};

// РОзрахунок квадратів 
class Square : public Quadrilateral {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double getArea() const override {
        return side * side;
    }

    double getPerimeter() const override {
        return 4 * side;
    }

    std::string toString() const override {
        return "Square: side=" + std::to_string(side);
    }
};

// Розрахунок ромбів
class Rhombus : public Quadrilateral {
private:
    double side;
    double angle12; // Кут між першою і другою сторонами
    double angle34; // Кут між третьою і четвертою сторонами

public:
    Rhombus(double s, double a12, double a34) : side(s), angle12(a12), angle34(a34) {}

    double getArea() const override {
        // Area calculation using the formula: side^2 * sin(angle)
        return side * side * std::sin(angle12 * M_PI / 180.0);
    }

    double getPerimeter() const override {
        return 4 * side;
    }

    std::string toString() const override {
        return "Rhombus: side=" + std::to_string(side) + ", angle12=" + std::to_string(angle12) + ", angle34=" + std::to_string(angle34);
    }
};

// Розрахунок довільних чотирикутників
class ArbitraryQuadrilateral : public Quadrilateral {
private:
    double s1, s2, s3, s4; 
    double a12, a34; 

public:
    ArbitraryQuadrilateral(double side1, double side2, double side3, double side4, double angle12, double angle34)
        : s1(side1), s2(side2), s3(side3), s4(side4), a12(angle12), a34(angle34) {}

    double getArea() const override {
       
        double s = getPerimeter() / 2.0;
        return std::sqrt((s - s1) * (s - s2) * (s - s3) * (s - s4) - s1 * s2 * s3 * s4 * std::cos((a12 + a34) * M_PI / 360.0) * std::cos((a12 + a34) * M_PI / 360.0));
    }

    double getPerimeter() const override {
        return s1 + s2 + s3 + s4;
    }

    std::string toString() const override {
        return "ArbitraryQuadrilateral: s1=" + std::to_string(s1) + ", s2=" + std::to_string(s2) + ", s3=" + std::to_string(s3) + ", s4=" + std::to_string(s4) + ", a12=" + std::to_string(a12) + ", a34=" + std::to_string(a34);
    }
};

#endif // QUADRILATERAL_H

