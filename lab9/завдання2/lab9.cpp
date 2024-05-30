#include <iostream>
#include <fstream>
#include <string>

// A. Функція для підрахунку кількості розділових знаків у рядку
int countPunctuationMarks(const std::string& line) {
    int count = 0;
    for (char ch : line) {
        if (ispunct(ch)) {
            count++;
        }
    }
    return count;
}

// B. Функція для перевірки, чи містить рядок розділові знаки
bool containsPunctuationMarks(const std::string& line) {
    for (char ch : line) {
        if (ispunct(ch)) {
            return true;
        }
    }
    return false;
}

// D. Обробка текстового файлу
void processFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        int punctuationCount = countPunctuationMarks(line);
        bool hasPunctuation = containsPunctuationMarks(line);

        // Запис результатів у вихідний файл
        outputFile << "Рядок: " << line << std::endl;
        outputFile << "Кількість розділових знаків: " << punctuationCount << std::endl;
        outputFile << "Містить розділові знаки: " << (hasPunctuation ? "Так" : "Ні") << std::endl;
        outputFile << "------------------------------------" << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    // C. Створити вхідний текстовий файл з 10 різними рядками
    std::ofstream inputFile("input.txt");
    if (inputFile.is_open()) {
        inputFile << "Hello, world!" << std::endl;
        inputFile << "This is a test sentence." << std::endl;
        inputFile << "How are you?" << std::endl;
        inputFile << "C++ is great; isn't it?" << std::endl;
        inputFile << "Let's write some code." << std::endl;
        inputFile << "Count the punctuation marks!" << std::endl;
        inputFile << "What's the time?" << std::endl;
        inputFile << "Goodbye..." << std::endl;
        inputFile << "Email me at example@example.com." << std::endl;
        inputFile << "The quick, brown fox jumps over the lazy dog." << std::endl;
        inputFile.close();
    }

    // D & E. Обробка файлу та запис результатів у вихідний файл
    processFile("input.txt", "output.txt");

    std::cout << "Обробка завершена. Перевірте файл output.txt для результатів." << std::endl;

    return 0;
}
