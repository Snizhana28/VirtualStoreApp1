#include "../../Domain/Controllers/CartService/CartService.h"
#include "../../Domain/Controllers/StoreService/StoreService.h"
#include "../../Domain/Controllers/EmployeeProvaider/EmployeeProvider.h"
#include "../../Domain/Controllers/ClientProvider/ClientProvider.h"
#include "../../Domain/Controllers/ProductProvaider/ProductProvider.h"

#ifndef SCREEN_H
#define SCREEN_H

class ScreensUI
{
public:
	StoreService store;
	CartService cart;
	ProductProvaider productProvaider;
	EmployeeProvider employeeProvider;
	ClientProvider clientProvider;
	Product product;

	void Screen1MainLogin();
	void Screen2SignUp();
	void Screen3SignIn();
	void Screen4EmployeeMenu();
	void Screen5ClientMenu();

	~ScreensUI() = default;
};
#endif