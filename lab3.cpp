#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

//						Каюк Валерія 14 30

void if14();
void geo30();
void geo30s();


int main() {
	int choice = 0; //Декларування змінної задля choice
	cout << "Choice the task: " << endl <<
		"1. If 14" << endl <<
		"2. Geo 15" << endl <<
		"3. Geo 15(Square and perimeter)" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		// if 14
		if14();
		break;
	}
	case 2:
	{
		// geo30(Належність точки до фігури)
		geo30();
		break;
	}
	case 3:
	{
		//geo15.2(Периметр та площа)
		geo30s();
		break;
	}
	default:
	{
		cout << "Wrong variant\n";
		break;
	}
	}
}

void if14()
{
	// IF 14
	cout << " IF 14" << endl;

	float A, B, C;
	cout << "Enter A, B and C: " << endl;
	cin >> A >> B >> C;

	// Перевірка на мінімальне число
	float minimum = A;
	if (B < minimum) {
		minimum = B;
	}
	if (C < minimum) {
		minimum = C;
	}

	//Перевірка на максимальне число
	float maximum = A;
	if (B > maximum) {
		maximum = B;
	}
	if (C > maximum) {
		maximum = C;
	}

	cout << "Lowest number is " << minimum << " and highiest number is " << maximum;

}

void geo30() {
	cout << " GEO 30" << endl;
	
	int r = 0, x = 0, y = 0;				 //Декларування змінних
	bool ar1, ar2;							 //Декларування змінних типу bool

	cout << "Enter a radius:  ";
	cin >> r;

	cout << "Enter X and Y:  ";
	cin >> x >> y;

	ar1 = pow((x + r), 2) + pow(y, 2) > pow(r, 2) && y > 0 && y < r && x >-1 * r && x < 0;		// Розрахунок знаходження першої фігури
	ar2 = pow((x + r), 2) + pow(y, 2) < pow(r, 2) && y > -x - 2 * r && y < 0 && x < -1 * r;			 // Розрахунок знаходження другої фігури

	if (ar1 || ar2) {
		cout << "In region!" << endl;
	}
	else {
		cout << "Out of region!";
	}
}

void geo30s() {
	int r, x, y;
	const float pi = 3.14;
	cout << "Enter a radius: ";
	cin >> r;

	float perimeter1 = (2 * pi * r) / 4 + 2 * r;
	float perimeter2 = r + r + r * sqrt(2);
	

	float square1 = pow(r, 2) - ((pi * pow(r, 2)) / 4);
	float square2 = pow(r,2)/2;

	cout << "Square of first figure = " << square1 << endl; // Виведення результату
	cout << "Square of second figure = " << square2 << endl; // Виведення результату

	cout << "Perimeter of first figure = " << perimeter1 << endl; // Виведення результату
	cout << "Perimeter of second figure = " << perimeter2 << endl; // Виведення результату
}
