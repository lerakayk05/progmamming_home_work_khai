#include <iostream>
#include <cmath>

using namespace std;

// Каюк Валерія 10 32 18

void Swap();
float EnterValue(float &X);
void Swapping(float &X, float &Y);

void Boolean32();
int EnterBool(int& X);
bool IsRightTriangle(int A, int B, int C);

void Integers18();
int EnterInteger(int &K);
int Split(int &K);
void ShowOut(int thousands, int &K);



int main() {
	int choice = 0; //Декларування змінної задля choice

	cout << "Виберiть яку з цих задач будете вирiшувати: " << endl <<
		"1. Swap " << endl <<
		"2. Boolean32 " << endl <<
		"3. Integers18 " << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		// Proc 10
		Swap();
		break;
	}
	case 2:
	{
		// Boolean 32
		Boolean32();
		break;
	}
	case 3:
	{
		// Integers 18
		Integers18();
		break;
	}
	default:
	{
		cout << "Такого варiанту немає\n";
		break;
	}
	}
}

void Swap()
{
	cout << "PROC 10(Swap)" << endl;
	float A, B, C, D;
	EnterValue(A);
	EnterValue(B);
	EnterValue(C);
	EnterValue(D);
	Swapping(A, B);
	Swapping(C, D);
	Swapping(B, C);

	cout << "A = " << A << endl << "B = " << B << endl << "C = " << C << endl << "D = " << D <<endl;
}

float EnterValue(float &X) {
	cout << "Enter a number: ";
	cin >> X;
	if (cin) {
		return X;
	}
	else {
		cout << "Wrong number, by default set 5" << endl;
		return X = 5;
	}
}

void Swapping(float&X, float&Y)
{
	float temp = X;
	X = Y;
	Y = temp;
}

void Boolean32()
{
	cout << "BOOLEAN 32" << endl;
	int A, B, C;
	EnterBool(A);
	EnterBool(B);
	EnterBool(C);

	cout << "This triangle is right?: " << boolalpha << IsRightTriangle(A, B, C) << endl;
}

int EnterBool(int& X) {
	cout << "Enter a number: ";
	cin >> X;
	if (cin) {
		return X;
	}
	else {
		cout << "Wrong number, by default set 7" << endl;
		return X = 7;
	}
}

bool IsRightTriangle(int A, int B, int C) {
	return A * A + B * B == C * C || B * B + C * C == A * A || A * A + C * C == B * B;
}

void Integers18()
{
	cout << "INTEGER 18" << endl;
	int K = 0;

	EnterInteger(K);
	int thousands = Split(K);
	ShowOut(thousands, K);
}

int EnterInteger(int& K) {
	cout << "Enter K: ";
	cin >> K;
	if (cin) {
		if (K < 999) {
			cout << "K less than 999, K equals 1000 now" << endl;
			return K = 1000;
		}
		return K;
	}
	else {
		cout << "K had been entered wrong! Returned 0 by default" << endl;
		return K = 0;
	}
}

int Split(int& K) {
	int thousands = K / 1000;
	return thousands;
}

void ShowOut(int thousands, int& K) {
	cout << "Thousands in number " << K << " is " << thousands << endl;
}
