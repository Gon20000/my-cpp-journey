#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  ll h{}, res{};
  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
    h = max(h, x);
  }

  for(ll x : arr) {
    if(x == h)
      ++res;
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

