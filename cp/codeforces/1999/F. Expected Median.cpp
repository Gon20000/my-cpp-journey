#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod{static_cast<int>(1e9) + 7};

void add(ll &x, ll y) { x = ((x % mod) + (y % mod)) % mod; }
ll multiply(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

ll modpow(ll x, ll n) {
  if (n == 0) {
    return 1 % mod;
  }

  ll u{modpow(x, n / 2)};
  u = (u * u) % mod;

  if (n % 2 == 1) {
    u = (u * x) % mod;
  }

  return u;
}

vector<ll> fac{1};
vector<ll> inv_fac{modpow(1, mod - 2)};

ll getFac(ll num) {
  while (fac.size() <= num) {
    fac.push_back(multiply(fac.back(), (int)fac.size()));
    inv_fac.push_back(modpow(fac.back(), mod - 2));
  }

  return fac[num];
}

ll getInvFac(ll num) { return modpow(num, mod - 2); }

ll nCr(ll n, ll r) {
  if (r > n)
    return 0;

  ll num{getFac(n)};
  return multiply(num, getInvFac(multiply(getFac(r), getFac(n - r))));
}

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  vector<ll> arr(n);
  ll cnt{}, cntz{}, res{};
  for (ll &x : arr) {
    cin >> x;
    cnt += x;
  }

  for (ll i{0}; i <= k / 2; ++i) {
    ll ones{nCr(cnt, k - i)}, zeros{nCr(n - cnt, i)};
    add(res, multiply(ones, zeros));
  }
  cout << res << '\n';
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
