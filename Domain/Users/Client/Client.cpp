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
	return "I�'�: " + first_name + "��i�����: " + last_name + " ���� �����: " + std::to_string(isClubMember) + " �������� ���� �������: " + std::to_string(totalPurchaseAmount);
}