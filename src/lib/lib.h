#include <iostream>
#include <tuple>
#include <functional>
#include <vector>
#include <cfloat>
#include <cmath>
#include <algorithm>

struct basic_item
{
};
struct sofa
{
};

class Item
{
public:
  Item() {};
  virtual std::string item_name() = 0;
  virtual ~Item() {};
};

class Sofa : public Item
{
public:
  virtual std::string item_name() override { return "Sofa"; }
};

class Factory
{
public:
  Factory() {};
  virtual Item* Produce() = 0;
  virtual ~Factory() {};
};

class SofaFactory : public Factory
{
public:
  SofaFactory() {};
  Item* Produce() {return new Sofa;};
  ~SofaFactory() {};
};
