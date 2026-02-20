#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using edge_t = tuple<ll, int, int>;

template <typename T> class DSU {
private:
  vector<int> m_p, m_size;

public:
  DSU(int n) : m_p(n), m_size(n, 1) {
    for (int i{}; i < n; ++i)
      m_p[i] = i;
  }

  T get(int x) { return m_p[x] = (m_p[x] == x ? x : get(m_p[x])); }

  void unify(int x, int y) {
    int x_root{get(x)}, y_root{get(y)};
    if (x_root == y_root)
      return;

    if (m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;
  }

  bool connected(int x, int y) { return get(x) == get(y); }
};

constexpr int N{300001}, LOG{20};
// w, u, v
vector<edge_t> edges{};
vector<vector<pair<int, ll>>> adj(N);
vector<vector<ll>> sparse(LOG, vector<ll>(N));
vector<vector<int>> p(LOG, vector<int>(N, -1));
vector<int> depth(N);

void dfs_init(int curr, int prev) {
  for (auto &[node, w] : adj[curr]) {
    if (node == prev)
      continue;

    p[0][node] = curr;
    sparse[0][node] = w;
    depth[node] = depth[curr] + 1;
    dfs_init(node, curr);
  }
}

void sparse_init(int n) {
  for (int i{1}; i < LOG; ++i) {
    for (int j{}; j < n; ++j) {
      int par{p[i - 1][j]};
      if (par != -1) {
        p[i][j] = p[i - 1][par];
        sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][par]);
      }
    }
  }
}

pair<int, ll> k_step(int curr, int k, ll wmax) {
  ll w{};
  for (int step{}; k > 0 && curr != -1; ++step, k >>= 1) {
    if (k & 1) {
      if (sparse[step][curr] < wmax)
        w = max(w, sparse[step][curr]);
      curr = p[step][curr];
    }
  }

  return {curr, w};
}

ll max_edge(int x, int y, ll wmax) {
  if (depth[x] < depth[y])
    swap(x, y);

  pair<int, ll> init_step{k_step(x, depth[x] - depth[y], wmax)};
  x = init_step.first;
  ll res{init_step.second};

  if (x == y)
    return res;

  for (int i{LOG - 1}; i >= 0; --i) {
    if (p[i][x] == p[i][y])
      continue;

    if (sparse[i][x] < wmax)
      res = max(res, sparse[i][x]);
    if (sparse[i][y] < wmax)
      res = max(res, sparse[i][y]);

    x = p[i][x];
    y = p[i][y];
  }

  if (sparse[0][y] < wmax)
    res = max(res, sparse[0][y]);
  if (sparse[0][x] < wmax)
    res = max(res, sparse[0][x]);
  return res;
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<edge_t> non_MST{};
  priority_queue<edge_t, vector<edge_t>, greater<edge_t>> pq{};
  edges.resize(m);
  for (auto &[w, u, v] : edges) {
    cin >> u >> v >> w;
    --u;
    --v;
    pq.push({w, u, v});
  }

  int root{-1};
  ll res{LLONG_MAX}, mst_weight{};
  DSU<int> dsu(n);
  while (!pq.empty()) {
    auto [w, u, v] = pq.top();
    pq.pop();
    if (dsu.connected(u, v)) {
      non_MST.emplace_back(w, u, v);
      continue;
    }

    mst_weight += w;
    root = u;
    dsu.unify(u, v);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs_init(root, -1);
  sparse_init(n);

  for (auto &[w, u, v] : non_MST) {
    ll cycle_max{max_edge(u, v, w)};

    res = min(res, mst_weight - cycle_max + w);
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
