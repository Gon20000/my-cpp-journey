#include <bits/stdc++.h>
#include <iterator>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str{};
  cin >> str;

  if (size(str) > 10)
    cout << str[0] << str.size() - 2 << str[str.size() - 1] << '\n';
  else
    cout << str << '\n';
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

