#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "booking.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

  
    Booking arr1[5] = {
        Booking(1, "Ivan", "111"),
        Booking(2, "Petro", "222"),
        Booking(3, "Olga", "333"),
        Booking(4, "Maria", "444"),
        Booking(5, "Adnrey", "555"),
    };

    Booking* arr2 = new Booking[5];
    for (int i = 0; i < 5; ++i) {
        arr2[i] = Booking(10 + i, "guest" + std::to_string(i), "000");
    }

    std::cout << "Static arr\n";
    for (int i = 0; i < 5; ++i) {
        arr1[i].Book(2 + i, "Comfort");  
        arr1[i].Confirm();
        arr1[i].Print();
    }

    std::cout << "\nDynamic arr\n";
    for (int i = 0; i < 5; ++i) {
        arr2[i].Book(3);                
        arr2[i].Print();
    }

    Booking* p = &arr1[0];
    p->Book(5, "Lux");
    p->Confirm();
    std::cout << "\nwPointer\n";
    p->Print();

    int size = 0;
    int* sample = arr1[1].RandomSortedArray(size);
    std::cout << "\nrandom arr (" << size << "): ";
    for (int i = 0; i < size; ++i) std::cout << sample[i] << " ";
    std::cout << "\n";
    delete[] sample;

    std::ofstream out("data.txt");
    for (int i = 0; i < 5; ++i) arr1[i].SaveToFile(out);
    out.close();

    std::ifstream in("data.txt");
    Booking loaded[5];
    for (int i = 0; i < 5; ++i) loaded[i].LoadFromFile(in);
    in.close();

    std::cout << "\nfrom file\n";
    for (int i = 0; i < 5; ++i) loaded[i].Print();

    delete[] arr2;
    return 0;
}