#include <iostream>
#include <cmath>

class Mat {
private:
    int rows, cols;
    double** values;
public:
    static int count;
    Mat(int r, int c) : rows(r), cols(c) {
        values = new double*[rows];
        for(int i = 0; i < rows; ++i)
            values[i] = new double[cols]();
        ++count;
    }
    ~Mat() {
        for(int i = 0; i < rows; ++i)
            delete[] values[i];
        delete[] values;
    }
    Mat operator=(const Mat& other);
    Mat operator+(const Mat& other);
    Mat operator-(Mat& other);
    Mat operator*(double scalar);
    Mat operator*(Mat& other);
    Mat negativeMatrix(Mat m);
    int getRows() { return rows; }
    int getCols() { return cols; }
    bool CheckM(Mat* first, Mat& second) { return first->rows == second.rows && first->cols == second.cols; }
    void Value(int row, int col, double value) { if(row >= 0 && row < rows && col >= 0 && col < cols) values[row][col] = value; }
    double getValue(int row, int col) { if(row >= 0 && row < rows && col >= 0 && col < cols) return values[row][col]; return 0.0; }
    void print(int row, int col) { if(row >= 0 && row < rows && col >= 0 && col < cols) std::cout << values[row][col] << " "; }
};

int Mat::count = 0;

class Vect {
private:
    int dimention;
    double* values;
public:
    static int count;
    Vect(int dim, double* rawValues) : dimention(dim) { values = new double[dim]; for(int i = 0; i < dim; ++i) values[i] = rawValues[i]; ++count; }
    ~Vect() { delete[] values; }
    Vect operator=(const Vect& other);
    Vect operator+(Vect& other);
    Vect operator-(Vect& other);
    Vect operator*(Vect& other);
    Vect operator/(Vect& other);
    Vect operator*(double scalar);
    Vect operator*(Mat& matrix);
    Vect negativeVect(Vect v);
    int getDimention() { return dimention; }
    void printV() { for(int i = 0; i < dimention; ++i) std::cout << values[i] << " "; std::cout << std::endl; }
};

int Vect::count = 0;

int main() {
    return 0;
}
