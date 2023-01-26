#pragma GCC optimize("Ofast")
//#pragma target("avx2")
///*/////////////////////////////////////////////////////////*///
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
///*/////////////////////////////////////////////////////////*///
#define pb push_back
#define ll long long
#define ld long double
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define endl "\n"
#define usk ios_base::sync_with_stdio(0);
#define ore cin.tie(0);
#define nie cout.tie(0);
///*/////////////////////////////////////////////////////////*///
using namespace std;
using namespace __gnu_pbds;
///*/////////////////////////////////////////////////////////*///
template <typename T>
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///*/////////////////////////////////////////////////////////*///
const int N=2e5;
///*/////////////////////////////////////////////////////////*///
const int MOD=1e9+7;
int32_t main() {
    usk ore nie
    int e;
    cin>>e;
    while(e--)
    {
        int z,x,c;
        cin>>z>>x>>c;
        if (z==x) {
        if (c%2==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }
        else if (z==c) {
         if (x%2==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }
        else if (c==x) {
            if (z%2==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}
