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

data_cx new_�x(float real, float imag);
void print_data(data_cx z);
void push(node_cx*& head, node_cx*& tail, data_cx z);
bool check(node_cx*& head);

void main() {
	setlocale(LC_ALL, "ru");

	node_cx* head = NULL, * tail = NULL;

	char name[50];
	std::cout << "������� �������� ����� ��� ���������� ����������� �����: " << std::endl;
	std::cin >> name;
	std::ifstream fin;
	fin.open(name);

	if (fin.is_open()) {
		float rl, im;
		fin >> rl >> im;
		while (!fin.fail()) {
			push(head, tail, new_�x(rl, im));
			fin >> rl >> im;
		}}
	fin.close();

	if (head == NULL)
		cout << "������ ����" << endl;
	else {
		if (check(head)) {
			node_cx* temp = head;
			data_cx res = new_�x(0, 0);
			while (temp) {
				res.real += temp->val.real;
				res.imag += temp->val.imag;
				temp = temp->next;
			}
			print_data(res);
		}
		else
			cout << "� ����� �� ������ 1 ������ �����" << endl;
	}}

data_cx new_�x(float real, float imag){
	data_cx z;
	z.real = real;
	z.imag = imag;
	return z;
}

void print_data(data_cx z) {
	cout << "�������������� ����� ������������ �����: " << z.real << endl;
	cout << "������ ����� ������������ �����:  " << z.imag << endl;
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