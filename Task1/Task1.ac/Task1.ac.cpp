#include <iostream>
#include <cstdlib>
#include <ctime>
#include <future>
#include <chrono>
#include <iomanip> // для fixed і setprecision
using namespace std;

void fynkcia(int arr[], int size) {
    if (size <= 20) {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
    }
    else {
        for (int i = 0; i < 3; i++) cout << arr[i] << " ";
        cout << "... ";
        for (int i = size - 3; i < size; i++) cout << arr[i] << " ";
    }
    cout << endl;
}

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

void shellSort(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void CountingSort(int arr[], int size) {
    const int MIN = 0;
    const int MAX = 100;
    int count[MAX - MIN + 1] = { 0 };

    for (int i = 0; i < size; i++) {
        if (arr[i] < MIN) arr[i] = MIN;
        if (arr[i] > MAX) arr[i] = MAX;
        count[arr[i] - MIN]++;
    }

    int j = 0;
    for (int i = 0; i <= MAX - MIN; i++) {
        while (count[i] > 0) {
            arr[j++] = i + MIN;
            count[i]--;
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    system("chcp 1251 > nul");
    srand(time(0));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand();

    cout << "Початковий масив: ";
    fynkcia(arr, n);

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = rand() % 101;
    }

    auto start1 = chrono::high_resolution_clock::now();
    auto future1 = async(launch::async, insertionSort, arr1, n);

    auto start2 = chrono::high_resolution_clock::now();
    auto future2 = async(launch::async, shellSort, arr2, n);

    auto start3 = chrono::high_resolution_clock::now();
    auto future3 = async(launch::async, CountingSort, arr3, n);

    future1.get();
    auto end1 = chrono::high_resolution_clock::now();

    future2.get();
    auto end2 = chrono::high_resolution_clock::now();

    future3.get();
    auto end3 = chrono::high_resolution_clock::now();

    cout << fixed << setprecision(0);

    cout << "Після сортування вставками: ";
    fynkcia(arr1, n);
    cout << "Час: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " мкс" << endl;

    cout << "Після сортування Шелла: ";
    fynkcia(arr2, n);
    cout << "Час: " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << " мкс" << endl;

    cout << "Після сортування підрахунком: ";
    fynkcia(arr3, n);
    cout << "Час: " << chrono::duration_cast<chrono::microseconds>(end3 - start3).count() << " мкс" << endl;

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