#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  ll even{}, high{}, high2{};
  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
    even += (x % 2 == 0);
    if(x % 2)
      high = max(high, x);
  }
  high2 = high;

  if(!even || even == n) {
    cout << 0 << '\n';
    return;
  }

  ll res{}, res2{};
  sort(arr.begin(), arr.end());
  for(ll x : arr) {
    if(x % 2)
      continue;

    if(x < high) {
      ++res;
      high = x + high;
    }
    else {
      res += 2;
      high += 2 * x;
    }
  }

  high = high2;
  for(int i{n - 1}; i >= 0; --i) {
    ll x{arr[i]};
    if(x % 2)
      continue;

    if(x < high) {
      ++res2;
      high = x + high;
    }
    else {
      res2 += 2;
      high += 2 * x;
    }
  }
  cout << min(res2, res) << '\n';
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

