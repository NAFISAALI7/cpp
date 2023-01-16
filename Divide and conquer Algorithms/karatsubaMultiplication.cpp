#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int getSize(long num){
    int count = 0;

    while (num > 0){
        count++;
        num /= 10;
    }
    
    return count;
}

long karatsuba(long X, long Y){
    if (X < 10 && Y < 10){
        return X * Y;
    }
    int size = fmax(getSize(X), getSize(Y));
    int n = (int)ceil(size / 2.0);

    long p = (long)pow(10, n);
    long a = (long)floor(X / (double)p);
    long b = X % p;
    long c = (long)floor(Y / (double)p);
    long d = Y % p;
    
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long e = karatsuba(a + b, c + d) - ac - bd;

    return (long)(pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * e + bd);
}

int main(){

    long num1 , num2;

    cout << "Enter the first number: " << endl;
    cin >> num1;

    cout << "Enter the second number: " << endl;
    cin >> num2;

    cout << "The answer is " << karatsuba(num1 , num2) << endl;

    return 0;
}