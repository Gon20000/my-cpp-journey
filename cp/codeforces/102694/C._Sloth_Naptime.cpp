#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<int>>;

constexpr int N{300'001}, LOG{19};

vector<int> adj[N];
sparse_t sparse(LOG, vector<int>(N, -1));
int depth[N];

void dfs_init(int curr, int prev, int dep = 0) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    sparse[0][node] = curr;
    dfs_init(node, curr, dep + 1);
  }

  depth[curr] = dep;
}

int k_step(int node, int steps, const sparse_t& sparse) {
  for(int i{}; i < LOG; ++i) {
    if(steps & 1)
      node = sparse[i][node];
    steps >>= 1;
  }

  return node;
}

int lca(int x, int y, const sparse_t& sparse) {
  if(depth[x] > depth[y])
    swap(y, x);

  if(depth[x] != depth[y]) 
    y = k_step(y, depth[y] - depth[x], sparse);

  if(x == y)
    return x;

  for(int i{LOG - 1}; i >= 0; --i) {
    if(sparse[i][x] == sparse[i][y])
      continue;

    x = sparse[i][x];
    y = sparse[i][y];
  }

  return sparse[0][x];
}

void solve() {
  int n{}, q{};
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs_init(0, -1);

  for(int i{1}; i < LOG; ++i) {
    for(int j{1}; j < n; ++j) {
      if(sparse[i - 1][j] == -1)
        continue;

      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  cin >> q;
  while(q--) {
    int a{}, b{}, c{};
    cin >> a >> b >> c;

    int par{lca(--a, --b, sparse)};

    int diff1{min(c, depth[a] - depth[par])};
    a = k_step(a, diff1, sparse);
    c -= diff1;

    if(a != par) {
      cout << a + 1 << '\n';
      continue;
    }
    int diff2{max(0, depth[b] - depth[par] - c)};
    cout << k_step(b, diff2, sparse) + 1 << '\n';
    
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


