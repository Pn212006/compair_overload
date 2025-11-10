#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    bool operator<(const Complex& other) const {
        return magnitude() < other.magnitude();
    }

    bool operator>(const Complex& other) const {
        return other < *this;
    }

    bool operator<=(const Complex& other) const {
        return !(other < *this);
    }

    bool operator>=(const Complex& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }
};

int main() {
    Complex a(3, 4);
    Complex b(1, 1);
    Complex c(3, 4);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n\n";

    std::cout << std::boolalpha;
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a == c: " << (a == c) << "\n";
    std::cout << "a > b: "  << (a > b) << "\n";
    std::cout << "a <= c: " << (a <= c) << "\n";
    std::cout << "b >= a: " << (b >= a) << "\n";

    return 0;
}
