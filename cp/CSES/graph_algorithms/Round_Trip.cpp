#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{100001};
vector<int> parent(N, -1);
vector<vector<int>> adj(N);

int cycle{-1}, par{-1};
bool dfs(int curr) {
  for(int node : adj[curr]) {
    if(parent[curr] == node)
      continue;

    else if(parent[node] != -1) {
      cycle = node;
      par = curr;
      return true;
    }

    parent[node] = curr;
    if(dfs(node))
      return true;
  }

  return false;
}

void print_cycle() {
  vector<int> res{cycle};
  while(par != cycle && par > 0) {
    res.push_back(par);
    par = parent[par];
  }
  
  cout << res.size() + 1 << '\n';
  for(int x : res)
    cout << x << ' ';
  cout << cycle << '\n';
}

void solve() {
  int n, m{};
  cin >> n >> m;

  while(m--) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i{1}; i <= n; ++i) {
    if(parent[i] != -1)
      continue;

    parent[i] = 0;
    if(dfs(i)) {
      break;
    }
  }

  if(cycle == -1)
    cout << "IMPOSSIBLE\n";
  else {
    print_cycle();
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

