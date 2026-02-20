#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// n / 2 * (2a + (n - 1)m)
ld pi{acos(-1)};
void solve() {
  ll n{}, m{}, a{};
  cin >> n >> m >> a;

  ll l{0}, r{static_cast<ll>(1e9)};
  while (l < r) {
    ll mid{l + ((r - l) / 2)};
    ld curr{mid / 2.0 * (2 * a + (mid - 1) * m)};

    if (2 * pi * curr <= n)
      l = mid + 1;
    else
      r = mid;
  }

  cout << a + m * (r - 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while (t--)
    solve();

  return 0;
}
