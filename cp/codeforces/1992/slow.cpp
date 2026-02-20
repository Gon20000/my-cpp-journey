#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;
  
  string str{to_string(n)};
  ll curr{n}, sz{int(log10(n))+1};
  ll curr_sz{sz};
  
  vector<pair<int, int>> ans{};
  while(curr <= ll(1e18)) { // fix this
    for(int mid{1}; mid <= 10000; ++mid) {
      ll other{sz * mid - curr_sz};
      ll val{n * mid - (other)};
      if(val == curr && other <= 10000 && other > 0) {
        ans.push_back({mid, other});
      }
    }

    ++curr_sz;
    curr = curr * 10 + (str[(curr_sz - 1) % sz] - '0');
  }

  cout << ans.size() << '\n';
  for(auto [x, y] : ans)
    cout << x << ' ' << y << '\n';
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


