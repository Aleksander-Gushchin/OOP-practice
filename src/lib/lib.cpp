#include "lib.h"


std::tuple<double, double, int> strongin::eval(const std::function<double(double)>& function, double r, double a, double b, double eps){
int N = 10000;
  std::vector<double> x(2);
  x.reserve(N);
  std::vector<double> Q(2);
  std::vector<double> R(N, -DBL_MAX);

  Q.reserve(N);

  x[0] = a;
  x[1] = b;

  Q[0]= function(x[0]);
  Q[1]= function(x[1]);

  double global_min;
  double func_val_at_min;

  if(Q[0] < Q[1]){
    global_min = x[0];
    func_val_at_min = Q[0];
  } else{
    global_min = x[1];
    func_val_at_min = Q[1];
  }

  auto get_M = [&](int i){
    return abs(Q[i + 1] - Q[i]) / (x[i+1] - x[i]);
  };

  double M_max =  get_M(0);
  
  int n = 2;
  while(n < N){
    double L = M_max < 1.e-5 ? 1 : r * M_max;
    
    for(int i = 0; i < n - 1; ++i)
      R[i] = L * (x[i + 1] - x[i]) 
      + pow(Q[i + 1] - Q[i], 2) / (L * (x[i + 1] - x[i]))
      - 2 * (Q[i + 1] + Q[i]);

    int ROI = std::distance(R.begin(), std::max_element(R.begin(), R.begin()+n));
    double x_new = .5* (x[ROI + 1] + x[ROI]) - (Q[ROI + 1] - Q[ROI])/(2*L);

    Q.insert(Q.begin() + ROI + 1, function(x_new));
    auto lower_x = std::lower_bound(x.begin(), x.end(), x_new);
    x.insert(lower_x, x_new);
    
    M_max = std::max({M_max, get_M(ROI), get_M(ROI + 1)});
    
    if(Q[ROI + 1] < func_val_at_min){
      global_min = x_new;
      func_val_at_min = Q[ROI + 1];
    }

    if(std::abs(*lower_x - *(--lower_x)) < eps)
      return std::make_tuple(global_min, function(global_min), n);
      
    ++n;
  }

  return std::make_tuple(global_min, function(global_min), n);
}
