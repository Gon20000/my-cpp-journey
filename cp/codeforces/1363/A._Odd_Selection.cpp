#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, x{}, even{}, odd{};
  cin >> n >> x;

  while (n--) {
    int curr{};
    cin >> curr;

    if (curr % 2 == 0)
      ++even;
    else
      ++odd;
  }

  int o{max(0, min(odd - !(odd % 2), x - !(x % 2)))};
  cout << (o > 0 && x - o <= even ? "YES\n" : "NO\n"); 
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
