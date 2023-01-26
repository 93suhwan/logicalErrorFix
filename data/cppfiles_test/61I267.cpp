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
const int N=2e5+7;
///*/////////////////////////////////////////////////////////*///
const int MOD=1e9+7;
int32_t main() {
 usk ore nie
    int e;
    cin>>e;
    while(e--)
    {
     int n;
     cin>>n;
     int x,y;
     //cin>>x>>y;
     set <int> st1;
     map <int,int> mp1;
     set <int> st2;
     map <int,int> mp2;
     for(int i=0;i<n;++i)
     {
    cin>>x>>y;
    mp1[x]++;
    st1.insert(x);
    if (x!=y) {
    mp2[y]++;
    st2.insert(y);
    }
     }
     int ans=n*(n-1)*(n-2)/6;
     for(auto to:st1)
        ans-=mp1[to]*(mp1[to]-1)/2;
        for(auto to:st2)
            ans-=mp1[to]*(mp1[to]-1)/2;
     cout<<ans<<endl;
    }
    return 0;
 }


