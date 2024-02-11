#include "ScreensUI.h"

void ScreensUI::Screen4EmployeeMenu()
{
	cls;
	double discount = 0;
	double totalPrice = 0;
	double discountedTotalPrice = 0;
	do
	{
		int choice;
		store.displayMenuForEmployee();
		cin >> choice;

		if (cin.fail())
		{
			cout << "Помилка введення! Будь ласка, введіть ціле число." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		switch (choice)
		{
		case 1:

			clientProvider.ShowAllClients();
			break;
		case 2:
			clientProvider.ShowClubMembers();
			break;
		case 3:
			clientProvider.ShowClientsWithPurchases();
			break;
		case 4:
			clientProvider.ShowClientWithMaxPurchase();
			break;
		case 5:
			productProvaider.AddProduct(product);
			break;
		case 6:
			productProvaider.ShowAllProducts();
			productProvaider.ChangeProductAvailability();
			break;
		case 7:
			productProvaider.ShowAllProducts();
			cout << "Введіть номер продукту, який хочете додати в корзину" << endl;
			int productNumber;
			cin >> productNumber;

			if (!productProvaider.CheckProduct(productNumber))
				continue;

			cout << "Введіть кількість продукту" << endl;
			int productCount;
			cin >> productCount;

			if (productCount <= 0)
			{
				cout << "Кількість продукту має бути більшою за 0" << endl;
				continue;
			}
			if (productProvaider.CheckProductAvailability(productNumber) == true)
			{
				cart.AddToCart(productProvaider.GetProduct(productNumber), productCount);
				cart.ShowCart();

				discount = cart.ApplyDiscount(&employeeProvider);
				cout << "Знижка: " << (discount * 100) << "%" << endl;
				totalPrice = cart.GetTotalPrice();
				discountedTotalPrice = totalPrice * (1 - discount);

				cout << "Загальна вартість покупки з урахуванням знижки: " << discountedTotalPrice << endl;
			}
			else
			{
				cout << "Товару немає в наявності" << endl;
			}
			cart.ClearCart();
			break;
		case 8:
			cout << endl;
			system("pause");
			Screen1MainLogin();
			return;
		default:
			cout << "Неправильне введення" << endl;
			break;
		}
	} while (true);
}