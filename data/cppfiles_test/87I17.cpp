#include<bits/stdc++.h>
// no of bits to store no 2e5 is 19
// 2e5 ka 5 times square root lene se 2 or 3 ke pass pahunch jate hai
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


#define int               long long
#define mod               1000000007
#define MOD               1000000007
#define MAX               1000000000
#define inf               2e18
#define ff                first
#define ss                second
#define mp                make_pair
#define pb                push_back
#define pii               pair<int,int>
#define mii               map<int, int>
#define all(x)            (x).begin(), (x).end()
#define fill(a,b)         memset(a, b, sizeof(a))
#define sp(x,y)           fixed<<setprecision(y)<<x
#define setbits(x)        __builtin_popcount(x)
#define fast_in_out       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define ll                long long
#define endl              '\n'


#define     ordered_set          tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define     ordered_multiset     tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

//member functions :
//1. order_of_key(k) : index of k in the set according to sorted order and if the element is not present then it will return the imaginary index if element was present( 0 based indexing )
//2. find_by_order(k) : k-th element in the set ( 0 based indexing )

// For Ordered Multiset lower bound and upper bound exchange their functions.




//   powermod(a,b,m) ==  powermod(a,b%(m-1),m)  when m is prime fermat's theorem a^(p-1) %p=1 p is prime
int powermod(int a,int b,int c) //  gives (a^b)%c
{
    int ans = 1,tempans=a%c;
    while(b>0)
    {
        if((b&1)==1)
        {
            ans=(ans*tempans)%c;
        }
             tempans=(tempans*tempans)%c;
             b=b>>1;
    }
    return ans;
}

int modinverse(int a,int m)   // gives a inverse wrt m and m is prime
{
    return powermod(a,m-2,m);
}

ll add(ll x, ll y) {
   x += y;
   if (x >= mod) return x - mod;
   return x;
}
ll sub(ll x, ll y) {
   x -= y;
   if (x < 0) return x + mod;
   return x;
}
ll mult(ll x, ll y) {
   return (x * y) % mod;
}
ll inv(ll x)
{
    return powermod(x, MOD - 2,mod);
}

ll divide(ll x, ll y)
{
    return mult(x, inv(y));
}

// my template                                              m
// prime factorization                                      pf
// ncr and factorials                                       ncr
// matrix exponentiation of fibonacci series in log(n)      matexpofib
// cycles in a graph                                        cycle
// prime factorization in log(n)                            spf
// disjoint set union                                       dsu
// maximum flow                                             mflow



void solve()
{
    int n,m;
    cin>>n>>m;
    ordered_set s;
    set<int> k;
    int a[n];
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        int l=s.order_of_key(x);
       ans+=l;
        s.insert(x);
        k.insert(x);

    }
    cout<<ans<<endl;




}


int32_t main()
{

  // freopen("input.txt" , "r" , stdin ) ;
  // freopen("output.txt" , "w" , stdout ) ;

  fast_in_out;

  int t=1;cin>>t;
  int count=0;


   while(t--)
   {
       count++;
       solve();
   }
}
