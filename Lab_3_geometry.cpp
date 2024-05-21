#include "geometry.h"

// Реализация методов для класса Линия
void Line::draw() const {
    std::cout << "Drawing a line from (" << x << ", " << y << ") to (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
}

void Line::erase() const {
    std::cout << "Erasing the line" << std::endl;
}

void Line::move(double dx, double dy) {
    x += dx;
    y += dy;
    p2.move(dx, dy);
}

void Line::rotate(double angle) {
    std::cout << "Cannot rotate a line" << std::endl;
}

// Реализация методов для класса Квадрат
void Square::draw() const {
    std::cout << "Drawing a square at (" << x << ", " << y << ") with side length " << side << std::endl;
}

void Square::erase() const {
    std::cout << "Erasing the square" << std::endl;
}

void Square::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Square::rotate(double angle) {
    std::cout << "Cannot rotate a square" << std::endl;
}

// Реализация методов для класса Ромб
void Rhombus::draw() const {
    std::cout << "Drawing a rhombus at (" << x << ", " << y << ") with side length " << side << " and angle " << angle << std::endl;
}

void Rhombus::erase() const {
    std::cout << "Erasing the rhombus" << std::endl;
}

void Rhombus::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Rhombus::rotate(double angle) {
    this->angle += angle;
    std::cout << "Rotating the rhombus by " << angle << " degrees" << std::endl;
}

// Реализация методов для класса Прямоугольник
void Rectangle::draw() const {
    std::cout << "Drawing a rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
}

void Rectangle::erase() const {
    std::cout << "Erasing the rectangle" << std::endl;
}

void Rectangle::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Rectangle::rotate(double angle) {
    std::cout << "Cannot rotate a rectangle" << std::endl;
}

// Реализация методов для класса Параллелограмм
void Parallelogram::draw() const {
    std::cout << "Drawing a parallelogram at (" << x << ", " << y << ") with side length " << side << " and angle " << angle << std::endl;
}

void Parallelogram::erase() const {
    std::cout << "Erasing the parallelogram" << std::endl;
}

void Parallelogram::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Parallelogram::rotate(double angle) {
    this->angle += angle;
    std::cout << "Rotating the parallelogram by " << angle << " degrees" << std::endl;
}
