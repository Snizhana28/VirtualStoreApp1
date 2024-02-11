#include "../../Models/Product/Product.h"

class ProductProvaider : public Product
{
private:
	vector<Product> products;
public:
	ProductProvaider() = default;

	void AddProduct(Product& product);
	void ChangeProductAvailability();
	void ShowAllProducts();
	void ShowAvailableProducts();
	bool CheckProduct(int index);
	bool CheckProductAvailability(int index);

	Product GetProduct(int index);
	~ProductProvaider();
};