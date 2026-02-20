#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, x{};
  cin >> n >> x;

  ll res{};
  map<ll, ll> mp{};
  ++mp[0];

  vector<ll> pref(n + 1);
  for(ll i{1}; i <= n; ++i) {
    cin >> pref[i];
    pref[i] += pref[i - 1];

    res += mp[pref[i] - x];
    // cout << pref[i] << ' ' << res << '\n';
    ++mp[pref[i]];
  }
    

  // for(auto [x, y] : mp)
  //   cout << x << ' ' << y << '\n';
  cout << res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}

