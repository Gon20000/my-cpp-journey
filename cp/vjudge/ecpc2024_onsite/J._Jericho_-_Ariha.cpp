#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll a{}, b{};
  cin >> a >> b;

  ll z{gcd(a, b)};
  a /= z;
  b /= z;

  ll x{(ll)sqrt(a)}, y{(ll)sqrt(b)};
  if(x * x != a || y * y != b) {
    cout << -1 << '\n';
    return;
  }

  a /= x;
  b /= y;

  ll res{};
  for(int i{2}; i * i <= max(a, b); ++i) {
    while(a % i == 0) {
      ++res;
      a /= i;
    }

    while(b % i == 0) {
      ++res;
      b /= i;
    } 
  } 

  if(a > 1)
    ++res;
  if(b > 1)
    ++res;

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

