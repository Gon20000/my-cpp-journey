#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;
  
  if(n == 1) {
    cout << 9999 << '\n';
    for(int i{2}; i <= 10000; ++i) {
      cout << i << ' ' << i - 1 << '\n';
    }
    return;
  }

  string str{to_string(n)};
  ll curr{n}, sz{int(log10(n))+1};
  ll curr_sz{sz};
  
  vector<pair<int, int>> ans{};
  while(curr <= ll(1e18)) { // fix this
    int l{}, r{10000};
    int res{-1};
    while(l <= r) {
      ll mid{l + (r - l) / 2};
      ll val{n * mid - (sz * mid - curr_sz)};
      if(val < curr) 
        l = mid + 1;
      else if(val > curr)
        r = mid - 1;
      else {
        res = mid;
        l = r + 1;
      }
    }

    if(res > 0) {
      ll other{sz  * res - curr_sz};

      if(other > 0 && res <= 10000 && other <= 10000)
        ans.push_back({res, other});
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

