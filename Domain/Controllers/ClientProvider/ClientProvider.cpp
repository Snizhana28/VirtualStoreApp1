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

string ClientProvider::InputLogin(string text)
{
	string value;
	bool check;
	do
	{
		check = false;
		cout << "������ ��� login:";
		cin >> value;
		for (auto obj : clients)
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

bool ClientProvider::InputStatus()
{
	bool value;
	bool check;
	int num;
	do
	{
		check = false;
		cout << "�� ���� �����?" << endl;
		cout << "������: ��� - 1 / ͳ - 0. " << endl;
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
			cout << "������� ��������! ����������� ��������." << endl;
			check = true;
			continue;
		}
		break;
	} while (check);
	return value;
}

void ClientProvider::Create()
{
	string firstName = CreatePersonalInfo("������ ���� ��'�: ", InfoType::personalInfo);
	string lastName = CreatePersonalInfo("������ ���� �������: ", InfoType::personalInfo);
	string login = InputLogin("������ ��� login: ");
	string password = CreatePersonalInfo("���������� ������: ", InfoType::password);
	bool vip = InputStatus();
	clients.push_back(new Client(login, password, firstName, lastName, vip));
	cout << "�������� ����� ��������! �������� ����...";
}


bool ClientProvider::SignIn()
{
	string login, password;
	cout << "������ ��� login:" << endl;
	cin >> login;
	cout << "������ ��� ������:" << endl;
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
		cout << "���� �������� ������!" << endl;
		cout << "������� ���, " << client->getFirstName() << " " << client->getLastName() << (client->getClubMember() ? " VIP!" : " !") << endl;
		return true;
	}
	else
	{
		cout << "������� �����! ������� ���� ��� ������." << endl;
		return false;
	}
}

void ClientProvider::ShowAllClients()
{
	cout << "�� �볺���:" << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		cout << i + 1 << ". " << "��'� " << clients[i]->getFirstName() << "\n������� " << clients[i]->getLastName() << " " << (clients[i]->getClubMember() ? " VIP!" : " !") << endl;
		cout << "-----------------------------------" << endl;
	}
}

void ClientProvider::ShowClubMembers()
{
	cout << "����� �����: " << endl;
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i]->getClubMember())
		{
			cout << i + 1 << ". " << "��'� " << clients[i]->getFirstName() << "\n������� " << clients[i]->getLastName() << " " << (clients[i]->getClubMember() ? " VIP!" : " !") << endl;
			cout << "-----------------------------------" << endl;
		}
	}
}

void ClientProvider::ShowClientsWithPurchases()
{
	cout << "�볺���, �� �������� ���� � ���� �������:" << endl;
	for (Client* customer : clients)
	{
		if (customer->getTotalPurchaseAmount() > 0.0)
		{
			cout << "��'� " << customer->getFirstName() << "\n������� " << customer->getLastName() << " VIP!" << endl;
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
	cout << "�볺�� �� �������� ����� �������:" << endl;
	cout << "��'� " << maxClient->getFirstName() << "\n������� " << maxClient->getLastName() << " " << (maxClient->getClubMember() ? " VIP!" : " !") << endl;
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