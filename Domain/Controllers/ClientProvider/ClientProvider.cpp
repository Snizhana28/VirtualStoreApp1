#include "ClientProvider.h"

ClientProvider::ClientProvider(vector<Client*> clients)
{
	this->clients = clients;
}

vector<Client*> ClientProvider::getClients()
{
	return clients;
}

string ClientProvider::CreatePersonalInfo(string text, InfoType info)
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

string ClientProvider::InputLogin(string text)
{
	string value;
	bool check;
	do
	{
		check = false;
		cout << "Введіть ваш login:";
		cin >> value;
		for (auto obj : clients)
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

bool ClientProvider::InputStatus()
{
	bool value;
	bool check;
	int num;
	do
	{
		check = false;
		cout << "Ви член клубу?" << endl;
		cout << "Введіть: Так - 1 / Ні - 0. " << endl;
		cin >> num;
		switch (num)
		{
		case 0:
			value = false;
			break;
		case 1:
			value = true;
			break;
		default:
			cout << "Помилка введення! Неправильне введення." << endl;
			check = true;
			continue;
		}
		break;
	} while (check);
	return value;
}

void ClientProvider::Create()
{
	string firstName = CreatePersonalInfo("Введіть ваше Ім'я: ", InfoType::personalInfo);
	string lastName = CreatePersonalInfo("Введіть ваше Прізвище: ", InfoType::personalInfo);
	string login = InputLogin("Введіть ваш login: ");
	string password = CreatePersonalInfo("Придумайте пароль: ", InfoType::password);
	bool vip = InputStatus();
	clients.push_back(new Client(login, password, firstName, lastName, vip));
	cout << "Обліковий запис створено! Повторіть вхід...";
}


bool ClientProvider::SignIn()
{
	string login, password;
	cout << "Введіть ваш login:" << endl;
	cin >> login;
	cout << "Введіть ваш пароль:" << endl;
	cin >> password;

	Client* client = nullptr;
	for (auto obj : clients)
	{
		if (obj->getLogin() == login && obj->getPassword() == password)
		{
			client = obj;
			break;
		}
	}

	if (client != nullptr)
	{
		cout << "Вхід виконано успішно!" << endl;
		cout << "Доброго дня, " << client->getFirstName() << " " << client->getLastName() << (client->getClubMember() ? " VIP!" : " !") << endl;
		return true;
	}
	else
	{
		cout << "Помилка входу! Невірний логін або пароль." << endl;
		return false;
	}
}

void ClientProvider::ShowAllClients()
{
	cout << "Усі клієнти:" << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		cout << i + 1 << ". " << "Ім'я " << clients[i]->getFirstName() << "\nПрізвище " << clients[i]->getLastName() << " " << (clients[i]->getClubMember() ? " VIP!" : " !") << endl;
		cout << "-----------------------------------" << endl;
	}
}

void ClientProvider::ShowClubMembers()
{
	cout << "Члени клубу: " << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i]->getClubMember())
		{
			cout << i + 1 << ". " << "Ім'я " << clients[i]->getFirstName() << "\nПрізвище " << clients[i]->getLastName() << " " << (clients[i]->getClubMember() ? " VIP!" : " !") << endl;
			cout << "-----------------------------------" << endl;
		}
	}
}

void ClientProvider::ShowClientsWithPurchases()
{
	cout << "Клієнти, які здійснили хоча б одну покупку:" << endl;
	for (Client* customer : clients)
	{
		if (customer->getTotalPurchaseAmount() > 0.0)
		{
			cout << "Ім'я " << customer->getFirstName() << "\nПрізвище " << customer->getLastName() << " VIP!" << endl;
			cout << "-----------------------------------" << endl;
		}
	}
}

void ClientProvider::ShowClientWithMaxPurchase()
{
	Client* maxClient = clients[0];
	for (int i = 1; i < clients.size(); i++)
	{
		if (clients[i]->getTotalPurchaseAmount() > maxClient->getTotalPurchaseAmount())
		{
			maxClient = clients[i];
		}
	}
	cout << "Клієнт із найвищою сумою покупок:" << endl;
	cout << "Ім'я " << maxClient->getFirstName() << "\nПрізвище " << maxClient->getLastName() << " " << (maxClient->getClubMember() ? " VIP!" : " !") << endl;
	cout << "-----------------------------------" << endl;
}

ClientProvider::~ClientProvider()
{
	for (size_t i = 0; i < clients.size(); i++)
	{
		delete[] clients[i];
	}
	clients.clear();
}