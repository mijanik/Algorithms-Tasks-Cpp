#ifndef EMBEDDED_CPP_TRAINING_H
#define EMBEDDED_CPP_TRAINING_H
#include <cstdint>
#include <string>
#include <queue>

// Symulacja prostego urządzenia komunikacyjnego
// Zaprojektuj w C++ prostą klasę Device, reprezentującą urządzenie komunikacyjne w sieci przemysłowej.
// Urządzenia mogą wysyłać i odbierać komunikaty. Każde urządzenie ma swój unikalny adres ID (np. uint8_t)
// oraz kolejkę odebranych wiadomości.
// Wiadomość zawiera nadawcę, odbiorcę i treść.

//Wymagania:
// Zaimplementuj klasy:
// Message – reprezentującą wiadomość (zawiera: nadawca, odbiorca, treść),
// Device – bazową klasę z metodami sendMessage(Device& target, const std::string& content) i receiveMessage(const Message&),
// Można rozszerzyć Device do SecureDevice, który dodaje do wiadomości nagłówek bezpieczeństwa (np. SECURE: na początku treści).
// Napisz prostą symulację z 2–3 urządzeniami wymieniającymi wiadomości.
// Bonus: Zaimplementuj ograniczoną wielkość bufora odebranych wiadomości (FIFO), np. 10 wiadomości max.
// Bonus 2: Zadbaj o to, żeby klasy były zgodne z zasadą SOLID (może Cię o to zapytać reviewer).

class Message {
    uint8_t sender_;
    uint8_t receiver_;
    std::string data_;
public:
    Message(const uint8_t& sender, const uint8_t& receiver, const std::string& data) :
        sender_(sender),
        receiver_(receiver),
        data_(data){}

    std::string getData() const {
        return data_;
    }
};

class Device {
protected:
    uint8_t ID_;
    std::queue<std::string> incoming_messages_;
public:
    Device() = delete;
    virtual ~Device() = default;

    explicit Device(const uint8_t& ID) : ID_(ID){}; // "explicit", aby uniknąć niejawnej konwersji int -> Device
    virtual void sendMessage(Device& target, const std::string& content) const;
    void receiveMessage(const Message& message);
    void readMessage();
    void readAllMessages();
    uint8_t getID() const {return ID_;}
};

inline void Device::sendMessage(Device &target, const std::string &content) const {
    const Message new_message = Message(this->ID_, target.ID_, content);
    target.receiveMessage(new_message);
}

inline void Device::receiveMessage(const Message& message) {
    if (incoming_messages_.size()<10) {
        incoming_messages_.emplace(message.getData());
    }
    else {
        std::cout << "Messages limit exceeded!" << std::endl;
    }
}

inline void Device::readMessage() {
    if (incoming_messages_.empty()) {
        std::cout<<"No Messages!"<<std::endl;
        return;
    }
    std::cout<<incoming_messages_.front()<<std::endl;
    incoming_messages_.pop();
}

inline void Device::readAllMessages() {
    if (incoming_messages_.empty()) {
        std::cout<<"No Messages!"<<std::endl;
        return;
    }
    while (!incoming_messages_.empty()) {
        std::cout<<incoming_messages_.front()<<std::endl;
        incoming_messages_.pop();
    }
}

class SecureDevice : public Device{
public:
    void sendMessage(Device& target, const std::string& content) const override {
        const Message new_message = Message(this->ID_, target.getID(), "SECURE: " + content);
        target.receiveMessage(new_message);
    }
    SecureDevice() = delete;
    SecureDevice(const uint8_t& ID) : Device(ID) {}
};

inline void communicationTest() {
    SecureDevice device1(1);
    SecureDevice device2(2);
    device1.sendMessage(device2, "Hi");
    device2.readMessage();
    return;
}

#endif //EMBEDDED_CPP_TRAINING_H
