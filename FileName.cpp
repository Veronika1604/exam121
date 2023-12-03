#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

const int MAX_N = 10; //Максимальна кількість елементів в масиві

void printArray(double[]);
double getRandomNumberFloat(double = -100, double = 100, int = 4);
double sumNegativeElements(double[]);
double sumElementsWithOddNumbers(double[]);
double sumElementsLocatedBetweenFirstAndLastNegativeElements(double[]);
void deleteElementsWithShift(double[]);

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    double arr[MAX_N];

    cout << "Згенерований одновимірний масив:" << endl;
    for (int i = 0; i < MAX_N; i++) arr[i] = getRandomNumberFloat(-2, 2, 3);
    printArray(arr);

    cout << "\n\nСума елементів масиву з непарними номерами: " << sumElementsWithOddNumbers(arr);
    cout << "\nСума елементів масиву, розташованих між першим  і останнім від’ємними елементами: " << sumElementsLocatedBetweenFirstAndLastNegativeElements(arr);
    cout << "\n\nМасив після виделення елементів: " << endl;
    deleteElementsWithShift(arr);
    printArray(arr);

    cout << "\n\nДякую за увагу :)" << endl;
    system("pause >> void");
    return 0;
}

// Функція, яка друкує одновимірний масив в консолі
// Функція отримує 1 параметр:
// - arr[] - одновимірний масив;
void printArray(double arr[])
{
    for (int i = 0; i < MAX_N; i++) cout << arr[i] << "\t";
}

// Функція, яка генерує випадкове число з плаваючою комою та вказаною точністю
// Функція отримує 3 параметри:
// - min - нижня межа;
// - max - верхня межа;
// - precision - точність, кількість знаків після коми.
double getRandomNumberFloat(double min, double max, int precision)
{
    // отримати випадкове число як ціле число з порядком precision
    double value = rand() % (int)pow(10, precision);

    // отримати дробове число
    return min + (value / pow(10, precision)) * (max - min);
}

// Функція, яка знаходить суму негативних елементів в одновимірному масиві.
// Функція отримує 1 параметр:
// - arr[] - одновимірний масив;
// Функція повертає суму негативних елементів масиву
double sumNegativeElements(double arr[]) {
    double sum = 0;

    for (int i = 0; i < MAX_N; i++)
        if (arr[i] < 0) sum += arr[i];

    return sum;
}

// Функція, яка знаходить суму елементів масиву з непарними порядковими номерами.
// Функція отримує 1 параметр:
// - arr[] - одновимірний масив;
// Функція повертає суму елементів масиву
double sumElementsWithOddNumbers(double arr[])
{
    double sum = 0;

    for (int i = 1; i < MAX_N; i+=2) sum += arr[i];

    return sum;
}

// Функція, яка знаходить суму елементів масиву, розташованих між першим і останнім від’ємними елементами.
// Функція отримує 1 параметр:
// - arr[] - одновимірний масив;
// Функція повертає суму елементів масиву
double sumElementsLocatedBetweenFirstAndLastNegativeElements(double arr[])
{
    int indexFirst = -1, indexLast = -1;
    double sum = 0;

    for (int i = 0; i < MAX_N; i++)
    {
        if (arr[i] < 0)
        {
            indexFirst = i;
            break;
        }
    }

    for (int i = MAX_N - 1; i > -1; i--)
    {
        if (arr[i] < 0)
        {
            indexLast = i;
            break;
        }
    }

    if (indexFirst != -1 && indexLast != -1 && indexFirst != indexLast) 
        for (int i = indexFirst + 1; i < indexLast; i++) sum += arr[i];

    return sum;
}

// Функція, яка видаляє з масиву вказаний елемент. 
// Елементи, що звільнилися в кінці масиву, заповнює нулями.
// Функція отримує 3 параметри:
// - arr[] - одновимірний масив;
// - k - порядковий номер елемента який треба видалити;
// - end - порядковий номер останнього "реального" елемента;
// Функція повертає порядковий номер останнього "реального" елемента.
int shiftsUndfillZeros(double arr[], int k, int end)
{
    for (int i = k; i < end; i++) arr[i] = arr[i + 1];
    for (int i = end - 1; i < MAX_N; i++) arr[i] = 0;
    return --end;
}

// Функція, яка стискає масив, видаливши з нього всі елементи, модуль яких не перевищує 1. 
// Елементи, що звільнилися в кінці масиву, заповнює нулями.
// Функція отримує 1 параметр:
// - arr[] - одновимірний масив;
void deleteElementsWithShift(double arr[])
{
    int end = MAX_N, i = 0;
    while (i < end)
    {
        if (fabs(arr[i]) < 1) end = shiftsUndfillZeros(arr, i, end);
        else i++;
    }
}
