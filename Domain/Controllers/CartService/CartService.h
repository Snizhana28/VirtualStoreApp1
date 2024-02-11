#include "../../Models/Product/Product.h"
#include "../EmployeeProvaider/EmployeeProvider.h"

class CartService
{
private:
	vector<Product> cart;
public:
	CartService() = default;
	~CartService();
	void AddToCart(const Product& product, int productCount);
	double GetTotalPrice();
	void ShowCart();
	void ClearCart();
	double ApplyDiscount(EmployeeProvider* employeeProvider);
};