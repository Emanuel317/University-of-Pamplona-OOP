#include <iostream>

/**
 * Implementación del Doxygen
 * @brief Programa para crear una clase de un auto y acelerar el auto
 * @param speed es la velocidad del auto
 * @return No retorna nada
 */

class Car {
    public:
        int speed;

        void acelerate() {
            speed += 10;
            std::cout << "Current speed is: " << speed << std::endl;
        }
};

int main () {

    return 0;
}