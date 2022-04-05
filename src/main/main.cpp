#include "lib.h"
#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <numeric>


int main()
{
   auto [point, res, num] = matopt<strongin>::get([&](double x){return x*(x-1);}, 3, 1, 6, 1e-3);
   std::cout << point << " " <<  num << "\n";
}