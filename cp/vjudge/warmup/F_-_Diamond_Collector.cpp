#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  ll n{}, k{};
  cin >> n >> k;

  // maxPile(i) -> maximum pile that can be obtained with i being leftmost element
  // suff(i) -> maximum Pile size from i to n
  vector<ll> arr(n), maxPile(n), suff(n);
  for(ll& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end());

  int r{};
  for(int l{}; l < n; ++l) {
    while(r < n && arr[r] - arr[l] <= k) 
      ++r;
    maxPile[l] = r - l;
  }

  suff[n - 1] = 1;
  for(ll i{n - 2}; i >= 0; --i) {
    suff[i] = max(suff[i + 1], maxPile[i]);
  }

  ll res{};
  for(ll l{}; l < n - 1; ++l) {
    ll curr{maxPile[l]};
    if(l + maxPile[l] < n)
      curr += suff[l + maxPile[l]];
    res = max(res, curr);
  }

  cout << res << '\n';

  return 0;
}

