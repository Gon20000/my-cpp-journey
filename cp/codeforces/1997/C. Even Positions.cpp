#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

/*
_(_(_
*/
void solve() {
  int n{};
  cin >> n;
  string str{};
  cin >> str;

  stack<pair<char, int>> st{};
  st.push({'(', 0});

  ll res{};
  for(int i{1}; i < n; ++i) {
    str[i] = str[i] == '_' ? (st.empty() ? '(' : ')') : str[i];
    if(str[i] == ')') {
      pair<char, int> p{st.top()};
      st.pop();

      res += i - p.second;
    }
    else if(str[i] == '(') {
      st.push({'(', i});
    }
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

