#include "CartService.h"

void CartService::AddToCart(const Product& product, int productCount)
{
	for (int i = 0; i < productCount; i++)
	{
		cart.push_back(product);
	}
	cout << "Товар додано до кошика" << endl;
}

double CartService::GetTotalPrice()
{
	cout << "Повна вартість: ";
	double totalPrice = 0;
	for (int i = 0; i < cart.size(); i++)
	{
		totalPrice += cart[i].getPrice();
	}
	return totalPrice;
}

void CartService::ShowCart()
{
	if (cart.size() == 0)
	{
		cout << "Корзина порожня" << endl;
	}
	else
	{
		cout << "Корзина: " << endl;
		for (int i = 0; i < cart.size(); i++)
		{
			cout << cart[i].toString() << endl;
		}
	}
}

double CartService::ApplyDiscount(EmployeeProvider* employeeProvider)
{
	double discount = 0;
	vector<Employee*> employees = employeeProvider->getEmployees();

	for (Employee* employee : employees)
	{
		if (employee->getRank() == "Звичайний співробітник")
		{
			discount = 0.1;
			break;
		}
		else if (employee->getRank() == "Менеджер")
		{
			discount = 0.2;
			break;
		}
		else if (employee->getRank() == "Співробітник управління")
		{
			discount = 0.3;
			break;
		}
	}
	for (Product product : cart)
	{
		double discountedPrice = product.getPrice() * (1 - discount);
		product.setPrice(discountedPrice);
	}
	cout << "Застосувалась знижка" << endl;
	return discount;
}

void CartService::ClearCart()
{
	cart.clear();
	cout << "Корзина очистилась" << endl;
}

CartService::~CartService(){}