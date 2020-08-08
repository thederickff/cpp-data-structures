#include <iostream>

#include "MyVector.h"

void MyVectorTest()
{
  std::cout << "MyVector: int" << std::endl;

  MyVector<int> myVectorInt;

  for (int i = 0; i < 100; ++i) {
    myVectorInt.PushBack(i);
  }

  for (int i = 0; i < myVectorInt.Size(); i++) {
    std::cout << myVectorInt[i] << std::endl;
  }

  std::cout << "MyVector: std::string" << std::endl;

  MyVector<std::string> myVectorString;

  for (int i = 0; i < 20; ++i) {
    myVectorString.PushBack("Blablabla");
  }

  for (int i = 0; i < myVectorString.Size(); i++) {
    std::cout << myVectorString[i] << std::endl;
  }
}

int main()
{
  MyVectorTest();

  return 0;
}
