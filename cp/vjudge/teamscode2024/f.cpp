#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll a{}, b{}, c{}, n{};
  cin >> a >> b >> c  >> n;

  ll curr{1}, res{a};
  while(curr * 2 < n) {

      res += a * curr;
    }
    else {
      res += b + c;
    }
    curr *= 2;
  }

  cout << res + (curr < n) << ' ' << curr << '\n';
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

