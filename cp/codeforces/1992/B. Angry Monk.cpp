#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  vector<ll> arr(k);
  for(ll& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end(), greater<ll>());
  ll res{};
  for(int i{1}; i < k; ++i) {
    ++res;
    res += (arr[i] - 1) * 2;
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

