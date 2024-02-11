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
			cout << "������� ��������! ���� �����, ������ ���� �����." << endl;
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
			cout << "������ ����� ��������, ���� ������ ������ � �������" << endl;
			int productNumber;
			cin >> productNumber;

			if (!productProvaider.CheckProduct(productNumber))
				continue;

			cout << "������ ������� ��������" << endl;
			int productCount;
			cin >> productCount;

			if (productCount <= 0)
			{
				cout << "ʳ������ �������� �� ���� ������ �� 0" << endl;
				continue;
			}
			if (productProvaider.CheckProductAvailability(productNumber) == true)
			{
				cart.AddToCart(productProvaider.GetProduct(productNumber), productCount);
				cart.ShowCart();

				discount = cart.ApplyDiscount(&employeeProvider);
				cout << "������: " << (discount * 100) << "%" << endl;
				totalPrice = cart.GetTotalPrice();
				discountedTotalPrice = totalPrice * (1 - discount);

				cout << "�������� ������� ������� � ����������� ������: " << discountedTotalPrice << endl;
			}
			else
			{
				cout << "������ ���� � ��������" << endl;
			}
			cart.ClearCart();
			break;
		case 8:
			cout << endl;
			system("pause");
			Screen1MainLogin();
			return;
		default:
			cout << "����������� ��������" << endl;
			break;
		}
	} while (true);
}