#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr ll halfN{1'000'000};
set<ll> possible{};
vector<bool> sieve(halfN + 1, true);

void init() {
  sieve[0] = sieve[1] = false;
  for(ll i{2}; i <= halfN; ++i) {
    if(!sieve[i])
      continue;

    for(ll j{i * 2}; j <= halfN; j += i) {
      sieve[j] = false;
    }

    possible.insert(i * i);
  }
}

void solve() {
  ll x{};
  cin >> x;

  cout << (possible.count(x) ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  init();
  while(t--)
    solve();

  return 0;
}

