#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, s{}, m{};
  cin >> n >> s >> m;

  vector<pair<ll, ll>> tasks(n);
  for(auto& x : tasks) {
    cin >> x.first >> x.second;
  }

  sort(tasks.begin(), tasks.end());

  ll last{0};
  tasks.push_back({m, m});

  for(auto [x, y] : tasks) {
    if(x - last >= s) {
      cout << "YES\n";
      return;
    }
    last = y;
  }

  cout << "NO\n";
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

