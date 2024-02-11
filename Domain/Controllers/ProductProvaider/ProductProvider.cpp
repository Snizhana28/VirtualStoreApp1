#include "ProductProvider.h"

void ProductProvaider::AddProduct(Product& product)
{
	string name;
	double price;
	double discount;
	cout << "Додавання продукту" << endl;
	cout << "Введіть назву продукту: ";
	cin >> name;
	product.setName(name);
	cout << "Введіть ціну продукту: ";
	cin >> price;
	product.setPrice(price);
	cout << "Введіть знижку на продукт: ";
	cin >> discount;
	product.setDiscount(discount);
	product.setAvailability(true);

	products.push_back(product);
	cout << "Продукт додано" << endl;
}

void ProductProvaider::ChangeProductAvailability()
{
	int number;
	cout << "Зміна статусу для продукту" << endl;
	cout << "Виберіть продукт: " << endl;
	for (int i = 0; i < products.size(); i++)
	{
		cout << i + 1 << ". " << products[i].getName() << endl;
	}
	cin >> number;
	if (products[number - 1].getAvailability() == true)
	{
		products[number - 1].setAvailability(false);
		cout << "Статус продукту змінено на 'немає в наявності'" << endl;
	}
	else
	{
		products[number - 1].setAvailability(true);
		cout << "Статус продукту змінено на 'є в наявності'" << endl;
	}
}

void ProductProvaider::ShowAllProducts()
{
	int number;
	cout << "Список продуктів" << endl;
	for (int i = 0; i < products.size(); i++)
	{
		cout << i + 1 << ". " << products[i].getName() << endl;
	}
	cout << "Виберіть продукт: ";
	cin >> number;
	cout << "Інформація про продукт: " << endl;
	cout << "Назва: " << products[number - 1].getName() << endl;
	cout << "Ціна: " << products[number - 1].getPrice() << endl;
	cout << "Знижка: " << products[number - 1].getDiscount() << endl;
	if (products[number - 1].getAvailability() == true)
	{
		cout << "В наявності" << endl;
	}
	else
	{
		cout << "Немає в наявності" << endl;
	}
}

void ProductProvaider::ShowAvailableProducts()
{
	int number;
	cout << "Список продуктів, які є в наявності" << endl;
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
		cout << "Неправильний індекс" << endl;
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

