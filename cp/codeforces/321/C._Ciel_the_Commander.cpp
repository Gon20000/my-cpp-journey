#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{100'001};

vector<int> sizes(N);
vector<int> adj[N], ancestors[N];
char chars[N];
vector<bool> is_removed(N, false);

int getSize(int curr, int prev) {
  sizes[curr] = 1;

  for (int node : adj[curr]) {
    if (node == prev || is_removed[node])
      continue;

    sizes[curr] += getSize(node, curr);
  }

  return sizes[curr];
}

int getCentroid(int curr, int prev, int n) {
  for (int node : adj[curr]) {
    if (node == prev || is_removed[node])
      continue;

    if (sizes[node] > n / 2)
      return getCentroid(node, curr, n);
  }

  return curr;
}

void setAncestors(int curr, int prev, int centroid) {
  for (int node : adj[curr]) {
    if (node == prev || is_removed[node])
      continue;

    ancestors[node].push_back(centroid);
    setAncestors(node, curr, centroid);
  }
}

void centroid_decomp(int curr = 0) {
  // is_removed handles everything imo
  int centroid{getCentroid(curr, -1, getSize(curr, -1))};

  is_removed[centroid] = true;
  setAncestors(centroid, -1, centroid);

  for (int node : adj[centroid]) {
    if (!is_removed[node])
      centroid_decomp(node);
  }
}

void solve() {
  int n{};
  cin >> n;

  for (int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  centroid_decomp();

  for(int i{}; i < n; ++i) {
    if(ancestors[i].size() >= 26) {
      cout << "Impossible!\n";
      return;
    }

    chars[i] = 'A' + ancestors[i].size();
  }
  
  for(int i{}; i < n - 1; ++i) {
    cout << chars[i] << ' ';
  }
  cout << chars[n - 1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while (t--)
    solve();

  return 0;
}
