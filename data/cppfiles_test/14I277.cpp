#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;
//memset(dp,-1,sizeof(dp));
//map<pair<ll,ll>,ll>mp;
//*p.find_by_order(ind) ...return iterator of index ind
// p.order_of_key(k)    ...return no of elements less  than k
bool compare(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.first<b.first;
}

const int M=1000000007;
string str="abcdefghijklmnopqrstuvwxyz";
void solve()
{
   ll n,i;
   cin>>n;
   ll a[n];
   for(i=0;i<n;i++)
    cin>>a[i];
   vector<ll>v;
   v.push_back(a[n-1]);
   ll c=0;
   vector<pair<int,int>>sexy;
   for(i=n-2;i>=0;i--)
   {
       if(a[i]<=v[0])
        v.insert(v.begin(),a[i]);
       else
       {
           //cout<<i+1<<" "<<n<<" "<<1<<endl;
           ll x=i;
           for(int k=0;k<v.size();k++)
           {
               if(v[k]<a[i])
               {
                   x++;
                   continue;
               }
               else
               break;
           }
           sexy.push_back({i+1,x+1});
           c++;
           v.push_back(a[i]);
       }
   }
   cout<<c<<endl;
   for(auto x:sexy)
   {
       cout<<x.first<<" "<<x.second<<" "<<1<<endl;
   }
}
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    
    
    int t;
    cin>>t;
    while(t--)
	 solve();
}