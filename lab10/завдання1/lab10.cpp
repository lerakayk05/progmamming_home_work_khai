#include <iostream>

struct TTime {
    int Hour;
    int Min;
    int Sec;
};

int CheckTime(TTime T) {
    int result = 0;
    if (T.Hour < 0 || T.Hour > 23) {
        result += 100;  // Помилка в годинах
    }
    if (T.Min < 0 || T.Min > 59) {
        result += 10;  // Помилка в хвилинах
    }
    if (T.Sec < 0 || T.Sec > 59) {
        result += 1;  // Помилка в секундах
    }
    return result;
}

void PrintCheckResult(TTime T) {
    int result = CheckTime(T);
    if (result == 0) {
        std::cout << "Time " << T.Hour << ":" << T.Min << ":" << T.Sec << " is correct." << std::endl;
    } else {
        std::cout << "Time " << T.Hour << ":" << T.Min << ":" << T.Sec << " is incorrect. Error code: " << result << std::endl;
    }
}

int main() {
    TTime times[5] = {
        {23, 59, 59},
        {24, 0, 0},
        {12, 60, 0},
        {12, 30, 61},
        {15, 45, 30}
    };

    for (int i = 0; i < 5; ++i) {
        PrintCheckResult(times[i]);
    }

    return 0;
}