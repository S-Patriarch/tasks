//
// (c) 2024 S-Patriarch
//
// ЗАДАЧА
// Дана последовательность положительных чисел. Пока среди них есть различные,
// выполняется следующая операция:
//	выбирается некоторое максимальное число и из него вычитается минимальное.
//
// Через сколько операций числа станут одинаковыми?
//
// input:
//	   3
//	   9 6 3
//	   В первой строке входных данных задано число n(1<=n<=1000).
//	   В следующей строке заданы n чисел a(i)(1<=a(i)<=10^9).
//
// output:
//    3
//	   Количество операций, после которых все числа станут одинаковыми.
//
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////
int main()
   // работаем с элементами вектора v через его итератор vi
   // перемещаться по элементам вектора можно следующими способами:
   // - v[std::distance(v.begin(),vi)] = ...
   // - std::advance(vi,0);
   // при этом следует подключить библиотеку: #include <iterator>
{
   std::vector<std::uint32_t> v = {9,6,3};

   if (v.empty() || v.size()<2) {
      std::cout << "E: Последовательность чисел пуста или слишком мала.\n";
   }
   else {
      std::cout << "Последовательность чисел\t";
      for (const auto& i : v)
         std::cout << i << ' ';
      std::cout << '\n';

      std::vector<std::uint32_t>::iterator vi;
      std::uint32_t res {};
      while (*std::min_element(v.begin(),v.end())!=
             *std::max_element(v.begin(),v.end())) {
         vi = std::max_element(v.begin(),v.end());
         *vi = *std::max_element(v.begin(),v.end())-
            *std::min_element(v.begin(),v.end());
         ++res;
      }
      std::cout << "Количество операций\t\t" << res << '\n';
   }
   return 0;
}
