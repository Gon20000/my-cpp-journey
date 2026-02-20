#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  ll n{}, k{}, b{};
  cin >> n >> k >> b;

  vector<ll> arr(n);
  for (int i{}; i < b; ++i) {
    ll x{};
    cin >> x;
    arr[--x] = 1;
  }

  ll cnt{};
  for (int i{}; i < k; ++i)
    cnt += arr[i];

  ll res{cnt};

  for (int l{1}; l <= n - k; ++l) {
    cnt -= arr[l - 1];
    cnt += arr[l + k - 1];
    res = min(res, cnt);
  }

  cout << res << '\n';
  return 0;
}
