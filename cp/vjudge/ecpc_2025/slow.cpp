#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const long double PI = acosl(-1.0);

void solve() {
  ll n, m, r;
  cin >> n >> m >> r;

  ll lo = 0, hi = 2e5; // upper bound on number of rounds
  while (lo < hi) {
    ll mid = (lo + hi + 1) / 2;

    // distance walked if you complete 'mid' full rounds
    long double walked = 2.0 * PI * (mid * r + m * mid * (mid - 1) / 2.0);

    if (walked <= n)
      lo = mid;
    else
      hi = mid - 1;
  }

  cout << r + lo * m << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

