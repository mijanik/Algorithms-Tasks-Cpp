//
// Created by Milosz on 2025-04-27.
//

#ifndef RTOS_SIMULATION_H
#define RTOS_SIMULATION_H
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

// Zaprojektuj w C++ prostą symulację działania RTOS Scheduler'a.

// W systemie będą występować: Task – bazowa klasa reprezentująca zadanie,
// ConcreteTask – klasy dziedziczące po Task (np.SensorTask, CommunicationTask),
// Scheduler – klasa zarządzająca kolejką tasków i ich "wykonywaniem"

// Każdy task: ma swoje ID, nazwę, "priorytet" (liczba całkowita: im większy, tym ważniejszy)
// ma metodę run(), która symuluje wykonanie zadania (np.cout << "Sensor reading...")

// Scheduler: przechowuje listę tasków, umożliwia dodawanie tasków,
// wykonuje je w kolejności od najwyższego priorytetu do najniższego (symulacja preemptive scheduler'a).

// Task – klasa bazowa (ID, nazwa, priorytet, run() jako virtual),
// SensorTask, CommunicationTask – dziedziczą po Task i implementują własne run().

// Scheduler umożliwia addTask(Task&),
// Scheduler sortuje i wywołuje wszystkie taski (runAll()),
// Max. 10 tasków w schedulerze.

// Bonusy:
// Ogranicz kolejkę (FIFO) – jak dodasz 11-ty task, najstarszy wyleci,
// Zaprojektuj wszystko zgodnie z SOLID,
// Możesz dodać np. SecureTask — task, który wykonuje się tylko jeśli spełnione są dodatkowe warunki (np. "secure mode enabled").

class Task {
protected:
    uint8_t ID_;
    std::string name_;
    uint8_t priority_;
public:
    virtual void run() = 0;
    Task(const uint8_t& id, const std::string& name, const uint8_t& priority) :
        ID_(id), name_(name), priority_(priority) {}
    uint8_t getPriority() const {
        return priority_;
    }

    Task() = delete;
    virtual ~Task() = default;

};

class SensorTask : public Task{
public:
    SensorTask() = delete;
    SensorTask(const uint8_t& id, const std::string& name, const uint8_t& priority) :
        Task(id, name, priority){}
    void run() override {
        std::cout << "SensorTask Running!" << std::endl;
    }
};

class CommunicationTask : public Task{
public:
    CommunicationTask() = delete;
    CommunicationTask(const uint8_t& id, const std::string& name, const uint8_t& priority) :
        Task(id, name, priority){}
    void run() override {
        std::cout << "CommunicationTask Running!" << std::endl;
    }
};

class Scheduler {
    std::vector<Task*> tasks;
public:
    Scheduler() = default;
    void addTask(Task* newTask) {
        tasks.emplace_back(newTask);
    }
    size_t getTaskIdxWithBiggestPriority() const {
        uint8_t maxPriority = 0;
        uint8_t maxPriority_index = 0;
        size_t i = 0;
        for (; i<tasks.size(); i++) {
            if (tasks[i]->getPriority() > maxPriority) {
                maxPriority_index = i;
                maxPriority = tasks[i]->getPriority();
            }
        }
        return maxPriority_index;
    }

    void runAll(uint8_t times) {
        for (auto i = 0; i < times; i++) {
            auto idx = getTaskIdxWithBiggestPriority();
            tasks[idx]->run();
        }
    }
};

inline void testRTOS() {
    Task* task1 = new SensorTask(1, "sensor1", 2);
    Task* task2 = new CommunicationTask(2, "sensor2", 3);
    Scheduler sch;

    sch.addTask(task1);
    sch.addTask(task2);
    sch.runAll(3);

    delete task1;
    delete task2;
}

#endif //RTOS_SIMULATION_H
