#include "../../Models/ActionHadler/ActionHadler.h"
#include "../../Models/Validation/Validation.h"
#include "../../Users/Employee/Employee.h"

#ifndef EMPLOYEEPROVIDER_H
#define EMPLOYEEPROVIDER_H

class EmployeeProvider : public ActionHandler
{
private:
	vector<Employee*> employees;
	string CreatePersonalInfo(string text, InfoType info);
	string InputLogin(string text);
	string InputRank();
public:
	EmployeeProvider() = default;
	EmployeeProvider(vector<Employee*> employees);

	vector<Employee*> getEmployees();
	void Create() override;
	bool SignIn() override;
	void ShowAllEmployees();
	~EmployeeProvider();
};

#endif