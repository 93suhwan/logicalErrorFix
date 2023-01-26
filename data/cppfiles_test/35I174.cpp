#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <sstream>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <assert.h>
#include <iomanip>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define ull unsigned long long
#define F first
#define S second
#define nl "\n"
#define ld long double
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.rbegin(),v.rend())
#define all(v) v.begin(),v.end()
#define div 1000000007
#define div2 998244353
#define PI 3.141592653589793
#define inf 1000000000000000000LL
#define blk 320
#define pb push_back


void solve()
{
    int n,m;cin>>n>>m;
    if(m<n)
    {
        cout<<0<<nl;
        return;
    }
    int ans=inf;
    int idx=30;
    while(idx>=0 && (m&(1<<idx))==0)
        idx--;
    int cur=0;
    for(int i=idx;i>=0;i--)
    {
        if((m&(1<<i))==0)
        {
            int mex=cur;
            if((n&(1<<i))==0)
                mex+=(1<<i);
            ans=min(ans,mex);
        }
        else
        {
            if((n&(1<<i))==0)
                cur+=(1<<i);
        }
    }
    cout<<ans<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int t=1;
        cin>>t;
        while(t--)
        {
            solve();
        }
}