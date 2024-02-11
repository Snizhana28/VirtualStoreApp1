#include "ScreensUI.h"

void ScreensUI::Screen5ClientMenu()
{
	cls;
	do
	{
		store.displayMenuForClient();
		int choice;
		cout << "������� ��:" << endl;
		cin >> choice;

		if (cin.fail())
		{
			cout << "������� ��������! ���� �����, ������ ���� �����." << endl;
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
			cout << "������ ����� ��������, ���� ������ ������ � �����" << endl;
			int productNumber;
			cin >> productNumber;

			if (!productProvaider.CheckProduct(productNumber))
			{
				cout << "������ � ����� ������� �� ����" << endl;
				continue;
			}

			cout << "������ ������� ��������" << endl;
			int productCount;
			cin >> productCount;

			if (productCount <= 0)
			{
				cout << "ʳ������ �������� �� ���� ������ �� 0" << endl;
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
			cout << "������� ������� ����� �������: " << cart.GetTotalPrice() << endl;
			cout << "����� �� �������!" << endl;
			cout << endl;
			system("pause");
			Screen1MainLogin();
			return;
		default:
			cout << "������� ��������! ������� ������ ��������." << endl;
			break;
		}
	} while (true);
}