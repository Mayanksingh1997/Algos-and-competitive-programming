(1)	Huge nth Fibonacci Number modulo m
In this problem, the given number n may be really huge. Hence an algorithm looping for n iterations will not fit into one second for sure. Therefore we need to avoid such a loop.
To get an idea how to solve this problem without going through all F(i) for i from 0 to n, let’s see what happens when m is small — say, m = 2 or m = 3.

 
Take a detailed look at this table. Do you see? Both these sequences are periodic! For m = 2, the period is 011 and has length 3, while for m = 3 the period is 01120221 and has length 8. Therefore, to compute, say,
F(2015) mod 3 we just need to find the remainder of 2015 when divided by 8. Since 2015 = 251·8+7, we conclude that F(2015) mod 3 = F 7 mod 3 = 1.
This is true in general: for any integer m ≥ 2, the sequence F(n) mod m is periodic. The period always starts with 01 and is known as Pisano period.
Algo-------------------------------------------------------------------



#include <iostream>
using namespace std;
typedef long long int ll;
ll get_pisano_period(ll m) {
    ll a = 0, b = 1, c = a + b;
    for (ll i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

ll get_fibonacci_huge(ll n, ll m) {
    ll remainder = n % get_pisano_period(m);

    ll first = 0;
    ll second = 1;

    ll res = remainder;

    for (ll i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main(void) {
    ll n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
