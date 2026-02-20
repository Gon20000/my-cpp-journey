#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, q{};
  cin >> n >> q;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end());
  
  while(q--) {
    ll x{}, y{};
    cin >> x >> y;

    cout << (upper_bound(arr.begin(), arr.end(), y) - lower_bound(arr.begin(), arr.end(), x)) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}

