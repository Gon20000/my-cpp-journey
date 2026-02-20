#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, x{};
  cin >> n >> x;

  vector<ll> arr(n);
  for(ll& x : arr)  
    cin >> x;

  map<ll, ll> mp{};
  mp[arr[0]] = 1;

  for(int i{1}; i < n - 1; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      if(mp.count(x - arr[i] - arr[j])) {
        cout << mp[x - arr[j] - arr[i]] << ' ' << i + 1 << ' ' << j + 1;
        return;
      }
    }
    mp[arr[i]] = i + 1;
  }

  cout << "IMPOSSIBLE\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}

