#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
// no., child, edge_num
using node_t = tuple<int, int, int>;

void solve() {
  int n{};
  cin >> n;

  vector<bool> visited(n + 5, false);
  vector<bool> temp_visited(n + 5, false);
  vector<pair<int, int>> adj[n + 5];
  vector<int> cycle{};

  for (int i{}; i < n; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back({y, i + 1});
    adj[y].push_back({x, i + 1});
  }

  function<pair<bool, int>(int, int)> dfs_cycle =
      [&](int curr, int prev) -> pair<bool, int> {
    temp_visited[curr] = true;

    for (auto &[node, edge] : adj[curr]) {
      if (node == prev)
        continue;

      if (temp_visited[node]) {
        cycle.push_back(edge);
        visited[curr] = true;
        return {true, node};
      }

      auto [check, num] = dfs_cycle(node, curr);
      if (check) {
        cycle.push_back(edge);
        visited[curr] = true;
        if (curr == num)
          return {false, -1};

        return {true, num};
      }
    }

    return {false, -1};
  };

  dfs_cycle(1, -1);

  temp_visited.assign(n + 5, false);
  priority_queue<node_t, vector<node_t>, greater<node_t>> pq{};
  for (int i{1}; i <= n; ++i) {
    if (visited[i])
      continue;

    if (adj[i].size() == 1) {
      pq.push({1, i, adj[i][0].second});
      temp_visited[i] = true;
    }
  }

  ll score{}, now{1};
  vector<int> res{};
  while (!pq.empty()) {
    auto [_, curr, edge] = pq.top();
    pq.pop();

    // cout << curr << '\n';
    res.push_back(edge);

    for (auto &[node, _] : adj[curr]) {
      // cout << visited[node] << '\n';
      if (temp_visited[node] || visited[node])
        continue;

      for (auto &[node2, edge_num] : adj[node]) {
        if (temp_visited[node2])
          continue;

        temp_visited[node] = true;
        pq.push({adj[node].size(), node, edge_num});
      }
    }
  }

  for (int edge : res) {
    ++now;
    score += now;
  }

  for (int i{}; i < cycle.size() - 1; ++i) {
    score += now;
    ++now;
  }

  cout << score + now << '\n';
  for (int edge : res) {
    cout << edge << ' ';
  }

  for (int i{}; i < cycle.size() - 1; ++i) {
    cout << cycle[i] << ' ';
  }
  cout << cycle.back() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while (t--)
    solve();

  return 0;
}
