#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n + 1, INT_MAX);
  arr[0] = 0;

  for(int i{1}; i <= n; ++i) {
    int x{i};
    while(x > 0) {
      arr[i] = min(arr[i], arr[i - (x % 10)] + 1);
      x /= 10;
    }
  }

  cout << arr.back() << '\n';
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

