#include "ScreensUI.h"

void ScreensUI::Screen2SignUp()
{
	cls;
	while (true)
	{
		cout << "��������� ������ ��������� ������" << endl;
		cout << "������� ��� ��������� ������:" << endl;
		cout << "1 - ��������� �� �볺���" << endl;
		cout << "2 - ��������� �� �����������" << endl;
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
			cout << "������� ��������! ������� ������ ��������.";
			break;
		}
	} 
}