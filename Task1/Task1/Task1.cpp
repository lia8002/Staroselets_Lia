#include <iostream>
#include <cstdlib> //потрібен для генерації випадкових чисел функціями rand() і srand()
#include <ctime> //використовується для отримання часу та вимірювання тривалості виконання.
#include <chrono> //дає більш точні засоби для вимірювання часу у мікросекундах.
using namespace std;

// функція яка виводить масив до 20 ел, а далі тільки перші і останні три
void fynkcia(int arr[], int size) {
    if (size <= 20) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            cout << arr[i] << " ";
        }
        cout << "... ";
        for (int i = size - 3; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

//Функція сортування вставками
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Функція сортування Шелла
void shellSort(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

//Функція сортування підрахунком (має обмеження)
void CountingSort(int arr[], int size) {
    const int MIN = 0;
    const int MAX = 100;
    int count[MAX - MIN + 1] = { 0 };

    // спочатку підганяємо числа під діапазон
    for (int i = 0; i < size; i++) {
        if (arr[i] < MIN) arr[i] = MIN;  // якщо менше MIN, ставимо MIN
        if (arr[i] > MAX) arr[i] = MAX;  // якщо більше MAX, ставимо MAX
        count[arr[i] - MIN]++;
    }

    int j = 0;
    for (int i = 0; i <= MAX - MIN; i++) {
        while (count[i] > 0) {
            arr[j] = i + MIN;
            j++;
            count[i]--;
        }
    }
}

//Функція бінарного пошук
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    system("chcp 1251 > nul"); //для укр мови
    srand(time(0));
    int n;

    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = new int[n];
    //заповнюємо масив випадковими числами без обмеження
    for (int i = 0; i < n; i++) {
        arr[i] = rand(); //будь-яке випадкове число
    }

    cout << "Початковий масив: ";
    fynkcia(arr, n);

    int* arr1 = new int[n]; //масив для сортування вставками
    int* arr2 = new int[n]; //масив для сортування Шелла
    int* arr3 = new int[n]; //масив для сортування підрахунком (з обмеженням 0-100)

    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i]; //копіюємо оригінальні числа
        arr2[i] = arr[i]; //копіюємо оригінальні числа
        arr3[i] = rand() % 101; //тут обмеження 0-100
    }

    // вимірюємо час сортування вставками
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr1, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Після сортування вставками: ";
    fynkcia(arr1, n);
    cout << "Час: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " мкс" << endl;

    // вимірюємо час сортування Шелла
    start = chrono::high_resolution_clock::now();
    shellSort(arr2, n);
    end = chrono::high_resolution_clock::now();
    cout << "Після сортування Шелла: ";
    fynkcia(arr2, n);
    cout << "Час: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " мкс" << endl;

    // вимірюємо час сортування підрахунком
    start = chrono::high_resolution_clock::now();
    CountingSort(arr3, n);
    end = chrono::high_resolution_clock::now();
    cout << "Після сортування підрахунком: ";
    fynkcia(arr3, n);
    cout << "Час: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " мкс" << endl;

    int target;
    cout << "\nВведіть число для пошуку: ";
    cin >> target;

    int result1 = binarySearch(arr1, n, target);
    int result2 = binarySearch(arr2, n, target);
    int result3 = binarySearch(arr3, n, target);

    if (result1 != -1) cout << "В масиві arr1 елемент знайдено на позиції: " << result1 << endl;
    else cout << "В масиві arr1 елемент не знайдено." << endl;

    if (result2 != -1) cout << "В масиві arr2 елемент знайдено на позиції: " << result2 << endl;
    else cout << "В масиві arr2 елемент не знайдено." << endl;

    if (result3 != -1) cout << "В масиві arr3 елемент знайдено на позиції: " << result3 << endl;
    else cout << "В масиві arr3 елемент не знайдено." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    system("pause > nul");
}