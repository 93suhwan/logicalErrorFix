#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define int                     ll
#define ar                      array
#define sz(v)                   (int)(v.size())
#define inf                     1e18
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int>
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll n, ll p) {
	if (n >= mod) n %= mod;
	ll r = 1;
	while (p) {
		if (p & 1) r = (r * n) % mod;
		n = (n * n) % mod;
		p /= 2LL;
	}
	return r;
}
ll modMul(ll a, ll b) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; }
ll modSub(ll a, ll b) { return ((((a % mod) - (b % mod)) % mod) + mod) % mod; }
ll modAdd(ll a, ll b) { return ((((a % mod) + (b % mod)) % mod) + mod) % mod; }
 
ll divmod(ll a, ll b) {
	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	if (a < 0) a += mod;
	if (b < 0) b += mod;
 
	ll ans = a * power(b, mod - 2);
	if (ans >= mod) ans %= mod;
	return ans;
}


// int nCr(int n, int r) {
// 	if (n < r) return 0;
// 	int num = f[n];
// 	int deno = (f[r] * f[n - r]) % mod;
// 	int ans = (num * power(deno, mod - 2)) % mod;
// 	return ans;
// }

vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, -1, 1, 1, -1};

vvii v;
int n,m;

bool check(int x)
{
    vector<bool> a(m);
    bool flag=false,t=true; // 1 shop must have atlest 2 items with (value >= x)
    fo(i,0,n-1)
    {
        int c=0;
        fo(j,0,m-1)
        {
            if(v[i][j]>=x)
            {
                c++;
                a[j]=true;
            }
        }
        if(c>1)
        {
            flag=true;
        }
    }

    for(auto k:a)
    {
        t = t && k;
    }

    if(!flag || !t)
    {
        return false;
    }
    return true;
}

void tarun_the_coder()
{
	int l=1,r=1,ans;
	cin >> n >> m;
	
    v.assign(n,vector<int>(m));

	fo(i,0,n-1)
    {
        fo(j,0,m-1)
        {
            cin>>v[i][j];
            r = max(v[i][j],r);
        }
    }

    //int ans=0;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    cout<<ans<<endl;
}

signed main() {

	FIO
	int t;
	t = 1;
	cin >> t;
	fo(i, 0, t - 1) {
    tarun_the_coder();
	}
	return 0;
}
