#include "lib.h"
#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <numeric>
#include <memory>

int main()
{
   SofaFactory fc;
   auto res = std::unique_ptr<Item>(fc.Produce());
   std::cout << res.get()->item_name();
}