#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

pair<ll, ll> check(ll num, ll odd) {
  for(ll i{2}; i != odd && i * i <= num; ++i) {
    if(num % i || (num / i == i) || (num / i == odd))
      continue;

    return {i, num / i};
  }

  return {-1, -1};
}

void solve() {
  ll x{};
  cin >> x;

  vector<ll> res(3, -1);
  for(ll i{2}; i * i <= x; ++i) {
    if(x % i)
      continue;

    pair<ll, ll> ans{check(x / i, i)};
    if(ans.first != -1) {
      cout << "YES\n";
      cout << i << ' ' << ans.first << ' ' << ans.second << '\n';
      return;
    }
  }

  cout << "NO\n";
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

