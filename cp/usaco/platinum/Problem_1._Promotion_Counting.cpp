#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;


constexpr int N{100001};
vector<vector<int>> adj(N);
vector<ll> vals(N), res(N);
vector<ll> lists[N];
int idx{};

void dfs(int curr, int prev) {
  vector<ll>& s(lists[curr]);
  s.push_back(vals[curr]);

  for (int node : adj[curr]) {
    if (node == prev)
      continue;

    dfs(node, curr);

    vector<ll>& s2(lists[node]);
    vector<ll> tempRes(s2.size() + s.size());
    if (s2.size() > s.size())
      swap(s2, s);

    merge(s.begin(), s.end(), s2.begin(), s2.end(), tempRes.begin());
    s = std::move(tempRes);
  }
  
  res[curr] = s.end() - upper_bound(s.begin(), s.end(), vals[curr]);
}

void solve() {
  int n{};
  cin >> n;

  for (int i{1}; i <= n; ++i)
    cin >> vals[i];

  for (int i{2}; i <= n; ++i) {
    int node{};
    cin >> node;

    adj[i].push_back(node);
    adj[node].push_back(i);
  }

  dfs(1, -1);

  for(int i{1}; i <= n; ++i)
    cout << res[i] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int t{1};
  // cin >> t;

  while (t--)
    solve();

  return 0;
}
