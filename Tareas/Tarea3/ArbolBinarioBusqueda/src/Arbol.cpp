#include "../includes/Arbol.hpp"
#include "../includes/Nodo.hpp"
#include <algorithm>

ArbolBS::ArbolBS() : raiz(nullptr) {}
// Constructor que inicializa el árbol con la raíz como nullptr, es decir, el árbol comienza vacío.

void ArbolBS::insertar(int valor)
{
  insertarNodo(raiz, valor);
}
// Inserta un valor en el árbol llamando a la función insertarNodo con la raíz como punto de partida.

void ArbolBS::imprimir() const
{
  inOrden(raiz);
  std::cout << std::endl;
}
// Imprime los valores del árbol en inorden (izquierda, nodo, derecha) usando la función inOrden.

bool ArbolBS::buscar(int valor) const
{
  return buscarNodo(raiz, valor);
}
// Busca un valor en el árbol comenzando desde la raíz. Devuelve true si encuentra el valor, false en caso contrario.

int ArbolBS::altura() const
{
  return altura(raiz);
}
// Calcula la altura del árbol (el número máximo de niveles) llamando a la función altura con la raíz como argumento.

bool ArbolBS::estaBalanceado() const
{
  return estaBalanceado(raiz);
}
// Verifica si el árbol está balanceado, es decir, si la diferencia de alturas entre los subárboles izquierdo y derecho no supera 1.

void ArbolBS::eliminar(int valor)
{
  raiz = eliminarNodo(raiz, valor);
}
// Elimina un nodo con un valor específico del árbol, actualizando la raíz si es necesario, llamando a eliminarNodo.

void ArbolBS::insertarNodo(Nodo *&nodo, int valor)
{
  if (nodo == nullptr) // Si el nodo es nulo, crea un nuevo nodo con el valor dado.
  {
    nodo = new Nodo(valor);
  }
  else if (valor < nodo->dato) // Si el valor es menor que el del nodo actual, inserta en el subárbol izquierdo.
  {
    insertarNodo(nodo->izquierdo, valor);
  }
  else // Si el valor es mayor o igual, inserta en el subárbol derecho.
  {
    insertarNodo(nodo->derecho, valor);
  }
}

void ArbolBS::inOrden(Nodo *nodo) const
{
  if (nodo != nullptr)
  {
    inOrden(nodo->izquierdo);       // Recorre recursivamente el subárbol izquierdo.
    std::cout << nodo->dato << " "; // Imprime el valor del nodo actual.
    inOrden(nodo->derecho);         // Recorre recursivamente el subárbol derecho.
  }
}

bool ArbolBS::buscarNodo(Nodo *nodo, int valor) const
{
  if (nodo == nullptr) // Si el nodo es nulo, significa que no encontró el valor.
    return false;
  if (nodo->dato == valor) // Si el valor del nodo actual coincide con el valor buscado, retorna true.
    return true;
  if (valor < nodo->dato) // Si el valor es menor, busca recursivamente en el subárbol izquierdo.
    return buscarNodo(nodo->izquierdo, valor);
  return buscarNodo(nodo->derecho, valor); // Si el valor es mayor, busca en el subárbol derecho.
}

int ArbolBS::altura(Nodo *nodo) const
{
  if (nodo == nullptr)
    return 0; // Si el nodo es nulo, la altura es 0 (árbol vacío).
  return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));
  // La altura es 1 más la altura máxima entre los subárboles izquierdo y derecho.
}

bool ArbolBS::estaBalanceado(Nodo *nodo) const
{
  if (nodo == nullptr)
    return true; // Un árbol vacío está balanceado por definición.

  int alturaIzquierda = altura(nodo->izquierdo); // Calcula la altura del subárbol izquierdo.
  int alturaDerecha = altura(nodo->derecho);     // Calcula la altura del subárbol derecho.

  return std::abs(alturaIzquierda - alturaDerecha) <= 1 && // Verifica que la diferencia de alturas sea de 1 o menos.
         estaBalanceado(nodo->izquierdo) &&                // Verifica recursivamente si el subárbol izquierdo está balanceado.
         estaBalanceado(nodo->derecho);                    // Verifica recursivamente si el subárbol derecho está balanceado.
}

Nodo *ArbolBS::obtenerSucesor(Nodo *nodo)
{
  nodo = nodo->derecho;
  while (nodo != nullptr && nodo->izquierdo != nullptr)
    nodo = nodo->izquierdo; // El sucesor es el nodo más a la izquierda en el subárbol derecho.
  return nodo;
}

Nodo *ArbolBS::eliminarNodo(Nodo *nodo, int valor)
{
  if (nodo == nullptr)
  {
    return nodo; // Si el nodo es nulo, no hay nada que eliminar.
    std::cout << "Eliminando " << valor << std::endl;
  }
  if (nodo->dato > valor)
    nodo->izquierdo = eliminarNodo(nodo->izquierdo, valor); // Busca recursivamente en el subárbol izquierdo.
  else if (nodo->dato < valor)
    nodo->derecho = eliminarNodo(nodo->derecho, valor); // Busca recursivamente en el subárbol derecho.
  else
  {
    // Si el nodo tiene solo un hijo o ninguno
    if (nodo->izquierdo == nullptr)
    {
      Nodo *temp = nodo->derecho; // Si no tiene hijo izquierdo, devuelve el hijo derecho.
      delete nodo;
      return temp;
    }

    if (nodo->derecho == nullptr)
    {
      Nodo *temp = nodo->izquierdo; // Si no tiene hijo derecho, devuelve el hijo izquierdo.
      delete nodo;
      return temp;
    }

    // Si tiene dos hijos, encuentra el sucesor
    Nodo *succ = obtenerSucesor(nodo);                       // Busca el sucesor inorden (el menor en el subárbol derecho).
    nodo->dato = succ->dato;                                 // Reemplaza el valor del nodo actual con el del sucesor.
    nodo->derecho = eliminarNodo(nodo->derecho, succ->dato); // Elimina el sucesor del subárbol derecho.
  }
  return nodo;
}
