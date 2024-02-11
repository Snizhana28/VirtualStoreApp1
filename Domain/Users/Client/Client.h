#include "../../Models/Account/Account.h"

#ifndef CLIENT_H
#define CLIENT_H

class Client : public Account
{
protected:
	bool isClubMember;
	double totalPurchaseAmount;
public:
	Client() : Account(), isClubMember(false) {}
	Client(string login, string password, string first_name, string last_name, bool isClubMember) : Account(login, password, first_name, last_name), isClubMember(isClubMember), totalPurchaseAmount(0.0) {}

	void setClubMember(bool isClubMember);
	bool getClubMember();
	double getTotalPurchaseAmount();

	string toString();
	~Client() = default;
};

#endif