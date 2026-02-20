#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end(), greater<ll>());

  ll res{};
  for(int i{1}; i < n; i += 2) {
    res += arr[i - 1];
    ll minus{min(arr[i - 1] - arr[i], k)};
    k -= minus;
    res -= arr[i] + minus;
  } 

  if(n % 2 == 1)
    res += arr.back();

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

