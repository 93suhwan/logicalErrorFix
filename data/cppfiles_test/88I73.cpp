#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#define int long long int
using namespace __gnu_pbds;
using namespace std;
  

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n*m+1];
    arr[0]=0;
    int d[n*m+1];
    d[0]=0;
    for(int i=1;i<=n*m;i++){
      cin>>arr[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        d[i]=arr[i];
    }
    sort(d,d+n*m+1);
    map<int,int> ff;
    for(int i=1;i<=n*m;i++)
    {
        ff[d[i]]=i;
    }
    new_data_set f;
    int cnt=0;
    for(int i=1;i<=n*m;i++)
    {
        f.insert(ff[arr[i]]);
        cnt+=f.order_of_key(ff[arr[i]]);
    }
    cout<<cnt<<endl;


}
int32_t main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}