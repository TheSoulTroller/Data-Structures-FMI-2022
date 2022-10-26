// Задачи 17.2, 17.5, 17.6, 17.7, 17.8 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int doubleNum(int x)
{
    return x * 2;
}

// Задача 17.5
void map(int* arr, size_t size, int (*foo)(int))
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = foo(arr[i]);
    }
}

// Задача 17.5.1
template <typename T> void map(T* arr, size_t size, T (*foo)(T))
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = foo(arr[i]);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    map(arr, 5, doubleNum);
    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}