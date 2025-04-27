//
// Created by Milosz on 2025-04-27.
//

#ifndef SENSORS_H
#define SENSORS_H
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

// System monitorowania czujników w sieci przemysłowej
// Zaprojektuj w C++ prosty system zarządzający czujnikami podłączonymi do magistrali komunikacyjnej w środowisku przemysłowym.

// Każdy czujnik wysyła okresowe dane pomiarowe (np. temperaturę, wilgotność).
// Dane te są odbierane przez jednostkę zarządzającą, która może je przetwarzać i logować.

// Wymagania:
// 1. Klasy:
// Sensor – klasa bazowa dla wszystkich czujników:
// ma ID, typ (np. "Temperature", "Humidity") i funkcję readData() zwracającą aktualny pomiar.

// TemperatureSensor, HumiditySensor – klasy dziedziczące po Sensor.
// Każdy typ generuje inne dane (float np. 23.5°C albo 45% RH).

// SensorManager – zarządza kolekcją czujników:
// pozwala rejestrować (addSensor) i odczytywać dane ze wszystkich czujników.

// 2. Funkcjonalność:
// Dodaj możliwość symulacji odczytu (np. losowe wartości dla pomiarów).
// SensorManager powinien potrafić przechowywać do 10 czujników.
// SensorManager powinien umożliwiać przegląd wszystkich aktualnych pomiarów.

// 3. Bonusy:
// Ogranicz wielkość listy czujników (max 10 czujników - FIFO: najstarsze są wyrzucane).
// Zaprojektuj tak, żeby klasy były zgodne z zasadami SOLID.
// Zrób osobną klasę np. DataLogger, która zapisuje pomiary (np. tylko wyświetla na ekranie).
// Wersja "SecureSensor" (opcjonalnie): odczyt danych z dodatkową weryfikacją.

enum sensorType {
    Temperature = 1,
    Humidity = 2,
    None = 0
};

class Sensor {
protected:
    uint8_t ID_;
    sensorType sensorType_;
public:
    Sensor() = delete;
    explicit Sensor(const uint8_t& ID, const sensorType& type) : ID_(ID), sensorType_(type) {}
    virtual ~Sensor() = default;

    virtual float readData() const = 0;

    uint8_t getID() const {return ID_;}
    std::string getTypeString() const {
        switch (sensorType_) {
            case Temperature:
                return "Temperature";
            case Humidity:
                return "Humidity";
            default:
                return "Unknown";
        }
    }
};

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor() = delete;
    explicit TemperatureSensor(const uint8_t& ID) : Sensor(ID, Temperature) {}
    float readData() const override {
        return 23.5; //tymczasowo
    }
};

class HumiditySensor : public Sensor {
public:
    HumiditySensor() = delete;
    explicit HumiditySensor(const uint8_t& ID) : Sensor(ID, Humidity) {}
    float readData() const override {
        return 45.0; //tymczasowo
    }
};

class SensorManager {
    std::vector<std::shared_ptr<Sensor>> sensors_;
public:
    SensorManager()= default;
    void addSensor(const std::shared_ptr<Sensor>& newSensorPtr) {
        if (sensors_.size()<10) {
            sensors_.emplace_back(newSensorPtr);
        }
        else
            std::cout << "ERROR - sensors number is " << sensors_.size() << " !" << std::endl;
    }
    void readAllSensors() const {
        for (const auto& s : sensors_) {
            std::cout << s->readData() << std::endl;
        }
    }
    void printConnectedSensors() const {
        for (const auto& s : sensors_) {
            std::cout << "ID: " <<static_cast<int>(s->getID())<< " , type: "<< s->getTypeString() << std::endl;
        }
    }

};

inline void testSensors() {
    auto t1 = std::make_shared<TemperatureSensor>(1);
    auto h1 = std::make_shared<HumiditySensor>(2);

    SensorManager manager;
    manager.addSensor(t1);
    manager.addSensor(h1);
    manager.readAllSensors();
    manager.printConnectedSensors();

}

#endif //SENSORS_H
