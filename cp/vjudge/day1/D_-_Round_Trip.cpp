#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
  int n{}, m{};
  cin >> n >> m;
 
  vector<vector<int>> adj(n + 1);
  vector<int> prev(n + 1, -1);
  vector<int> dist(n + 1, INT_MAX);
  vector<bool> global_visited(n + 1, false);
 
  while (m--) {
    int x{}, y{};
    cin >> x >> y;
 
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int cycle{-1}, par{-1};
  // not a connected/complete graph so you need to check for all nodes
  for (int i{1}; i <= n; ++i) {
    if (global_visited[i] || adj[i].empty())
      continue;
 
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q{};
    q.push({i, -1});
    visited[i] = true;
    global_visited[i] = true;
    dist[i] = 0;
 
    while (!q.empty()) {
      auto [curr, last]{q.front()};
      q.pop();
 
      for (int node : adj[curr]) {
        if (node == last)
          continue;
 
        else if (visited[node]) {
          cycle = node;
          par = curr;
          break;
        }
 
        visited[node] = true;
        global_visited[node] = true;
        q.push({node, curr});
        prev[node] = curr;
        dist[node] = dist[curr] + 1;
      }
 
      if(cycle != -1)
        break;
    }
 
    if (cycle != -1)
      break;
 
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(prev.begin(), prev.end(), -1);
  }
 
  if (cycle == -1)
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> res1{cycle}, res2{};
 
    int dist1{dist[par]}, dist2{dist[cycle]};
    // dist2 will never be less as it's visited first in the bfs
    while (dist1 > dist2) {
      --dist1;
      res1.push_back(par);
      par = prev[par];
    }
 
    while (dist2 > dist1) {
      --dist2;
      res2.push_back(cycle);
      cycle = prev[cycle];
    }
 
 
    while (cycle != par && cycle != -1) {
      res1.push_back(par);
      res2.push_back(cycle);
 
      par = prev[par];
      cycle = prev[cycle];
    }
 
    if (cycle == par)
      res1.push_back(cycle);
 
    cout << res1.size() + res2.size() << '\n';
 
    for (int x : res1)
      cout << x << ' ';
 
    for (int i{(int)res2.size() - 1}; i > 0; --i) {
      cout << res2[i] << ' ';
    }
    cout << res2[0] << '\n';
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
