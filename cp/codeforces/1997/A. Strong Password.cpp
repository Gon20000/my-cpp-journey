#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int check(string& str) {
  char x{};

  ll res{};
  for(char chr : str) {
    if(chr == x)
      ++res;
    else
      res += 2;

    x = chr;
  }

  return res;
}

void solve() {
  int idx{};
  string str{};
  cin >> str;

  ll res{};
  string ans{};
  for(int i{0}; i < str.size(); ++i) {
    string cop{str};
    char x{'a'};

    while((i > 0 && str[i - 1] == x) || (x == str[i]))
      ++x;

    cop.insert(i, string{x});
    if(check(cop) > res) {
      res = check(cop);
      ans = cop;
    }
  }

  cout << ans << '\n';

  /*
      aaaa
      2111
      ataaa
      22211
      aataa
      21221 
      aaata
      21121
      aaaat

      aaa
      ataa
      2221
      aata
      2122
      */

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

