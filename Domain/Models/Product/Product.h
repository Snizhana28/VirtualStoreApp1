#include "../../../Internal/library.h"

#ifndef PRODUCT_H
#define PRODUCT_H
class Product
{
private:
	string name;
	double price;
	double discount;
	bool available;
public:
	Product() = default;
	Product(string name, double price, double discount) : name(name), price(price), discount(discount), available(true) {}


	string getName() const;
	double getPrice() const;
	double getDiscount() const;
	bool getAvailability() const;

	void setName(string newName);
	void setPrice(double newPrice);
	void setDiscount(double newDiscount);
	void setAvailability(bool newAvailability);
	string toString();

	~Product() {
		name.clear();
		price = 0;
		discount = 0;
	}
};

#endif