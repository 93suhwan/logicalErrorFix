///    Success is not a Miracle , it's a journey of DEDICATION   ///

/*
 *
 * FILE: C.cpp
 *
 * Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
 *
 * Name        : Sourav Roy (Shuvo)
 *
 * Department  : Computer Science and Engineering (Batch - CSE'19)
 *
 * Email       : souravkumarroy813965@gmail.com
 *
 */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
// Graph on 2D Grid //
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve()
{
    int n,d,i,mn=1e18,ans=1e18;
    cin >> n;
    int arr[n+5];
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        mn = min(arr[i],mn);
    }
    vector <int> smallest;
    for(i=1; i<=n; i++)
    {
        if(mn==arr[i])
        {
            smallest.pb(i);
        }
        if(i>2)
        {
            d = arr[i]/3;
            arr[i-1] += d;
            arr[i-2] += (2*d);
            arr[i] -= (3*d);
        }
    }

    for(i=0; i<smallest.size(); i++)
    {
        ans = min(ans,arr[smallest[i]]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :

**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

