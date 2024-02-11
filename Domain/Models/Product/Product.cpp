#include "Product.h"

string Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}
double Product::getDiscount() const {
	return discount;
}

bool Product::getAvailability() const {
	return available;
}

void Product::setName(string newName) {
	name = newName;
}

void Product::setPrice(double newPrice) {
	price = newPrice;
}
void Product::setDiscount(double newDiscount) {
	discount = newDiscount;
}

void Product::setAvailability(bool newAvailability) {
	available = newAvailability;
}

string Product::toString() {
	return name + " - $" + std::to_string(price) + " [" + (available ? "Available" : "Not Available") + "]";
}