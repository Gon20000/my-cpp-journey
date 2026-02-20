#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds; 
#define int long long 
#define A first
#define B second 
#define all(x) x.begin() , x.end()
#define popcnt(x) __builtin_popcountll(x)Q
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)

#define ordered_set tree < array<int , 2> ,  null_type ,  less<array<int , 2>> ,  rb_tree_tag ,  tree_order_statistics_node_update >

int modpow(int b , int p , int mod = LLONG_MAX){
    if (!p) return 1;
    int z = modpow(b , p>>1 , mod);
    z = ((z*z)%mod * (p&1 ? b : 1))%mod; 
    return z;
}

bool ispalindrome(string x){
    int n = x.size();
    for (int i = 0 ;  i < n ; i++){
        if (x[i] != x[n-i-1]) return 0;
    }
    return 1;
}

bool isprime(int x){
    for (int i = 2 ; i*i <= x ; i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}


void doWork(){
 int l1 , r1 , l2 , r2;
 cin >> l1 >> r1 >> l2 >> r2 ;
 int x = min(r1 , r2) - max(l1 , l2);
 if (x < 0) cout << 1;
 else {
    cout << x + (l1 != l2) + (r1 != r2) ; 
 }
}       

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
     cin >> t;
    while(t--){
        doWork(); cout << '\n';
    }
}
