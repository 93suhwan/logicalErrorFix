/*
source code by vishnu verma
 
tej_1441
 
it's my arrival.
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

      //this doesn't work for array so convert it into vector before calculating
      // this work for the container which can be transversed using for(auto it:container);
          void __print(int x) {cerr << x;}
          void __print(long x) {cerr << x;}
          void __print(long long x) {cerr << x;}
          void __print(unsigned x) {cerr << x;}
          void __print(unsigned long x) {cerr << x;}
          void __print(unsigned long long x) {cerr << x;}
          void __print(float x) {cerr << x;}
          void __print(double x) {cerr << x;}
          void __print(long double x) {cerr << x;}
          void __print(char x) {cerr << '\'' << x << '\'';}
          void __print(const char *x) {cerr << '\"' << x << '\"';}
          void __print(const string &x) {cerr << '\"' << x << '\"';}
          void __print(bool x) {cerr << (x ? "true" : "false");}
          template<typename T, typename V>
          void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
          template<typename T>
          void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
          void _print() {cerr << "]\n";}
          template <typename T, typename... V>
         void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
          #ifndef ONLINE_JUDGE
          #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
          #else
          #define debug(x...)
          #endif

#define pb               push_back
#define ed               endl
#define doub(x);         cout<<fixed<<setprecision(20)<<x;
#define int              long long
#define ll               long long
#define ld               long double
#define db               double
#define ull              unsigned long long
#define mk               make_pair
#define pii              pair<int,int>
#define pldb             pair<ldb,ldb>
#define ff               first
#define ss               second
#define vull             vector<ull>
#define ub               upper_bound
#define lb               lower_bound
#define loop(i,a,b)       for(int i=a;i<b;i++)
#define mem1(a)          memset(a,-1,sizeof(a))
#define mem0(a)          memset(a,0,sizeof(a))
#define sortg(v)         sort(v.begin(),v.end(),greater<ll>())
#define vi               vector<int>//vll v; means vector<long long>v;
#define vb               vector<bool>
#define vldb             vector<ldb>
#define vp               vector<pii>
#define vpldb            vector<pldb>
#define pqmin            priority_queue<ll,vector<ll>,greater<ll>>  //minheap
#define pq               priority_queue<int> //maxheap
#define pqmaxp           priority_queue<pair<int,int>>//pqr with pairs
#define pqminp           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define mldb             map<ldb,ldb>
#define us               unordered_set<ll>
#define ppc(x)         __builtin_popcount(x)
#define pp(x)          __builtin_parity(x)
#define ppll(x)        __builtin_parityll(x)
#define clz(x)         __builtin_clz(x)
#define ctz(x)         __builtin_ctz(x)
#define clzll(x)       __builtin_clzll(x)
#define ctzll(x)       __builtin_ctzll(x)
#define ppcll(x)       __builtin_popcountll(x)
#define maxx           1e9+7
#define minn          -(1e9+7)
ll mod=1000000000+7;//998244353;
ll inf=1e17;
 //memset(dp, -1, sizeof dp);
//1<log(n)<sqrrt(n)<n<nlog(n)<n^2<n^3<........<2^n<3^n.....<n^n
/* n<=22    O((2^n)*n)            * 1->no of digits=floor(log10(n))+1;
2->transform(s.begin(),s.end(),s.begin(),::toupper)  to transform string to uppercase
3->return(x&&(!(x&(x-)))); tell if x is power of 2;
4->accumulate(v.begin(),v.end(),0);
5->return(log2(n & -n) + 1) gives position of rightmost set bit 
6->val = std::ceil(val * 100.0) / 100.0; is used to find round upto 2 decimal places

iota(order.begin(), order.end(), 0); used to assign consecutive value from 0 to n
vector<int>::iterator it;
__lg(10)=3   to know
log(i)=log(i/2) + 1 recurrance relation to calculate the log value
log(10)=2.3059*log10(10)
log10(10)=1
cout<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<ed;  set the feild width to 2 and default value is 0
*/
/*
NOTE-pow() funtion is not so precise
order_of_key(val)--->give no of element strictly less than the required val
find_by_order(k)---->kth element in set(counting from 0)
to make multiordered set use less_equal
to use pair type pair<int,int>
distance funtion is O(n) time complexity for set it doesn't allow randon point access
always use sq=sqrt(n) as index or for calculation

*/
/*---------------------------------------------------------------------------------------------------*/
const int N=2e5+5;
bool prime[N];
void print_vector(vector<int>v){for(int i=0;i<v.size();i++){cout<<v[i]<<' ';}cout<<ed;}
ll power(ll a,ll n,int p){ ll res=1;while(n){if(n%2==0){a=(a*a)%p;n=n/2;}else{n--;res=(res*a)%p;}}return(res);}
bool pred(pair<int,int>p1,pair<int,int>p2){if(p1.ss!=p2.ss){return(p1.ss<p2.ss);}else{return(p1.ff<p2.ff);}}
void sort_second(vector<pair<int,int>>&v){sort(v.begin(),v.end(),pred);}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x/gcd(x,y)*y;}
int countpf(int x){int ans=0;for(int i=2;i*i<=x;i++) while(x%i==0) ans++, x/=i;if(x>1) ans++;return ans;}
void normalize(pair<int,int>&p){int val1=p.ff;int val2=p.ss;int g=gcd(abs(val1),abs(val2));p.ff/=g;p.ss/=g;}
/*------------------------------------------------------------------------------------------------------*/

void tej_1441()
{
int n;
int m;
cin>>m;
int arr[m];
for(int i=0;i<m;i++)
{
    cin>>arr[i];
}
cin>>n;
// mem1(dp);
int dp1[n+2][m+1];
mem0(dp1);
for(int i=0;i<=m;i++)
{
    dp1[0][i]=1;
}
for(int i=0;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        dp1[i][j]=dp1[i][j-1]%mod;
        if(arr[j-1]<=i)
        {
            dp1[i][j]=(dp1[i][j]%mod +dp1[i-arr[j-1]][j]%mod)%mod;
        }
    }
}
cout<<dp1[n][m]<<ed;



}
int32_t main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
//primegen()
int t;
cin>>t;
while(t--)
tej_1441();
return(0);
}