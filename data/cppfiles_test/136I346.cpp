#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define mod 1000000007
#define PI 3.1415926535
#define maxn 100005
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(),x.end()
#define speedUp ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
void _SSGJ_()
{   
    int n;
    cin>>n;

    vector <int> v(n);
    int s=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        s += v[i];
    }

    int val = n*(n + 1)/2;
    if(s%val){
        cout<<"NO\n";
        return;
    }

    s /= val;
    vector <int> ans(n,0);
    for(int i=0;i<n - 1;i++){
        int d = v[i + 1] - v[i];
        if((s - d)%n || s - d <= 0){
            cout<<"NO\n";
            return;
        }

        ans[i + 1] = (s - d)/n;
    }

    for(auto i: ans){
        s -= i;
    }

    ans[0] = s;
    cout<<"YES\n";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"\n";

}
 
signed main()
{
    speedUp
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
   #endif
   
    int t;
    cin>>t;
    while(t--)
    _SSGJ_();
   
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    return 0;
}