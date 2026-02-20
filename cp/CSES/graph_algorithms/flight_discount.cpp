#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
// weight, node
using node_t = pair<ll, int>;

struct node {
  ll w{};
  int y{};
  bool done{};

  node(ll a, int b, bool c = false) : w{a}, y{b}, done{c} {};

  bool operator<(const node &a) const { return w < a.w; }
  bool operator>(const node &a) const { return w > a.w; }
};

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<node>> adj(n + 1);
  vector<ll> dist1(n + 1, LLONG_MAX);
  vector<ll> dist2(n + 1, LLONG_MAX);
  priority_queue<node, vector<node>, greater<node>> pq{};

  while (m--) {
    int x{}, y{};
    ll w{};
    cin >> x >> y >> w;

    adj[x].push_back({w, y});
  }

  dist1[1] = dist2[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [w, curr, done] = pq.top();
    pq.pop();
    // cout << curr << ' ' << w << ' ' << done << '\n';

    if (w > dist1[curr] || (done && w > dist2[curr]))
      continue;

    for (auto [w2, node, _] : adj[curr]) {
      if (w + w2 >= dist1[node])
        continue;

      if (!done) {
        dist1[node] = w + w2;
        pq.push({dist1[node], node});

        if(w + w2 / 2 < dist2[node]) {
          dist2[node] = w + w2 / 2; 
          pq.push({dist2[node], node, true});
        }
      }
      else if (w + w2 < dist2[node]) {
        dist2[node] = w + w2;
        pq.push({dist2[node], node, true});
      }
    }
  }

  cout << dist2[n] << '\n';
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

