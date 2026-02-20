#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  ll res{LLONG_MAX};
  for(ll i{1}; i <= k && i * i <= n; ++i) {
    if(n % i)
      continue;

    res = min(res, n / i);
    if(n / i <= k)
      res = min(res, i);
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

