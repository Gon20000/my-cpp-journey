#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <typename T> 
class BIT {
  vector<T> arr, bit;

public:
  int size{};
  BIT(vector<T> input)
      : size{(int)input.size()}, arr(input), bit(input.size() + 1) {
    for (int i{1}; i <= size; ++i) {
      bit[i] += arr[i - 1];

      int j{i + (i & -i)};
      if (j > size)
        continue;

      bit[j] += bit[i];
    }
  }

  void add(int ind, T val) {
    arr[ind] += val;

    for (++ind; ind <= size; ind += ind & -ind)
      bit[ind] += val;
  }

  void set(int ind, T val) {
    add(ind, val - arr[ind]);
  }

  T sum(int ind) {
    T res{};

    for (++ind; ind > 0; ind -= ind & -ind)
      res += bit[ind];

    return res;
  }

  T psum(int x, int y) {
    if (x == 0)
      return sum(y);

    return sum(y) - sum(x - 1);
  }
};

void solve() {
  int n{}, q{};
  cin >> n >> q;
  
  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  BIT<ll> bit(arr);

  while(q--) {
    int t{};
    cin >> t;

    if (t == 1) {
      int k{}; ll u{};
      cin >> k >> u;

      bit.set(--k, u);
    }
    else {
      int a{}, b{};
      cin >> a >> b;
      cout << bit.psum(--a, --b) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}

