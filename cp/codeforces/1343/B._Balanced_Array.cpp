#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  if (n % 4 != 0) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  int last{};
  for (int i{2}; i <= n; i += 2) {
    cout << i << ' ';
    last += i;
  }

  for(int i{1}; i < n - 1; i += 2) {
    cout << i << ' ';
    last -= i;
  }

  cout << last << '\n';
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
