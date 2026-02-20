#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using a_t = array<int, 26>;

const int max_size{100001};
a_t arr[max_size];
a_t seg[4 * max_size];
string str{};

ll ord(char x) { return x - 'a'; }

void change(a_t& a, int pos, char chr) {
  --a[ord(str[pos])];
  ++a[ord(chr)];
} 

a_t add(a_t x, a_t y) {
  a_t res{};
  for (int i{}; i < 26; ++i)
    res[i] = x[i] + y[i];

  return res;
}

ll getAns(a_t res) {
  ll ans{};
  for(ll x : res)
    ans += (x > 0);

  return ans;
}

void recalc(int idx) { seg[idx] = add(seg[2 * idx + 1], seg[2 * idx + 2]); }

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

a_t query(int idx, int left, int right, int x, int y) {
  if (x <= left && y >= right)
    return seg[idx];
  else {
    int mid{left + (right - left) / 2};
    a_t res{};

    if (x <= mid) {
      res = add(res, query(2 * idx + 1, left, mid, x, y));
    }

    if (y > mid) {
      res = add(res, query(2 * idx + 2, mid + 1, right, x, y));
    }

    return res;
  }
}

void update(int idx, int left, int right, int pos, char add) {
  if (left == pos && left == right) {
    change(seg[idx], pos, add);
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, q{};
  cin >> n >> q;

  cin >> str;
  for(int i{}; i < n; ++i) {
    ++arr[i][ord(str[i])];
  }
  build(0, 0, n - 1);

  while (q--) {
    ll mode{}, low{};
    cin >> mode >> low;

    if (mode == 2) {
      char chr{};
      cin >> chr;
      update(0, 0, n - 1, low - 1, chr);
      str[low - 1] = chr;
    }
    else {
      ll high{};
      cin >> high;
      a_t res = query(0, 0, n - 1, low - 1, high - 1);
      cout << getAns(res) << '\n';
    }
  }
}
