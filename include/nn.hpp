#ifndef NN_HPP
#define NN_HPP

#include <vector>
#include <Eigen/Dense>

class MLP {
public:
    MLP(const std::vector<int>& layers);
    Eigen::VectorXd forward(const Eigen::VectorXd& input);
    void train(const Eigen::MatrixXd& inputs, const Eigen::MatrixXd& targets, int epochs, double learning_rate);

private:
    std::vector<int> layers;
    std::vector<Eigen::MatrixXd> weights;
    std::vector<Eigen::VectorXd> biases;
};

#endif // NN_HPP    