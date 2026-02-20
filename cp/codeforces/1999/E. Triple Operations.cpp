#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const vector<ll> pows{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323};

ll bin(ll x) {
  auto it{lower_bound(pows.begin(), pows.end(), x)};
  return it - pows.begin() + (*it == x ? 1 : 0);
}
void solve() {
  ll res{};
  ll x{}, y{};
  cin >> x >> y;

  res += 2 * bin(x);
  for(++x; x <= y; ++x) {
    auto it{lower_bound(pows.begin(), pows.end(), x)};
    if(*it <= y) {
      res += (it - pows.begin()) * (*it - x);
      res += (it - pows.begin() + 1);
      x = *it;
    }
    else {
      res += (it - pows.begin()) * (y - x + 1);
      x = y + 1;
    }
  }

  cout << res << '\n';
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

