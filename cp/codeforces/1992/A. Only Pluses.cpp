#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  vector<ll> arr(3);
  for(ll& x : arr)
    cin >> x;

  for(int i{}; i < 5; ++i) {
    sort(arr.begin(), arr.end());
    ++arr[0];
  }

  ll res{1};
  for(ll x : arr)
    res *= x;

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

