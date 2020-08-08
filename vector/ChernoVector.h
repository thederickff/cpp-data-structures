#ifndef __DataStructures_ChernoVector__
#define __DataStructures_ChernoVector__

#include <iostream>

template<typename T>
class ChernoVector
{
public:
  ChernoVector()
  {
    ReAlloc(2);
  }

  ~ChernoVector()
  {
    delete[] m_Data;
  }

  void PushBack(const T &value)
  {
    if (m_Size >= m_Capacity) {
      ReAlloc(m_Capacity * 1.5);
    }

    m_Data[m_Size] = value;
    m_Size++;
  }

  void PushBack(const T &&value)
  {
    if (m_Size >= m_Capacity) {
      ReAlloc(m_Capacity * 1.5);
    }

    m_Data[m_Size] = std::move(value);
    m_Size++;
  }

  template<typename... Args>
  T& EmplaceBack(Args&&... args)
  {
    if (m_Size >= m_Capacity) {
      ReAlloc(m_Capacity * 1.5);
    }

    new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
    return m_Data[m_Size++];
  }

  void PopBack()
  {
    if (m_Size > 0) {
      m_Size--;
      m_Data[m_Size].~T();
    }
  }

  void Clear()
  {
    for (size_t i = 0; i < m_Size; ++i) {
      m_Data[i].~T();
    }

    m_Size = 0;
  }

  constexpr size_t Size() const { return m_Size; }

  T &operator[](size_t index) { return m_Data[index]; }

  const T &operator[](size_t index) const { return m_Data[index]; }

private:
  void ReAlloc(size_t newCapacity)
  {
    std::cout << "Growing from " << m_Capacity << " to " << newCapacity << std::endl;
    T* newBlock = new T[newCapacity];

    if (newCapacity < m_Size) {
      m_Size = newCapacity;
    }

    for (size_t i = 0; i < m_Size; ++i) {
      newBlock[i] = std::move(m_Data[i]);
    }

    delete[] m_Data;
    
    m_Data = newBlock;
    m_Capacity = newCapacity;
  }

private:
  T *m_Data = nullptr;
  
  size_t m_Size = 0;
  size_t m_Capacity = 0;
};

#endif /* defined(__DataStructures_ChernoVector__) */