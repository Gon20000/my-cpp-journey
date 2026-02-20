#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool check(string& str, int idx) {
  return str[idx] == '.';
}
void solve() {
  int n{};
  cin >> n;

  string str1{}, str2{};
  cin >> str1 >> str2;

  ll res{};
  for(int i{1}; i < n - 1; ++i) {
    if(str1[i] == 'x')
      continue;

    res += str1[i - 1] == str1[i + 1] && check(str1, i + 1) && !check(str2, i - 1) && !check(str2, i + 1) && check(str2, i);
  }

  for(int i{1}; i < n - 1; ++i) {
    if(str2[i] == 'x')
      continue;

    res += str2[i - 1] == str2[i + 1] && check(str2, i + 1) && !check(str1, i - 1) && !check(str1, i + 1) && check(str1, i);
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

