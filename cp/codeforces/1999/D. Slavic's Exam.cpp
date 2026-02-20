#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str{}, word{};
  cin >> str >> word;

  int idx{(int)word.size() - 1};

  for(int i{(int)str.size() - 1}; i >= 0; --i) {
    if(str[i] != word[idx] && str[i] != '?')
      continue;

    str[i] = word[idx];
    --idx;
    if(idx < 0) {
      break;
    }
  }

  if(idx >= 0) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for(char chr : str) {
    if(chr == '?')
      cout << 'x';
    else
      cout << chr;
  }
  cout << '\n';
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

