#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x{};
  cin >> x;

  while (x != 1) {
    cout << x << ' ';

    x = (x % 2) ? 3 * x + 1 : x / 2;
  }
  
  cout << 1;
  return 0;
}
