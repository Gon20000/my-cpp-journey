#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
  int n{};
  cin >> n;

  indexed_set s{};
  ll res{};
  
  while(n--) {
    int x{};
    cin >> x;

    s.insert(x);
    res += s.size() - s.order_of_key(x) - 1;
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

