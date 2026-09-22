#include "booking.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

Booking::Booking()
    : id(0), name("-"), phone("-"), room_("Standard"), nights_(1),
    seats_(1), price_(0), confirmed_(false) {
}

Booking::Booking(int id_value, std::string name_value, std::string phone_value)
    : id(id_value), name(name_value), phone(phone_value), room_("Standard"),
    nights_(1), seats_(1), price_(0), confirmed_(false) {
}

void Booking::Book(int nights) {
    nights_ = nights;
    room_ = "Standard";
    price_ = 900;
}

void Booking::Book(int nights, std::string room) {
    nights_ = nights;
    room_ = room;
    if (room_ == "Lux") price_ = 2500;
    else if (room_ == "Comfort") price_ = 1500;
    else price_ = 900;
}

bool Booking::Confirm() {
    confirmed_ = true;
    return confirmed_;
}

double Booking::Total() const {
    return price_ * nights_;
}

void Booking::Print() const {

    std::cout << "id=" << id << " name=" << name << " tel=" << phone
        << " num=" << room_ << " places=" << seats_
        << " nights=" << nights_ << " price/night=" << price_
        << " sum=" << Total()
        << " aprooved=" << (confirmed_ ? "yes" : "no") << "\n";
}

void Booking::SaveToFile(std::ofstream& out) const {
    out << id << '\n' << name << '\n' << phone << '\n' << room_ << '\n'
        << seats_ << '\n' << nights_ << '\n' << price_ << '\n'
        << confirmed_ << '\n';
}

void Booking::LoadFromFile(std::ifstream& in) {
    in >> id;
    in.ignore();
    std::getline(in, name);
    std::getline(in, phone);
    std::getline(in, room_);
    in >> seats_ >> nights_ >> price_ >> confirmed_;
    in.ignore();
}

int* Booking::RandomSortedArray(int& size) const {
    size = 3 + std::rand() % 6;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = nights_ + std::rand() % 10;
    }
    std::sort(arr, arr + size);
    return arr;
}