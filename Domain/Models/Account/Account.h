#include "../../../Internal/library.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
	string login;
	string password;
	string first_name;
	string last_name;

public:
	Account() = default;
	Account(string login, string password, string first_name, string last_name);

	void setLogin(string login);
	void setPassword(string password);
	void setFirstName(string first_name);
	void setLastName(string last_name);

	string getLogin();
	string getPassword();
	string getFirstName();
	string getLastName();
	Account getCurrentInstance();

	~Account() {
		login.clear();
		password.clear();
		first_name.clear();
		last_name.clear();
	}
};

#endif