#include <iostream>
using namespace std;

template <class T>
class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  T *arrayStack;
  int arraySize;
  int topElement;

  bool isFull();
  bool isEmpty();

  void push(T element);
  T pop();
  T peek();

};


template <class T>
GenStack<T>::GenStack() // default constructor
{
  arrayStack = new T[1];
  topElement = -1;
  arraySize = 1;
}

template <class T>
GenStack<T>::GenStack(int maxSize) // overloaded constructor
{
  arrayStack = new T[maxSize];
  topElement = -1;
  arraySize = maxSize;
}

template <class T>
GenStack<T>::~GenStack() // deconstructor
{
  if (arrayStack)
  {
    delete [] arrayStack;
  }
}

// check if the stack is full
template <class T>
bool GenStack<T>::isFull()
{
  if (topElement == (arraySize-1))
    return true;
  else
    return false;
}

// check if the stack is empty
template <class T>
bool GenStack<T>::isEmpty()
{
  if (topElement == -1)
    return true;
  else
    return false;
}

// add new element to the top of the stack
template <class T>
void GenStack<T>::push(T element)
{
  // make the array larger if it is already full
  if (isFull())
  {
    char *newArray;
    newArray = new T[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
      newArray[i] = arrayStack[i];
    }

    arraySize++;

    // delete the original array and replace it with the new, larger array
    delete [] arrayStack;
    arrayStack = newArray;
    newArray[++topElement] = element;
  }

  else
  {
    arrayStack[++topElement] = element;
  }
}

// return and remove the top element of the stack
template <class T>
T GenStack<T>::pop()
{
  // first check if the stack is empty
  if (isEmpty())
  {
    cout << "There is nothing in the stack." << endl;
    return ' ';
  }

  else
  {
    T removed = arrayStack[topElement--];
    return removed;
  }
}

// return the top element without removing it from the stack
template <class T>
T GenStack<T>::peek()
{
  if (isEmpty())
  {
    cout << "There is nothing in the stack." << endl;
    return ' ';
  }
  else
  {
    return topElement;
  }
}
