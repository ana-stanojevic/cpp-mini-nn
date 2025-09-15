#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "nn.hpp"

TEST_CASE("Forward output size matches last layer size") {
    MLP net({2,3,1});
    Eigen::VectorXd input(2);
    input << 0.0, 0.0;
    auto out = net.forward(input);
    CHECK(out.size() == 1);
}