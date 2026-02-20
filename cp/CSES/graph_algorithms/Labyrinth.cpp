#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<bool>> check(n, vector<bool>(m, false));
  vector<vector<char>> prev(n, vector<char>(m));
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  pair<int, int> start{}, end{};

  for (int i{}; i < n; ++i) {
    for (int j{}; j < m; ++j) {
      char x{};
      cin >> x;

      if (x == '#')
        continue;

      check[i][j] = true;
      if (x == 'A')
        start = {i, j};
      else if (x == 'B')
        end = {i, j};
    }
  }

  // NOTE for the future: BFS guarantees that the first time you visit a node, you’ve found the shortest path to it.
  // so you can omit the third parameter in the tuple!
  prev[start.first][start.second] = 'x';
  dist[start.first][start.second] = 0;
  deque<tuple<int, int, int>> q{};
  q.push_back({start.first, start.second, 0});

  while (!q.empty()) {
    auto curr{q.front()};
    q.pop_front();

    auto work = [&](int i, int j, char letter) -> void {
      if (i < 0 || j < 0 || i >= n || j >= m || !check[i][j])
        return;

      // correcting mistakes: Don't forget the equal
      if (dist[i][j] <= get<2>(curr) + 1)
        return;

      dist[i][j] = get<2>(curr) + 1;
      prev[i][j] = letter;
      if (!(i == end.first && j == end.second))
        q.push_back({i, j, dist[i][j]});
    };

    work(get<0>(curr) + 1, get<1>(curr), 'D');
    work(get<0>(curr) - 1, get<1>(curr), 'U');
    work(get<0>(curr), get<1>(curr) + 1, 'R');
    work(get<0>(curr), get<1>(curr) - 1, 'L');
  }

  if (dist[end.first][end.second] == INT_MAX)
    cout << "NO\n";
  else {
    cout << "YES\n" << dist[end.first][end.second] << '\n';
    int i{end.first}, j{end.second};
    string res{};
    while(prev[i][j] != 'x') {
      // correcting mistakes: Add to the end of the string and not the beginning, O(n) vs O(1)
      res += prev[i][j];
      if(prev[i][j] == 'D')
        --i;
      else if(prev[i][j] == 'U')
        ++i;
      else if(prev[i][j] == 'R')
        --j;
      else if(prev[i][j] == 'L')
        ++j;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
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
