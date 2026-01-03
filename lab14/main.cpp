#include <Windows.h>
#include "main.h"
#include "../../utils/utils/utils.h"


struct Animal {
	char name[20];
	int age;
	double weight;
	char group;
	bool sterilized;
	int reviews[3];
};

void print(Animal&);

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
			cout << "Введите имя: ";
			cin >> a2.name;
			cout << "Введите возраст: ";
			cin >> a2.age;
			cout << "Введите вес: ";
			cin >> a2.weight;
			cout << "Введите группу: ";
			cin >> a2.group;
			cout << "Животное стерилизовали (0-нет/1-да): ";
			cin >> a2.sterilized;
			cout << "Введите оценки (3): ";
			cin >> a2.reviews[0] >> a2.reviews[1] >> a2.reviews[2];

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
			ra4.sterilized = false;
			ra4.reviews[0] = 9;
			ra4.reviews[1] = 8;
			ra4.reviews[2] = 9;

			print(ra4);
		} break;


		case -1: cout << "Выход из программы.\n"; break;
		default: cout << "Неверный номер.\n";
		}

		cout << endl;
	} while (p != -1);

	system("pause");
	return 0;
}

void print(Animal& a) {
	cout << a.name << " | " << a.age << " | " << a.weight << " | " << a.group << " | "
		<< boolalpha << a.sterilized << " | " << a.reviews[0] << ", " << a.reviews[1] << ", " << a.reviews[2] << endl;
	return;
}