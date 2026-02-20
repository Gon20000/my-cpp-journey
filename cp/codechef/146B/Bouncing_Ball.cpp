#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll p(ll x, ll y, vector<ll>& psum) {
  if(x == 0)
    return psum[y];
  return psum[y] - psum[x - 1];
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), psum(n);
  for(int i{}; i < n; ++i) {
    cin >> arr[i];
    psum[i] = arr[i];
    if(i > 0)
      psum[i] += psum[i - 1];
  }

  ll res{};
  for(int i{}; i < n; ++i) {
    if(arr[i] != 0)
      continue;

    ll l{p(0, i, psum)}, r{p(i, n - 1, psum)};
    if(l != r && abs(l - r) == 1)
      ++res;

    else if(l == r) {
      res += 2;
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

