#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<int>>;

constexpr int N{200'001}, LOG{30};

sparse_t sparse(LOG, vector<int>(N, -1));

ll k_step(int node, ll steps, const sparse_t& sparse) {
  for(int i{}; i < LOG; ++i) {
    if(steps & 1)
      node = sparse[i][node];
    steps >>= 1;
  }

  return node;
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i) {
    int par{};
    cin >> par;

    sparse[0][i] = --par;
  }

  for(int i{1}; i < LOG; ++i) {
    for(int j{}; j < n; ++j) {
      if(sparse[i - 1][j] == -1)
        continue;

      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  while(q--) {
    int u{}, k{};
    cin >> u >> k;

    cout << k_step(--u, k, sparse) + 1 << '\n';
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


