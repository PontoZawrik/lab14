#include <Windows.h>
#include "main.h"
#include "../../utils/utils/utils.h"


struct Animal {
	char name[20];
	int age;
	double weight;
	char group;
	bool sterilized;
	int reviews[10];
};

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

		} break;


		case -1: cout << "Выход из программы.\n"; break;
		default: cout << "Неверный номер.\n";
		}

		cout << endl;
	} while (p != -1);

	system("pause");
	return 0;
}