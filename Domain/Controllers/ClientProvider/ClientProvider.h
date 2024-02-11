#include "../../Models/ActionHadler/ActionHadler.h"
#include "../../Models/Validation/Validation.h"
#include "../../Users/Client/Client.h"

#ifndef CLIENTPROVIDER_H
#define CLIENTPROVIDER_H

class ClientProvider : public ActionHandler
{
private:
	vector<Client*> clients;

	string CreatePersonalInfo(string text, InfoType info);
	string InputLogin(string text);
	bool InputStatus();

public:
	ClientProvider() = default;
	ClientProvider(vector<Client*> employees);

	void Create() override;
	bool SignIn() override;

	void ShowAllClients();
	void ShowClubMembers();
	void ShowClientsWithPurchases();
	void ShowClientWithMaxPurchase();

	vector<Client*> getClients();
	~ClientProvider();
};

#endif