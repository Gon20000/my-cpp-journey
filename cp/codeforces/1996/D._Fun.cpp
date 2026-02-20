#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, mx{};
  cin >> n >> mx;

  ll res{};
  for(ll a{1}; a < mx - 1; ++a) {
    for(ll b{1}; a * b < n && a + b < mx; ++b) {
      ll c{min(mx - a - b, (n - a * b) / (a + b))};
      res += max(0ll, c);
    }
  }

  cout << res << '\n';
 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

