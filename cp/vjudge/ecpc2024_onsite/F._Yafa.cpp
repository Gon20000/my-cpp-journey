#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void printArr(const vector<int>& arr) {
  for(int i{0}; i < (int)arr.size() - 1; ++i)
    cout << arr[i] << ' ';
  cout << arr.back() << endl;
}

void solve() {
  int l{1}, r{2000};
  int i{};
  while(l <= r && i++ < 7) {
    int seg{(int)round((r - l) / 3.0)};
    int mid1{l + seg - 1}, mid2{mid1 + seg};
    vector<int> arr[3];
    for(int i{l}; i <= mid1; ++i) {
      arr[0].push_back(i);
    }

    for(int i{mid1 + 1}; i <= mid2; ++i) {
      arr[1].push_back(i);
    }

    for(int i{mid2 + 1}; i <= r; ++i) 
      arr[2].push_back(i);

    cout << '?' << endl;
    cout << mid1 - l + 1 << endl;
    printArr(arr[0]);
    cout << mid2 - mid1 << endl;
    printArr(arr[1]);

    int x{}, y{};
    cin >> x >> y;

    if(x == y) {
      if(arr[x - 1].size() == 2) {
        cout << "! " << arr[x - 1][0] << ' ' << arr[x - 1][1] << endl;
        return;
      }
    }
    else if(arr[x - 1].size() + arr[y - 1].size() == 2) {
      cout << "! ";
      if(arr[x - 1].empty())
        cout << arr[y - 1][0] << ' ' << arr[y - 1].back() << endl;
      else if(arr[y - 1].empty())
        cout << arr[x - 1][0] << ' ' << arr[x - 1].back() << endl;
      else
        cout << arr[x - 1][0] << ' ' << arr[y - 1][0] << endl;
      return;
    }

    if(x == 2)
      l = mid1 + 1;
    else if(x == 3)
      l = mid2 + 1;

    if(y == 1)
      r = mid1;
    else if(y == 2)
      r = mid2;
  }

  cout << "Fatal Error\n";
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

