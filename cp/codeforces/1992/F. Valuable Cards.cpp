#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, num{};
  cin >> n >> num;

  ll res{}, curr{1};
  vector<ll> arr(n);
  for(ll& e : arr)
    cin >> e;

  for(int i{}; i < n - 1; ++i) {
    ll x{arr[i]};
    curr *= x;

    if(curr % num == 0) {
      ++res;
      curr = 1;
    }
  }

  cout << res + 1 << '\n';
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

