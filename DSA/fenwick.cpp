#include <bits/stdc++.h>
using namespace std;

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

  T range_add(int x, int y, T val) {
    add(x, val);
    if (y < size)
      add(y + 1, 0 - val);
  }
};
