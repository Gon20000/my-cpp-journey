#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  string str{};
  cin >> str;

  map<char, int> mp{};
  for(char x : str) {
    ++mp[x];
  }

  ll res{};
  for(auto [chr, cnt] : mp) {
    if(chr == '?')
      continue;

    res += min(cnt, n);
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

