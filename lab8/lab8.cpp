#include <iostream>
#include <ctime>
#include <windows.H>
#include <string>
#include <fstream>
#include <sstream>

const int M = 20, N = 20, F = 100;

void array70();
std::vector<int> readArrayFromFile(const std::string& filename);

void matrix31();
void enter(float arr[M][N], int row, int column, std::string in);
int count(const float a[M][N], const int row, const int column);

void sort12();
int main() {
	srand(time(NULL));			//Генератор случайности
		setlocale(LC_ALL, "Ukrainian");

		int choice = 0;

		while (choice != 4) {

			std::cout << "Оберiть завдання: "
				"\n1.Array#70"
				"\n2.Matrix#39"
				"\n3.Sort#20"
				"\n4.Exit" << std::endl;

			std::cin >> choice;

			switch (choice) {
				case 1: {
					array70();		//Задание array70
					break;
				}
				case 2: {
					matrix31();		// Задание matrix31
					break;
				}
				case 3: {
					sort12();		// Задание sort12
					break;
				}
				case 4: {
					std::cout << "Програма завершена!";
					break;
				}
				default: {
					std::cout << "Невiрний варiант, спробуйте ще раз";
				}
			}
	    }
}

// Задание Array70
// Функція, що змінює місцями першу і другу половини масиву
void array70() {
    // Читання масиву з файлу
    std::string filename = "/lab8/array70/array_in_70.txt";
    std::vector<int> arr = readArrayFromFile(filename);

    int N = arr.size();

   // Перевірка, що розмір масиву парний
   if (N % 2 != 0) {
       std::cerr << "Розмір масиву повинен бути парним!" << std::endl;
       return;
   }

   // Зміна місцями першої і другої половини масиву
   for (int i = 0; i < N / 2; ++i) {
       std::swap(arr[i], arr[N / 2 + i]);
   }

    std::cout << "Змінений масив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Функція для зчитування масиву з файлу
std::vector<int> readArrayFromFile(const std::string& filename) {
    std::vector<int> arr;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return arr;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            arr.push_back(num);
        }
    }

    file.close();
    return arr;
}

// Задание Matrix31

void matrix31() {
	int M, N;
  std::string filename = "matrix31.txt";
  std::vector<std::vector<int>> matrix = readMatrixFromFile(filename, M, N);

  if (matrix.empty()) {
      return;
  }

  // Обчислення середнього значення всіх елементів матриці
  double sum = 0;
  int totalElements = M * N;
  for (const auto& row : matrix) {
      for (int element : row) {
          sum += element;
      }
  }
  double average = sum / totalElements;

  // Знаходження елемента найближчого до середнього значення
  double minDifference = std::numeric_limits<double>::max();
  int closestRow = -1, closestCol = -1;

  for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
          double difference = std::abs(matrix[i][j] - average);
          if (difference < minDifference) {
              minDifference = difference;
              closestRow = i;
              closestCol = j;
          }
      }
  }

  // Виведення результату
  std::cout << "Середнє значення: " << average << std::endl;
  std::cout << "Найближчий елемент до середнього значення: " << matrix[closestRow][closestCol] << std::endl;
  std::cout << "Рядок: " << closestRow << ", Стовпчик: " << closestCol << std::endl;
}


void enter(float arr[M][N], int row, int column, std::string in) {
	std::string out;
	float num = 0;
	int numRows = 0, numCols = 0;

	std::ifstream f;

	std::istringstream iss(out);

	f.open(in);

	std::getline(f, out);

	while (std::getline(f, out) && numRows < row) {
		std::istringstream iss(out);
		numCols = 0;

		while (iss >> num && numCols < column) {
			arr[numRows][numCols] = num;
			numCols++;
		}

		numRows++;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::ofstream outp;

	outp.open(in, std::ios::app);

	if (!outp)
	{
		std::cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		outp << "\nНеунiкальних стовпців : " << count(arr, row, column) << std::endl;
	}

}

int count(const float a[M][N], const int row, const int column) {
	bool foundZero = false;
	int nonunique = 0;

	std::cout << "\n";

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

// Задание Sort12

// Функція сортування бульбашковим методом
void sort12() {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементами arr[j] та arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    std::cout << "Відсортований масив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}