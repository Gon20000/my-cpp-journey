#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <typename T>
class BIT {
  vector<T> arr, bit;

public:
  int size{};
  // BIT is one indexed so that you can deal with the LSB
  BIT(vector<T> input)
      : size{(int)input.size()}, arr(input), bit(input.size() + 1) {
    for (int i{1}; i <= size; ++i) {
      // copying the array basically
      bit[i] += arr[i - 1];

      // note: i & -i is the least significant bit (last bit)
      int j{i + (i & -i)};
      if (j > size)
        continue;

      // update the next one only and it will update the one after it (William
      // fiset video)
      bit[j] += bit[i];
    }
  }

  void add(int ind, T val) {
    // debugging purposes
    arr[ind] += val;

    // add the value to each segment containing current index
    for (++ind; ind <= size; ind += ind & -ind)
      bit[ind] += val;
  }

  T sum(int ind) {
    T res{};

    // notice ++ind because bit is 1-indexed
    for (++ind; ind > 0; ind -= ind & -ind)
      res += bit[ind];

    return res;
  }

  void set(int ind, T val) {
    // clear the element then add val
    add(ind, val - arr[ind]);
  }

  T psum(int x, int y) {
    if (x == 0)
      return sum(y);

    return sum(y) - sum(x - 1);
  }

  void range_add(int x, int y, T val) {
    add(x, val);
    // ASSUMING T is an integer type
    if (y < size)
      add(y + 1, 0 - val);
  }
};

void solve() {
  int n{}, q{};
  cin >> n >> q;
  
  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  BIT<ll> diff(vector<ll>(n,0));

  while(q--) {
    int t{};
    cin >> t;

    if (t == 1) {
      int a{}, b{}; ll u{};
      cin >> a >> b >> u;

      diff.range_add(--a, --b, u);
    }
    else {
      int a{};
      cin >> a;
      --a;

      cout << arr[a] + diff.sum(a) << '\n';
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

