//
// (c) 2024 S-Patriarch
//
// ЗАДАЧА
// Дан не пустой массив интов.
// Каждый элемент массива встречается ровно 2 раза, кроме одного, который
// встречается 1 раз.
// Необходимо найти этот элемент.
// При этом, решить задачу надо за линейное время и константную сложность
// по памяти.
//
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <array>
////////////////////////////////////////////////////////////////////////////////
std::int32_t main(std::int32_t argc, char** argv)
   // для решения этой задачи используем операцию xor (исключающее или)
   // операция xor над числами имеет следующие свойства - xor двух
   // одинаковых чисел дает ноль и xor любого числа с нулем в результате
   // будет давать то же самое число
   // временная сложность: O(n), где n - размер массива
   // пространственная сложность: O(1), поскольку мы используем только одну
   // переменную для хранения результата
{
   std::array<std::int32_t,5> a = {1,2,3,2,1};

   std::int32_t res {0};
   for (const auto& it : a) res^=it;
   std::cout << res << '\n';

   std::exit(EXIT_SUCCESS);
}
