#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

using namespace std;

// Структура узла бинарного дерева
struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для создания и построения бинарного дерева
Node *buildBinaryTree(const string &binaryCode, int value);

// Функция для добавления узла в дерево
void insertNode(Node *&root, const string &binaryCode, int value);

// Функция для вывода дерева боком
void printTree(Node *root);

// Функция существования пути
bool pathExists(Node *root, const string &binaryCode);

#endif