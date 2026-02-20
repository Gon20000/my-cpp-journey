#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200'001};
vector<int> adj[N];
bitset<N> is_removed{};
int sizes[N];
vector<int> cnt(N);
ll k{}, res{}, maxDepth{};

int get_size(int curr, int prev) {
  sizes[curr] = 1;

  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    sizes[curr] += get_size(node, curr);
  }

  return sizes[curr];
}

int get_centroid(int curr, int prev, int n) {
  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    if(sizes[node] > n / 2)
      return get_centroid(node, curr, n);
  }

  return curr;
}

void setAncestors(int curr, int prev, bool filling, ll depth = 1)  {
  if(depth > k)
    return;

  maxDepth = max(maxDepth, depth);
  if(!filling)
    res += cnt[k - depth];
  else
    ++cnt[depth];

  for(int node : adj[curr]) {
    if(node == prev || is_removed[node])
      continue;

    setAncestors(node, curr, filling, depth + 1);
  }
}

void centroid_decomp(int curr) {
  int centroid{get_centroid(curr, -1, get_size(curr, -1))};

  is_removed[centroid] = true;

  maxDepth = 0;
  ++cnt[0];
  for(int node : adj[centroid]) {
    if(is_removed[node])
      continue;

    setAncestors(node, -1, false);
    setAncestors(node, -1, true);
  }
  cnt.assign(maxDepth + 1, 0);


  for(int node : adj[centroid]) {
    if(is_removed[node])
      continue;

    centroid_decomp(node);
  }
}

void solve() {
  int n{};
  cin >> n >> k;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  centroid_decomp(0);

  cout << res << '\n';
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

