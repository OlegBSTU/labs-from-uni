/*
Дана матрица А(nxn). Найти количество положительных
элементов в каждом из столбцов. Поменять местами столбцы с
наибольшим и наименьшим количеством положительных элементов.
*/
#include <iostream>
#include <locale.h>
#include <malloc.h>
#include <iomanip>

int** create_matr(int  n);
void clear_matr(int** A, int n);
void read_matr(int** A, int  n);
void print_matr(int** arr, int n);
int get_max(int** a, int n);
int get_min(int** a, int n);
int quantity(int** a, int n, int j);
void swap_columns(int** arr, int n, int j1, int j2);
void Sort(int** a, int n);

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	//srand(time(NULL));
	int  n;

	printf("Введите порядок квадратной матрицы: n=");
	scanf_s("%d", &n);

	int** A = create_matr(n);
	printf("Введите элементы матрицы:\n");
	read_matr(A, n);

	cout << "Исходная матрица: " << endl;
	print_matr(A, n);

	if (get_min(A, n) != get_max(A, n)) {
		swap_columns(A, n, get_max(A, n), get_min(A, n));
		cout << "Новая матрица: " << endl;
		print_matr(A, n);}
	else
		cout << "В матрице нет столбцов, которые бы выполняли условие в задаче." << endl;

	clear_matr(A, n);
	return 0;
}

int** create_matr(int n) {
	int** A = NULL;
	A = new int*[n];
	//A = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		A[i] = new int[n];
		//A[i] = (int*)malloc(n * sizeof(int));
	return A;
}

void print_matr(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(6) << arr[j][i];
		cout << endl;
	}
}

void clear_matr(int** A, int n)
{
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}

void read_matr(int** A, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			//A[i][j] = -3 + rand() % 11;
			cin >> A[j][i];}

int quantity(int** a, int n, int j){
	int k = 0;
	//cout << j+1 << ") ";
	for (int i = 0; i < n; i++)
		if (a[j][i] >= 0)
			k++;
	//cout << endl << "Количество положительных элементов: " << k << endl;
	return k;}

int get_max(int** a, int n) {
	int max = quantity(a, n, 0), max_j = 0;
	for (int j = 1, k = 0; j < n; j++) {
		k = quantity(a, n, j);
		if (max < k) {
			max = k;
			max_j = j;}}
	return max_j;}

int get_min(int** a, int n) {
	int min = quantity(a, n, 0), min_j = 0;
	for (int j = 1, k = 0; j < n; j++) {
		k = quantity(a, n, j);
		if (min > k) {
			min = k;
			min_j = j; }}
	return min_j; }

void swap_columns(int** arr, int n, int j1, int j2) {
	int* temp = NULL;
	temp = arr[j1];
	arr[j1] = arr[j2];
	arr[j2] = temp; }

void Sort(int** a, int n){
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++){
		swapped = false;
		for (j = 0; j < n - i - 1; j++){
			if (a[quantity(a, n, j)][j] < a[quantity(a, n, j + 1)][j + 1]){
				swap_columns(a, n, j, j + 1);
				swapped = true;}}

		if (swapped == false) {
			break;}}}