#include "../includes/BinarySearchTree.hpp"
#include <functional>
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destructor para liberar memoria
BinarySearchTree::~BinarySearchTree() {
  // Función lambda para liberar memoria de forma recursiva
  function<void(TreeNode *)> deleteNodes =
      [&](TreeNode
              *node) { // Función lambda para liberar memoria de forma recursiva
        if (node == nullptr)
          return;
        deleteNodes(node->left);  // Llamada recursiva para liberar memoria de
                                  // los nodos izquierdos
        deleteNodes(node->right); // Llamada recursiva para liberar memoria de
                                  // los nodos derechos
        delete node;
      };
  deleteNodes(
      root); // Llamada a la función lambda para liberar memoria de los nodos
}

// Función auxiliar para insertar nodos de forma recursiva
TreeNode *BinarySearchTree::insert(TreeNode *node, int value) {
  if (node == nullptr) {
    return new TreeNode(value); // Crear un nuevo nodo si el nodo actual es nulo
  }
  if (value <
      node->value) { // Insertar en el subárbol izquierdo si el valor es menor
    node->left = insert(
        node->left,
        value); // Llamada recursiva para insertar en el subárbol izquierdo
  } else if (value > node->value) { // Insertar en el subárbol derecho si el
                                    // valor es mayor
    node->right =
        insert(node->right,
               value); // Llamada recursiva para insertar en el subárbol derecho
  }
  return node; // Retornar el nodo actual
}

// Método para insertar un nodo
void BinarySearchTree::insert(int value) { root = insert(root, value); }

// Función auxiliar para buscar el ancestro común más cercano
TreeNode *BinarySearchTree::findLCA(TreeNode *node, int v1, int v2) {
  if (node == nullptr) { // Retornar nulo si el nodo es nulo
    return nullptr;
  }

  if (v1 < node->value &&
      v2 < node->value) { // Verificar si ambos valores son menores que el valor
                          // del nodo actual
    return findLCA(
        node->left, v1,
        v2); // Llamada recursiva para buscar en el subárbol izquierdo
  }

  if (v1 > node->value &&
      v2 > node->value) { // Verificar si ambos valores son mayores que el valor
                          // del nodo actual
    return findLCA(node->right, v1,
                   v2); // Llamada recursiva para buscar en el subárbol derecho
  }

  return node;
}

// Método para encontrar el ancestro común más cercano
int BinarySearchTree::findLowestCommonAncestor(int v1, int v2) {
  if (!search(root, v1) ||
      !search(root, v2)) { // Verificar si ambos valores existen en el árbol
    throw invalid_argument("Uno o ambos valores no existen en el árbol.");
  }
  TreeNode *lca =
      findLCA(root, v1, v2); // Llamar a la función auxiliar para encontrar el
                             // ancestro común más cercano
  if (lca == nullptr) {      // Verificar si no se encontró el ancestro común
    throw runtime_error("No se encontró el ancestro común.");
  }
  return lca->value;
}

// Función auxiliar para imprimir el árbol en orden
void BinarySearchTree::inOrderTraversal(TreeNode *node) {
  if (node == nullptr)
    return;
  inOrderTraversal(node->left);
  cout << node->value << " ";
  inOrderTraversal(node->right);
}

// Método para imprimir el árbol en orden
void BinarySearchTree::printInOrder() {
  inOrderTraversal(root);
  cout << endl;
}

// Función auxiliar para verificar si un valor existe en el árbol
bool BinarySearchTree::search(TreeNode *node, int value) {
  if (node == nullptr) // Retornar falso si el nodo es nulo
    return false;
  if (node->value == value) // Retornar verdadero si el valor es igual al valor
                            // del nodo actual
    return true;
  if (value < node->value) // Buscar en el subárbol izquierdo si el valor es
                           // menor que el valor del nodo actual
    return search(node->left, value); // Llamada recursiva para buscar en el
                                      // subárbol izquierdo
  return search(node->right, value);  // Llamada recursiva para buscar en el
                                      // subárbol derecho
}
