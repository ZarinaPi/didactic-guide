// Laba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

static void Output(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    Sleep(300);
}

static void RandomArr(int** arr, int size)
{
    int max = 99, min = -99;
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

static void ZeroArr(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }
}

static void SpiralSnake(int **arr, int size)
{
    int numberOne = 1;
    int row1 = 0;
    int row2 = size - 1;
    int col1 = 0;
    int col2 = size - 1;

    ZeroArr(arr, size);

    cout << "----------------СПИРАЛЬ----------------" << endl;
    
    while (numberOne <= (size * size))
    {
        for (int i = col1; i <= col2; i++)
        {
            arr[row1][i] = numberOne++;
            Output(arr, size);
            system("CLS");
        }
        for (int j = row1 + 1; j <= row2; j++)
        {
            arr[j][col2] = numberOne++;
            Output(arr, size);
            system("CLS");
        }
        for (int i = col2 - 1; i >= col1; i--)
        {
            arr[row2][i] = numberOne++;
            Output(arr, size);
            system("CLS");
        }
        for (int j = row2 - 1; j >= row1 + 1; j--)
        {
            arr[j][col1] = numberOne++;
            Output(arr, size);
            system("CLS");
        }
        row1++; row2--; col1++; col2--;
    }
    
    cout << "----------------ЗМЕЙКА-----------------" << endl;
    ZeroArr(arr, size);
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[j][i] = numberOne++;
            Output(arr, size);
            system("CLS");
        }
    }

    cout << "---------------------------------------" << endl;
}

static void Shake(int** arr, int size)
{
    ZeroArr(arr, size);
    RandomArr(arr, size);
    Output(arr, size);
    cout << "-----ПЕРЕМЕЩАЕМ СТОЛБЦЫ---------------" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            swap(arr[i][j], arr[i][j + (size / 2)]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----ПЕРЕМЕЩАЕМ СТРОКИ----------------" << endl;

    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            swap(arr[i][j], arr[i + (size / 2)][j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---ПЕРЕМЕЩАЕМ ПО ЧАСОВОЙ СТРЕЛКЕ------" << endl;
    int** arrB = new int* [size / 2];

    for (int i = 0; i < size / 2; i++)
    {
        arrB[i] = new int[size / 2];
    }
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            arrB[i][j] = arr[i][j];
        }
    }
    for (int i = size / 2; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            arr[i - (size / 2)][j] = arr[i][j];
        }
    }
    for (int i = size / 2; i < size; i++)
    {
        for (int j = size / 2; j < size; j++)
        {
            arr[i][j - size / 2] = arr[i][j];
        }
    }
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = size / 2; j < size; j++)
        {
            arr[i + size / 2][j] = arr[i][j];
        }
    }
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = size / 2; j < size; j++)
        {
            arr[i][j] = arrB[i][j - size / 2];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---ПЕРЕМЕЩАЕМ ПО ДИАГОНАЛЯМ-----------" << endl;
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            swap(arr[i][j], arr[i + (size + 1) / 2][j + (size + 1) / 2]);
        }
    }
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = (size + 1) / 2; j < size; j++)
        {
            swap(arr[i][j], arr[i + (size + 1) / 2][j - (size + 1) / 2]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

static void Sort(int size)
{
    int** A = new int* [size];
    int* pdat = new int[size * size]; // выделим один непрерывный кусок для всех данных
    for (int i = 0; i < size; i++)
    {
        A[i] = pdat + i * size;  // расставим указатели на строки
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = -50 + (rand() % 101);
        }
    }
    
    Output(A, size);
    cout << "-----------------------------------------------" << endl;

    int* pA = &A[0][0];
    for (int j = 0; j < size * size; j++)
    {
        int ind = j;
        int tmp = pA[j];
        for (int h = j + 1; h < size * size; h++)
        {
            if (pA[h] < tmp)
            {
                ind = h;
                tmp = pA[h];
            }
        }
        pA[ind] = pA[j];
        pA[j] = tmp;
    }

    Output(A, size);
}

static void sum(int** arr, int size)
{
    int number;
    cout << "Введите число на которое хотите увеличить элементы матрицы = ";
    cin >> number;
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] += number;
        }
    }
    Output(arr, size);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    int size;
    cout << "Введите размерность массива (6, 8, 10) = ";
    cin >> size;

    int** arr = new int* [size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size] {};
    }

    for (;;)
    {
        cout << "1.Заполнить матрицу спиралькой и змейкой." << endl;
        cout << "2.Получает новую матрицу, из матрицы переставляя ее блоки." << endl;
        cout << "3.Сортировка." << endl;
        cout << "4.Увеличить все элементы массива на введённое число." << endl;
        cout << "5.Выход из программы." << endl;
        cout << "Выберите пункт меню. И введите номер выбранного пункта = ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            SpiralSnake(arr, size);
            break;
        }
        case 2:
        {
            Shake(arr, size);
            break;
        }
        case 3:
        {
            Sort(size);
            break;
        }
        case 4:
        {
            ZeroArr(arr, size);
            RandomArr(arr, size);
            Output(arr, size);
            sum(arr, size);
            break;
        }
        default:
            return 0;
            break;
        }
    }
}


