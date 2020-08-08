#ifndef __DataStructures_MyVector__
#define __DataStructures_MyVector__

#include <iostream>

template<typename T>
class MyVector
{
public:
  MyVector()
  : m_Size(10), m_Pos(0)
  {
    m_Data = new T[m_Size];
  }

  ~MyVector()
  {
    delete[] m_Data;
  }

  void PushBack(T data)
  {
    if (m_Pos >= m_Size) {
      const size_t newSize = m_Size * 1.5;
      T* newData = new T[newSize];

      for (size_t i = 0; i < m_Size; ++i) {
        newData[i] = m_Data[i];
      }

      delete[] m_Data;

      std::cout << "Growing from " << m_Size << " to " << newSize << std::endl;

      m_Data = newData;
      m_Size = newSize;
    }

    m_Data[m_Pos] = data;
    m_Pos++;
  }

  constexpr size_t Size() const { return m_Pos; }

  T &operator[](size_t index) { return m_Data[index]; }

  const T &operator[](size_t index) const { return m_Data[index]; }

private:
  size_t m_Size;
  size_t m_Pos;
  T *m_Data;
};

#endif /* defined(__DataStructures_MyVector__) */