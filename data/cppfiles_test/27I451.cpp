#include<bits/stdc++.h>
using namespace std;

#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int     long long

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    k -= 2;
    if(m < (n-1) || m > (n*(n-1))/2) {
        cout<<"NO\n";
    } else if(k <= -1) {
        cout<<"NO\n";
    } else if(k == 0) {
        if(n == 1) {
            cout<<"YES\n";
        } else {
            cout<<"NO";
        }
    } else if(k == 1) {
        if(m == n*(n-1)/2) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    } else {
        cout<<"YES\n";
    }
}

int_fast32_t main() {
    FIO;
    int tt;
    cin>>tt;
    while(tt--) {
        solve();
    }
    return 0;
}
