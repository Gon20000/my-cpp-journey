#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int C{26};
vector<ll> subtract(vector<ll>& vec, vector<ll>& vec2) {
  vector<ll> res(C);
  for(int i{}; i < C; ++i) {
    res[i] = vec[i] - vec2[i];
  }

  return res;
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  string str1{}, str2{};
  cin >> str1 >> str2;

  vector<vector<ll>> vec1(n);
  vector<vector<ll>> vec2(n);
  vec1[0] = vec2[0] = vector<ll>(C);
  for(int i{}; i < n; ++i) {
    if(i > 0) {
      vec1[i] = vec1[i - 1];
      vec2[i] = vec2[i - 1];
    }

    ++vec1[i][str1[i] - 'a'];
    ++vec2[i][str2[i] - 'a'];
  }

  while(q--) {
    int x{}, y{};
    cin >> x >> y;

    --x; --y;
    vector<ll> vecx{}, vecy{};
    if(x == 0) {
      vecx = vec1[y];
      vecy = vec2[y];
    }
    else {
      vecx = subtract(vec1[y], vec1[x - 1]);
      vecy = subtract(vec2[y], vec2[x - 1]);
    }

    ll res{};
    for(int i{}; i < C; ++i) {
      res += max(0ll, vecx[i] - vecy[i]);
    }

    cout << res << '\n';
  }
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

