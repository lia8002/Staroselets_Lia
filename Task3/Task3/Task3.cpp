#include <iostream>
#include <iomanip>
#include <ctime> //для випадкових чисел
using namespace std;
//функція створює двовимірний масив
int** createMatrix(int n) {
    int** matrix = new int* [n]; //створюємо масив рядків
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n]; //кожен рядок це ще один масив
    }
    return matrix;
}
//заповнення мтр
void fillMatrix(int** matrix, int n, int V) {
    int min = -10 - V; //мій варіант 30
    int max = 10 + V;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        //генерує випадкове число в цьому діапазон(0-80)
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}
//вивід мтр
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j]; //setw(5) — щоб числа були рівно вирівнян, вивід мтр
        }
        cout << endl;
    }
}

// мінімальний елемент головної діагоналі
int getMinDiagonal(int** matrix, int n) {
    int min = matrix[0][0];
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < min) { //шукаємо найменше число
            min = matrix[i][i];
        }
    }
    return min;
}

// сектор 10: остача = 3
int countSector10(int** matrix, int n, int k) {
    int count = 0;
    int startCol = (n + 1) / 2; //початок правої частини матриці

    for (int i = 0; i < n; i++) {
        for (int j = startCol; j < n; j++) {
            if (matrix[i][j] % k == 3) { //перевірка
                count++;
            }
        }
    }
    return count;
}

// сектор 1: порахувати і замінити
int processSector1(int** matrix, int n, int minDiag) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i <= j && (i + j) <= (n - 1)) { /*i <= j - верхня частина (разом з головною діагоналлю)
                                                 i + j <= n-1 - до побічної діагоналі*/
                count++;
                matrix[i][j] = minDiag;
            }

        }
    }
    return count;
}
//звільняємо памʼять
void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(0)); //запуск генератора випадкових чисел

    int n, k; /*n — розмір матриці
               k — число для остачі
               V — номер варіанту*/
    int V = 30;

    cout << "Enter the matrix size: ";
    cin >> n;

    cout << "Enter a number for the remainder: ";
    cin >> k;

    int** matrix = createMatrix(n); //створення матриці
    fillMatrix(matrix, n, V); //заповнення

    cout << "\nInitial matrix:\n";
    printMatrix(matrix, n); //показ матриці

    int minDiag = getMinDiagonal(matrix, n); //знаходимо мінімум діагоналі
    int count10 = countSector10(matrix, n, k); //рахуємо сектор 10
    int count1 = processSector1(matrix, n, minDiag); //обробляємо сектор 1

    cout << "\n\n Result\n";
    cout << "Minimum of the main diagonal: " << minDiag << endl;
    cout << "Number of elements in sector 10 (remainder 3): " << count10 << endl;
    cout << "Number of elements in sector 1: " << count1 << endl;

    cout << "\nMatrix after changes:\n";
    printMatrix(matrix, n); //вивід

    deleteMatrix(matrix, n); //видалення
    return 0;
}