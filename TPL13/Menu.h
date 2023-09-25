#pragma once
#include "Furniture.h"
#include "Worker.h"
#include "Keeper.h"
#include "Car.h"
int action;
int actionF;
int val = 0;
int actionAttribute;

void MenuMain() {

	std::cout << "�������� ��������\n";
	std::cout << "1 - ������ � Furniture\n";
	std::cout << "2 - ������ � Worker\n";
	std::cout << "3 - ������ � Car\n";
	std::cout << "4 - ������� ��� ����������\n";
	std::cout << "5 - ��������� � ���� ��� ����������\n";
	std::cout << "6 - ������� �� �����\n";
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

void MenuAttributesF() {
	std::cout << "�������� ��� ������ ��������\n";
	std::cout << "1 - ��� ������\n";
	std::cout << "2 - �������\n";
	std::cout << "3 - ����\n";
	std::cout << "4 - ��������\n";
	std::cout << "5 - ���������\n";
	std::cout << "0 - �����\n";
	std::cout << "��� �����: \n";
	std::cin >> actionAttribute;
}

void MenuAttributesW() {
	std::cout << "�������� ��� ������ ��������\n";
	std::cout << "1 - ���\n";
	std::cout << "2 - ���������\n";
	std::cout << "3 - ���. �����\n";
	std::cout << "4 - �����\n";
	std::cout << "5 - ����� ��������\n";
	std::cout << "0 - �����\n";
	std::cout << "��� �����: \n";
	std::cin >> actionAttribute;
}

void MenuAttributesC() {
	std::cout << "�������� ��� ������ ��������\n";
	std::cout << "1 - �����\n";
	std::cout << "2 - ������\n";
	std::cout << "3 - ���. �����\n";
	std::cout << "0 - �����\n";
	std::cout << "��� �����: \n";
	std::cin >> actionAttribute;
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

			try {
				if (f.getCount() == 0) throw std::exception("� Keeper ��� ���������");
				
				val = 0;
				std::cout << "������� ����� �������� ��� ���������� �� �������: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����");
				if (f.getCount() < val)  throw std::exception("������ �������� �� ����������");
				std::cout << f[val];
				f.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");
			actionAttribute = 0;
			MenuAttributesF();
			//std::cout<<(f[1].getCost());
			f.changeElementF(f, actionAttribute);

			//f.sortirovka(f);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			f.display(f);

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
			try {
				if (w.getCount() == 0) throw std::exception("� Keeper ��� ���������");
				val = 0;
				std::cout << "������� ����� �������� ��� ���������� �� �������: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����");
				if (w.getCount() < val )  throw std::exception("������ �������� �� ����������");
				std::cout << w[val];
				w.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");

			actionAttribute = 0;
			MenuAttributesW();
			try {
				w.changeElementW(w, actionAttribute);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}
			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			w.display(w);

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
			try {
				if (c.getCount() == 0) throw std::exception("� Keeper ��� ���������");
				val = 0;
				std::cout << "������� ����� �������� ��� ���������� �� �������: ";
				std::cin >> val;
				if (val <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����");
				if (c.getCount() < val)  throw std::exception("������ �������� �� ����������");
				std::cout << c[val];
				c.extractElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 3:
			system("cls");

			actionAttribute = 0;
			MenuAttributesC();
			c.changeElementC(c, actionAttribute);

			system("pause");
			system("cls");
			MenuInClass();
			break;
		case 4:
			system("cls");

			c.display(c);
			
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

			fur.display(fur);
			wor.display(wor);
			car.display(car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 5:
			system("cls");

			fur.fileDisplay(fur);
			wor.fileDisplayT(wor);
			car.fileDisplayT(car);

			system("pause");
			system("cls");
			MenuMain();
			break;
		case 6:
			system("cls");

			fur.fileSetData(fur, wor, car);

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




