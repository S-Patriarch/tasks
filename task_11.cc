/*
 * Copyright (C) 2024, S-Patriarch
 *
 * ЗАДАЧА
 * Для целочисленного массива, повернуть массив вправо на k шагов, где
 * k - неотрицательное число.
 *
 * Пример:
 * ввод  - nums = [1,2,3,4,5,6,7], k = 3
 * вывод - [5,6,7,1,2,3,4]
 *
 * Алгоритм:
 * 1. Создаем дополнительный массив, в который будем помещать каждый элемент
 * исходного массива на его новую позицию. Элемент на позиции i в исходном
 * массиве будет размещен на индексе (i+k)% длина массива.
 * 2. Копируем элементы из нового массива в исходоный массив, сохраняя новый
 * порядок элементов.
 * 3. Заменяем исходный массив полученным результатом, завершая процесс
 * поворота массива.
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace mns {
  class Solution {
  public:
    void rotate(vector<int>& nums, int k)
    {
      int n = nums.size();
      vector<int> v(n);
      for (auto i =0; i!=n; ++i) {
        v[(i+k)%n] = nums[i];
      }
      for (auto i =0; i!=n; ++i) {
        nums[i] = v[i];
      }
    }
  };
}

int main()
{
  mns::Solution s;
  vector<int> nums {1,2,3,4,5,6,7};
  int k {3};

  auto out_nums = [&](){
    cout << "\nn : ";
    for (const auto& n : nums) {
      cout << n << ' ';
    }
  };

  out_nums();
  cout << "\nk : " << k;

  s.rotate(nums, k);

  out_nums();
  cout << '\n' << endl;

  std::exit(0);
}
