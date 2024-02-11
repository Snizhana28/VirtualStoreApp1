#include "ScreensUI.h"

void ScreensUI::Screen1MainLogin()
{
	cls;
	while (true)
	{
		cout << "Ласкаво просимо в систему магазину!" << endl;
		cout << "1 - Створіть новий обліковий запис" << endl;
		cout << "2 - Увійдіть в існуючий обліковий запис" << endl;
		cout << "3 - Вийти" << endl;
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
			cls;
			Screen2SignUp(); 
			cout << endl << endl;
			break;
		case 2:
			cls;
			Screen3SignIn(); 
			cout << endl << endl;
			break;
		case 3:
			cout << "Вихід...";
			exit(0);
			break;
		default:
			cout << "Помилка введення! Невірний символ введення.";
			break;
		}
	} 

	
}