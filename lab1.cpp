#include <iostream>
							//Каюк Валерія 15 24
using namespace std;

int main() {
	
	int A, B, C;						//Begin15

	cout << "Enter A, B and C: ";  //
	cin >> A >> B >> C;    //Присвоєння даних змінним

	int temp = C;
	 
	C = B;				 //Розрахунок
	B = A;
	A = temp;

	cout << "Edited A = " << A << " ,B = " << B << " ,C = " << C << endl;

	cout << "--------------------------------------------------------" << endl;

	float TC = 0;  // Begin 24

	cout << "Enter a temperature(Celsius): ";
	cin >> TC; //Присвоєння даних змінній

	float TF = (TC * 9.0 / 5) + 32; //Розрахунок

	cout << "Temperature in Fahrenheit: " << TF;
}
