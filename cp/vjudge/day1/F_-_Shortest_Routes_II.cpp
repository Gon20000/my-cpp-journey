#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{}, q{};
  cin >> n >> m >> q;

  // floyd warshall
  vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
  while (m--) {
    int x{}, y{};
    ll w{};
    cin >> x >> y >> w;

    if (dp[--x][--y] > w) {
      dp[x][y] = w;
      dp[y][x] = w;
    }
  }

  for (int i{}; i < n; ++i)
    dp[i][i] = 0;

  // notice k being the outer loop
  for (int k{}; k < n; ++k) {
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        if (max(dp[i][k], dp[j][k]) == LLONG_MAX)
          continue;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k]);
      }
    }
  }

  while (q--) {
    int x{}, y{};
    cin >> x >> y;

    ll ans{dp[--x][--y]};
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while (t--)
    solve();

  return 0;
}
