#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>

// Абстрактный класс Точка
class Point {
protected:
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    virtual ~Point() {}

    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;

    double getX() const { return x; }
    double getY() const { return y; }
};

// Класс Линия
class Line : public Point {
protected:
    Point p2;

public:
    Line(double x1, double y1, double x2, double y2) : Point(x1, y1), p2(x2, y2) {}
    ~Line() {}

    void draw() const override;
    void erase() const override;
    void move(double dx, double dy) override;
    void rotate(double angle) override;
};

// Класс Квадрат
class Square : public Point {
protected:
    double side;

public:
    Square(double x, double y, double side) : Point(x, y), side(side) {}
    ~Square() {}

    void draw() const override;
    void erase() const override;
    void move(double dx, double dy) override;
    void rotate(double angle) override;
};

// Класс Ромб
class Rhombus : public Square {
protected:
    double angle;

public:
    Rhombus(double x, double y, double side, double angle) : Square(x, y, side), angle(angle) {}
    ~Rhombus() {}

    void draw() const override;
    void erase() const override;
    void move(double dx, double dy) override;
    void rotate(double angle) override;
};

// Класс Прямоугольник
class Rectangle : public Point {
protected:
    double width, height;

public:
    Rectangle(double x, double y, double width, double height) : Point(x, y), width(width), height(height) {}
    ~Rectangle() {}

    void draw() const override;
    void erase() const override;
    void move(double dx, double dy) override;
    void rotate(double angle) override;
};

// Класс Параллелограмм с виртуальным наследованием от Квадрат
class Parallelogram : public virtual Square {
protected:
    double angle;

public:
    Parallelogram(double x, double y, double side, double angle) : Square(x, y, side), angle(angle) {}
    ~Parallelogram() {}

    void draw() const override;
    void erase() const override;
    void move(double dx, double dy) override;
    void rotate(double angle) override;
};

#endif
