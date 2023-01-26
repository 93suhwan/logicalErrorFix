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
struct node{
  lli ans;
  int pl;
  int sl;
  int fst;
  int lst;
  int flag;
  node operator+(const node &other)
  {
    node x=*(this);
    x.ans=ans+other.ans;
    if(lst<=other.fst)
    x.ans+=sl*other.pl;
    x.pl=pl;
    x.flag=0;
    if(flag)
    {
      if(lst<=other.fst)
      {
        x.pl+=other.pl;
        if(other.flag)
        x.flag=1;
      }
    }
    x.sl=other.sl;
    if(other.flag)
    {
      if(lst<=other.fst)
      x.sl+=sl;
    }
    x.fst=fst;
    x.lst=other.lst;
    return x;
  }
};
node tre[600000];
int n;
node sum(int st,int end,int a,int b,int index)
{
  if(st>b||end<a)
  {
  node d;
  d.ans=0;
  d.pl=0;
  d.sl=0;
  d.fst=0;
  d.lst=0;
  d.flag=0;
  return d;
  }
  if(st>=a&&end<=b)
  return tre[index];
  int mid=(st+end)/2;
  node lft=sum(st,mid,a,b,index*2);
  node rt=sum(mid+1,end,a,b,index*2+1);
  node mn=lft+rt;
  return mn;
}
void add(int i,int x)
{
  i+=n-1;
  tre[i].fst=x;
  tre[i].lst=x;
  for(i/=2;i>=1;i/=2)
  tre[i]=tre[2*i]+tre[2*i+1];
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int m,n1,d,i,type,l,r,a;
lli mans;
cin>>n>>m;
vector <int> v;
for(i=0;i<n;i++)
{
cin>>a;
v.pb(a);
}
d=1;
while(d<n)
d*=2;
for(i=1;i<=(d-n);i++)
v.pb(0);
n1=n;
n=d;
for(i=n;i<2*n;i++)
{
  if(v[i-n]>0)
  {
    tre[i].ans=1;
    tre[i].pl=1;
    tre[i].sl=1;
    tre[i].flag=1;
  }
  else
  {
    tre[i].ans=0;
    tre[i].pl=0;
    tre[i].sl=0;
    tre[i].flag=0;
  }
  tre[i].fst=v[i-n];
  tre[i].lst=v[i-n];
}
for(i=n-1;i>=1;i--)
tre[i]=tre[2*i]+tre[2*i+1];
while(m--)
{
  cin>>type>>l>>r;
  if(type==1)
  add(l,r);
  else
  {
    mans=sum(1,n,l,r,1).ans;
    cout<<mans<<"\n";
  }
}
}