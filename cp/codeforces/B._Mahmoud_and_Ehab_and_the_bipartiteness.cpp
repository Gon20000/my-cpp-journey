#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{100'000};
ll red{}, blue{}, res{};
vector<vector<int>> adj(N);

void dfs(int curr, int prev, bool isRed = true) {
  if(isRed) {
    res += max(blue - 1, 0ll);
    ++red;
  }
  else {
    res += max(red - 1, 0ll);
    ++blue;
  }

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs(node, curr, !isRed);
  }
}

void solve() {
  res = 0;
  int n{};
  cin >> n;
  while(--n) {
    int x{}, y{};
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs(0, -1);
  cout << res << '\n';
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

