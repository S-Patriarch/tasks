/*
 * Copyright (C) 2024, S-Patriarch
 *
 * ЗАДАЧА
 * Написать функцию для нахождения медианы в отсортированном массиве целых
 * чисел. Функция должна корректно работать как с массивами четной длины,
 * так и с нечетной, и возвращать медиану в виде числа с плавающей точкой.
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;
using std::size_t;

namespace mns {
  template <class T>
  class Solution {
  public:
    double find_median(const vector<T> &v)
    {
      size_t size =v.size();
      if (size%2 == 0) {
        return (v[size/2-1]+v[size/2])/2.0;
      }
      else {
        return v[size/2];
      }
    }
  };
}

int main()
{
  vector<int> v1 {1,3,3,6,7,8,9};
  vector<int> v2 {1,2,3,4,5,6,8,9};

  mns::Solution<int> sol;

  cout
    << sol.find_median(v1)
    << endl;
  cout
    << sol.find_median(v2)
    << endl;

  std::exit(0);
}
