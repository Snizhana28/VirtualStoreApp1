#include "ScreensUI.h"

void ScreensUI::Screen3SignIn()
{
	cls;
	 while (true)
	 {
		bool loggedIn = false;
		cout << "Вхід в обліковий запис" << endl;
		cout << "Виберіть тип облікового запису:" << endl;
		cout << "1 - Вхід як клієнта" << endl;
		cout << "2 - Вхід як співробітника" << endl;
		cout << "3 - Назад" << endl;
		cout << "Виберіть дію: ";
		unsigned int num;
		cin >> num;

		if (cin.fail())
		{
			cout << "Помилка введення! Будь ласка, введіть ціле число." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		switch (num)
		{
			case 1:
				loggedIn = clientProvider.SignIn();
				if (loggedIn)
				{
					cout << endl;
					system("pause");
					Screen5ClientMenu();
				}
				else
					Screen1MainLogin();
			case 2:
				loggedIn = employeeProvider.SignIn();
				if (loggedIn)
				{
					cout << endl;
					system("pause");
					Screen4EmployeeMenu();
				}
				else
				{
					cout << endl;
					system("pause");
					Screen1MainLogin();
				}
				break;
			case 3:
				return;
				break;
			default:
				cout << "Помилка введення! Невірний символ введення.";
				break;
		}
	}
}