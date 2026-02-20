#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll x{};
  cin >> x;

  long long l{0}, r{static_cast<ll>(1e10)};
  while(l < r) {
    ll mid{l + static_cast<ll>(ceil((r-l)/2.0))};
    if(mid * mid < x)
      l = mid;
    else if (mid * mid >= x)
      r = mid - 1;
  }

  cout << l << '\n';
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

