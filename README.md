# cpp-mini-nn

![CI](https://github.com/ana-stanojevic/cpp-mini-nn/actions/workflows/cpp-ci.yml/badge.svg?branch=main)
![C++](https://img.shields.io/badge/C++-20-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A **multi-layer perceptron (MLP)** implemented **in modern C++20**.  
The goal is to showcase **C++/systems thinking**, memory handling, numerical methods, and CMake-based builds.  

---

## ✨ Features
- Dense layers with sigmoid activation
- Simple stochastic gradient descent (SGD)
- Tiny demo: learning XOR
- CMake build + unit tests + GitHub Actions

---

## 📂 Project structure

```text
cpp-mini-nn/
├─ CMakeLists.txt
├─ README.md
├─ LICENSE
├─ .gitignore
├─ include/
│  └─ nn.hpp
├─ src/
│  └─ nn.cpp
├─ examples/
│  └─ xor_demo.cpp
└─ tests/
   └─ test_nn.cpp
```

---

## 🚀 Quick start

Clone the repo and build the project:

```bash
git clone https://github.com/ana-stanojevic/cpp-mini-nn.git
cd cpp-mini-nn

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

Run the XOR demo:

```bash
./build/xor_demo
```

Expected output:

```
0 XOR 0 -> ~0.0
0 XOR 1 -> ~1.0
1 XOR 0 -> ~1.0
1 XOR 1 -> ~0.0
```

---

## 🧪 Running tests

Build and run tests:

```bash
ctest --test-dir build --output-on-failure
```

The unit test (`tests/test_nn.cpp`) verifies that the network learns the XOR function (≈95–100% accuracy).  

---

## ❓ Why this project

This repo is a **showcase** of my **C++ skills** while working on an example of AI/ML system. 
It also serves as an educational reference for how a basic MLP works without relying on large frameworks.  

---

## ⚙️ Tech stack

- **Language:** C++20  
- **Build system:** CMake  
- **Linear algebra:** [Eigen](https://eigen.tuxfamily.org/) (header-only)
- **Optional acceleration:** OpenBLAS (via CMake option)
- **Testing:** ctest + assertions  
- **CI-ready:** GitHub Actions  

---

## 👩‍💻 Author

**Ana Stanojevic**  
[Scholar ↗](https://bit.ly/ana-stanojevic) • [CV ↗](https://bit.ly/ana-stanojevic-cv)  

---

## 📜 License  
MIT License — free to use, modify and distribute.  
