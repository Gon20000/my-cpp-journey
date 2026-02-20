#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<int>> adj(n);

  for(int i{}; i < m; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
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


