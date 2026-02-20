#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll l{2}, r{999};

  while(l < r) {
    ll mid1{l + (r - l) / 3}, mid2{r - (r - l) / 3};
    cout << "? " << mid1 << ' ' << mid2 << endl;

    ll x{};
    cin >> x;
    if(x == -1)
      return;

    if(x == mid1 * mid2)
      l = mid2 + 1;
    else if(x == mid1 * (mid2 + 1)) {
      l = mid1 + 1;
      r = mid2;
    }
    else {
      r = mid1;
    }
  }

  cout << "! " << l << endl;
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
