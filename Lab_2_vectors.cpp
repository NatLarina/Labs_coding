#include "classes.h"

int Vect::count = 1;

Vect::Vect(int dim, double* rawValues) {
    this->dimention = dim;
    this->values = new double[dim];
    for (int i = 0; i < dim; i++) {
        this->values[i] = rawValues[i];
    }
    id = count++;
    std::cout << "Vector " << id << " was created" << std::endl;
}

Vect::~Vect() {
    std::cout << "Vector " << id << " was deleted" << std::endl;
    delete[] values;
}

bool Check(const Vect& first, const Vect& second) {
    return first.getDimention() == second.getDimention();
}

Vect& Vect::operator=(const Vect& other) {
    if (this != &other) {
        dimention = other.dimention;
        delete[] values;
        values = new double[dimention];
        for (int i = 0; i < dimention; i++) {
            values[i] = other.values[i];
        }
    }
    return *this;
}

Vect Vect::operator+(const Vect& other) {
    if (Check(*this, other)) {
        Vect temp(dimention, new double[dimention]);
        for (int i = 0; i < dimention; i++)
            temp.values[i] = this->values[i] + other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator-(const Vect& other) {
    if (Check(*this, other)) {
        Vect temp(dimention, new double[dimention]);
        for (int i = 0; i < dimention; i++)
            temp.values[i] = this->values[i] - other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator*(const Vect& other) {
    if (Check(*this, other)) {
        Vect temp(dimention, new double[dimention]);
        for (int i = 0; i < dimention; i++)
            temp.values[i] = this->values[i] * other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator/(const Vect& other) {
    if (Check(*this, other)) {
        Vect temp(dimention, new double[dimention]);
        for (int i = 0; i < dimention; i++)
            temp.values[i] = this->values[i] / other.values[i];
        return temp;
    }
    throw std::runtime_error("Invalid dimention of second vector");
}

Vect Vect::operator*(double scalar) {
    Vect temp(dimention, new double[dimention]);
    for (int i = 0; i < dimention; ++i) {
        temp.values[i] = values[i] * scalar;
    }
    return temp;
}

Vect Vect::negativeVect() {
    Vect temp(dimention, new double[dimention]);
    for (int i = 0; i < dimention; ++i) {
        temp.values[i] = -values[i];
    }
    return temp;
}

int Vect::getDimention() const {
    return this->dimention;
}

void Vect::printV() const {
    for (int i = 0; i < this->dimention; i++) {
        std::cout << this->values[i] << " " << std::endl;
    }
}
