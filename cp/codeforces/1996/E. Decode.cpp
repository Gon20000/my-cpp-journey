#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200001}, LOG{18};
using node_t = vector<ll>;
using sparse_t = vector<node_t>;

constexpr ll mod{ll(1e9) + 7};
void solve() {
  string str{};
  cin >> str;
  int n{int(str.size())};

  vector<ll> psum(n);
  for(int i{}; i < n; ++i) {
    if(i > 0)
      psum[i] += psum[i - 1];
    psum[i] += str[i] == '1';
  }

  vector<ll> dp(n + 1);
  ll res{};
  for(int step{2}; step <= n; step += 2) {
    vector<ll> curr_dp(n - step + 1);
    for(int j{}; j < n - step + 1; ++j) {
      curr_dp[j] += dp[j + 2];
      ll curr_sum = psum[j + step - 1];

      if(j > 0) {
        curr_dp[j] -= dp[j - 1];
        curr_sum -= psum[j - 1];
      }

      if(curr_sum == step / 2) {
        ++curr_dp[j];
        res += curr_dp[j];
        res %= mod;
      }
      
      if(j > 0)
        curr_dp[j] += curr_dp[j - 1];
    }

    dp = curr_dp;
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

