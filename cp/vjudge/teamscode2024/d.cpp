#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{100'001};
constexpr ll mod{static_cast<ll>(1e9) + 7};
void solve() {
  int n{};
  cin >> n;

  ll res{1};
  vector<bool> visited(2 * N + 1);

  ll l{1}, r{};

  for(int i{}; i < n; ++i) {
    ll t{}, v{};
    cin >> t >> v;

    if(i == 0) {
      if(t == 1)
        r = v - l;
      else if(t == 2) 
        r = l + v;
      else
        r = v;
    }
    else {
      if(l == r) {
        res = (res * 2) % mod;
      }
    }

    visited[l++] = visited[r++] = true;
    while(visited[l]) ++l;
    while(visited[r]) ++r;
  }
  cout << res << '\n';
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

