#include <iostream>
#include <string>

// Клас "Двигун"
class Engine {
private:
    std::string type;

public:
    Engine(std::string t) : type(t) {}

    std::string getType() const {
        return type;
    }
};

// Клас "Кузов"
class Body {
private:
    std::string color;

public:
    Body(std::string c) : color(c) {}

    std::string getColor() const {
        return color;
    }
};

// Клас "Колесо"
class Wheel {
private:
    int size;

public:
    Wheel(int s) : size(s) {}

    int getSize() const {
        return size;
    }
};

// Клас "Автомобіль"
class Car {
private:
    Engine engine;
    Body body;
    Wheel frontLeftWheel;
    Wheel frontRightWheel;
    Wheel rearLeftWheel;
    Wheel rearRightWheel;

public:
    // Конструктор
    Car(std::string engineType, std::string bodyColor, int wheelSize)
        : engine(engineType),
        body(bodyColor),
        frontLeftWheel(wheelSize),
        frontRightWheel(wheelSize),
        rearLeftWheel(wheelSize),
        rearRightWheel(wheelSize) {}

    // Конструктор копіювання з можливістю змін
    Car(const Car& other)
        : engine(other.engine.getType()),
        body(other.body.getColor()),
        frontLeftWheel(other.frontLeftWheel.getSize()),
        frontRightWheel(other.frontRightWheel.getSize()),
        rearLeftWheel(other.rearLeftWheel.getSize()),
        rearRightWheel(other.rearRightWheel.getSize()) {}

    // Вивід інформації про автомобіль
    void showInfo() const {
        std::cout << "Engine Type: " << engine.getType() << std::endl;
        std::cout << "Body Color: " << body.getColor() << std::endl;
        std::cout << "Wheel Size: " << frontLeftWheel.getSize() << " inches" << std::endl;
    }

    // Зміна кольору кузова
    void changeBodyColor(std::string newColor) {
        body = Body(newColor);
    }
};

int main() {
    // Створення першого автомобіля
    Car car1("V6", "Blue", 18);
    std::cout << "Car 1:" << std::endl;
    car1.showInfo();

    // Створення другого автомобіля на основі першого
    Car car2 = car1;
    std::cout << "\nCar 2 (copied from Car 1):" << std::endl;
    car2.showInfo();

    // Зміна кольору кузова другого автомобіля
    car2.changeBodyColor("Red");
    std::cout << "\nCar 2 after changing body color:" << std::endl;
    car2.showInfo();

    return 0;
}
