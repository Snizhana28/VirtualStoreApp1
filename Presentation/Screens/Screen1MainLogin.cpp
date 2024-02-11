#include "ScreensUI.h"

void ScreensUI::Screen1MainLogin()
{
	cls;
	while (true)
	{
		cout << "������� ������� � ������� ��������!" << endl;
		cout << "1 - ������� ����� �������� �����" << endl;
		cout << "2 - ������ � �������� �������� �����" << endl;
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
			cout << "�����...";
			exit(0);
			break;
		default:
			cout << "������� ��������! ������� ������ ��������.";
			break;
		}
	} 

	
}