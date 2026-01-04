#include <Windows.h>
#include "main.h"
#include "../../utils/utils/utils.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int p;

	do {
		cout << "Введите номер задания (-1 для выхода): ";
		cin >> p;

		switch (p) {
		case 1: {
			Animal a0 = { "Puma", 5, 50.3, 'A', true, { 8, 7, 9 } };

			Animal a1;
			strcpy_s(a1.name, "Lion");
			a1.age = 6;
			a1.weight = 70.2;
			a1.group = 'B';
			a1.sterilized = true;
			a1.reviews[0] = 5;
			a1.reviews[1] = 7;
			a1.reviews[2] = 8;

			print(a0);
			print(a1);

			Animal a2;
			a2 = input();
			print(a2);

			Animal* pa3 = new Animal;
			strcpy_s(pa3->name, "Tiger");
			pa3->age = 5;
			pa3->weight = 58.4;
			pa3->group = 'C';
			pa3->sterilized = false;
			pa3->reviews[0] = 6;
			pa3->reviews[1] = 9;
			pa3->reviews[2] = 7;

			cout << pa3->name << " | " << pa3->age << " | " << pa3->weight << " | " << pa3->group << " | "
				<< boolalpha << pa3->sterilized << " | " << pa3->reviews[0] << ", " << pa3->reviews[1] << ", " << pa3->reviews[2] << endl;

			Animal a4;
			Animal& ra4 = a4;
			strcpy_s(ra4.name, "Lion");
			ra4.age = 3;
			ra4.weight = 43.9;
			ra4.group = 'C';	
			ra4.sterilized = true;
			ra4.reviews[0] = 9;
			ra4.reviews[1] = 8;
			ra4.reviews[2] = 9;

			print(ra4);
		} break;

		case 2: {
			const int size = 3;
			Animal animals[size];

			for (int i = 0; i < size; i++) {
				animals[i] = input();
				print(animals[i]);
			}

			cout << "\nЗаписанные животные:\n";
			for (int i = 0; i < size; i++) {
				print(animals[i]);
			}


			double x;
			cout << "Введите искомый вес: ";
			cin >> x;

			int count = 0;
			for (int i = 0; i < size; i++) {
				count += animals[i].weight > x ? 1 : 0;
			}
			cout << "Подходящие животные: " << count << endl;


			cout << "\nДинамический массив.\n";
			int size0 = 2;
			Animal* animals0 = createArray<Animal>(size0);

			for (int i = 0; i < size0; i++) {
				animals0[i] = input();
				print(animals0[i]);
			}

			cout << "\nЗаписанные животные:\n";
			for (int i = 0; i < size0; i++) {
				print(animals0[i]);
			}

			delete[] animals0;
			animals0 = NULL;
		} break;

		case 3: {
			const int size = 5;
			Tovar tovars[size];

			for (int i = 0; i < size; i++) {
				cin.ignore();

				cout << "Название товара: "; 
				cin.getline(tovars[i].name, 20);
				cout << "Название магазина: "; 
				cin.getline(tovars[i].shopName, 20);
				cout << "Стоимость товара: "; 
				cin >> tovars[i].price;
			}

			sortTovar(tovars, size);

			cout << endl;
			for (int i = 0; i < size; i++) {
				cout << tovars[i].name << " | " << tovars[i].shopName << " | " << tovars[i].price << endl;
			}

			char search[20];
			cout << "\nВведите название товара: ";
			cin.ignore();
			cin.getline(search, 20);

			int iTovar = searchTovar(tovars, size, search);

			if (iTovar >= 0) {
				cout << "Название: " << tovars[iTovar].name << endl;
				cout << "Магазин: " << tovars[iTovar].shopName << endl;
				cout << "Стоимость: " << tovars[iTovar].price << " руб.\n";
			}
			else {
				cout << "Такого товара нет.\n";
			}
		} break;


		case -1: cout << "Выход из программы.\n"; break;
		default: cout << "Неверный номер.\n";
		}

		cout << endl;
	} while (p != -1);

	system("pause");
	return 0;
}