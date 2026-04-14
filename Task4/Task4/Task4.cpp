#include <iostream> //для виводу
#include <fstream>//для роботи з файлами
#include <string> //для рядків
#include <cmath> //для abs() (модуль числа
using namespace std;
// Рахує кількість символів
int getCount(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') { //щоб було без пробілів
            count++;
        }
    }
return count;
}
int main() {
    ifstream inputFile("input.txt"); //файли з реченнями
    ofstream outputFile("output.txt");
    if (!inputFile) { //якщо не читає файл
        cout << "Not found!" << endl;
        return 1;
    }
    string s1, s2; //речення
    string best1 = "", best2 = "";
    int maxDiff = -1; /* найбільша різниця, не мож бути від'ємною, якщо різниця 
                      буде 0, то може нічого не виводити тому -1 */

    while (getline(inputFile, s1)) { //беремо 1 реч
         if (s1.length() == 0) continue; //пропускаємо пусті рядки
         ifstream inputFile2("input.txt"); //відкриваємо файл ще раз
    while (getline(inputFile2, s2)) { //беремо 2 реч
          if (s2.length() == 0) continue;
          if (s1 != s2) {
                int count1 = getCount(s1);
                int count2 = getCount(s2); //рахуємо кількість символів
                int diff = abs(count1 - count2);
         if (diff > maxDiff) { //якщо різниця більша: запам’ятовуємо ці речення
                    maxDiff = diff;
                    best1 = s1;
                    best2 = s2;
                }
            }
        }
      inputFile2.close();
    }
    outputFile << "Sentense 1: " << best1 << endl; //записуєм результ у файл
    outputFile << "Sentence 2: " << best2 << endl;
    outputFile << "Difference: " << maxDiff << endl;
    cout << "Good!" << endl;
  return 0;
}