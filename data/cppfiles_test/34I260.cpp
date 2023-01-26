
//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%lld",&x)
#define lli long long int
#define ll64 int64_t
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define frr(i,a) for(int i=0;i<a;i++)
#define frl(i,a) for(lli i=0;i<a;i++)
#define fr1(i,a) for(int i=1;i<=a;i++)
#define iter(x)  x.begin(),x.end()
#define Memset(a,x,n) for(int i=0;i<n;i++)a[i]=x;
#define fi first
#define si second
//std::string s=std::bitset<M>(n).to_string();  //number to binary string
//lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
//upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
//if mod is prime modInv(a,mod)==binExp(a,mod-2);
typedef pair<lli,lli>pll;
typedef tree<pair<pll,lli>,null_type,less<pair<pll,lli>>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
//if we are working with pair write pii in place of int.
//indexed_set s , declaration. s.insert(x) ,to insert x. find_by_order(x) , to find the xth smallest element in the set(starting from 0).  order_of_key(x) to find the lower bound position of key x.(starting from 0)

const lli inf=2000005;
void solve()
{
    lli n,m;
    cin>>n>>m;
    lli a[n];
    frr(i,n)cin>>a[i];
    lli ans=-inf;
    for(int i=n-1,j=0;j<min(100ll,n);i--,j++)
    {
        for(int k=0;k<n;k++)
        {
            if(i!=k)
            {
                ans=max(ans,  ((i+1)*(k+1))-m*(a[i]|a[k]));
            }
        }
    }
    cout<<ans<<endl;

}
int main()
{
    int t=1,tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        solve();
    }
}

