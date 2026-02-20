#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{}, k{};
  cin >> n >> m >> k;

  vector<int> res{};
  for(int i{n}; i > m; --i) {
    res.push_back(i);
  }

  for(int i{1}; i <= m; ++i)
    res.push_back(i);

  for(int i{}; i < n - 1; ++i)
    cout << res[i] << ' ';
  cout << res.back() << '\n';
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

