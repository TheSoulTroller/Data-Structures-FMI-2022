// Задачи 12.1, 12.2, 12.3, 12.4, 12.7
#include <iostream>
#include "LList.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
  LList<int> list;
  // Задача 12.3
  list.push_back(1);
  list.push_back(2);
  list.print();

  // Задача 12.4
  list += 3;
  list += 2;
  list.print();

  // Задача 12.1
  cout << list.count(2) << endl;

  // Задача 12.2
  LList<int> list2(5, 7);
  list2.print();

  // Задача 12.7
  list.append(list2);
  list.print();

  return 0;
}