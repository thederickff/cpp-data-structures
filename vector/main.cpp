#include <iostream>

#include "MyVector.h"
#include "ChernoVector.h"

struct Vector3
{
  float x = 0.0f, y = 0.0f, z = 0.0f;

  Vector3() {}

  Vector3(float scalar)
  : x(scalar), y(scalar), z(scalar) { }

  Vector3(float x, float y, float z)
  : x(x), y(y), z(z) { }

  Vector3(const Vector3 &other)
  : x(other.x), y(other.y), z(other.z)
  {
    std::cout << "Copy\n";
  }

  Vector3(const Vector3 &&other)
  : x(other.x), y(other.y), z(other.z)
  {
    std::cout << "Move\n";
  }

  ~Vector3()
  {
    std::cout << "Destroy\n";
  }

  Vector3 &operator=(const Vector3 &other)
  {
    std::cout << "Copy\n";
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
  }

  Vector3 &operator=(const Vector3 &&other)
  {
    std::cout << "Move\n";
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
  }
};

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

void ChernoVectorTest()
{
  {
    std::cout << "\nChernoVector: std::string" << std::endl;
    ChernoVector<std::string> vector;
    vector.PushBack("Cherno");
    vector.PushBack("C++");
    vector.PushBack("Vector");

    for (size_t i = 0; i < vector.Size(); ++i) {
      std::cout << vector[i] << std::endl;
    }
  
    std::cout << "----------------------" << std::endl;
  }

  {
    std::cout << "\nChernoVector: Vector3" << std::endl;
    ChernoVector<Vector3> vector3s;
    // vector3s.PushBack(Vector3(30.0f));
    // vector3s.PushBack(Vector3(1.0, 1.5, 0.5));
    // vector3s.PushBack(Vector3());

    vector3s.EmplaceBack(30.0f);
    vector3s.EmplaceBack(1.0, 1.5, 0.5);
    vector3s.EmplaceBack();

    for (size_t i = 0; i < vector3s.Size(); ++i) {
      std::cout << "{ " << vector3s[i].x << ", " << vector3s[i].y << ", " << vector3s[i].z << " }" << std::endl;
    }
    vector3s.PopBack();
    vector3s.PopBack();

    for (size_t i = 0; i < vector3s.Size(); ++i) {
      std::cout << "{ " << vector3s[i].x << ", " << vector3s[i].y << ", " << vector3s[i].z << " }" << std::endl;
    }

    vector3s.Clear();

    for (size_t i = 0; i < vector3s.Size(); ++i) {
      std::cout << "{ " << vector3s[i].x << ", " << vector3s[i].y << ", " << vector3s[i].z << " }" << std::endl;
    }

    std::cout << "----------------------" << std::endl;
  }
}


int main()
{
  MyVectorTest();
  ChernoVectorTest();

  return 0;
}
