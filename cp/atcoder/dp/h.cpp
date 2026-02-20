#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr ll MOD{static_cast<ll>(1e9) + 7};
void add(ll& x, ll& y) {
  x += y;
  x %= MOD;
}

void solve() {
  int h{}, w{};
  cin >> h >> w;

  vector<vector<bool>> check (h, vector<bool>(w, true));
  vector<vector<ll>> dp(h, vector<ll>(w));
  ++dp[0][0];

  for(int i{}; i < h; ++i) {
    for(int j{}; j < w; ++j) {
      char x{};
      cin >> x;

      if(x == '#')
        check[i][j] = false;
    }
  }

  for(int i{}; i < h; ++i) {
    for(int j{}; j < w; ++j) {
      if(!check[i][j])
        continue;
      
      if(i > 0)
        add(dp[i][j], dp[i - 1][j]);
      if(j > 0)
        add(dp[i][j], dp[i][j - 1]);
      // cout << dp[i][j] << ' ';
    }
    // cout <<'\n';
  }

  cout << dp[h - 1][w - 1] << '\n';
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

