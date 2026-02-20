#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;
  
  vector<ll> in(n + 1);
  vector<vector<int>> adj(n + 1);

  while(m--) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    ++in[y];
  }

  vector<int> res{};
  queue<int> q{};
  for(int i{1}; i <= n; ++i) {
    if(in[i] == 0)
      q.push(i);
  } 

  while(!q.empty()) {
    int curr{q.front()}; q.pop();

    res.push_back(curr);
    for(int node : adj[curr]) {
      if(--in[node] == 0)
        q.push(node);
    }
  }

  if(res.size() != n) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  for(int i{}; i < n - 1; ++i) 
    cout << res[i] << ' ';
  cout << res.back() << '\n';
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

