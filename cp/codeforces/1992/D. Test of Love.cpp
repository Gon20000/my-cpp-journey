#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{}, k{};
  cin >> n >> m >> k;

  vector<ll> dp(n + 2, INT_MAX);
  dp[0] = 0;

  string str{};
  cin >> str;
  str = 'L' + str;

  for(int i{0}; i <= n; ++i) {
    char x{str[i]};

    if(x == 'C')
      continue;
    else if(x == 'W') {
      ++dp[i];
        dp[i + 1] = min(dp[i + 1], dp[i]);
    }
    else {
      for(int j{1}; j <= m && i + j <= n + 1; ++j) {
        dp[i + j] = min(dp[i + j], dp[i]);
      }
    }
  }

  cout << (dp[n + 1] <= k ? "YES\n" : "NO\n");
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

