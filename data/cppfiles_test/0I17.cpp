#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
void __print(int x){cout<<x;}void __print(long long x){cout<<x;}
void __print(double x){cout<<x;}void __print(long double x){cout<<x;}
void __print(char x){cout<<'\''<<x<<'\'';}void __print(const char *x){cout<<'\"'<<x<<'\"';}
void __print(const string &x){cout<<'\"'<<x<<'\"';}void __print(bool x){cout<<(x?"True":"False");}
template<typename T,typename V>
void __print(const pair<T,V>&x){cout<<'{';__print(x.first);cout<<',';__print(x.second);cout<<'}';}
template<typename T>
void __print(const T &x){int f=0;cout<<'{';for(auto &i:x)cout<<(f++?",":""),__print(i);cout<<"}";}
void _print(){cout<<"]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define lp(i,a,b)       for (int i=a;i<=b;i++)
#define rp(i,a,b)       for (int i=a;i>=b;i--)
#define ms(a,x)         memset(a,x,sizeof a)
//#define int             long long 
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define rall(a)         a.rbegin(),a.rend()
#define pb              push_back
#define nl              cout<<"\n"
#define index           find_by_order
#define less            order_of_key
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        (((a)*(b))/(gcd(a,b)))
#define sq(a)           ((a)*(a))
#define sz(a)           (int) a.size()
#define mod             1000000007
const int N=1e6+5;
string arr[N];
int n,m;
bool cmp(string& a,string& b)
{
  lp(i,0,m-1)
  {
    if(a[i]==b[i])
      continue;
    if(i%2==0)
      return a[i]<b[i];
    else
      return a[i]>b[i];
  }
  return 1;
}
void mergE(int l , int mid , int r)
{
    vector < string > lef , rig;
    for(int i = l ; i<=mid ; i++) lef.push_back(arr[i]);
    for(int i = mid + 1 ; i<=r ; i++) rig.push_back(arr[i]);
 
    int i = 0 , j = 0, cur = l; 
    while(i<lef.size() && j<rig.size()){
        if(cmp(lef[i],rig[j])){
            arr[cur] = lef[i];
            i++;
        }
        else{
            arr[cur] = rig[j];
            j++;
        }
        cur++;
    }
 
    while(i<lef.size()){
        arr[cur] = lef[i];
        i++;
        cur++;
    }
 
    while(j<rig.size()){
        arr[cur] = rig[j];
        cur++;
        j++;
    }
 
}
 
void merge_sort(int l, int r)
{
    if(l<r)
    {
      int mid = (l+r)/2;
      merge_sort(l,mid);
      merge_sort(mid+1,r);
      mergE(l,mid,r);
    }
}
void solve()
{
  cin>>n>>m;
  lp(i,1,n)
  {
    cin>>arr[i];
    arr[i]+=(char)(i+'0');
  }
  merge_sort(1,n);
  lp(i,1,n)
    cout<<arr[i].back()<<' ';
}

signed main()
{
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  int T=1; 
  //cin>>T;
  while(T--) solve();
  return 0;
}
