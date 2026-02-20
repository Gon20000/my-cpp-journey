#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<int> adj[200'001];
vector<int> sizes(200'001, 1);
int n{};

void dfs_size(int curr, int prev) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs_size(node, curr);
    sizes[curr] += sizes[node];
  }
}

int centroid(int curr, int prev) {
  for(int node: adj[curr]) {
    if(node == prev)
      continue;

    if(sizes[node] > n / 2)
      return centroid(node, curr);
  }

  return curr;
}

void solve() {
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs_size(0, -1);
  cout << centroid(0, -1) + 1 << '\n';
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

