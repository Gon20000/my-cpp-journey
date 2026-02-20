#include <bits/stdc++.h>
#pragma omp parallel
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  priority_queue<pair<ll, ll>> pq{};
  vector<ll> a(n), b(n);
  for(ll& x : a)
  cin >> x;

  for(int i{}; i < n; ++i) {
    cin >> b[i];
    pq.push({a[i], b[i]});
  }

  ll res{};
  #pragma omp for 
  for(int i{}; i < k; ++i) {
    pair<ll, ll> p{pq.top()};
    pq.pop();
    if(p.first == 0)
      break;

    res += p.first;
    pq.push({max(0ll, p.first - p.second), p.second});
  }

  cout << res << '\n';

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

