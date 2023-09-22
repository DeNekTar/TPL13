#pragma once
#include "Furniture.h"
#include "Worker.h"
#include "Keeper.h"
#include "Car.h"
int action;
int actionF;
int val = 0;


void MenuMain() {

	std::cout << "�������� ��������\n";
	std::cout << "1 - ������ � Furniture\n";
	std::cout << "2 - ������ � Worker\n";
	std::cout << "3 - ������ � Car\n";
	std::cout << "4 - ������� ��� ����������\n";
	std::cout << "0 - �����\n";
	std::cout << "���� ��������: \n";
	std::cin >> action;

}

void MenuInClass() {
	std::cout << "�������� ��������\n";
	std::cout << "1 - ���������� ��������\n";
	std::cout << "2 - �������� ��������\n";
	std::cout << "3 - �������������� ��������\n";
	std::cout << "4 - ������� ��� �������� ����� ���������\n";
	std::cout << "0 - �����\n";
	std::cout << "���� ��������: \n";
	std::cin >> actionF;
}

void MenuFurniture(Keeper<Furniture>& f) {

	setlocale(LC_ALL, "Russian");
	
	Furniture* fu;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {

		switch (actionF) {
		case 1:
			system("cls");
			
			fu = new Furniture;
			fu->setData();
			f.addElement(*fu);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");
			std::cout << "������� ����� �������� ��� ���������� �� �������: ";
			std::cin >> val;
			std::cout << f[val];
			f.extractElement(val);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");



			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");


			std::cout << "\nFurniture all" << std::endl;

			if (f.getCount() == 0) {
				std::cout << "��������� Furniture ���" << std::endl;

			}
			for (int i = 1;i < f.getCount()+1;++i) {
				std::cout << f[i];
				std::cout << '\n';

			}
			std::cout << "\n���������� ��������� Furniture: " << f.getCount() << std::endl << std::endl;

			

			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}

void MenuWorker(Keeper<Worker>& w) {

	setlocale(LC_ALL, "Russian");

	Worker* wo;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {

		switch (actionF) {
		case 1:
			system("cls");

			wo = new Worker;
			wo->setData();
			w.addElement(*wo);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");
			std::cout << "������� ����� �������� ��� ���������� �� �������: ";
			std::cin >> val;
			std::cout << w[val];
			w.extractElement(val);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");



			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");


			std::cout << "\nFurniture all" << std::endl;

			if (w.getCount() == 0) {
				std::cout << "��������� Furniture ���" << std::endl;

			}
			for (int i = 1;i < w.getCount() + 1;++i) {
				std::cout << w[i];
				std::cout << '\n';

			}
			std::cout << "\n���������� ��������� Furniture: " << w.getCount() << std::endl << std::endl;



			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}

void MenuCar(Keeper<Car>& c) {

	setlocale(LC_ALL, "Russian");

	Car* ca;
	actionF = 0;
	MenuInClass();

	while (actionF != 0) {

		switch (actionF) {
		case 1:
			system("cls");

			ca = new Car;
			ca->setData();
			c.addElement(*ca);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 2:
			system("cls");
			std::cout << "������� ����� �������� ��� ���������� �� �������: ";
			std::cin >> val;
			std::cout << c[val];
			c.extractElement(val);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");



			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");


			std::cout << "\nFurniture all" << std::endl;

			if (c.getCount() == 0) {
				std::cout << "��������� Furniture ���" << std::endl;

			}
			for (int i = 1;i < c.getCount() + 1;++i) {
				std::cout << c[i];
				std::cout << '\n';

			}
			std::cout << "\n���������� ��������� Furniture: " << c.getCount() << std::endl << std::endl;



			system("pause");
			system("cls");
			MenuInClass();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuInClass();
			break;
		}
	}
}


void Menu() {
	setlocale(LC_ALL, "Russian");
	Keeper<Furniture> fur;
	Keeper<Worker> wor;
	Keeper<Car> car;


	action = 0;
	MenuMain();

	while (action != 0) {

		switch (action) {
		case 1:
			system("cls");

			MenuFurniture(fur);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 2:
			system("cls");

			MenuWorker(wor);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 3:
			system("cls");

			MenuCar(car);


			system("pause");
			system("cls");
			MenuMain();
			break;
		case 4:
			system("cls");



			system("pause");
			system("cls");
			MenuMain();
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			MenuMain();
			break;
		}


	}



}




