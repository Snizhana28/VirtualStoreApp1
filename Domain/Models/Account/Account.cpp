#include "Account.h"

Account::Account(string login, string password, string first_name, string last_name)
{
	setLogin(login);
	setPassword(password);
	setFirstName(first_name);
	setLastName(last_name);
}

void Account::setLogin(string login)
{
	this->login = login;
}
void Account::setPassword(string password)
{
	this->password = password;
}
void Account::setFirstName(string first_name)
{
	this->first_name = first_name;
}
void Account::setLastName(string last_name)
{
	this->last_name = last_name;
}

string Account::getLogin()
{
	return login;
}
string Account::getPassword()
{
	return password;
}
string Account::getFirstName()
{
	return first_name;
}
string Account::getLastName()
{
	return last_name;
}
Account Account::getCurrentInstance()
{
	return *this;
}