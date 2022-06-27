#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

struct data_cx {
	float real, imag;
};

struct node_cx {
	data_cx val;
	node_cx* next;
};

data_cx new_сx(float real, float imag);
void print_data(data_cx z);
void push(node_cx*& head, node_cx*& tail, data_cx z);
bool check(node_cx*& head);

void main() {
	setlocale(LC_ALL, "ru");

	node_cx* head = NULL, * tail = NULL;

	char name[50];
	cout << "Введите название файла для считывания комплексных чисел: " << std::endl;
	cin >> name;
	ifstream fin;
	fin.open(name);

	if (fin.is_open()) {
		float rl, im;
		fin >> rl >> im;
		while (!fin.fail()) {
			push(head, tail, new_сx(rl, im));
			fin >> rl >> im;
		}}
	fin.close();

	if (head == NULL)
		cout << "Пустой стек" << endl;
	else {
		if (check(head)) {
			node_cx* temp = head;
			data_cx res = new_сx(0, 0);
			while (temp) {
				res.real += temp->val.real;
				res.imag += temp->val.imag;
				temp = temp->next;
			}
			print_data(res);
		}
		else
			cout << "В стеке не только 1 мнимое число" << endl;
	}}

data_cx new_сx(float real, float imag){
	data_cx z;
	z.real = real;
	z.imag = imag;
	return z;
}

void print_data(data_cx z) {
	cout << "Действительная часть комплексного числа: " << z.real << endl;
	cout << "Мнимая часть комплексного числа:  " << z.imag << endl;
}

void push(node_cx*& head, node_cx*& tail, data_cx z) {
	node_cx* temp = new node_cx;
	temp->val = z;
	if (head == nullptr) {
		temp->next = NULL;
		head = tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}}

bool check(node_cx*& head) {
	if (head == NULL)
		return false;

	int k = 0;
	node_cx* temp = head;
	while (temp) {
		if (temp->val.imag != 0)
			k++;
		temp = temp->next;
	}
	if (k == 1)
		return true;
	else
		return false;
}