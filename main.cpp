// main.cpp
#include "quadrilateral.h"
#include "logger.h"
#include "encryption.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

// Меню (вибір функції)
void printMenu() {
    std::cout << ":Choose:\n";
    std::cout << "1. Add Square\n";
    std::cout << "2. Add Rectangle\n";
    std::cout << "3. Add Rhombus\n";
    std::cout << "4. Add Arbitrary Quadrilateral\n";
    std::cout << "5. Show all Quadrilaterals\n";
    std::cout << "6. Save Quadrilaterals to File\n";
    std::cout << "7. Analyze Quadrilaterals\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

// Квадрат
void addSquare(std::vector<Quadrilateral*>& quads) {
    double side;
    std::cout << "Enter side length: ";
    std::cin >> side;
    quads.push_back(new Square(side));
}

// Прямокутник
void addRectangle(std::vector<Quadrilateral*>& quads) {
    double width, height;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;
    quads.push_back(new Rectangle(width, height));
}

// Ромб
void addRhombus(std::vector<Quadrilateral*>& quads) {
    double side, angle12, angle34;
    std::cout << "Enter side length: ";
    std::cin >> side;
    std::cout << "Enter angle between first and second sides (in degrees): ";
    std::cin >> angle12;
    std::cout << "Enter angle between third and fourth sides (in degrees): ";
    std::cin >> angle34;
    quads.push_back(new Rhombus(side, angle12, angle34));
}



// Довільний чотирикутник
void addArbitraryQuadrilateral(std::vector<Quadrilateral*>& quads) {
    double s1, s2, s3, s4, a12, a34;
    std::cout << "Enter length of first side: ";
    std::cin >> s1;
    std::cout << "Enter length of second side: ";
    std::cin >> s2;
    std::cout << "Enter length of third side: ";
    std::cin >> s3;
    std::cout << "Enter length of fourth side: ";
    std::cin >> s4;
    std::cout << "Enter angle between first and second sides (in degrees): ";
    std::cin >> a12;
    std::cout << "Enter angle between third and fourth sides (in degrees): ";
    std::cin >> a34;
    quads.push_back(new ArbitraryQuadrilateral(s1, s2, s3, s4, a12, a34));
}


// Функція, що демонструє всі наявні фігури
void showQuadrilaterals(const std::vector<Quadrilateral*>& quads) {
    for (const auto& quad : quads) {
        std::cout << *quad << " Area=" << quad->getArea() << " Perimeter=" << quad->getPerimeter() << std::endl;
    }
}



// Функція збереження чотирикутників у файл із шифруванням
void saveToFile(const std::vector<Quadrilateral*>& quads, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Неможливо відкрити файл для запису.");
    }

    for (const auto& quad : quads) {
        file << Encryption::encrypt(quad->toString()) << std::endl;
    }

    file.close();
}
void analyzeQuadrilaterals(const std::vector<Quadrilateral*>& quads) {
    int squareCount = 0, rectangleCount = 0, rhombusCount = 0, arbitraryCount = 0;
    double maxAreaSquare = 0, minAreaSquare = 0; // Початкове значення мінімальної площі
    double maxAreaRectangle = 0, minAreaRectangle = 0; // Початкове значення мінімальної площі
    double maxAreaRhombus = 0, minAreaRhombus = 0; // Початкове значення мінімальної площі
    double maxAreaArbitrary = 0, minAreaArbitrary = 0; // Початкове значення мінімальної площі
    double maxPerimeterSquare = 0, minPerimeterSquare = 0; // Початкове значення мінімального периметру
    double maxPerimeterRectangle = 0, minPerimeterRectangle = 0; // Початкове значення мінімального периметру
    double maxPerimeterRhombus = 0, minPerimeterRhombus = 0; // Початкове значення мінімального периметру
    double maxPerimeterArbitrary = 0, minPerimeterArbitrary = 0; // Початкове значення мінімального периметру

    for (const auto & quad : quads) {
        if (dynamic_cast<Square*>(quad) != nullptr) {
            squareCount++;
            double area = quad->getArea();
            double perimeter = quad->getPerimeter();
            if (area > maxAreaSquare) maxAreaSquare = area;
            if (area < minAreaSquare || minAreaSquare == 0) minAreaSquare = area;
            if (perimeter > maxPerimeterSquare) maxPerimeterSquare = perimeter;
            if (perimeter < minPerimeterSquare || minPerimeterSquare == 0) minPerimeterSquare = perimeter;
        }
        else if (dynamic_cast<Rectangle*>(quad) != nullptr) {
            rectangleCount++;
            double area = quad->getArea();
            double perimeter = quad->getPerimeter();
            if (area > maxAreaRectangle) maxAreaRectangle = area;
            if (area < minAreaRectangle || minAreaRectangle == 0) minAreaRectangle = area;
            if (perimeter > maxPerimeterRectangle) maxPerimeterRectangle = perimeter;
            if (perimeter < minPerimeterRectangle || minPerimeterRectangle == 0) minPerimeterRectangle = perimeter;
        }
        else if (dynamic_cast<Rhombus*>(quad) != nullptr) {
            rhombusCount++;
            double area = quad->getArea();
            double perimeter = quad->getPerimeter();
            if (area > maxAreaRhombus) maxAreaRhombus = area;
            if (area < minAreaRhombus || minAreaRhombus == 0) minAreaRhombus = area;
            if (perimeter > maxPerimeterRhombus) maxPerimeterRhombus = perimeter;
            if (perimeter < minPerimeterRhombus || minPerimeterRhombus == 0) minPerimeterRhombus = perimeter;
        }
        else if (dynamic_cast<ArbitraryQuadrilateral*>(quad) != nullptr) {
            arbitraryCount++;
            double area = quad->getArea();
            double perimeter = quad->getPerimeter();
            if (area > maxAreaArbitrary) maxAreaArbitrary = area;
            if (area < minAreaArbitrary || minAreaArbitrary == 0) minAreaArbitrary = area;
            if (perimeter > maxPerimeterArbitrary) maxPerimeterArbitrary = perimeter;
            if (perimeter < minPerimeterArbitrary || minPerimeterArbitrary == 0) minPerimeterArbitrary = perimeter;
        }
    }
    // Виводимо результати
    std::cout << "Square Count: " << squareCount << std::endl;
    std::cout << "Rectangle Count: " << rectangleCount << std::endl;
    std::cout << "Rhombus Count: " << rhombusCount << std::endl;
    std::cout << "Arbitrary Quadrilateral Count: " << arbitraryCount << std::endl;

    std::cout << "Max Area Square: " << maxAreaSquare << std::endl;
    std::cout << "Min Area Square: " << minAreaSquare << std::endl;
    std::cout << "Max Perimeter Square: " << maxPerimeterSquare << std::endl;
    std::cout << "Min Perimeter Square: " << minPerimeterSquare << std::endl;

    std::cout << "Max Area Rectangle: " << maxAreaRectangle << std::endl;
    std::cout << "Min Area Rectangle: " << minAreaRectangle << std::endl;
    std::cout << "Max Perimeter Rectangle: " << maxPerimeterRectangle << std::endl;
    std::cout << "Min Perimeter Rectangle: " << minPerimeterRectangle << std::endl;

    std::cout << "Max Area Rhombus: " << maxAreaRhombus << std::endl;
    std::cout << "Min Area Rhombus: " << minAreaRhombus << std::endl;
    std::cout << "Max Perimeter Rhombus: " << maxPerimeterRhombus << std::endl;
    std::cout << "Min Perimeter Rhombus: " << minPerimeterRhombus << std::endl;

    std::cout << "Max Area Arbitrary Quadrilateral: " << maxAreaArbitrary << std::endl;
    std::cout << "Min Area Arbitrary Quadrilateral: " << minAreaArbitrary << std::endl;
    std::cout << "Max Perimeter Arbitrary Quadrilateral: " << maxPerimeterArbitrary << std::endl;
    std::cout << "Min Perimeter Arbitrary Quadrilateral: " << minPerimeterArbitrary << std::endl;
}



// Main function
int main() {
    Logger logger("log.txt");  // Logger to log important events
    logger.log("Program started.");

    std::vector<Quadrilateral*> quads;  // Vector to store quadrilateral objects
    int choice;

    while (true) {
        printMenu();  // Print menu options
        std::cin >> choice;

        switch (choice) {
        case 1:
            addSquare(quads);  // Add a square
            logger.log("Added a square.");
            break;
        case 2:
            addRectangle(quads);  // Add a rectangle
            logger.log("Added a rectangle.");
            break;
        case 3:
            addRhombus(quads);  // Add a rhombus
            logger.log("Added a rhombus.");
            break;
        case 4:
            addArbitraryQuadrilateral(quads);  // Add an arbitrary quadrilateral
            logger.log("Added an arbitrary quadrilateral.");
            break;
        case 5:
            showQuadrilaterals(quads);  // Show all quadrilaterals
            break;
        case 6:
            saveToFile(quads, "quads.txt");  // Save quadrilaterals to a file
            logger.log("Saved quadrilaterals to file.");
            break;
        case 7:
            analyzeQuadrilaterals(quads);  // Analyze quadrilaterals
            break;
        case 8:
            std::cout << "Exiting...\n";
            logger.log("Program ended.");
            for (auto& quad : quads) {  // Clean up allocated memory
                delete quad;
            }
            return 0;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}

