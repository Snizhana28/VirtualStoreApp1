#include "../../Models/Account/Account.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Account
{
protected:
	string rank;
public:
	Employee() : Account() {}
	Employee(string login, string password, string first_name, string last_name, string rank) : Account(login, password, first_name, last_name), rank(rank) {}

	void setRank(string rank);
	string getRank();

	~Employee() = default;
};

#endif