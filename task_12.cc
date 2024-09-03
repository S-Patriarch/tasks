/*
 * Copyright (C) 2024, S-Patriarch
 *
 * ЗАДАЧА
 * Даны два целых числа left и right, которые представляют диапазон
 * [left, right], верните побитовой И всех чисел в этом диапазоне 
 * включительно.
 *
 * Пример:
 * ввод  - left = 5, right = 7
 * вывод - 4
 *
 * Алгоритм:
 * 1. Сдвигать left и right вправо, пока не станут равными.
 * 2. Подсчитать количество сдвигов.
 * 3. Сдвинуть left влево на количество сдвигов и вернуть результат.
 */

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

namespace mns {
  class Solution {
  public:
    int range_bitwise_and(int m, int n)
    {
      int count {0};
      while (m < n) {
        m >>= 1;
        n >>= 1;
        ++count;
      }
      return (m << count);
    }
  };
}

int main()
{
  mns::Solution s;
  int m {5};
  int n {7};

  cout << '\n' << '[' << m << "..." << n << "]\n";
  cout << s.range_bitwise_and(m,n) << '\n' << endl;

  std::exit(0);
}
