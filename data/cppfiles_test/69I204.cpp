#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef long long unsigned int llu;
const int INF = 0x3f3f3f3f;

#define ff first
#define ss second
#define ins insert
#define tc   \
  int tt;    \
  cin >> tt; \
  while (tt--)

#define sync                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define pb push_back
#define pf pop_front
#define mp make_pair
#define all(v) v.begin(), v.end()

#define mpi unordered_map<ll, ll>
#define pr pair<ll, ll>
#define vi vector<ll>
#define vc vector<char>

#define mpc unordered_map<char, ll>
#define it_loop(it, m) for (auto it = m.begin(); it != m.end(); it++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repx(i, begin, end) for (ll i = begin; i <= end; i++)

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//#define mod 1e9+7
#define count_ones __builtin_popcountl               // #ones in binary rep.
#define what_is(x) cerr << #x << " is " << x << endl //#x -> actual name of variable

#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
#define eb emplace_back                         // faster than push_back
#define mt make_tuple                           //  for returning more than one value with tie(args ...) = tuple
#define fill(a, n, start) iota(a, a + n, start) // fill array in increasing order

#define shuffle(a, n) shuffle(a, a + n, default_random_engine(0))
#define print_arr(a, n) rep(i, n) cout << a[i] << endl
#define read_arr(a, n) rep(i, n) cin >> a[i]
#define ook order_of_key // ook(n) It returns to the number of items that are strictly smaller than our item n

#define nds new_data_set  //pbds array
#define fbo find_by_order // fbo(i), returns an iterator at the ith index
#define graph_i unordered_map<ll,vector<ll>>
#define graph_pair unordered_map<ll,vector<pair<ll,ll>>>
#define f(t) get<0>(t)
#define s(t) get<1>(t)
#define t(t) get<2>(t)
#define ft(t) get<3>(t)
void err(istream_iterator<string> it){}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
string key(int x,int y){
	return to_string(x) + ':' + to_string(y);
}
/* gcd __gcd(a,b)
 * sparse_table: st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1])
 * sparse_table: for range query in immutable array
 * modified queue: stack<pair<ll,ll>> s1,s2   s1->add,  s2->delete
 * long long binpow(long long a, long long b) {    long long res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}
 * " \n"[0] is ' ' and " \n"[1] is '\n'
 * we can also use ignore keyword in tie to ignore a value ->  tie(b, ignore, a, ignore)
 * 0 based indexing in pbds ordered_set
 * add(l,x) & add(r+1,-x) for BIT range update point query
 * use scanf and printf insted of fastio
 * gcc optimizations work best with arrays not vectors
 * use int till 1e5
*/
//ll mod = 1e9 + 7;
//long long binpow(long long a, long long b) {    long long res = 1;while (b > 0) {if (b & 1)res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res%mod;}

void solve(){
	ll n;
	cin>>n;
	
	vi v;
	v.pb(0);
	for(ll i=0;pow(2,i)<=n*n; i++)
		v.pb(pow(2,i));
	int ans = 11;
	string s2 = to_string(n);
	
	for(ll X:v){
		string s1 = to_string(X);
		for(size_t i=0;i<s2.size();i++){
			int l1=0,l2=i;
			while(l1<s1.size() && l2<s2.size()){
				if(s1[l1]==s2[l2]){
					l1++,l2++;
				}else l2++;
			}
			ans=min(ans,int(s2.size())-l1 + (int(s1.size())-l1));
		}
	}
	int x = n<=10?1:100;
	cout<<min(ans,x)<<endl;
}

int main()	
{
  sync;
  tc { solve(); }
  //solve();
}
