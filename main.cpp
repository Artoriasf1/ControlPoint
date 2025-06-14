#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "binary_tree.h"

using namespace std;

int main()
{
  Node *root = nullptr;
  string line;
  string binaryCode;
  int value;

  ifstream file("numbersAndBinaryCode.txt");
  if (!file)
  {
    cout << "Ошибка открытия файла!" << endl;
  }

  while (getline(file, line))
  {
    istringstream iss(line); // Позволяет использовать оператор >> для извлечения данных из строки по частям

    // Извлекаем данные из строки
    iss >> value >> binaryCode;

    if (pathExists(root, binaryCode))
    {
      cout << "Ошибка: путь " << binaryCode << " уже существует для другого значения" << endl;
      continue;
    }

    // Строим дерево
    if (root == nullptr)
    {
      root = buildBinaryTree(binaryCode, value);
    }
    else
    {
      insertNode(root, binaryCode, value);
    }
  }

  file.close();

  // Вывод дерева в консоль
  if (pathExists(root, binaryCode) == true)
    printTree(root);
}