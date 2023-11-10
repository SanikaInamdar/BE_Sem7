#include <iostream>

using namespace std;

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
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci series: ";
    for (int i = 0; i <= n; i++) {
        cout << fibonacciIterative(i) << " ";
    }

    recursiveCalls = 0;
    cout << "Fibonacci(" << n << ") using recursive approach = " << fibonacciRecursive(n) << endl;
    cout << "Recursive calls: " << recursiveCalls << endl;
    cout << "Time complexity of recursive approach: O(2^n)" << endl;

    iterativeCalls = 0;
    cout << "Fibonacci(" << n << ") using iterative approach = " << fibonacciIterative(n) << endl;
    cout << "Iterative calls: " << iterativeCalls << endl;
    cout << "Time complexity of iterative approach: O(n)" << endl;

    return 0;
}
