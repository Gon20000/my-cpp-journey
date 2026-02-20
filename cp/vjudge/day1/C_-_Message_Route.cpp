#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;
  
  vector<vector<int>> adj(n + 1);
  vector<int> prev(n + 1, -1);
  vector<bool> visited(n + 1, false);

  while(m--) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  queue<int> q{{1}};
  visited[1] = true;

  while(!q.empty()) {
    int curr{q.front()}; q.pop();

    for(int node : adj[curr]) {
      if(visited[node])
        continue;

      visited[node] = true;
      q.push(node);
      prev[node] = curr;
    }
  }

  if(!visited[n])
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> res{};
    int curr{n};
    while(curr != -1) {
      res.push_back(curr);
      curr = prev[curr];
    }

    cout << res.size() << '\n';
    for(int i{(int)res.size() - 1}; i > 0; --i) {
      cout << res[i] << ' ';
    }
    cout << res[0] << '\n';
  }
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

