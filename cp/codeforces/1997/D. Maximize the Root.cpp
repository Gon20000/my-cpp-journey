#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200'001};

vector<int> adj[N];
ll vals[N];
vector<ll> low(N, INT_MAX);

void dfs(int curr, int prev, int depth = 1) {
  ll lowest{LLONG_MAX};
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs(node, curr);
    low[curr] = min({vals[node], low[curr], low[node]});
    lowest = min(lowest, vals[node]);
  }

  if(lowest != LLONG_MAX)
    vals[curr] += lowest / depth;
}

void solve() {
  int n{};
  cin >> n;

  for(int i{1}; i <= n; ++i) {
    cin >> vals[i];
    adj[i].clear();
    low[i] = INT_MAX;
  }

  for(int i{2}; i <= n; ++i) {
    int x{};
    cin >> x;

    adj[x].push_back(i);
    adj[i].push_back(x);
  }

  dfs(1, -1);
  cout << vals[1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

