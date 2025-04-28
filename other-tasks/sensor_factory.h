//
// Created by Milosz on 2025-04-28.
//

#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H
#include <iostream>
#include <memory>
#include <vector>

// Zaprojektuj system obsługi różnych typów sensorów w urządzeniu embedded (np. temperatura, ciśnienie, wilgotność).
// Wymagania:

// Abstrakcyjna klasa bazowa:
// Sensor (interfejs)
// virtual void read() = 0; — metoda do odczytu danych z sensora.
// virtual ~Sensor() = default;

// Konkretnie zaimplementowane klasy sensorów:
// TemperatureSensor
// PressureSensor
// HumiditySensor
// Każda implementuje własną wersję read(), symulując odczyt np. std::cout << "Temperature: 25C".

// Factory (Wzorzec projektowy - Factory Method):
// SensorFactory — klasa z metodą:
// static std::unique_ptr<Sensor> createSensor(const std::string& type);
// Tworzy odpowiedni obiekt w zależności od parametru ("temperature", "pressure", "humidity").

// Manager sensorów: SensorManager
// Przechowuje listę sensorów (std::vector<std::unique_ptr<Sensor>>).
// Metoda void addSensor(const std::string& type); — wykorzystuje SensorFactory.
// Metoda void readAllSensors(); — wywołuje read() na wszystkich sensorach.

// Ograniczenia:
// Maksymalnie 5 sensorów. Jak dodasz 6-ty → wyświetl błąd.
// Zastosuj RAII — brak wycieków pamięci.
// Zaprojektuj zgodnie z SOLID.

// Interfejs
class Sensor {
public:
    virtual void read() = 0;
    virtual ~Sensor() = default;
};

class TemperatureSensor : public Sensor {
public:
    void read() override {
        std::cout << "reading temperature" << std::endl;
    }
};

class PressureSensor : public Sensor {
    void read() override {
        std::cout << "reading pressure" << std::endl;
    }
};

class HumiditySensor : public Sensor {
    void read() override {
        std::cout << "reading humidity" << std::endl;
    }
};

class SensorFactory {
public:
    static std::unique_ptr<Sensor> createSensor(const std::string& type) {
        switch (type) {
            case "TemperatureSensor":
                return std::make_unique<TemperatureSensor>();
            case "PressureSensor":
                return std::make_unique<PressureSensor>();
            case "HumiditySensor":
                return std::make_unique<PressureSensor>();
            default:
                return nullptr;
        }
    }
};

class SensorManager {
    std::vector<std::unique_ptr<Sensor>> sensors_;
public:
    void addSensor(const std::string& type);
    void readAllSensors();
    // TODO
};

#endif //SENSOR_FACTORY_H
