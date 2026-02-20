#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  ll x{(ll)sqrt(n)};
  deque<ll> deq{};
  for(int i{1}; i <= x; ++i) {
    if(n % i)
      continue;

    if(n / i != i)
      deq.push_front(n / i);
    if(--k == 0) {
      cout << i << '\n';
      return;
    }
  } 

  cout << (deq.size() < k ? -1 : deq[--k]) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

