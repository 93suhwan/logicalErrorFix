#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define lli long long int
#define INF 1000000000000000000
#define llu unsigned long long int
#define pb push_back
#define ff first
#define ss second
long long mod=1000000007;
/*
bool comparator(const pair<vector<int>,int> a,const pair<vector<int>,int> b)
{
return a.ff.size()<b.ff.size();
}
*/
vector<int> getans(int n,int add)
{
  int i;
  vector <int> ans;
  for(i=1;i<n;i+=2)
  ans.pb(i+add);
  for(i=n-4;i>=1;i--)
  ans.pb(i+add);
  return ans;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t,n,i,f,pos;
cin>>t;
while(t--)
{
  cin>>n;
  vector <int> a(n+1),pref(n+1);
  for(i=1;i<=n;i++)
  cin>>a[i];
  pref[1]=a[1];
  for(i=2;i<=n;i++)
  pref[i]=pref[i-1]^a[i];
  pos=0;f=0;
  if(n%2==0)
  {
    pos=-1;
    for(i=1;i<n;i+=2)
    if(pref[i]==0)
    {
      pos=i;
      break;
    }
  }
  if(pref[n]!=0)
  f=1;
  if(f==1||pos==-1)
  cout<<"NO\n";
  else
  {
    cout<<"YES\n";
    vector <int> ans;
    if(n%2)
    ans=getans(n,0);
    else
    {
      ans=getans(n-pos,pos);
      if(pos!=1)
      {
        vector <int> tmp=getans(pos,0);
        n=(int)tmp.size();
        for(i=0;i<n;i++)
        ans.pb(tmp[i]);
      }
    }
    n=(int)ans.size();
    cout<<n<<"\n";
    for(i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<"\n";
  }
}
}