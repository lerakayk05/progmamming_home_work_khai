#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int M = 50, N = 50;

void findClosestToAverage31(); // Завдання #31
void print31(int matr1[M][N], int row, int column, int closestRow, int closestCol);
void deleteColumnWithMaxElement64();
void printMatrix64(int matrix[M][N], int row, int column);
int count(const int a[M][N], const int row, const int column);
void enter(int a[M][N], int& column, int& row);
void deleteColumnWithMaxElement64(); // Завдання #64 Дана матриця розміру M × N.

int main() {
	srand(time(NULL));			//Генератор семя случайности
	setlocale(LC_ALL, "Ukrainian");

	int choice = 0;

	while (choice != 3) {

		cout << "Оберiть завдання: "
			"\n1.Array#31"
			"\n2.Array#64"
			"\n3.Exit" << endl;

		cin >> choice;

		switch (choice) {
			case 1: {
				findClosestToAverage31();
				break;
			}
			case 2: {
				deleteColumnWithMaxElement64();
				break;
			}
			case 3: {
				cout << "Програма завершена!";
				break;
			}
			default: {
				cout << "Невiрний варiант, спробуйте ще раз";
			}
		}
    }
}


void findClosestToAverage31() { //Завдання 31
    int matr1[M][N];						// Массив
	int row, column;

	enter(matr1, row, column);
	// Знаходимо середнє значення всіх елементів матриці
        double sum = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                sum += matr1[i][j];
            }
        }
        double average = sum / (row * column);

        // Шукаємо елемент, найближчий до середнього значення
        int closestRow = 0;
        int closestCol = 0;
        double minDifference = abs(matr1[0][0] - average);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                double difference = abs(matr1[i][j] - average);
                if (difference < minDifference) {
                    minDifference = difference;
                    closestRow = i;
                    closestCol = j;
                }
            }
            }
            print31(matr1, row, column, closestRow, closestCol);
            }
void print31(int matr1[M][N], int row, int column, int closestRow, int closestCol) {
    for (int i = 0; i < row; i++) {
                		for (int j = 0; j < column; j++) {
                			cout << " | " << matr1[i][j] <<  "\t | ";
                		}
                		cout << "\n";
    }
                cout << "Номер рядка і стовпчика для елемента матриці, найближчого до середнього значення: "
                         << closestRow << ", " << closestCol << endl;
    }

int count(const int a[M][N], const int row, const int column) {
	bool foundZero = false;
	int nonunique = 0;

	for (int j = 0; j < column; j++) {
		foundZero = 0;
		for (int i = 0; i < row; i++) {
			for (int g = i + 1; g < row; g++) {
				if (a[i][j] == a[g][j]) {
					foundZero = true;
					break;
				}
			}
			if (foundZero) {
				break;
			}
		}
		if (foundZero) {
			nonunique++;
		}
	}
	return nonunique;
}


void enter(int a[M][N], int& column, int& row) {
	do
	{
		cout << "Число стовпцiв (2-20): ";
		cin >> column;
		cout << "Число рядкiв (2-20): ";
		cin >> row;
	}
	// доки некоректні вхід.дані
	while (column < 2 || column>N || row <2 || row>M);

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {							//Случайные значение всем элементам массива
			a[i][j] = (rand() % 100) + 1;
		}
	}
}

void deleteColumnWithMaxElement64() {
    int matr1[M][N];						// Массив
	int row, column;
	enter(matr1, row, column);

    // Знаходження стовпця з максимальним елементом
    int maxElementColumn = 0;
    int maxElement = matr1[0][0];
    for (int j = 0; j < column; ++j) {
        for (int i = 0; i < row; ++i) {
             if (matr1[i][j] > maxElement) {
                    maxElement = matr1[i][j];
                    maxElementColumn = j;
             }
        }
    }

    // Видалення стовпця з максимальним елементом
   for (int i = 0; i < row; ++i) {
           for (int j = maxElementColumn; j < column - 1; ++j) {
               matr1[i][j] = matr1[i][j + 1];
           }
   }
   --column; // Зменшення кількості стовпців
   printMatrix64(matr1, row, column);
}

void printMatrix64(int matrix[M][N], int row, int column) {
    cout << "Матриця після видалення стовпця з максимальним елементом:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}