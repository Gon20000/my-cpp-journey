#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{};
  cin >> n;

  if(n <= 2) {
    cout << n << '\n';
    return;
  }

  ll x{n * (n - 1)};
  ll ans{x * (n - 2) / gcd(x, n - 2)};

  if(n % 2 == 0) {
    ans = max(ans, (n - 1) * (n - 2) * (n - 3));
    for(ll i{n - 2}; i >= 1; --i) {
      ll g{gcd(x, i)};
      ans = max(ans, x * i / g);
      if(g == 1) {
        break;
      }
    }
  }

  cout << ans << '\n';
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

