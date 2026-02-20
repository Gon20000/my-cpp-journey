#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<int> dp(n);
  vector<bool> visited(n, false);
  vector<vector<int>> adj(n);
  while (m--) {
    int x{}, y{};
    cin >> x >> y;
    adj[--x].push_back(--y);
  }

  std::function<void(int)> dfs = [&](int ind) -> void {
    int longest{0};
    for (int node : adj[ind]) {
      if (!visited[node])
        dfs(node);
      longest = max(longest, dp[node] + 1);
    }

    dp[ind] = longest;
    visited[ind] = true;
  };

  int res{};
  for (int i{}; i < n; ++i) {
    if (!visited[i])
      dfs(i);

    res = max(res, dp[i]);
  }

  cout << res << '\n';
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
