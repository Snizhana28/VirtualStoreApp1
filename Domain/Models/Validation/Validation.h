#include "../../../Internal/library.h"

#ifndef VALIDATION_H
#define VALIDATION_H

enum InfoType {
	personalInfo,
	password
};

class Validation
{
private:
	static bool IsDigit(char sign);
public:
	static bool ValidatePersonalInfo(string personalInfo);
	static bool ValidatePassword(string password);
};
#endif 