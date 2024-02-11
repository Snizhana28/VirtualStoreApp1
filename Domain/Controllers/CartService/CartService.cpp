#include "CartService.h"

void CartService::AddToCart(const Product& product, int productCount)
{
	for (int i = 0; i < productCount; i++)
	{
		cart.push_back(product);
	}
	cout << "����� ������ �� ������" << endl;
}

double CartService::GetTotalPrice()
{
	cout << "����� �������: ";
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
		cout << "������� �������" << endl;
	}
	else
	{
		cout << "�������: " << endl;
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
		if (employee->getRank() == "��������� ����������")
		{
			discount = 0.1;
			break;
		}
		else if (employee->getRank() == "��������")
		{
			discount = 0.2;
			break;
		}
		else if (employee->getRank() == "���������� ���������")
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
	cout << "������������� ������" << endl;
	return discount;
}

void CartService::ClearCart()
{
	cart.clear();
	cout << "������� ����������" << endl;
}

CartService::~CartService(){}