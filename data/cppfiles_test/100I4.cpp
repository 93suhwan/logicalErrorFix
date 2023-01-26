#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 #include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; 
#define sor(vec) sort(vec.begin(), vec.end())
#define rever(vec) reverse(vec.begin(), vec.end())
#define trav(x , p) for(auto &x : p)
#define ull  unsigned long long
 #define MAXN 200005
 #define fi first
#define se second
const ll mod =998244353; 
#define dbg(i,j,k)  cout<<"("<<i<<","<<j<<")"<<" "<<k<<" "
#define dbgp(i,j)   cout<<i<<" "<<j<<endl
#define print cout<<"**"<<endl;
 const int inf=1e9+7;
 void vcin(vector<ll> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
 void vcout(vector<ll> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
const ll MOD = 1e9+7;
double eps = 0.0000001;
#define endl "\n";
 //member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
// cout<<"Case #"<<p<<": "<<ans<<endl;


void solve()
{
  
   ll n;
   cin>>n;
   multiset<ll> s;
   vector<ll> v(n);
   for(int i=0;i<n;i++)
   {
      ll x;
      cin>>x;
      s.insert(x);
      v[i]=x;
   }
   sor(v);
   if(n==1)
   {
      cout<<v[0]<<endl;
      return ;
   }
   ll ans=*s.begin();
   s.erase(ans);
   ll del=0;
   ll curr=ans;
  
   while(!s.empty())
   {
         ans=max(ans,*s.begin()-curr);
            curr+=(*s.begin()-curr);
         //del+=(*s.begin()-del-curr);
         //curr=*s.begin();
         //dbgp(ans,curr);
         s.erase(*s.begin());
   }
   cout<<ans<<endl;
}



int32_t main()  
{
  
  
	 ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
     
         ll t;
         cin>>t;
      
   
         while(t--)
         {
            solve();
         }
   
}

