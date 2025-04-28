//
// Created by Milosz on 2025-04-28.
//

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H
#include <iostream>
#include <memory>
#include <vector>

// Zaprojektuj w C++ system do symulacji zarządzania kilkoma silnikami w urządzeniu embedded.
// Wymagania:
// Base class : Motor Pole: ID(numer silnika) Pole: speed(prędkość obrotowa,int)
// virtual void run() — wirtualna metoda uruchamiająca silnik (symulacja przez std::cout)

// Derived classes:
// StepperMotor — silnik krokowy (specjalny run())
// DcMotor — zwykły silnik DC (specjalny run())

//Manager
// class : MotorController Przechowuje wektor wskaźników na Motor.
// addMotor(Motor*) — dodaje nowy silnik.
// runAllMotors() — wywołuje run() na wszystkich silnikach.
// Maksymalnie 5 silników.
// Jeśli próbujesz dodać6. silnik — ignoruj lub wypisz błąd.

//Bonus:
// Zaimplementuj destruktory poprawnie (żeby nie było wycieków pamięci).
// Zaprojektuj zgodnie z SOLID.

class Motor {
protected:
    size_t ID_;
    size_t speed_;
public:
    virtual void run() = 0;
    explicit Motor(const size_t& id) : ID_(id), speed_(0) {}
    virtual ~Motor() = default;
};

class StepperMotor : public Motor {
public:
    void run() override {
        speed_ = 10;
        std::cout << "Running STEP at speed: " << speed_ << std::endl;
    }
    explicit StepperMotor(const size_t& id) : Motor(id) {}

};

class DcMotor : public Motor {
public:
    void run() override {
        speed_ = 100;
        std::cout << "Running DC at speed: " << speed_ << std::endl;
    }
    explicit DcMotor(const size_t& id) : Motor(id) {}

};

class MotorController {
    std::vector<std::shared_ptr<Motor>> motors;
public:
    void addMotor(const std::shared_ptr<Motor>& motorPtr) {
        if (motors.size()<5)
            motors.emplace_back(motorPtr);
    }
    void runAllMotors() {
        for (const auto& m : motors) {
            m->run();
        }
    }

};


inline void testMotor() {
    std::shared_ptr<Motor> m1 = std::make_shared<StepperMotor>(1);
    std::shared_ptr<Motor> m2 = std::make_shared<DcMotor>(2);
    MotorController c1;
    c1.addMotor(m1);
    c1.addMotor(m2);
    c1.runAllMotors();

}

#endif //MOTOR_CONTROLLER_H
