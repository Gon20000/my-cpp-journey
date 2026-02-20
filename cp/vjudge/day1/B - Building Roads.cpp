#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<bool> visited(n);
  while (m--) {
    int x{}, y{};
    cin >> x >> y;
    --x;
    --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  function<void(int)> dfs = [&](int curr) -> void {
    visited[curr] = true;

    for (int node : adj[curr]) {
      if (visited[node])
        continue;

      dfs(node);
    }
  };

  dfs(0);
  int prev{}, res{};
  vector<pair<int, int>> roads{};

  for (int i{1}; i < n; ++i) {
    if (visited[i])
      continue;

    ++res;
    roads.emplace_back(prev + 1, i + 1);
    prev = i;
    dfs(i);
  }

  cout << res << '\n';
  for(int i{}; i < res; ++i) {
    cout << roads[i].first << ' ' << roads[i].second << '\n';
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
