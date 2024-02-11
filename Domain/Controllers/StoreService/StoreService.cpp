#include "StoreService.h"

void StoreService::displayMenuForEmployee()
{
	cout << "Меню" << endl;
	cout << "1. Показати всіх клієнтів" << endl;
	cout << "2. Показати членів клубу" << endl;
	cout << "3. Показати клієнтів, які здійснили покупки" << endl;
	cout << "4. Показати клієнта з максимальною сумою покупки" << endl;
	cout << "5. Додати продукт" << endl;
	cout << "6. Змінити статус інвентарю для продукту" << endl;
	cout << "7. Здійснити покупку" << endl;
	cout << "8. Вийти" << endl;
}

void StoreService::displayMenuForClient()
{
	cout << "Меню" << endl;
	cout << "1. Показати всі продукти" << endl;
	cout << "2. Додати продукт у кошик" << endl;
	cout << "3. Показати кошик" << endl;
	cout << "4. Очистити кошик" << endl;
	cout << "5. Завершення покупки" << endl;
}