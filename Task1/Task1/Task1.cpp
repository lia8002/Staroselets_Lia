#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

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

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void CountingSort(int arr[], int size) {
    const int MAX_VALUE = 101;
    int count[MAX_VALUE] = { 0 };
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        while (count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}
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
    system("chcp 1251 > nul");
    srand(time(0));
    int n;

    cout << "Введіть розмір масиву: ";
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Початковий масив: ";
    fynkcia(arr, n);

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr1, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Після сортування вставками: ";
    fynkcia(arr1, n);
    cout << "Час: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " мкс" << endl;


    start = chrono::high_resolution_clock::now();
    shellSort(arr2, n);
    end = chrono::high_resolution_clock::now();
    cout << "Після сортування Шелла: ";
    fynkcia(arr2, n);
    cout << "Час: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " мкс" << endl;


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
    int result = binarySearch(arr1, n, target);
    if (result != -1) {
        cout << "Елемент знайдено на позиції: " << result << endl;
    }
    else {
        cout << "Елемент не знайдено." << endl;
    }
    system("pause > nul");
}