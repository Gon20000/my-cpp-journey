#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class SegTree {
  vector<ll> arr{}, seg{};

public:
  SegTree(vector<ll> vec) : arr(vec), seg(4 * vec.size()) {
    build(0, 0, vec.size() - 1);
  }

  void recalc(int idx) { seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2]; }

  void build(int idx, int left, int right) {
    if (left == right) {
      seg[idx] = arr[left]; // leaf node, gets appened to the end
    } else {
      int mid{left + (right - left) / 2};
      build(2 * idx + 1, left, mid);
      build(2 * idx + 2, mid + 1, right);
      recalc(idx);
    }
  }

  ll query(int idx, int left, int right, int x, int y) {
    if (x <= left && y >= right)
      return seg[idx];
    else {
      int mid{left + (right - left) / 2};
      ll res{};

      if (x <= mid) {
        res ^= query(2 * idx + 1, left, mid, x, y);
      }

      if (y > mid) {
        res ^= query(2 * idx + 2, mid + 1, right, x, y);
      }

      return res;
    }
  }

  void update(int idx, int left, int right, int pos, ll add) {
    if (left == pos && left == right) {
      seg[idx] = add; // leaf node
    } else {
      int mid{left + (right - left) / 2};

      if (pos <= mid) {
        update(2 * idx + 1, left, mid, pos, add);
      }

      else {
        update(2 * idx + 2, mid + 1, right, pos, add);
      }

      recalc(idx);
    }
  }
};

constexpr int N{200001};
vector<vector<int>> adj(N);
vector<ll> vals(N), euler;

vector<int> in(N), out(N);
int currIn{};

void dfs(int curr, int prev) {
  for (int node : adj[curr]) {
    if (node == prev)
      continue;

    in[node] = ++currIn;
    euler[currIn] = vals[node];
    dfs(node, curr);
  }
  out[curr] = ++currIn;
  euler[currIn] = vals[curr];
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for (int i{1}; i <= n; ++i)
    cin >> vals[i];

  for (int i{1}; i < n; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  euler.resize(2*n);
  euler[0] = vals[1];
  dfs(1, -1);
  SegTree tr(euler);

  while(q--) {
  int t{};
    cin >> t;

    if(t == 1) {
      ll s{}, x{};
      cin >> s >> x;

      tr.update(0, 0, 2 * n - 1, in[s], x);
      tr.update(0, 0, 2 * n - 1, out[s], x);
    }
    else {
      int x, y;
      cin >> x >> y;

      cout << tr.query(0, 0, 2 * n - 1, in[x], out[y] - 1) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cowland.in", "r", stdin);
  // freopen("cowland.out", "w", stdout);
  int t{1};
  // cin >> t;

  while (t--)
    solve();

  return 0;
}
