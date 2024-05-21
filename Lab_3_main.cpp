#include "geometry.h"

int main() {
    // Создаем объекты геометрических фигур
    Line line(0, 0, 5, 5);
    Square square(2, 2, 4);
    Rhombus rhombus(3, 3, 6, 30);
    Rectangle rectangle(1, 1, 6, 4);
    Parallelogram parallelogram(4, 4, 5, 45);

    // Вызываем методы для каждого объекта
    line.draw();
    line.move(2, 2);
    line.erase();

    square.draw();
    square.move(1, -1);
    square.rotate(45);
    square.erase();

    rhombus.draw();
    rhombus.move(-2, 2);
    rhombus.rotate(30);
    rhombus.erase();

    rectangle.draw();
    rectangle.move(3, -3);
    rectangle.rotate(90);
    rectangle.erase();

    parallelogram.draw();
    parallelogram.move(-1, 1);
    parallelogram.rotate(-30);
    parallelogram.erase();

    return 0;
}
