#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<string, int> mp{{"BG", 0}, {"BR", 1}, {"BY", 2},
                    {"GR", 3}, {"GY", 4}, {"RY", 5}};
vector<string> mp2{"BG", "BR", "BY", "GR", "GY", "RY"};

bool check(int x, int y) {
  return mp2[x][0] == mp2[y][0] || mp2[x][0] == mp2[y][1] ||
         mp2[x][1] == mp2[y][0] || mp2[x][1] == mp2[y][1];
}

int ans(int curr, int start, int soFar, vector<int> &inp,
        vector<vector<int>> &arr) {
  
  int currIdx{inp[curr]}, startIdx{inp[start]};

  if (check(currIdx, startIdx))
    return soFar + abs(curr - start);

  int res{INT_MAX};
  for (int i{}; i < 6; ++i) {
    if (i == currIdx || !check(currIdx, i))
      continue;

    auto it{lower_bound(arr[i].begin(), arr[i].end(), start)};
    auto it2{upper_bound(arr[i].begin(), arr[i].end(), start)};

    if (it != arr[i].end())
      res = min(res, ans(*it, start, abs(curr - *it), inp, arr));

    if(it2 != arr[i].begin()) {
      --it2;
      res = min(res, ans(*it2, start, abs(curr - *it2), inp, arr));
    }
  }

  return res;
}

void solve() {
  vector<vector<int>> arr(6);

  int n{}, q{};
  cin >> n >> q;

  vector<int> inp(n + 1);
  for (int i{1}; i <= n; ++i) {
    string str{};
    cin >> str;

    inp[i] = mp[str];
    arr[mp[str]].push_back(i);
  }

  while (q--) {
    int x{}, y{};
    cin >> x >> y;

    int res{ans(y, x, 0, inp, arr)};
    cout << (res == INT_MAX ? -1 : res) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while (t--)
    solve();

  return 0;
}
