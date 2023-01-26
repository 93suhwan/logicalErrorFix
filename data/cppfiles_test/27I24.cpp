#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fill(arr,c) memset(arr,c,sizeof(arr))
#define perm(r) next_permutation(all(r))
//it gives bool value ans permute the string lexoggraphically
#define sortdesc greater<int>()
#define ll long long int 
//std::setfill('0') << std::setw(5) << 25; it adds leaing zeroes;
#define f(i,a) for(ll i=0;i<a;i++)
#define fo(i,a) for(ll i=1;i<=a;i++)
#define foo(i,x,n,c) for(ll i=x;i<n;i+=c)
#define foi(i,x,n,c) for(ll i=x;i>=n;i+=c)
#define fauto(i,m) for(auto i:m)
#define forall(a) for( auto itr=a.begin();itr!=a.end();itr++)
#define ld long double
#define in push_back
#define vl vector<ll >
#define o(a) cout<<a
#define os(a) cout<<a<<" "
#define en cout<<"\n";
#define testcase ll t ;cin>>t; while(t--)
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define sz(a)  (a).size()
#define prec(n) fixed<<setprecision(n)
#define mp make_pair
#define bitcount  __builtin_popcountll
#define imin o("imin");en;
//for interactive use endl after every output and fflush(stdout) after every input//
//  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
using namespace __gnu_pbds;
typedef  tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void fastio()
{
    	ios::sync_with_stdio(0);
cin.tie(0);

}
ll M=1e9+7;
ll mod( ll m ,ll mod = M) {
   m %= mod;
   return (m + mod) % mod;
}
 

int main()
{
fastio();

testcase
{
ll n,m,k;
cin>>n>>m>>k;
k--;
ll ans=(n*(n-1))/2;
if(m==ans && k>1)
{
	o("YES");
}
else if(m>=n-1 && m<ans && k>2)
{
	o("YES");
}
else
o("NO");
en;
}
return 0;
}
//grAPH layering 
// knapsack
// dp //digitdp
//binary search
//dsu //square root decomposition //binary lifting 
// lca can be found using binary search and binary lifing
// * int over/under flow?
// * modulo mistake (forgot? / incorrect for -ve?)
// * array bounds? 
// * variable uninitialized?
// * dont get stuck in one approach
// * can it be reduced? (to graph? to bsearch? to NP-hard?)
// * Is there any special constraint to be exploited?
// * special cases (n=0,1? division by 0 somewhere?)
// * review precision error? missing typecasts?
// *cin.ignore() before getline for whitespaces ignored due to cin
// *segtree //*fenwicktreee //*kmp 

// *docker exec -ti my_container sh -c "echo a && echo b"
