#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll randNum(ll x, ll y) { return x + rand() % (y - x + 1); }

int main(int argc, char **argv) {
  srand(atoi(argv[1]));
  ll t{randNum(1, 100)};
  cout << t << '\n';

  while (t--) {
    ll n{randNum(1, static_cast<ll>(1e9))};
    ll m{randNum(1, static_cast<ll>(1e4))};
    ll r{randNum(1, static_cast<ll>(1e4))};

    cout << n << ' ' << m << ' ' << r << '\n';
  }

  return 0;
}
