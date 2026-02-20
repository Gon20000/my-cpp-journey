#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s{};
  cin >> s;

  int sz{}, max_sz{};
  for (char x : s) {
    if (x == 'L')
      ++sz;
    else {
      max_sz = max(max_sz, sz);
      sz = 0;
    }
  }
  max_sz = max(max_sz, sz);

  cout << max_sz + 1 << '\n';
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
