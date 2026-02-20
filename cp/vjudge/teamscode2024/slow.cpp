#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  ll res{}, sum{};
  for(ll& x : arr) {
    cin >> x;
    res += x;
    sum += x;
  }

  for(int i{}; i < n; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      ll curr{sum - arr[i] - arr[j] + (arr[i] ^ arr[j])};
      res = min(res, curr);
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

