#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

constexpr int N{100001};
vector<vector<int>> adj(N);
vector<ll> vals(N), res(N);
int idx{};

indexed_set dfs(int curr, int prev) {
  indexed_set s{};
  s.insert({vals[curr], ++idx});

  for (int node : adj[curr]) {
    if (node == prev)
      continue;

    indexed_set s2{dfs(node, curr)};
    if (s2.size() > s.size())
      swap(s2, s);

    for(auto& x : s2) {
      s.insert(x);
    }
  }

  res[curr] = s.size() - s.order_of_key({vals[curr] + 1, -1});
  return s;
}

void solve() {
  int n{};
  cin >> n;

  for (int i{1}; i <= n; ++i)
    cin >> vals[i];

  for (int i{2}; i <= n; ++i) {
    int node{};
    cin >> node;

    adj[i].push_back(node);
    adj[node].push_back(i);
  }

  dfs(1, -1);

  for(int i{1}; i <= n; ++i)
    cout << res[i] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int t{1};
  // cin >> t;

  while (t--)
    solve();

  return 0;
}
