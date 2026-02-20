#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
// weight, node
using node_t = pair<ll, int>;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<node_t>> adj(n + 1);
  // INT_MAX would be too small
  vector<ll> dist(n + 1, LLONG_MAX);
  vector<int> prev(n + 1, -1);
  auto check = [](node_t& x, node_t& y) -> bool {
    return x.first > y.first;
  };
  priority_queue<node_t, vector<node_t>, decltype(check)> pq(check);

  while(m--) {
    int x{}, y{};
    ll w{};
    cin >> x >> y >> w;

    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
  }

  dist[1] = 0;
  pq.push({0, 1});

  while(!pq.empty()) {
    auto [w, curr] = pq.top(); pq.pop();

    for(auto [w2, node] : adj[curr]) {
      if(w + w2 >= dist[node])
        continue;

      prev[node] = curr;
      dist[node] = w + w2;
      pq.push({dist[node], node});
    }
  }

  if(prev[n] == -1) {
    cout << -1;
    return;
  }

  vector<int> res{};
  int curr{n};
  while(curr != -1) {
    res.push_back(curr);
    curr = prev[curr];
  }

  for(int i{(int)res.size() - 1}; i > 0; --i)
    cout << res[i] << ' ';
  cout << res[0] << '\n';
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

