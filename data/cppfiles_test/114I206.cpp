#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
//#define int long long
#define nline "\n"
#define _USE_MATH_DEFINES
#define ld long double
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define pi 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ull power(ull x,ull y,int p){ull res=1;x=x%p;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ull powull(ull x,ull y){ull ans=1;while(y--)ans=ans*x;return ans;}




void solve(){
int t=1;       cin>>t;
while(t--)
{
    int n;cin>>n;
    int a[n];
    set<int>s;
    for(int i=0;i<n;i++){
            cin>>a[i];
    s.insert(a[i]);
}
    sort(a,a+n,greater<int>());
    int k=n/2;
    int i=1;
    while(i<n&&k)
    {
        if(s.find(a[0]%a[i])==s.end())
        {
            cout<<a[0]<<' '<<a[i]<<endl;
            k--;
        }
        i++;
    }




}
}



int32_t main()
{

ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
return 0;
}

