#include <iostream>
#define SIZE 5 // Define el tamaño máximo de la cola

using namespace std;

class Queue
{
private:
  int items[SIZE], front, rear; // Arreglo que almacena los elementos de la cola y dos índices (front, rear)

public:
  Queue()
  {
    // Inicializa los índices front y rear. Ambos empiezan en -1, indicando que la cola está vacía.
    front = -1;
    rear = -1;
  }

  // Función para verificar si la cola está llena
  bool isFull()
  {
    // La cola está llena si front es 0 y rear es el último índice del arreglo
    if (front == 0 && rear == SIZE - 1)
    {
      return true;
    }
    return false;
  }

  // Función para verificar si la cola está vacía
  bool isEmpty()
  {
    // La cola está vacía si el índice front es -1
    if (front == -1)
    {
      return true;
    }
    return false;
  }

  // Función para agregar un elemento a la cola
  void enQueue(int element)
  {
    if (isFull())
    {
      // Si la cola está llena, muestra un mensaje y no agrega el elemento
      cout << "Cola llena" << endl;
    }
    else
    {
      // Si es la primera inserción, inicializa front a 0
      if (front == -1)
        front = 0;
      // Incrementa rear para apuntar al siguiente espacio vacío y añade el nuevo elemento
      rear++;
      items[rear] = element;
      cout << "Insertado " << element << endl;
    }
  }

  // Función para eliminar un elemento de la cola
  int deQueue()
  {
    int element;
    if (isEmpty())
    {
      // Si la cola está vacía, muestra un mensaje y retorna -1
      cout << "Cola vacía" << endl;
      return -1;
    }
    else
    {
      // Guarda el elemento al frente de la cola antes de eliminarlo
      element = items[front];
      // Si la cola solo tiene un elemento, resetea los índices a -1
      if (front == rear)
      {
        front = -1;
        rear = -1;
      }
      else
      {
        // Si hay más de un elemento, incrementa front para apuntar al siguiente elemento
        front++;
      }
      cout << "Eliminado -> " << element << endl;
      return element;
    }
  }

  // Función para mostrar los elementos de la cola
  void display()
  {
    int i;
    if (isEmpty())
    {
      // Si la cola está vacía, muestra un mensaje
      cout << endl
           << "Cola vacía" << endl;
    }
    else
    {
      // Muestra el índice de front, los elementos en la cola y el índice de rear
      cout << endl
           << "Indice del frente -> " << front << endl;
      cout << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
           << "Rear index -> " << rear << endl;
    }
  }
};

int main()
{
  Queue q; // Crea una instancia de la clase Queue

  // Intento de desencolar un elemento de una cola vacía
  q.deQueue();

  // Inserta 5 elementos en la cola
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // Intento de insertar un sexto elemento en una cola que ya está llena
  q.enQueue(6);

  // Muestra el estado de la cola después de las inserciones
  q.display();

  // Elimina un elemento de la cola (el primero que fue insertado)
  q.deQueue();

  // Muestra el estado de la cola después de eliminar un elemento
  q.display();

  return 0; // Termina el programa
}
