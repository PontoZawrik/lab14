#pragma once
#include <iostream>
using namespace std;

struct Animal {
	char name[20];
	int age;
	double weight;
	char group;
	bool sterilized;
	int reviews[3];
};

struct Tovar {
	char name[20];
	char shopName[20];
	double price;
};


void print(Animal& a) {
	cout << a.name << " | " << a.age << " | " << a.weight << " | " << a.group << " | "
		<< boolalpha << a.sterilized << " | " << a.reviews[0] << ", " << a.reviews[1] << ", " << a.reviews[2] << endl;
	return;
}

Animal input() {
	Animal a;

	cout << "Введите имя: ";
	cin >> a.name;
	cout << "Введите возраст: ";
	cin >> a.age;
	cout << "Введите вес: ";
	cin >> a.weight;
	cout << "Введите группу: ";
	cin >> a.group;
	cout << "Животное стерилизовали (0-нет/1-да): ";
	cin >> a.sterilized;
	cout << "Введите оценки (3): ";
	cin >> a.reviews[0] >> a.reviews[1] >> a.reviews[2];

	return a;
}


void sortTovar(Tovar* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
				Tovar temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int searchTovar(Tovar arr[], int size, char* search) {
	int result = -1;

	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i].name, search) == 0) {
			result = i;
		}
	}
	return result;
}