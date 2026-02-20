#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr ll inf{static_cast<ll>(1e9) + 7};
void solve() {
  int n{};
  cin >> n;

  map<ll, ll> mp{};

  while(n--) {
    ll x{};
    cin >> x;

    ++mp[x];
  }

  ll res{};
  for(auto it{mp.begin()}; it != mp.end(); ++it) {
    if(it->second == 0)
      continue;

    ++res;
    ll curr{it->first};
    while(curr <= inf) {
      if(mp.count(curr))
        mp[curr] = 0;
      curr *= 2;
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

