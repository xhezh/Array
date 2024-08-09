#pragma once
#include <algorithm>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};
template <typename T, std::size_t N>
class Array {
public:
  T data[N];

  T& operator[](std::size_t idx) {
    return data[idx];
  }

  const T& operator[](std::size_t idx) const {
    return data[idx];
  }

  T& At(std::size_t idx) {
    if (idx >= N) {
      throw ArrayOutOfRange{};
    }
    return data[idx];
  }

  const T& At(std::size_t idx) const {
    if (idx >= N) {
      throw ArrayOutOfRange{};
    }
    return data[idx];
  }

  T& Front() {
    return data[0];
  }

  const T& Front() const {
    return data[0];
  }

  T& Back() {
    return data[N - 1];
  }

  const T& Back() const {
    return data[N - 1];
  }

  T* Data() {
    return data;
  }

  const T* Data() const {
    return data;
  }

  std::size_t Size() const {
    return N;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T& value) {
    std::fill_n(data, N, value);
  }

  void Swap(Array<T, N>& other) {
    std::swap_ranges(data, data + N, other.data);
  }
};
#define ARRAY_TRAITS_IMPLEMENTED

template <typename T>
std::size_t GetSize(const T&) {
  return 0;
}

template <typename T, std::size_t N>
std::size_t GetSize(const T(&)[N]) {
  return N;
}

template <typename T>
std::size_t GetRank(const T&) {
  return 0;
}

template <typename T, std::size_t N>
std::size_t GetRank(const T(&)[N]) {
  return 1 + GetRank(T{});
}

template <typename T>
std::size_t GetNumElements(const T&) {
  return 1;
}

template <typename T, std::size_t N>
std::size_t GetNumElements(const T(&)[N]) {
  return N * GetNumElements(T{});
}