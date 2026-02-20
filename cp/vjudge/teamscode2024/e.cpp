#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll count(ll pattern, const vector<ll>& arr) {
  ll res{};
  for(ll x : arr) {
    if(x & pattern)
      ++res;
  }

  return res;
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  ll sum{}, res{};
  for(ll& x : arr) {
    cin >> x;
    res += x;
    sum += x;
  }

  ll pat{};
  for(int i{31}; i >= 0; --i) {
    /*if(count)*/
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

