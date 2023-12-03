#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

const int MAX_N = 10; //����������� ������� �������� � �����

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

    cout << "������������ ����������� �����:" << endl;
    for (int i = 0; i < MAX_N; i++) arr[i] = getRandomNumberFloat(-2, 2, 3);
    printArray(arr);

    cout << "\n\n���� �������� ������ � ��������� ��������: " << sumElementsWithOddNumbers(arr);
    cout << "\n���� �������� ������, ������������ �� ������  � ������� �䒺����� ����������: " << sumElementsLocatedBetweenFirstAndLastNegativeElements(arr);
    cout << "\n\n����� ���� ��������� ��������: " << endl;
    deleteElementsWithShift(arr);
    printArray(arr);

    cout << "\n\n����� �� ����� :)" << endl;
    system("pause >> void");
    return 0;
}

// �������, ��� ����� ����������� ����� � ������
// ������� ������ 1 ��������:
// - arr[] - ����������� �����;
void printArray(double arr[])
{
    for (int i = 0; i < MAX_N; i++) cout << arr[i] << "\t";
}

// �������, ��� ������ ��������� ����� � ��������� ����� �� �������� �������
// ������� ������ 3 ���������:
// - min - ����� ����;
// - max - ������ ����;
// - precision - �������, ������� ����� ���� ����.
double getRandomNumberFloat(double min, double max, int precision)
{
    // �������� ��������� ����� �� ���� ����� � �������� precision
    double value = rand() % (int)pow(10, precision);

    // �������� ������� �����
    return min + (value / pow(10, precision)) * (max - min);
}

// �������, ��� ��������� ���� ���������� �������� � ������������ �����.
// ������� ������ 1 ��������:
// - arr[] - ����������� �����;
// ������� ������� ���� ���������� �������� ������
double sumNegativeElements(double arr[]) {
    double sum = 0;

    for (int i = 0; i < MAX_N; i++)
        if (arr[i] < 0) sum += arr[i];

    return sum;
}

// �������, ��� ��������� ���� �������� ������ � ��������� ����������� ��������.
// ������� ������ 1 ��������:
// - arr[] - ����������� �����;
// ������� ������� ���� �������� ������
double sumElementsWithOddNumbers(double arr[])
{
    double sum = 0;

    for (int i = 1; i < MAX_N; i+=2) sum += arr[i];

    return sum;
}

// �������, ��� ��������� ���� �������� ������, ������������ �� ������ � ������� �䒺����� ����������.
// ������� ������ 1 ��������:
// - arr[] - ����������� �����;
// ������� ������� ���� �������� ������
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

// �������, ��� ������� � ������ �������� �������. 
// ��������, �� ���������� � ���� ������, �������� ������.
// ������� ������ 3 ���������:
// - arr[] - ����������� �����;
// - k - ���������� ����� �������� ���� ����� ��������;
// - end - ���������� ����� ���������� "���������" ��������;
// ������� ������� ���������� ����� ���������� "���������" ��������.
int shiftsUndfillZeros(double arr[], int k, int end)
{
    for (int i = k; i < end; i++) arr[i] = arr[i + 1];
    for (int i = end - 1; i < MAX_N; i++) arr[i] = 0;
    return --end;
}

// �������, ��� ������ �����, ��������� � ����� �� ��������, ������ ���� �� �������� 1. 
// ��������, �� ���������� � ���� ������, �������� ������.
// ������� ������ 1 ��������:
// - arr[] - ����������� �����;
void deleteElementsWithShift(double arr[])
{
    int end = MAX_N, i = 0;
    while (i < end)
    {
        if (fabs(arr[i]) < 1) end = shiftsUndfillZeros(arr, i, end);
        else i++;
    }
}