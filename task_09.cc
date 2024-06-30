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
//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <array>
#include <utility>
//------------------------------------------------------------------------------
#define LEN_ARRAY   6
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
auto two_single_numbers(const array<int,LEN_ARRAY>& a)
{
   int common_xor {0};
   for (const auto& it : a) {common_xor^=it;}

   int shift {-1};
   while (!((common_xor >> ++shift)&1)) {}

   int mask {1<<shift};
   int group_1_xor {0};
   int group_2_xor {0};
   for (const auto& it : a) {
      if (it & mask) {group_1_xor^=it;}
      else {group_2_xor^=it;}
   }
   return pair<int,int>(group_1_xor,group_2_xor);
}
////////////////////////////////////////////////////////////////////////////////
int main()
{
   array<int,LEN_ARRAY> a = {1,2,3,4,2,1};

   pair<int,int> n;
   n = two_single_numbers(a);
   cout << n.first << ' ' << n.second << '\n';

   exit(EXIT_SUCCESS);
}

