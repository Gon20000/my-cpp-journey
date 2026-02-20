#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, W{};
  cin >> n >> W;

  map<ll, ll> mp{};
  mp.insert({0, W});

  while(n--) {
    ll w1{}, v1{};
    cin >> w1 >> v1;

    vector<pair<ll, ll>> additions{};

    for(auto& [v2, w2] : mp) {
      // w2 is the remaining weight, so w2 - w1 has to be >= 0
      if(w1 > w2)
        continue;

      additions.emplace_back(v1 + v2, w2 - w1);
    }

    for(pair<ll, ll>& p : additions) {
      if(mp.count(p.first))
        mp[p.first] = max(mp[p.first], p.second);
      else
       mp[p.first] = p.second;
    }
  }

  cout << mp.rbegin()->first << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

