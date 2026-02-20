#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// NOTE this sol can be converted into a 1D array since it uses the same row in the transition
void solve() {
  ll n{}, W{};
  cin >> n >> W;

  vector<vector<ll>> arr(n);
  arr[0].resize(W + 2);

  for(int i{}; i < n; ++i) {
    ll w{}, v{};
    cin >> w >> v;

    if(i > 0)
      arr[i] = arr[i - 1];

    for(ll j{W}; j >= w; --j)
      arr[i][j] = max(arr[i][j], arr[i][j - w] + v);

    // for(int j{}; j <= W; ++j)
    //   cout << arr[i][j] << ' ';
    // cout << '\n';
  }
  
  cout << arr[n - 1][W] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

