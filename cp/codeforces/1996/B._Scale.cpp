#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, k{};
  cin >> n >> k;

  vector<vector<int>> res{};
  for(int i{}; i < n; ++i) {
    string str{};
    cin >> str;

    if(i % k > 0)
      continue;

    res.push_back({});
    for(int j{}; j < n; j += k) {
      res.back().push_back(str[j] - '0');
    }
  }

  for(vector<int>& vec : res) {
    for(int x : vec)
      cout << x;
    cout << '\n';
  }
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

