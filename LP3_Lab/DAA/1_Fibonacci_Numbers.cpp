#include <iostream>

int recursiveCalls = 0; 

int fibonacciRecursive(int n) {
    recursiveCalls++;
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int iterativeCalls = 0; 
int fibonacciIterative(int n) {
    iterativeCalls++;
    if (n <= 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        iterativeCalls++; 
    }

    return b;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Fibonacci series: ";
    for (int i = 0; i <= n; i++) {
        std::cout << fibonacciIterative(i) << " ";
    }

    recursiveCalls = 0;
    std::cout << "Fibonacci(" << n << ") using recursive approach = " << fibonacciRecursive(n) << std::endl;
    std::cout << "Recursive calls: " << recursiveCalls << std::endl;
    std::cout << "Time complexity of recursive approach: O(2^n)" << std::endl;

    iterativeCalls = 0;
    std::cout << "Fibonacci(" << n << ") using iterative approach = " << fibonacciIterative(n) << std::endl;
    std::cout << "Iterative calls: " << iterativeCalls << std::endl;
    std::cout << "Time complexity of iterative approach: O(n)" << std::endl;

    return 0;
}
