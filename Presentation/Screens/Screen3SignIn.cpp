#include "ScreensUI.h"

void ScreensUI::Screen3SignIn()
{
	cls;
	 while (true)
	 {
		bool loggedIn = false;
		cout << "���� � �������� �����" << endl;
		cout << "������� ��� ��������� ������:" << endl;
		cout << "1 - ���� �� �볺���" << endl;
		cout << "2 - ���� �� �����������" << endl;
		cout << "3 - �����" << endl;
		cout << "������� ��: ";
		unsigned int num;
		cin >> num;

		if (cin.fail())
		{
			cout << "������� ��������! ���� �����, ������ ���� �����." << endl;
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
				cout << "������� ��������! ������� ������ ��������.";
				break;
		}
	}
}