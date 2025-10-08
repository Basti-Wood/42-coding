#include <iostream>

class Fixed {
private:
    int _raw;
    static const int _fractionalBits = 8;

public:
    Fixed() : _raw(0) {}
    Fixed(const Fixed &other) : _raw(other._raw) {}
    
    Fixed &operator=(Fixed const &src) {
        std::cout << "Assignment operator called" << std::endl;
        if (this != &src) {
            this->_raw = src._raw;
        }
        return *this;
    }
    
    ~Fixed() {}
};

int main() {
    Fixed a;
    Fixed b;
    a = b;  // This should call the assignment operator
    std::cout << "Test completed" << std::endl;
    return 0;
}
