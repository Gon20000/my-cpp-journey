#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool check(ll x, vector<ll> &arr) { return x >= arr[0] && x <= arr[1]; }

void solve() {
  vector<ll> a(2), b(2);

  for (ll &x : a)
    cin >> x;

  for (ll &x : b)
    cin >> x;

  if (a[0] > b[0]) {
    swap(a, b);
  }

  ll res{};

  for (ll f{a[0]}; f <= a[1]; ++f) {
    if (check(f + 1, b))
      ++res;
  }

  if (b[0] > a[1] + 1)
    ++res;
  if(a[1] > b[1] + 1)
    ++res;

  cout << res << '\n';
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
