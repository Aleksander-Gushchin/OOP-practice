#include <iostream>
#include <tuple>
#include <functional>
#include <vector>
#include <cfloat>
#include <cmath>
#include <algorithm>


class strongin{
public:
    using return_type = std::tuple<double, double, int>;
    std::tuple<double, double, int> static eval(const std::function<double(double)>& function, double r, double a, double b, double eps);
};

class nestrongin{
public:
    double eval(double x, std::function<double(double)>& function, double r, double a, double b) {return x;};
};

template<typename type> class matopt{
public:
    template<typename... Args> static typename type::return_type get(Args... args){
        return type::eval(args...);
    }
};
