#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <vector>
#include <ostream>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> vec);

bool is_prime(int num);
string to_binary(int n);

template <typename T>
ostream &operator<<(ostream &os, vector<T> vec)
{
    os << "[ ";
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        cout << vec[i];
        if (i != size - 1)
            cout << ", ";
    }
    os << " ]";
    return os;
}

bool is_prime(int num)
{
    if (num < 1)
        return false;
    else if (num < 4)
        return true;
    int sq = (int)sqrt(num);
    for (int i = 2; i < sq + 1; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

string to_binary(int n)
{
    if (n == 0)
        return "0";
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(41);
    cout << vec << endl;

    return 0;
    for (int i = 0; i < INT_MAX; i++)
    {
        string num = to_string(i);
        int size = num.size();
        int combs = (int)powl(2, size) - 1;
        for (int j = 1; j <= combs; j++)
        {
            string bin = to_binary(j);
            int size_bin = bin.size();
            bin = string(size - size_bin, '0').append(bin);
            vector<int> primes;
            for (int k = 0; k < 10; k++)
            {
                string num_to_test = num;
                for (int d = 0; d < size; d++)
                    if (bin[d] == '1' && !(d == 0 && k == 0))
                        num_to_test[d] = k + '0';
                if (num_to_test == num)
                    continue;
                int x = atoi(num_to_test.c_str());
                if (is_prime(x))
                {
                    primes.push_back(x);
                }
            }
            if (primes.size() == 8)
            {
                cout << num << " - ";
                for (int &i : primes)
                    cout << i << ", ";
                cout << endl;
                cin.get();
            }
        }
    }
    return 0;
}