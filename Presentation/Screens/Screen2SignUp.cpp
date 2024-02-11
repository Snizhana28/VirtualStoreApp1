#include "ScreensUI.h"

void ScreensUI::Screen2SignUp()
{
	cls;
	while (true)
	{
		cout << "Реєстрація нового облікового запису" << endl;
		cout << "Виберіть тип облікового запису:" << endl;
		cout << "1 - Реєстрація як клієнта" << endl;
		cout << "2 - Реєстрація як співробітника" << endl;
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
			clientProvider.Create();
			cout << endl;
			system("pause");
			Screen1MainLogin();
			break;
		case 2:
			employeeProvider.Create();
			cout << endl;
			system("pause");
			Screen1MainLogin();
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