#include "nn.hpp"
#include <iostream>

int main() {
  
  MLP net({2, 4, 1});
  Eigen::MatrixXd inputs(4, 2);
  Eigen::MatrixXd targets(4, 1);
  inputs << 0, 0,
            0, 1,
            1, 0,
            1, 1;
  targets << 0,
             1,
             1,
             0;
  net.train(inputs, targets, 2000, 0.1);
  for (int i = 0; i < inputs.rows(); ++i) {
    Eigen::VectorXd y = net.forward(inputs.row(i));
    std::cout << inputs(i, 0) << " xor " << inputs(i, 1) << " -> " << y[0] << "\n";
  }
}