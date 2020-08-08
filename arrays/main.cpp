#include <iostream>

template<typename T, size_t S>
class Array
{
public:
  constexpr size_t Size() const { return S; }

  T& operator[](size_t index) { return m_Data[index]; }
  const T& operator[](size_t index) const { return m_Data[index]; }

  T* Data() { return m_Data; }
  const T* Data() const { return m_Data; }
private:
  T m_Data[S];
};

int main()
{
  constexpr size_t size = 2;
  Array<std::string, size> data;
  data[0] = "Cherno";
  data[1] = "C++";

  const auto& arrayRef = data;

  for (size_t i = 0; i < data.Size(); ++i)
  {
    // arrayRef[i] = "Done";

    std::cout << arrayRef[i] << std::endl;
  }



  // for (int i = 0; i < collection.size(); ++i)
  // {
  //   std::cout << collection[i] << std::endl;
  // }

  // int array[5];

  // int size = 5;
  // int* heapArray = new int[size];
  // delete[] heapArray;

  return 0;
}