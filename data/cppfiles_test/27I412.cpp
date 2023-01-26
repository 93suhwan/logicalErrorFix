#include<bits/stdc++.h>
using namespace std;

#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int     long long

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    if(m < n-1 || m > (n*(n-1)/2) )  {
        cout<<"NO\n";
        return;
    }
    if(n == 1) {
        if(k>0 && m == 0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        return;
    }

    if(m == (n*(n-1)/2)) {
        if(k > 2) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        return;
    }

    if(k>3) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
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
