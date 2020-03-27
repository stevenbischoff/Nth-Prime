#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

vector<int> list_append(vector<int> primes, int high, int low)
{
    for (int p = low; p <= high; p++)
    {
        primes.push_back(1);
    }
    return primes;
}

vector<int> list_generate(int high, int low)
{
    vector<int> primes = {};
    for (int p = low; p <= high; p++)
    {
        primes.push_back(1);
    }
    return primes;
}

vector<int> base_primes_update(vector<int> base_primes, int sqrt_high, int last_sqrt_high)
{
    base_primes = list_append(base_primes, sqrt_high, last_sqrt_high);
    for (int p = 2; p <= sqrt_high; p++)
    {
        if (base_primes[p-2] == 1)
        {
            int q = p + p;
            while (q <= last_sqrt_high)
            {
                q += p;
            }
            while (q <= sqrt_high)
            {
                base_primes[q-2] = 0;
                q += p;
            }
        }
    }
    return base_primes;
}

void sieve(int max_primes)
{
    int low = 2;
    int high = max_primes;
    int increment = high;
    vector<int> base_primes = {};
    int total_primes = 0;
    int last_prime = 1;
    int last_sqrt_high = 1;

    while (true)
    {
        int sqrt_high = sqrt(high);
        base_primes = base_primes_update(base_primes, sqrt_high, last_sqrt_high);
        vector<int> primes = list_generate(high, low);
        for (int p = 2; p <= sqrt_high; p++)
        {
            if (base_primes[p-2] == 1)
            {
                int q = p + p;
                while (q < low)
                {
                    q += p;
                }
                while (q <= high)
                {
                    primes[q-low] = 0;
                    q += p;
                }
            }
        }
        for (int p = low; p <= high; p++)
        {
            if (primes[p-low] == 1)
            {
                total_primes += 1;
                if (total_primes == max_primes)
                {
                    cout << "The Nth prime is " << p;
                    return;
                }
            }
        }
        low = high + 1;
        high += increment;
    }
}

int ask_for_input()
{
    int max_primes;
    cin >> max_primes;
    while (true)
    {
        if (cin.fail()||max_primes < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "You have entered wrong input" << endl;
            if (max_primes < 1)
            {
                max_primes = ask_for_input();
            }
            else
            {
                cin >> max_primes;
            }
        }
        if (!cin.fail())
        {
            break;
        }
    }
    return max_primes;
}

int main()
{
    cout << "Enter a positive integer N to find the Nth prime\n";
    int max_primes = ask_for_input();
    sieve(max_primes);
}



