#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll x{};
  cin >> x;

  vector<ll> vec{};
  for (ll i{2}; i * i <= x; ++i) {
    if (x % i == 0) {
      ll num{1};
      while (x % i == 0) {
        x /= i;
        num *= i;
      }

      vec.push_back(num);
    }
  }

  if (x > 1)
    vec.push_back(x);

  pair<ll, ll> res{LLONG_MAX, LLONG_MAX};
  int n{(int)vec.size()};
  int powed{1 << n};
  for (ll i{}; i < powed; ++i) {
    ll a{1}, b{1};
    for (int j{}; j < n; ++j) {
      if ((i >> j) & 1) {
        a *= vec[j];
      } else
        b *= vec[j];
    }
    if (max(a, b) < max(res.first, res.second))
      res = {a, b};
  }
  cout << res.first << ' ' << res.second << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while (t--)
    solve();

  return 0;
}
