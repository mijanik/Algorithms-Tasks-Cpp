//
// Created by Milosz on 2025-04-18.
//

#ifndef CODERS_CLASSES_11_H
#define CODERS_CLASSES_11_H
#include <string>

class Ship {
private:
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_; // aktualna liczba załogi na statku
public:
    size_t getID() const {return id_;}
    std::string getName() const {return name_;}
    size_t getSpeed() const {return speed_;}
    size_t getMaxCrew() const {return maxCrew_;}
    size_t getCapacity() const {return capacity_;}

    Ship() : id_(-1){}
    Ship(const size_t &id, const std::string &name, const size_t &speed, const size_t &maxCrew, const size_t &capacity) :
        id_(id),
        name_(name),
        speed_(speed),
        maxCrew_(maxCrew),
        capacity_(capacity)
        {}
    Ship(const size_t &id, const size_t &speed, const size_t &maxCrew) :
        Ship(id, "", speed, maxCrew, 0){}

    Ship& operator+= (const int crew) {
        crew_ += crew;
        return *this;
    }
    Ship& operator-= (const int crew) {
        crew_ -= crew;
        return *this;
    }

};

class Cargo {
private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
public:
    Cargo& operator+=(const size_t cargo) {
        amount_+=cargo;
        return *this;
    }
    Cargo& operator-=(const size_t cargo) {
        amount_+=cargo;
        return *this;
    }
};

#endif //CODERS_CLASSES_11_H
