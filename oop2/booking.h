#ifndef BOOKING_H_
#define BOOKING_H_

#include <fstream>
#include <string>

class Booking {
public:
	Booking();
	Booking(int id_value, std::string name_value, std::string phone_value);
	int id;
	std::string name;
	std::string phone;

	void Book(int nights);                       
	void Book(int nights, std::string room);       
	bool Confirm();
	double Total() const;

	void Print() const;
	void SaveToFile(std::ofstream& out) const;
	void LoadFromFile(std::ifstream& in);

	int* RandomSortedArray(int& size) const;

private:
	std::string room_;
	int nights_;
	int seats_;
	double price_;
	bool confirmed_;
};

#endif 
