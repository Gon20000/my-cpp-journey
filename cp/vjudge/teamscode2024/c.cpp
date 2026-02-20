#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, q{};
  cin >> n >> q;

  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
    x *= 2;
  }

  vector<ll> pref(n);
  pref[0] = arr[0];
  for(int i{1}; i < n; ++i) {
    pref[i] = arr[i];
    pref[i] ^= pref[i - 1];
  }

  while(q--) {
    int x{}, y{};
    cin >> x >> y;  
    --x; --y;

    if(x == 0)
      cout << pref[y] << '\n';
    else
      cout << (pref[y] ^ pref[x - 1]) << '\n';
  }
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

