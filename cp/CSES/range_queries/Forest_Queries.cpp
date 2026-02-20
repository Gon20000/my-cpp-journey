#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<int>> pref(n, vector<int>(n, 0));
  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      char x{};
      cin >> x;

      pref[i][j] = x != '.';
      if (j > 0)
        pref[i][j] += pref[i][j - 1];
    }
  }

  for (int i{1}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      pref[i][j] += pref[i - 1][j];
    }
  }

  while(m--) {
    int x1{}, y1{}, x2{}, y2{};
    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;

    int res{pref[x2][y2]};
    if(x1 > 0)
      res -= pref[x1 - 1][y2];
    if(y1 > 0)
      res -= pref[x2][y1 - 1];

    if(x1 > 0 && y1 > 0)
      res += pref[x1 - 1][y1 - 1];

    cout << res << '\n';
  }
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
