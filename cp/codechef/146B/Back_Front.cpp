#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const string str1{"front"}, str2{"back"};

inline int c(char x) { return x - 'a'; }

void solve() {
  int n{};
  string str{};
  cin >> n >> str;

  int res{n};
  vector<int> mp(26);
  for (int i{}; i < n; ++i) {
    size_t idx{str1.find(str[i])};
    if ((idx == string::npos) || (idx > 0 && mp[c(str[idx])] >= mp[c(str1[idx - 1])]))
      continue;

    ++mp[c(str[i])];
  }

  int added{mp[c('t')]};

  /*mp[c('k')] += first;*/
  /*for (int i{n - 1}; i >= 0; --i) {*/
  /*  size_t idx{str2.find(str[i])};*/
  /*  if (idx == string::npos)*/
  /*    continue;*/
  /**/
  /*  if (idx < 3 && sz(str[i], mp) >= sz(str2[idx + 1], mp))*/
  /*    continue;*/
  /**/
  /*  ++mp[str[i] - 'a'];*/
  /*}*/
  /**/
  /*ll second{mp[c('b')]};*/
  /*res -= second * 3;*/
  /**/
  /*for(int i{}; i < str2.size() - 1; ++i) {*/
  /*  ll curr{sz(str2[i + 1], mp) - sz(str2[i], mp)};*/
  /*  if(curr <= 0)*/
  /*    continue;*/
  /**/
  /*  ll add{min(second / (i + 1), curr)};*/
  /*  second -= add;*/
  /*  res -= 3 * add;*/
  /*}*/

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while (t--)
    solve();

  return 0;
}
