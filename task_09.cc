//
// (c) 2024 S-Patriarch
//
// ЗАДАЧА
// Дан не пустой массив интов.
// Каждый элемент массива встречается ровно 2 раза, кроме двух, которые
// встречаются 1 раз.
// Необходимо найти эти элементы.
// При этом, решить задачу надо за линейное время и константную сложность
// по памяти.
//
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <array>
#include <utility>
//------------------------------------------------------------------------------
#define LEN_ARRAY   6
//------------------------------------------------------------------------------
auto two_single_numbers(const std::array<std::int32_t,LEN_ARRAY>& a)
{
   std::int32_t common_xor {0};
   for (const auto& it: a) {common_xor^=it;}

   std::int32_t shift {-1};
   while (!((common_xor >> ++shift)&1)) {}

   std::int32_t mask {1<<shift};
   std::int32_t group_1_xor {0};
   std::int32_t group_2_xor {0};
   for (const auto& it: a) {
      if (it&mask) {group_1_xor^=it;}
      else {group_2_xor^=it;}
   }
   return (std::pair<std::int32_t,std::int32_t>(group_1_xor,group_2_xor));
}
////////////////////////////////////////////////////////////////////////////////
std::int32_t main(std::int32_t argc, char** argv)
{
   std::array<std::int32_t,LEN_ARRAY> a = {1,2,3,4,2,1};

   std::pair<std::int32_t,std::int32_t> n;
   n = two_single_numbers(a);
   std::cout << n.first << ' ' << n.second << '\n';

   std::exit(EXIT_SUCCESS);
}
