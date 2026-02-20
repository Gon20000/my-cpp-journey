#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, m{};
  cin >> n >> m;

  vector<ll> arr(m);
  ll res{};
  for(ll& x : arr) {
    cin >> x;
    if(n % x == 0)
      ++res;
  }

  for(int i{}; i < m - 1; ++i) {
    for(int j{i + 1}; j < m; ++j) {
      res += (n % gcd(arr[i], arr[j]) == 0);
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

