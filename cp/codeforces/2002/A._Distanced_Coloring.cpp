#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = int;
using ld = long double;

void solve() {
  ll n{}, m{}, k{};
  cin >> n >> m >> k;


  cout << min(n, k) * min(m, k) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while (t--)
    solve();

  return 0;
}
