#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using tree_t = vector<vector<int>>;

pair<int, int> dfs(int curr, int prev, const tree_t &adj) {
  pair<int, int> res{curr, 0};
  for (int node : adj[curr]) {
    if (node == prev)
      continue;

    pair<int, int> currPair(dfs(node, curr, adj));
    ++currPair.second;
    if (currPair.second > res.second)
      res = currPair;
  }

  return res;
}

void solve() {
  int n{};
  cin >> n;

  tree_t adj(n);

  while (--n) {
    int x{}, y{};
    cin >> x >> y;
    --x;
    --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  pair<int, int> first(dfs(0, -1, adj));
  pair<int, int> second(dfs(first.first, -1, adj));

  cout << 3 * second.second << '\n';
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
