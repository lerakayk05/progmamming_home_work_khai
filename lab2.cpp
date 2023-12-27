#include <iostream>
#include <cmath>

using namespace std;

					// Каюк Валерія 18 32 39

int main() {
	// Integer 18
	cout << " INTEGER 18" << endl;
	int A = 0;                                    //Декларація змінної
	cout << "Enter A(>1000): " << endl;
	cin >> A;
	
	int thousands = A / 1000;
	cout << "Thousands in number " << A << " is " << thousands << endl;

	cout << "---------------------------------------------------" << endl;

	// Boolean 32
		cout << " BOOLEAN 32" << endl;
		int A1, B1, C1;							//Декларація змінних
		bool IsRightTriangle;
		cout << "Enter A, B and C: " << endl;
		cin >> A1 >> B1 >> C1;

		IsRightTriangle = (A1 * A1 + B1 * B1 == C1 * C1 || B1 * B1 + C1 * C1 == A1 * A1 || A1 * A1 + C1 * C1 == B1 * B1);

		cout << "This triangle is right?: " << boolalpha << IsRightTriangle << endl;

		cout << "---------------------------------------------------" << endl;
	// Solve 39
		cout << " SOLVE 39" << endl;
		float x = 0;							//Декларація змінних
		const float pi = 3.14;					//Декларація сталої П=3.14

		cout << " Enter X: ";
		cin >> x;
		float xforsin = x * (180 / pi);				//Перевод радіан у градуси

		float square = pow((xforsin + 64), 2);		//Спрощення
		float loghariphm = log(fabs(x)) / log(3);	//Спрощення	

		float nom = pow(5, pow(x, 2) * pow(sin(xforsin), 2)) * pow(fabs(pow(sin(square), 2)) * loghariphm, 0.25);		// Числівник
		float denom = pow(tan(xforsin), 3) * pow(sin(xforsin*xforsin*xforsin), 2);										// Знаменник
		float y = nom / denom;			//Розрахунок

		cout << "Y = " << y; // Виведення результату
}
