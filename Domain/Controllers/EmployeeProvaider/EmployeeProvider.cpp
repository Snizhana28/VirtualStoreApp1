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
				cout << "Помилка введення! Введений текст не повинен містити цифер." << endl;
			else
				break;
		}
		else
		{
			if (Validation::ValidatePassword(value) == false)
				cout << "Помилка введення! Довжина пароля не повинна бути меншою за 8 символів." << endl;
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
		cout << "Введіть ваш login:";
		cin >> value;
		for (auto obj : employees)
		{
			if (obj->getLogin() == value)
			{
				cout << "Введений login зайнятий! Введіть інший..." << endl;
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

		cout << "Виберіть ваш ранг: ";
		cout << "\n[1] : Звичайний співробітник \n[2] : Менеджер \n[3] : Співробітник управління" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			value = "Звичайний співробітник";
			break;
		case 2:
			value = "Менеджер";
			break;
		case 3:
			value = "Співробітник управління";
			break;
		default:
			cout << "Помилка введення! Неправильне введення.";
			check = true;
			break;
		}
	} while (check);
	return value;
}

void EmployeeProvider::Create()
{
	string firstName = CreatePersonalInfo("Введіть ваше Ім'я: ", InfoType::personalInfo);
	string lastName = CreatePersonalInfo("Введіть ваше Прізвище: ", InfoType::personalInfo);
	string login = InputLogin("Введіть ваш login: ");
	string password = CreatePersonalInfo("Придумайте пароль: ", InfoType::password);
	string rank = InputRank();
	employees.push_back(new Employee(login, password, firstName, lastName, rank));
	cout << "Обліковий запис створено! Повторіть вхід...";
}

bool EmployeeProvider::SignIn()
{
	string login, password;
	cout << "Введіть ваш login:" << endl;
	cin >> login;
	cout << "Введіть ваш пароль:" << endl;
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
		cout << "Вхід виконано успішно!" << endl;
		cout << "Доброго дня, " << employee->getFirstName() << " " << employee->getLastName() << " (" << employee->getRank() << ")!" << endl;
		return true;
	}
	else
	{
		cout << "Помилка входу! Невірний логін або пароль." << endl;
		return false;
	}
}

void EmployeeProvider::ShowAllEmployees()
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		cout << "Імя: " << employees[i]->getFirstName() << endl;
		cout << "Прізвище: " << employees[i]->getLastName() << endl;
		cout << "Login: " << employees[i]->getLogin() << endl;
		cout << "Ранг: " << employees[i]->getRank() << endl;
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