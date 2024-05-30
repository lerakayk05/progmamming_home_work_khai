#include <iostream>
#include <string>

// Власна реалізація функції assign
void myAssign(char* dest, const char* src, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
    dest[n] = '\0'; // Завершення рядка нульовим символом
}

int main() {
    // Введення рядка з консолі
    char input[100];
    std::cout << "Введіть рядок: ";
    std::cin.getline(input, 100);

    // Використання методу string::assign
    std::string str;
    std::string str2 = "Writing";
    std::string str3 = "Print 10 and then 5 more";

    // Використання методу assign
    str.assign(input, 5); // Приклад використання assign з введеним рядком
    std::cout << "Результат використання string::assign: " << str << '\n';

    // Виклик власної функції
    char dest[100];
    myAssign(dest, input, 5); // Приклад використання власної функції
    std::cout << "Результат використання myAssign: " << dest << '\n';

    return 0;
}
