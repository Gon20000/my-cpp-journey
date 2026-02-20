#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{};
  cin >> n;

  ll res{};
  map<ll, ll> mp{};
  ++mp[0];

  vector<ll> pref(n + 1);
  for(ll i{1}; i <= n; ++i) {
    cin >> pref[i];
    pref[i] = (((pref[i] % n) + n) % n + pref[i - 1]) % n; // negatives almost ruined my sol!!!
    res += mp[pref[i]]++;
  }

  cout << res << '\n';
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

/*
5
3 1 2 7 4
3 1 2 2 4
3 4 1 3 2
*/
