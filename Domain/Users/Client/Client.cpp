#include "Client.h"

void Client::setClubMember(bool isClubMember)
{
	this->isClubMember = isClubMember;
}
bool Client::getClubMember()
{
	return this->isClubMember;
}
double Client::getTotalPurchaseAmount()
{
	return this->totalPurchaseAmount;
}
string Client::toString()
{
	return "Iм'я: " + first_name + "Прiзвище: " + last_name + " Член клуба: " + std::to_string(isClubMember) + " Загальну сума покупки: " + std::to_string(totalPurchaseAmount);
}