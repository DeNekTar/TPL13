#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
//#include "Menu.h"

//void MenuAttributesF();
//void MenuAttributesW();
//void MenuAttributesC();

template <class T>
class Keeper {

private:
    template <class T>
    class Element {        //  ���� ������� � �������
    public:
        T* value;          //��������
        Element<T>* prev;

        Element(T* data /*= T()*/, Element<T>* prev = nullptr) {    //����������� ��������
            this->value = data;
            this->prev = prev;
        }
        ~Element() {    //����������� ��������
           delete this->value;
           //delete this->prev;
        }


    };
    int count;
    Element<T>* head;      //��������� �� ������ �������
    Element<T>* help;

public:
    Keeper() {
#ifdef DEBUG
        std::cout << "����������� Keeper\n";
#endif // DEBUG	
        count = 0;
        head = nullptr;
        help = nullptr;
    }

    ~Keeper() {
#ifdef DEBUG
        std::cout << "���������� Keeper\n";
#endif // DEBUG	
        int b = getCount();
        for (int i = 1;i < b+1;i++) {
            std::cout << 'C'<< getCount() << '\n';

            extractElement(i);
            std::cout << 'C' <<getCount() << '\n';

        }
        head = nullptr;
        help = nullptr;
    }


    int getCount() { return count; }

    T& operator[] (const int index) {

        int cnt = getCount();
        Element<T>* cur;

        cur = this->head;
        while (cur != nullptr) {
            if (cnt == index) {
                return  *(cur->value);
            }

            cur = cur->prev;
            cnt--;
        }

    }

    void addElement(T* x) {
        if (head == nullptr) {
            head = new Element<T>(x);
            head->value = x;

        }
        else {
            help = new Element<T>(x);
            help->prev = head;
            head = help;
            head->value = x;
        }
        count++;
    }

    void extractElement(const int index) {	//����� �������� �������� �� �������


        if (1 == getCount()) {	//���� � ������� ���� �������
            delete this->head;	//������� ������, �������=0, ����� ��������
            count--;
            //std::cout << "������� ��������� ���������" << std::endl;
        }
        else if (index == getCount()) {	//���� ��������� ��������� �������
            Element<T>* cur = this->head;	//��������� ��������� �� ������
            head = head->prev;	//����������� ������
            delete cur;			//������� ���������, ������ �� ������ �������
            count--;	//�������� �� ���� �������
        }
        else {		//���� �� ���������, � � ������� >������ ��������
            Element<T>* cur = this->head;		//������ ���������
            Element<T>* current1 = this->head;		//������ ���������
            int c = getCount();	//���������� ���������
            bool flag = 0;	//���� ��� �����������
            while (flag != 1) {
                if (c == index) {		//���� ����� �� ������� ��������
                    int r = getCount();
                    while (r != (c + 1)) {
                        current1 = current1->prev;	//����������� ������ �� ���� ����� ������� ����������
                        r--;
                    }
                    Element<T>* temp = cur;//��������� �� ��������� �������		
                    cur = cur->prev;				//����������� ���������
                    current1->prev = cur;		//��� ����������
                    delete temp;
                    flag = 1;	//����������� ������
                    count--;	//�������� �������

                }
                else {	//���� �� ����� �� ������� ��������
                    cur = cur->prev;	//	��������� �� �������
                    c--;
                }
            }
            delete cur, current1;
        }

    }
    /*
    void changeElementW(Keeper<Worker>& w, int& a) {
        int ind = 0;
        try {
            std::cout << "�������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
            if (ind <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����\n");
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
            std::cout << "�������� ���������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
        }
        std::string valuestr = "";
        int value = 0;
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                w[ind].setFIO(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 2:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                w[ind].setPost(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();

                break;
            case 3:
                system("cls");

                std::cout << w[ind];
                value = 0;
                std::cout << "������� ��������: ";
                std::cin >> value;
                w[ind].setSal(value);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 4:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                w[ind].setAdd(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            case 5:
                system("cls");

                std::cout << w[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                w[ind].setNum(valuestr);

                system("pause");
                system("cls");
                MenuAttributesW();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesW();
                break;

            }
        }

    }

    void changeElementF(Keeper<Furniture>& k, int& a) {
        int ind = 0;
        try {
            std::cout << "�������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
            if (ind <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����\n");
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
            std::cout << "�������� ���������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
        }
        std::cout << "�������� ����� �������� ��� ��������������: ";
        std::cin >> ind;
        std::string valuestr = "";
        int value = 0;
        int b = 0;
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                k[ind].setType(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 2:
                system("cls");

                std::cout << k[ind];
                value = 0;
                std::cout << "����� ������ ������ �������� \n1 - �������\n2 - ������\n3 - ������\n �����: ";
                std::cin >> b;
                std::cout << "������� ��������: ";
                std::cin >> value;
                k[ind].setSize(value, b);

                system("pause");
                system("cls");
                MenuAttributesF();

                break;
            case 3:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                k[ind].setColor(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 4:
                system("cls");

                std::cout << k[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                k[ind].setMat(valuestr);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            case 5:
                system("cls");

                std::cout << k[ind];
                value = 0;
                std::cout << "������� ��������: ";
                std::cin >> value;
                k[ind].setCost(value);

                system("pause");
                system("cls");
                MenuAttributesF();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesF();
                break;

            }
        }

    }

    void changeElementC(Keeper<Car>& c, int& a) {
        int ind = 0;
        try {
            std::cout << "�������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
            if (ind <= 0) throw std::exception("����� �������� �� ����� ���� ������������� ��� ������ ����\n");
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
            std::cout << "�������� ���������� ����� �������� ��� ��������������: ";
            std::cin >> ind;
        }
        std::cout << "�������� ����� �������� ��� ��������������: ";
        std::cin >> ind;
        std::string valuestr = "";
        while (a != 0) {
            switch (a) {
            case 1:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                c[ind].setBrand(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();
                break;
            case 2:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                c[ind].setModel(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();

                break;
            case 3:
                system("cls");

                std::cout << c[ind];
                valuestr = "";
                std::cout << "������� ��������: ";
                std::cin >> valuestr;
                c[ind].setSnum(valuestr);

                system("pause");
                system("cls");
                MenuAttributesC();
                break;
            default:
                system("cls");

                std::cout << "Trouble maaaann. Select attribute again.\n";

                system("pause");
                system("cls");
                MenuAttributesC();
                break;

            }
        }

    }

    void sortirovka(Keeper<Furniture>& k) {

        for (int i = 1;i < k.getCount() + 1;++i) {
            for (int j = 1;j < k.getCount();++j) {

                if ((k[j].getCost()) > (k[j + 1].getCost())) {
                    Furniture b = k[j]; // ������� �������������� ����������
                    k[j] = k[j + 1]; // ������ �������
                    k[j + 1] = b; // �������� ���������
                }
            }
        }
    }*/

    void display(Keeper<T>& k) {
        try {

            if (k.getCount() == 0) throw std::exception("��������� ���\n");
            std::cout << "\nAll Element of " << typeid(T).name() << std::endl;


            for (int i = 1;i < k.getCount() + 1;++i) {
                k[i].getData();
                std::cout << '\n';

            }
            std::cout << "\n���������� ��������� " << typeid(T).name() << " : " << k.getCount() << std::endl << std::endl;
        }
        catch (const std::exception& ex) {

            std::cout << ex.what() << '\n';
        }
    }
    /*
    void fileDisplay(Keeper<Furniture>& k) {
        std::ofstream out;          // ����� ��� ������
        out.open("out.txt", std::ios::out);      // ��������� ���� ��� ������

        try {
            if (!out.is_open()) throw std::exception("���� �� ������\n");

            std::cout << "yeah";
            for (int i = 1;i < k.getCount() + 1;++i) {
                out << "Furniture ";
                out << i;
                out << '\n';
                k[i].getData(out);
                out << '\n';
            }

        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        out.close();
    }

    void fileDisplayT(Keeper<T>& k) {
        std::ofstream out;          // ����� ��� ������
        out.open("out.txt", std::ios::app);      // ��������� ���� ��� ������
        try {
            if (!out.is_open()) throw std::exception("���� �� ������\n");

            std::cout << "yeah";
            for (int i = 1;i < k.getCount() + 1;++i) {
                out << typeid(T).name();
                out << i;
                out << '\n';
                k[i].getData(out);
                out << '\n';
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        out.close();
    }

    void fileSetData(Keeper<Furniture>& f, Keeper<Worker>& w, Keeper<Car>& c) {
        int v = 0;
        Furniture* fu;
        Worker* wo;
        Car* ca;
        std::ifstream in;          // ����� ��� ������
        in.open("in.txt");      // ��������� ���� ��� ������
        try {
            if (!in.is_open()) throw std::exception("���� �� ������\n");
            std::cout << "yeah";
            in >> v;

            for (int i = 1;i < v + 1;++i) {
                fu = new Furniture;
                fu->FsetData(in);
                f.addElement(*fu);
                //in >> c;
            }

            in >> v;

            for (int i = 1;i < v + 1;++i) {
                wo = new Worker;
                wo->FsetData(in);
                w.addElement(*wo);
                //in >> c;
            }

            in >> v;

            for (int i = 1;i < v + 1;++i) {
                ca = new Car;
                ca->FsetData(in);
                c.addElement(*ca);
                //in >> c;
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        in.close();
    }
    */
};