#include "ProductProvider.h"

void ProductProvaider::AddProduct(Product& product)
{
	string name;
	double price;
	double discount;
	cout << "��������� ��������" << endl;
	cout << "������ ����� ��������: ";
	cin >> name;
	product.setName(name);
	cout << "������ ���� ��������: ";
	cin >> price;
	product.setPrice(price);
	cout << "������ ������ �� �������: ";
	cin >> discount;
	product.setDiscount(discount);
	product.setAvailability(true);

	products.push_back(product);
	cout << "������� ������" << endl;
}

void ProductProvaider::ChangeProductAvailability()
{
	int number;
	cout << "���� ������� ��� ��������" << endl;
	cout << "������� �������: " << endl;
	for (int i = 0; i < products.size(); i++)
	{
		cout << i + 1 << ". " << products[i].getName() << endl;
	}
	cin >> number;
	if (products[number - 1].getAvailability() == true)
	{
		products[number - 1].setAvailability(false);
		cout << "������ �������� ������ �� '���� � ��������'" << endl;
	}
	else
	{
		products[number - 1].setAvailability(true);
		cout << "������ �������� ������ �� '� � ��������'" << endl;
	}
}

void ProductProvaider::ShowAllProducts()
{
	int number;
	cout << "������ ��������" << endl;
	for (int i = 0; i < products.size(); i++)
	{
		cout << i + 1 << ". " << products[i].getName() << endl;
	}
	cout << "������� �������: ";
	cin >> number;
	cout << "���������� ��� �������: " << endl;
	cout << "�����: " << products[number - 1].getName() << endl;
	cout << "ֳ��: " << products[number - 1].getPrice() << endl;
	cout << "������: " << products[number - 1].getDiscount() << endl;
	if (products[number - 1].getAvailability() == true)
	{
		cout << "� ��������" << endl;
	}
	else
	{
		cout << "���� � ��������" << endl;
	}
}

void ProductProvaider::ShowAvailableProducts()
{
	int number;
	cout << "������ ��������, �� � � ��������" << endl;
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getAvailability() == true)
		{
			cout << i + 1 << ". " << products[i].getName() << endl;
		}
	}
}

bool ProductProvaider::CheckProduct(int index)
{
	if (index < 0 || index > products.size())
	{
		cout << "������������ ������" << endl;
		return false;
	}
	return true;
}

bool ProductProvaider::CheckProductAvailability(int index)
{
	if (products[index - 1].getAvailability() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Product ProductProvaider::GetProduct(int index)
{
	return products[index - 1];
}

ProductProvaider::~ProductProvaider()
{
	products.clear();
}

