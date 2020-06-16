#include "Vector3.h"
#include <cmath>

Vector3::Vector3() {
    for (int i = 0; i < n; i++)
        elem[i] = 0;
} // +

Vector3::Vector3(double arg) {
    for (int i = 0; i < n; i++)
        elem[i] = arg;
}

Vector3::Vector3(const double arg[3]) {
    for (int i = 0; i < n; i++)
        elem[i] = arg[i];
}

Vector3::Vector3(const Vector3& other) {
    *this = other;
}

Vector3::Vector3(double arg1, double arg2, double arg3) {
    elem[0] = arg1; elem[1] = arg2; elem[2] = arg3;
}

double& Vector3::operator[](unsigned int i) {// +
    return elem[i];
}

double Vector3::operator[](unsigned int i) const {
    return elem[i];
}

Vector3& Vector3::operator=(const Vector3& other) {// +
    for (unsigned int i = 0; i < n; i++)
        elem[i] = other[i];
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& other) {
    for (int i = 0; i < n; i++)
        elem[i] += other[i];
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    for (int i = 0; i < n; i++)
        elem[i] -= other[i];
    return *this;
}

Vector3& Vector3::operator*=(const double number) {
    for (int i = 0; i < n; i++)
        elem[i] *= number;
    return *this;
}

Vector3& Vector3::operator/=(const double number) {
    double numOver = 1.0f / number;
    for (int i = 0; i < n; i++)
        elem[i] *= numOver;
    return *this;
}

bool operator==(const Vector3& lhs, const Vector3& rhs) { 
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

Vector3 operator+(const Vector3& our, const Vector3& other) {
    return Vector3(our) += other;
}

Vector3 operator-(const Vector3& our, const Vector3& other) {
    return { our.elem[0] - other.elem[0], our.elem[1] - other.elem[1], our.elem[2] - other.elem[2] };
}

Vector3 operator*(const Vector3& our, double number) {
    return our.elem[0] * number, our.elem[1] * number, our.elem[2] * number;
}

Vector3 operator*(const double number, const Vector3& our) {
    return number * our.elem[0], number* our.elem[1], number* our.elem[2];
}

Vector3 operator/(const Vector3& our, const double number) {
    double numOver = 1.0f / number;
    return our.elem[0] * numOver, our.elem[1] * numOver, our.elem[2] * numOver;
}

double Vector3::getNorma() const {
    return sqrt(elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2]);
}

void Vector3::normalize() {
    double magInv = elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2];
    double invNorm = 1.0f / sqrt(magInv);
    elem[0] *= invNorm;
    elem[1] *= invNorm;
    elem[2] *= invNorm;
}

Vector3 Vector3::getNormalized()const {
    Vector3 result(*this);
    double magInv = elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2];
        double invNorm = 1.0f / sqrt(magInv);
        result.elem[0] *= invNorm;
        result.elem[1] *= invNorm;
        result.elem[2] *= invNorm;
    return result;
}

double Vector3::getScalarProduct(const Vector3& other) const {
    return (elem[0] * other.elem[0]) + (elem[1] * other.elem[1]) + (elem[2] * other.elem[2]);
}

Vector3 getVectorProduct(const Vector3& our, const Vector3& other) {
    return Vector3(
        (our[1] * other[2]) - (our[2] * other[1]),
        (our[2] * other[0]) - (our[0] * other[2]),
        (our[0] * other[1]) - (our[1] * other[2])
    );
}

Vector3 Vector3::operator-()const {
    return Vector3(-elem[0], -elem[1], -elem[2]); // ?+
}

std::ostream& operator<<(std::ostream& stream, const Vector3& V) {
    stream << "vector [" << V[0] << ", " << V[1] << ", " << V[2] << "]";
    return stream;
}

const double* Vector3::getElements() {
    return elem;
}

bool operator!=(const Vector3& our, const Vector3& other) {
    return !(our == other);// +
}

Vector3::~Vector3() {
}
