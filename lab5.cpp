#include <iostream>
#include <cmath>
// Каюк Валерія 30 4 16
using namespace std;

void geo30(); //Декларування функції типу void(задача geo30)

void Sum4();//Декларування функції типу void(задача Sum4)
double factorial(int temp);

void Sum16();//Декларування функції типу void(задача Sum16)

int main() 
{
	int choice = 0; //Декларування змінної задля choice

	while (choice != 4) {
		cout.clear();
		cout << "Choose the task: "
			"\n1. Geometry#30"
			"\n2. Sum4"
			"\n3. Sum16.2"
			"\n4. Quit" << endl;


		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			// Завдання геометричне #30
			geo30();
			break;
		}
		case 2:
		{
			// Завдання # 4
			Sum4();
			break;
		}
		case 3:
		{
			// Завдання # 16
			Sum16();
			break;
		}
		case 4:
		{
			cout << "Програма завершена";
			break;
		}
		default:
		{
			cout << "Такого варiанту немає\n";
			break;
		}
		}
	}
}

void geo30() { // Функція Geo30 
	cout << " GEOMETRY 30" << endl;

	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2; // Декларування змінних типу bool
	int n, count = 0;  // Декларування змінних типу int

	cout << "Number of cycles: ";
	cin >> n;

	cout << "Enter a radius: ";
	cin >> r;

	for (int i = 1; i <= n; i++) // Цикл відліку з 1 до n
	{

		if (r > 0) // Умова перевірки: чи r більше за нуль?
		{
			cout << "Enter X : ";
			cin >> x;
			cout << "Enter Y : ";
			cin >> y;


			ar1 = pow((x + r), 2) + pow(y, 2) > pow(r, 2) && y > 0 && y < r && x >-1 * r && x < 0; //Рівняння першої фігури(верхньої)
			ar2 = pow((x + r), 2) + pow(y, 2) < pow(r, 2) && y > -x - 2 * r && y < 0 && x < -1 * r; //Рівняння другої фігури(нижньої)

			if (ar1 || ar2) {
				count++;  // Інкремент лічильника
			}
		}
		else {
			cout << "Radius cannot be less than 0" << endl; // Вивід повідомлення, що радіус не може бути менше за нуль
		}
	}
	cout << "Counter:  " << count << " from " << n;	//Підрахунок вдалих спробз усіх
}

void Sum4() // Функція Sum4
{
	cout << " SUMOFTHESERIES 4" << endl;
	int k = 0, i; // Декларування змінних типу int
	const double pi = 3.14; // Декларування сталої типу double
	double x, mlt = 1; // Декларування змінних типу double

	cout << "Enter X: ";
	cin >> x;			// Введення х

	cout << "Numbers of cycles: ";
	cin >> i;			// Введення i (кількість циклів)

	cout.precision(10);
	if (!cin || i < 0)
	{
		cout << "Wrong entered n" << endl;
	}
	else
	{
		for (k; k <= i; k++)
		{
			int count = 0;

			double part1 = (pow(x,k) - k);
			double part2 = factorial(k);

			double solving = part1 / part2;

			mlt *= solving;
			solving = 0;

			count = k % 3;

			if (count == 2) {
				cout << "Product of series is " << mlt << endl;
			}
		}
	}
}

double factorial(int temp) // Функція факторіалу
{
	int equals = 1;
	for (int i = 1; i <= temp; i++)
	{
		equals *= i;
	}
	return equals;
}

void Sum16() // Функція Sum16
{
	cout << " SUMOFTHESERIES 16" << endl;
	int k = 0;
	const double pi = 3.14, e = 2.71;
	double x, g = 1E+7;


	cout << "Enter X: ";
	cin >> x;

	double sum = 0;

	do
	{
		k++;
		int count = 0;

		double part1 = pow(k,3)*pow(e,(2*k+1));
		double part2 = factorial(k);

		double solving = part1 / part2;

		sum += solving;
		solving = 0;

		count = k % 3;

		if (count == 2) {
			cout << "Summary of series: " << sum << endl;
		}
	} while (sum < g); // Робити до тих пір, поки сума не перевищить ліміт(g).
}
