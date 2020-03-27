#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> list_generate(vector<int> primes, int high, int low)
{
    for (int p = low; p <= high; p++)
    {
        primes.push_back(1);
    }
    return primes;
}

void sieve(int max_primes)
{
    int low = 2;
    int high = max_primes*16;
    int increment = high;
    vector<int> primes = {};
    int total_primes = 0;
    int last_prime = 1;

    while (true)
    {
        primes = list_generate(primes, high, low);
        int sqrt_high = sqrt(high);
        for (int p = 2; p <= high; p++)
        {
            if (primes[p-2] == 1)
            {
                if (p >= last_prime)
                {
                    total_primes += 1;
                    last_prime = p;
                }
                if (total_primes == max_primes)
                {
                    cout << "Prime #" << max_primes << ": " << p;
                    return;
                }
                if (p <= sqrt_high)
                {
                    for (int q = p+p; q <= high; q+=p)
                    {
                        primes[q - 2] = 0;
                    }
                }
            }
        }
        low = high + 1;
        high += increment;
    }
    cout << '\n' << total_primes << '\n';
}

int main()
{
    int max_primes;
    cout << "Enter an integer N to find the Nth prime\n";
    cin >> max_primes;
    sieve(max_primes);
}



