//
// Created by Milosz on 2025-04-27.
//

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H
#include <iostream>
#include <string>
#include <mutex>
// Zaimplementuj w C++ prostą kolejkę wiadomości (MessageQueue), podobną do tej, jaką oferuje np. FreeRTOS.
// MessageQueue to klasa umożliwiająca przechowywanie wiadomości (np. int, string itp.).
// Kolejka działa na zasadzie FIFO (first-in-first-out).

// Musisz zaimplementować metody:
// void send(const std::string& msg): dodaj wiadomość na koniec kolejki,
// std::string receive(): odbierz wiadomość z początku kolejki.

// Kolejka ma ograniczoną pojemność: np. max 5 wiadomości.
// Jeśli kolejka jest pełna i ktoś wyśle nową wiadomość → nadpisz najstarszą (jak w pierścieniu - circular buffer).
// Jeżeli receive() wywołasz na pustej kolejce → powinno rzucić wyjątek lub zwrócić specjalną wiadomość ("EMPTY").
// Używaj czystego C++, bez STL-a typu std::queue (chcemy, żebyś sam zarządzał buforem).

// Wymagania dodatkowe (Bonusy):
// Kolejka powinna być thread-safe (np. użyj std::mutex).
// Obsłuż przepełnienie w elegancki sposób (np. wyrzuć wyjątek lub nadpisuj automatycznie).
// Zaprojektuj kod zgodnie z SOLID.


class MessageQueue {
    std::mutex queueMutex;
    std::string messages[5];
    size_t writeIdx;
    size_t readIdx;
    size_t messageCount;
public:
    MessageQueue() : writeIdx(0), readIdx(0), messageCount(0){}
    void send(const std::string& msg) {
        std::lock_guard<std::mutex> lock(queueMutex); //RAII
        messages[writeIdx] = msg;
        if (messageCount == 5) {
            readIdx = (readIdx + 1) % 5;
        }
        else {
            messageCount++;
        }
        writeIdx = (writeIdx + 1) % 5;
        return;
    }
    std::string receive() {
        std::lock_guard<std::mutex> lock(queueMutex); //RAII
        if (messageCount == 0) {
            std::cout << "EMPTY!" << std::endl;
            return "";
        }
        std::string messageCopy = messages[readIdx];
        readIdx = (readIdx + 1) % 5;
        messageCount--;
        return messageCopy;
    }
};

inline void testMessageQueue() {

    MessageQueue q;
    q.send("1");
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;
    q.send("2");
    q.send("3");
    q.send("4");
    q.send("5");
    q.send("6");
    q.send("7");
    q.send("8");
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;
    std::cout << q.receive() << std::endl;

}

#endif //MESSAGE_QUEUE_H
