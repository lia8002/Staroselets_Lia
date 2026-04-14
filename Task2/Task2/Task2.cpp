#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення факторіалу
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    cout << "Calculating expression y" << endl;

    double x = 8.31;
    int n = 4;

    cout << fixed << setprecision(6); //6 елементів після коми

    // Перша сума: sum k=1..10 cos(kx)
    double sum1 = 0;
    for (int k = 1; k <= 10; k++) {
        sum1 += cos(k * x);
    }

    // Друга частина (чисельник)
    double numerator = sqrt(pow(factorial(n), 2) + pow(cos(x), 2));

    //Друга частина (знаменник)
    double sum2 = 0;
    for (int k = 1; k <= 6; k++) {
        sum2 += cos(k * x);
    }

    double denominator = sqrt(pow(sum2, 2) + pow(factorial(2 * n), 2));

    double fraction = numerator / denominator;

    //Третя частина (4-й корінь)
    double third_part = pow(pow(factorial(2 * n - 1), 2) + 4, 0.25);

    //Загальний результат
    double y = sum1 + fraction + third_part;

    // Вивід
    cout << "Sum1 = " << sum1 << endl;
    cout << "Fraction = " << fraction << endl;
    cout << "Fourth root part = " << third_part << endl;

    cout << "Final result y = " << y << endl;

    return 0;
}