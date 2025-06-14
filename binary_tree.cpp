#include "binary_tree.h"

using namespace std;

// Функция для создания и построения бинарного дерева
Node *buildBinaryTree(const string &binaryCode, int value)
{
  Node *root = new Node(0);
  insertNode(root, binaryCode, value);
  return root;
}

// Функция для добавления узла в дерево
void insertNode(Node *&root, const string &binaryCode, int value)
{
  if (binaryCode.empty())
  {
    // Если путь закончился, присваиваем значение текущему узлу
    root->value = value;
    return;
  }

  char direction = binaryCode[0];
  string remainingPath = binaryCode.substr(1);

  if (direction == '0')
  {
    // Переход к левому потомку
    if (root->left == nullptr)
    {
      root->left = new Node(0);
    }
    insertNode(root->left, remainingPath, value);
  }
  else if (direction == '1')
  {
    // Переход к правому потомку
    if (root->right == nullptr)
    {
      root->right = new Node(0);
    }
    insertNode(root->right, remainingPath, value);
  }
  else
  {
    cout << "Ошибка: недопустимый символ в двоичном коде" << endl;
  }
}

// Вспомогательная рекурсивная функция для вывода дерева
void printTree(Node *node, const string &prefix, bool isLast)
{
  if (node == nullptr)
    return;

  cout << prefix;
  cout << (isLast ? "└── " : "├── ") << node->value << endl;

  string newPrefix = prefix + (isLast ? "    " : "│   ");

  if (node->right != nullptr)
    printTree(node->right, newPrefix, false); // Выводим правый потомок
  if (node->left != nullptr)
    printTree(node->left, newPrefix, true); // Выводим левый потомок
}

// Основная функция вывода
void printTree(Node *root)
{
  if (root != nullptr)
    printTree(root, "", true);
}

// Функция существования пути
bool pathExists(Node* root, const std::string& binaryCode) {
    if (!root || binaryCode.empty())
        return false;

    Node* current = root;

    for (char ch : binaryCode) {
        if (ch == '0') {
            if (!current->left)
                return false;
            current = current->left;
        } else if (ch == '1') {
            if (!current->right)
                return false;
            current = current->right;
        } else {
            return false; // недопустимый символ
        }
    }

    // Путь считается занятым, если узел не равен 0 (начальное значение)
    return current->value != 0;
}