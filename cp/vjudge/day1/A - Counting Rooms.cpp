#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<bool>> check(n, vector<bool>(m, false));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i{}; i < n; ++i) {
    for (int j{}; j < m; ++j) {
      char x{};
      cin >> x;

      check[i][j] = (x == '.');
    }
  }

  std::function<void(int, int)> dfs = [&](int i, int j) -> void {
    if (i < 0 || j < 0 || i >= n || j >= m || !check[i][j])
      return;

    visited[i][j] = true;
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};

    for (int k{}; k < 4; ++k) {
      int i2{i + dx[k]}, j2{j + dy[k]};
      if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || visited[i + dx[k]][j + dy[k]])
          continue;

      dfs(i + dx[k], j + dy[k]);
    }
  };

  int res{};
  for (int i{}; i < n; ++i) {
    for (int j{}; j < m; ++j) {
      if (!check[i][j] || visited[i][j])
        continue;
      ++res;
      dfs(i, j);
    }
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
