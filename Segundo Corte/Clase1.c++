#include <iostream>

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