#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  set<pair<ll, ll>> s{};

  vector<ll> res(16);
  for(int i{}; i < 16; ++i) {
    ll x{};
    cin >> x;
    s.insert({x, i});
  }

  ll start{1}, cnt{0};
  
  ll curr{0};
  res[s.begin()->second] = 0;
  for(auto it{++s.begin()}; it != s.end(); ++it) {
    if(curr == 0) {
      start *= 2;
      ++cnt;
      curr = start;
    }

    --curr;
    res[it->second] = cnt;
  }

  for(int i{}; i < 15; ++i)
    cout << res[i] << ' ';
  cout << res.back() << '\n';
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

