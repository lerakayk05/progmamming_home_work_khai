#include <iostream>
#include <cmath>

using namespace std;

void array48(); //Декларування функції типу void(задача Array26)
void input_arr(int arr[], int& n, const int N);
int identicalnumbers(int arr[], int n);
void output(int count);

void array70();//Декларування функції типу void(задача Array92)
void input_arr70(int arr[], int& n, const int N);
void Swap(int arr[], int n);


int main()
{
	int choice = 0; //Декларування змінної задля choice

	while (choice != 3) {
		
		cout.clear();
		cout << "Choose the TASK: "
			"\n1. Array#48"
			"\n2. Array#70"
			"\n3. exit" << endl;


		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			// array26
			array48();
			break;
		}
		case 2:
		{
			// array92
			array70();
			break;
		}
		case 3:
		{
			cout << "Program has ended";
			break;
		}
		default:
		{
			cout << "Variety with this number doesn't exist\n";
			break;
		}
		}
	}
}

void array48() {
	const int N = 50;
	int n = 0;
	int arr[N];
	input_arr(arr, n, N);
	int count = identicalnumbers(arr, n);
	output(count);
}

void input_arr(int arr[], int& n, const int N)
{
	cout << "Amount of elements: ";
	cin >> n;
	if (n < N && n > 0) {
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
	}
	else {
		cout << "N entered wrong";
	}
}

int identicalnumbers(int arr[], int n) {						//Перебирает весь массив, если идут несколько чисел в ряд - добавляет по 1 в count, если же число arr[i-1] отличается от arr[i], тогда count передает данные в temp и обнуляется.
	int count = 1, temp = 0;
	for (int i = 1; i < n; i++) {
			if (arr[i - 1] != arr[i]) {
				if (temp < count) {
					temp = count;
					/*cout << "gg, count = : " << count << endl;*/			//Для отладки			
				}
				else {
					count = 1;
					/*cout << "-, count = : " << count << endl;	*/		//Для отладки
				}
			}
			else if (arr[i - 1] == arr[i]){
				count++;
				/*cout << "+, count = : " << count << endl;*/			//Для отладки
			}
			if (i + 1 == n) {
				return temp;
			}
	}
}

void output(int count) {
	cout << "Max number of identical elements: " << count << endl;
}

void array70() {
	const int N = 50;
	int n = 0;
	int arr[N];
	input_arr70(arr, n, N);
	Swap(arr, n);
}

void input_arr70(int arr[], int& n, const int N)		// Ввод элементов массива(отличается от input_arr тем, что в if стоит дополнительное условие n % 2 == 0)
{
	cout << "Amount of elements: ";
	cin >> n;
	if (n < N && n > 0 && n % 2 == 0) {
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
	}
	else {
		cout << "N entered wrong" << endl;
		array70();
	}
}

void Swap(int arr[], int n) {							// Делит весь массив пополам и меняет местами arr[i] и arr[fp]
	int fp = n / 2;
	int sp = n / 2;
	for (int i = 0; i < fp; i++) {
		int temp = arr[i + fp];
		arr[i + fp] = arr[i];
		arr[i] = temp;
		}
	cout << "New massive is ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
