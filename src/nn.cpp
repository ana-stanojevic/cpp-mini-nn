#include "nn.hpp"
#include <iostream>
#include <cmath>

MLP::MLP(const std::vector<int> &layers):layers(layers)
{
    // Initialize weights and biases
    for (size_t i = 1; i < layers.size(); ++i) {
        weights.emplace_back(Eigen::MatrixXd::Random(layers[i], layers[i-1]));
        biases.emplace_back(Eigen::VectorXd::Random(layers[i]));
    }
}

Eigen::VectorXd MLP::forward(const Eigen::VectorXd &input)
{
    // Placeholder for forward pass implementation
    Eigen::VectorXd output = input;
    for (size_t i = 0; i < weights.size(); ++i) {
        Eigen::VectorXd z = weights[i] * output + biases[i];
        output = z.unaryExpr([](double x) { return 1.0 / (1.0 + std::exp(-x)); });  // Sigmoid activation
    }
    return output;
}

void MLP::train(const Eigen::MatrixXd &inputs, const Eigen::MatrixXd &targets, int epochs, double learning_rate)
{
    for (int epoch = 0; epoch < epochs; ++epoch) {
        double total_loss = 0.0;
        for (int sample = 0; sample < inputs.rows(); ++sample) {
            std::vector<Eigen::VectorXd> activations;
            std::vector<Eigen::VectorXd> zs;
            Eigen::VectorXd activation = inputs.row(sample);
            activations.push_back(activation);
            
            // Forward pass
            for (size_t i = 0; i < weights.size(); ++i) {
                Eigen::VectorXd z = weights[i] * activations.back() + biases[i];
                zs.push_back(z);
                activation = z.unaryExpr([](double x) { return 1.0 / (1.0 + std::exp(-x)); });  // Sigmoid activation
                activations.push_back(activation);
            }

            // Compute MSE loss 
            Eigen::VectorXd output = activations.back();
            Eigen::VectorXd target = targets.row(sample);
            Eigen::VectorXd diff = output - target;
            total_loss += diff.squaredNorm() / diff.size();

            // Backward pass 
            // Output layer delta
            Eigen::VectorXd delta = diff.cwiseProduct(
                zs.back().unaryExpr([](double x)    { 
                    double sig = 1.0 / (1.0 + std::exp(-x)); 
                    return sig * (1 - sig); 
                })
            );

            for (int l = (int)(weights.size()) - 1; l >= 0; --l) {
                Eigen::MatrixXd grad_w = delta * activations[l].transpose();
                Eigen::VectorXd grad_b = delta;
                weights[l] -= learning_rate * grad_w;
                biases[l] -= learning_rate * grad_b;
                if (l > 0) {
                    delta = (weights[l].transpose() * delta).cwiseProduct(
                        zs[l-1].unaryExpr([](double x) { 
                            double sig = 1.0 / (1.0 + std::exp(-x)); 
                            return sig * (1 - sig); 
                        })
                    );
                }

        }
        total_loss /= inputs.rows();
        std::cout << "Epoch " << epoch << "/" << epochs << ", Loss: " << total_loss << std::endl;
    }   
}


