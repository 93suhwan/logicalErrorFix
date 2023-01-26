#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define MAX(a,b,c) max((ll)a,max((ll)b,(ll)c))
#define MIN(a,b,c) min((ll)a,min((ll)b,(ll)c))
#define umpll unordered_map<ll,ll>
#define mpll map<ll,ll>
#define deb(x) cout << #x<<' '<< x << endl;
#define deb2(x,y) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<endl;
#define deb3(x,y,z) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<' '<< #z<<' '<<z<<endl;
#define dar(arr,t)  for(ll pn=t;pn<arr.size();pn++)  cout<<arr[pn]<<' ';  cout<<endl; 
#define pll pair<ll,ll>
#define cord(x,y) vector<ll> x={1,0,-1,0},y={0,1,0,-1};
#define bits(x) __builtin_popcountll(x)
#define trail(x) __builtin_ctzll(x);
#define pb_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pb_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define element(x) find_by_order(x) //iterator to xth element.
#define less(x) order_of_key(x) //index of xth element (zero based).
#define pdoub(x)  cout<<fixed<<setprecision(10)<<x;
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
ll n,m,k;
vector<ll> v;
void solve()
{
cin>>n>>m;
string s;
cin>>s;
ll ans2;
ll y=0;
ll mx=0;
ll mn=0;
for(ll i=0;i<s.length();i++)
{
if(s[i]=='L')
y-=1;
else if(s[i]=='R')
y+=1;
mn=min(mn,y);
mx=max(mx,y);
if(abs(mn)+mx>m-1)
{
ans2=m-mx;
break;
}
ans2=m-mx;
}
ll x=0;
ll ans1;
mx=0;
mn=0;
for(ll i=0;i<s.length();i++)
{
    if(s[i]=='U')
    x-=1;
    else if(s[i]=='D')
    x+=1;
    mn=min(mn,x);
    mx=max(mx,x);
    if(abs(mn)+mx>n-1)
    {
    ans1=n-mx;
    break;
    }
    ans1=n-mx;

}
cout<<ans1<<" "<<ans2<<"\n";
}
int main()
{
fast
ll q;
cin>>q;
while(q--)
{
v.clear();
solve();
}
}