#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<int> arr1(n), arr2(n);

  for (int &x : arr1)
    cin >> x;

  for (int &x : arr2)
    cin >> x;

  if(arr1.front() != arr2.front()) 
    reverse(arr2.begin(), arr2.end());

  cout << (arr1 == arr2 ? "Bob\n" : "Alice\n");
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

/*
1 2
2 1


Alice
1 2 3
3 1 2

Bob
5 1 2 4 3
4 3 2 1 5

Bob
1 2 3 4
4 2 3 1

1 2 3
1 3 2


1 2 3 4 5
1 4 2 3 5

1 2 3 4
3 2 1 4


5 1 2 3 4
1 3 2 4 5
*/
