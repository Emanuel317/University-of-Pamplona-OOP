#include <iostream>

/**
 * Implementación del Doxygen
 * @brief Programa para crear una clase de un auto y acelerar el auto
 * @param speed es la velocidad del auto
 * @return No retorna nada
 */

using std::string;

class Car {
    
    //Atributos
    string Manufacturer;
    int EngineCapacity;
    int Power;
    string Color;
    double Price;

    //Métodos
    void start() {
        std::cout << "Car is starting..." << std::endl;
        std::cout << "Car is now on." << std::endl;
    }

    void accelerate() {
        std::cout << "Car is accelerating..." << std::endl;
        std::cout << "Car is now at speed." << std::endl;
    }

    void brake() {
        std::cout << "Car is braking..." << std::endl;
        std::cout << "Car is now stopped." << std::endl;
    }

    void turn() {

        std::cout << "Car is turning..." << std::endl;
        std::cout << "Car has just turned." << std::endl;
    }
};

int main () {

    Car joseCar;
    Car mariaCar;
    return 0;
}