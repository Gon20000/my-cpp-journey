#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <typename T> struct segNode {
  T val;
  T lazy;
};

template <typename T> class SegTree {
  vector<T> arr{};
  vector<segNode<T>> seg{};

public:
  SegTree(vector<ll> &vec) : arr(vec), seg(4 * vec.size()) {
    build(0, 0, static_cast<int>(vec.size()) - 1);
  }

  void recalc(int idx) {
    seg[idx] = seg[2 * idx + 1].val + seg[2 * idx + 2].val;
  }

  void build(int idx, int left, int right) {
    if (left == right)
      seg[idx].val = arr[left];
    else {
      int mid{left + (right - left) / 2};
      build(2 * idx + 1, left, mid);
      build(2 * idx + 2, mid + 1, right);
      recalc(idx);
    }
  }

  void propagate(int idx, int left, int right) {
    seg[idx].val += (left - right + 1) * seg[idx].lazy;
    if (left < right) {
      seg[2 * idx + 1].lazy += seg[idx].lazy;
      seg[2 * idx + 2].lazy += seg[idx].lazy;
    }

    seg[idx].lazy = 0;
  }

  T range_query(int idx, int l, int r, int x, int y) {
    propagate(idx, l, r);
    if (x <= l && y >= r)
      return seg[idx].val;

    T res{};
    int mid{l + (r - l) / 2};

    if (x <= mid)
      res += range_query(2 * idx + 1, l, mid, x, y);

    if (y > mid)
      res += range_query(2 * idx + 2, mid + 1, r, x, y);
  }

  void update(int idx, int l, int r, int x, int y, T num) {
    propagate(idx, l, r);
    if (x <= l && y >= r)
      return seg[idx].lazy += num;

    int mid{l + (r - l) / 2};
    if (x <= mid)
      update(2 * idx + 1, l, mid, x, y, num);
    if (y > mid)
      update(2 * idx + 2, mid + 1, r, x, y, num);
  }
};

void solve() {

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

