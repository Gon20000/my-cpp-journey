#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);

  ll curr{1};
  for(int i{}; i < n; i += 2) {
    arr[i] = curr++;
  }

  for(int i{1}; i < n; i += 2) {
    arr[i] = curr++;
  }

  for(int i{}; i < n - 1; ++i)
    cout << arr[i] << ' ';
  cout << arr.back() << '\n';
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

