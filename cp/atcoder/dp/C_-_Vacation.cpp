#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<vector<ll>> arr(n, vector<ll>(3));
  for(int i{}; i < n; ++i) {
    for(int j{}; j < 3; ++j) {
      cin >> arr[i][j];
    
      ll add{};
      for(int k{}; k < 3 && i > 0; ++k)
        if(k != j)
          add = max(arr[i - 1][k], add);
      arr[i][j] += add;
    }
  }

  cout << *max_element(arr.back().begin(), arr.back().end()) << '\n';
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

