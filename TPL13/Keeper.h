#pragma once
#include <algorithm>

template <class T>
class Keeper {


private:
    template <class T>
    class Element {        //  ���� ������� � �������
    public:
        T* value;          //��������
        Element<T>* prev;
        
        Element(T data /*= T()*/, Element<T>* prev = nullptr) {    //����������� ��������
            this->value = &data;
            this->prev = prev;
        }
    };
	int count;
    Element<T>* head;      //��������� �� ������ �������
    Element<T>* help;

public:
	Keeper() {
		count = 0;
        head = nullptr;
        help = nullptr;
	}

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


    void addElement(T& x) {
        if (head == nullptr) {
            head = new Element<T>(x);
            head->value = &x;
            
        }
        else {
            help = new Element<T>(x);
            help->prev = head;
            head = help;
            head->value = &x;
        }
        count++;
    }




    void extractElement(const int index) {	//����� �������� �������� �� �������

        if (getCount() == 1) {	//���� � ������� ���� �������
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
        }
    }
    

   
    
    

    void sortirovka(Keeper<Furniture>& k, int left, int right) {
        /*
        for (int i = 1;i < k.getCount()+1;++i) {
            for (int j = 1;j < k.getCount();++j) {

                if ((k[j].getCost()) > (k[j + 1].getCost())){
                    Furniture b = k[j]; // ������� �������������� ����������
                    k[j] = k[j + 1]; // ������ �������
                    k[j + 1] = b; // �������� ���������
                }
            }
        }*/

        }





    }



    void display(Keeper<T>& k) {
        std::cout << "\nAll Element of " << typeid(T).name() << std::endl;

        if (k.getCount() == 0) {
            std::cout << "��������� " << typeid(T).name() << " ���\n";

        }
        for (int i = 1;i < k.getCount() + 1;++i) {
            std::cout << k[i];
            std::cout << '\n';

        }
        std::cout << "\n���������� ��������� " << typeid(T).name()<< " : " << k.getCount() << std::endl << std::endl;
    }



   
    int getCount() { return count; }



};

/*

template<typename T>
class Deque {
private:

    template<typename T>
    class Element {        //  ���� ������� � �������
    public:
        T value;          //��������
        Element* next;
        Element* prev;

        Element(T data = T(), Element* next = nullptr, Element* prev = nullptr) {    //����������� ��������
            this->value = data;
            this->next = next;
            this->prev = prev;
        }
    };

    int count;          //���������� ��������� � �������
    Element<T>* left;      //��������� �� ������ �������
    Element<T>* right;     //��������� �� ��������� �������
    Element<T>* help;

public:


    Deque(Deque<T>& dq) {

        count = dq.count;
        for (int i = 0; i < count; i++) {
            addElement(dq[i]);
        }
    }

    int getCount() { return count; }
    virtual ~Deque() {};

    Deque() {

        count = 0;
        left = nullptr;
        right = nullptr;
        help = nullptr;

        //����� ��� �������, ���������� ��������
        srand(time(0));

        count = rand() % 30;



        for (int i = 0; i < count; i++) {

            if (left == nullptr) {
                left = new Element<T>(rand() % 10);
                help = right = left;
                left->prev = right->prev = nullptr;
            }
            else {
                help = new Element<T>(rand() % 10);
                help->prev = right;
                right->next = help;
                right = help;
                right->prev = help->prev;

            }

        }
        right->next = nullptr;

    }

    void addElement(T x) {
        if (left == nullptr) {
            left = new Element<T>(x);
            left->value = x;
            right = left = help;
        }
        else {
            help = new Element<T>(x);
            help->prev = right;
            right->next = help;
            right = help;
        }
        count++;
    }


    T& operator[] (const int index) {

        int cnt = 0;
        Element<T>* cur;

        cur = this->left;
        while (cur->next != nullptr) {
            if (cnt == index) {
                return  cur->value;
            }

            cur = cur->next;
            cnt++;
        }

    }



    Deque(int size) {
        try {

            if (size == 0) {
                throw 0;
            }

            count = size;
            left = nullptr;
            right = nullptr;
            help = nullptr;


            srand(time(0));




            for (int i = 0; i < count; i++) {

                if (left == nullptr) {
                    left = new Element<T>(rand() % 10);
                    help = right = left;
                    left->prev = right->prev = nullptr;
                }
                else {
                    help = new Element<T>(rand() % 10);
                    help->prev = right;
                    right->next = help;
                    right = help;
                    right->prev = help->prev;

                }
            }
            right->next = nullptr;
        }
        catch (...) {
            //std::cout << "555\n";
            count = 0;
            left = nullptr;
            right = nullptr;
            help = nullptr;


            srand(time(0));

            count = rand() % 30;

            for (int i = 0; i < count; i++) {

                if (left == nullptr) {
                    left = new Element<T>(rand() % 10);
                    help = right = left;
                    left->prev = right->prev = nullptr;
                }
                else {
                    help = new Element<T>(rand() % 10);
                    help->prev = right;
                    right->next = help;
                    right = help;
                    right->prev = help->prev;

                }
            }
            right->next = nullptr;
        }

    }
    friend void operator<< (std::ostream& out, Deque<T>& dq) {
        dq.extractElement(1);

    }

    friend void operator>> (std::ostream& out, Deque<T>& dq) {
        dq.extractElement(0);

    }

    void extractElement(bool b) {
        if (b == 1) {
            help = left;
            left = left->next;
            left->prev = nullptr;
            count--;
            delete help;
        }
        else {
            help = right;
            right = right->prev;
            right->next = nullptr;
            count--;
            delete help;
        }
    }

    friend void operator+ (Deque<T>& fq, Deque<T>& dq) {
        int i;
        if (fq.count <= dq.count) {
            i = 0;
            while (i < fq.count) {
                fq[i] += dq[i];
                i++;
            }

            while (i < dq.count) {
                fq.addElement(dq[i]);
                i++;
            }

        }

        else {
            i = 0;
            while (i < dq.count) {
                fq[i] += dq[i];
                i++;
            }
        }
    }

    friend bool operator> (Deque<T>& fq, Deque<T>& dq) {
        if (fq.count > dq.count) {

            return true;
        }
        else if (fq.count < dq.count) {

            return false;
        }

    }

};*/