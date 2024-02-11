#include "ScreensUI.h"

void ScreensUI::Screen5ClientMenu()
{
	cls;
	do
	{
		store.displayMenuForClient();
		int choice;
		cout << "Виберіть дію:" << endl;
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
			productProvaider.ShowAvailableProducts();
			break;
		case 2:
			cout << "Введіть номер продукту, який хочете додати в кошик" << endl;
			int productNumber;
			cin >> productNumber;

			if (!productProvaider.CheckProduct(productNumber))
			{
				cout << "Товару з таким номером не існує" << endl;
				continue;
			}

			cout << "Введіть кількість продукту" << endl;
			int productCount;
			cin >> productCount;

			if (productCount <= 0)
			{
				cout << "Кількість продукту має бути більшою за 0" << endl;
				continue;
			}

			cart.AddToCart(productProvaider.GetProduct(productNumber), productCount);
			break;
		case 3:
			cart.ShowCart();
			break;
		case 4:
			cart.ClearCart();
			break;
		case 5:
			cout << "Поточна вартість вмісту корзини: " << cart.GetTotalPrice() << endl;
			cout << "Дякую за покупку!" << endl;
			cout << endl;
			system("pause");
			Screen1MainLogin();
			return;
		default:
			cout << "Помилка введення! Невірний символ введення." << endl;
			break;
		}
	} while (true);
}