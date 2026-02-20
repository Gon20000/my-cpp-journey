#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int num(int x, int y) { return x + (rand() % (y - x + 1)); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));

  int t{num(1, 10)};

  cout << t << '\n';
  while (t--)
    for (int i{}; i < 2; ++i) {
      ll x{num(1, 100)};
      cout << x << ' ' << num(x, 100) << '\n';
    }

  return 0;
}
