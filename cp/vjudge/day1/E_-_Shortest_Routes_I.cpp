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
  vector<ll> dist(n + 1, LLONG_MAX);
  auto check = [](node_t& x, node_t& y) -> bool {
    return x.first > y.first;
  };
  priority_queue<node_t, vector<node_t>, decltype(check)> pq(check);

  while(m--) {
    int x{}, y{};
    ll w{};
    cin >> x >> y >> w;

    adj[x].push_back({w, y});
  }

  dist[1] = 0;
  pq.push({0, 1});

  while(!pq.empty()) {
    auto [w, curr] = pq.top(); pq.pop();
    // THIS LINE IS VERY VERY IMPORTANT (TLE)
    //  otherwise you'll revisit nodes with outdated longer paths
    // aka if a node gets updated and reinserted in the priority queue, 
    // the earlier entry with the higher cost can still be in the queue and needs to be ignored.
    if(w > dist[curr])
      continue;

    for(auto [w2, node] : adj[curr]) {
      if(w + w2 >= dist[node])
        continue;

      dist[node] = w + w2;
      pq.push({dist[node], node});
    }
  }

  for(int i{1}; i < n; ++i)
    cout << dist[i] << ' ';
  cout << dist[n] << '\n';
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

