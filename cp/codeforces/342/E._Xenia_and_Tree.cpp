#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{100'001};

vector<int> sizes(N), min_dist(N, N * 2);
vector<int> adj[N];
vector<pair<int, int>> ancestors[N];
vector<bool> is_removed(N, false);

int getSize(int curr, int prev) {
  sizes[curr] = 1;

  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    sizes[curr] += getSize(node, curr);
  }
  
  return sizes[curr];
}

int getCentroid(int curr, int prev, int n) {
  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    if(sizes[node] > n / 2)
      return getCentroid(node, curr, n);
  }

  return curr;
}

void get_dists(int curr, int prev, int centroid, int depth = 0) {
  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    get_dists(node, curr, centroid, depth + 1);
  }

  ancestors[curr].push_back({centroid, depth});
}

void centroid_decomp(int curr = 0) {
  // is_removed handles everything imo
  int centroid{getCentroid(curr, -1, getSize(curr, -1))};

  is_removed[centroid] = true;
  get_dists(centroid, -1, centroid);

  for(int node : adj[centroid]) {
    if(!is_removed[node])
      centroid_decomp(node);
  }
}

void paint(int curr) {
  for(auto& [centroid, dist] : ancestors[curr]) {
    min_dist[centroid] = min(min_dist[centroid], dist);
  }
}

ll query(int curr) {
  int res{INT_MAX};
  for(auto& [centroid, dist] : ancestors[curr]) {
    res = min(res, dist + min_dist[centroid]);
  }

  return res;
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  centroid_decomp();
  paint(0);
  while(q--) {
    int t{}, u{};
    cin >> t >> u;
    --u;

    if(t == 1) {
      paint(u);
    }
    else {
      cout << query(u) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

