#include <iostream>
using namespace std;

int main() {
    const int MAX_NUM = 100;
    int primes[MAX_NUM];
    int prime_count = 0;
    for (int i = 100; i <= 200; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes[prime_count] = i;
            prime_count++;
        }
    }
    cout << "100到200之间的素数有：\n";
    for (int i = 0; i < prime_count; i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
    return 0;
}

