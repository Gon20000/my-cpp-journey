#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  string str{}, f{};
  cin >> str;

  map<char, ll> mp = {
    {'a', 4},
    {'b', 9},
    {'c', 40},
    {'d', 90},
    {'e', 400},
    {'f', 900},
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
  };
  for (int i{}; i < n; ++i) {
    if (i < n - 1) {
      if (str[i] == 'I') {
        if (str[i + 1] == 'V') {
          f += 'a';
          ++i;
        } else if (str[i + 1] == 'X') {
          f += 'b';
          ++i;
        } else {
          f += str[i];
        }
      } else if (str[i] == 'X') {
        if (str[i + 1] == 'L') {
          f += 'c';
          ++i;
        } else if (str[i + 1] == 'C') {
          f += 'd';
          ++i;
        } else {
          f += str[i];
        }
      } else if (str[i] == 'C') {
        if (str[i + 1] == 'D') {
          f += 'e';
          ++i;
        } else if (str[i + 1] == 'M') {
          f += 'f';
          ++i;
        } else {
          f += str[i];
        }
      } else {
        f += str[i];
      }
    } else {
      f += str[i];
    }
  }

  ll res{};
  for(char x : f)
    res += mp[x];
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while (t--)
    solve();

  return 0;
}
