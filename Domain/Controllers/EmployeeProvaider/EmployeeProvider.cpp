#include "EmployeeProvider.h"

EmployeeProvider::EmployeeProvider(vector<Employee*> employees)
{
	this->employees = employees;
}

vector<Employee*> EmployeeProvider::getEmployees()
{
	return employees;
}

string EmployeeProvider::CreatePersonalInfo(string text, InfoType info)
{
	string value;
	do
	{
		cout << text;
		cin >> value;
		if (info == InfoType::personalInfo)
		{
			if (Validation::ValidatePersonalInfo(value) == false)
				cout << "������� ��������! �������� ����� �� ������� ������ �����." << endl;
			else
				break;
		}
		else
		{
			if (Validation::ValidatePassword(value) == false)
				cout << "������� ��������! ������� ������ �� ������� ���� ������ �� 8 �������." << endl;
			else
				break;
		}
	} while (true);
	return value;
}

string EmployeeProvider::InputLogin(string text)
{
	string value;
	bool check;
	do
	{
		check = false;
		cout << "������ ��� login:";
		cin >> value;
		for (auto obj : employees)
		{
			if (obj->getLogin() == value)
			{
				cout << "�������� login ��������! ������ �����..." << endl;
				check = true;
				break;
			}
		}
	} while (check);
	return value;
}

string EmployeeProvider::InputRank()
{
	string value;
	int num;
	bool check;
	do
	{
		check = false;

		cout << "������� ��� ����: ";
		cout << "\n[1] : ��������� ���������� \n[2] : �������� \n[3] : ���������� ���������" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			value = "��������� ����������";
			break;
		case 2:
			value = "��������";
			break;
		case 3:
			value = "���������� ���������";
			break;
		default:
			cout << "������� ��������! ����������� ��������.";
			check = true;
			break;
		}
	} while (check);
	return value;
}

void EmployeeProvider::Create()
{
	string firstName = CreatePersonalInfo("������ ���� ��'�: ", InfoType::personalInfo);
	string lastName = CreatePersonalInfo("������ ���� �������: ", InfoType::personalInfo);
	string login = InputLogin("������ ��� login: ");
	string password = CreatePersonalInfo("���������� ������: ", InfoType::password);
	string rank = InputRank();
	employees.push_back(new Employee(login, password, firstName, lastName, rank));
	cout << "�������� ����� ��������! �������� ����...";
}

bool EmployeeProvider::SignIn()
{
	string login, password;
	cout << "������ ��� login:" << endl;
	cin >> login;
	cout << "������ ��� ������:" << endl;
	cin >> password;

	Employee* employee = nullptr;
	for (auto obj : employees)
	{
		if (obj->getLogin() == login && obj->getPassword() == password)
		{
			employee = obj;
			break;
		}
	}
	if (employee != nullptr)
	{
		cout << "���� �������� ������!" << endl;
		cout << "������� ���, " << employee->getFirstName() << " " << employee->getLastName() << " (" << employee->getRank() << ")!" << endl;
		return true;
	}
	else
	{
		cout << "������� �����! ������� ���� ��� ������." << endl;
		return false;
	}
}

void EmployeeProvider::ShowAllEmployees()
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		cout << "���: " << employees[i]->getFirstName() << endl;
		cout << "�������: " << employees[i]->getLastName() << endl;
		cout << "Login: " << employees[i]->getLogin() << endl;
		cout << "����: " << employees[i]->getRank() << endl;
		cout << "-----------------------------------" << endl;
	}
}

EmployeeProvider::~EmployeeProvider()
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		delete[] employees[i];
	}
	employees.clear();
}