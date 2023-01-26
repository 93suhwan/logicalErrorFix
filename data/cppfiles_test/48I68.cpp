// Designed by Nguyen Thanh Chau
// a.k.a Paperback Collector
// En Taro Adun! - TemplarAssasin a.k.a Zeratul

//                #####                #####
//              ###    ####        ####    ###
//             ##         ###    ###         ##
//             ##            ####            ##
//             ##            ####            ##
//             ##          ##    ##          ##
//             ##        ###      ###        ##
//              ##  ######################  ##
//           ######    ###          ###    ######
//       ###    ##    ##              ##    ##    ###
//    ###        ## ###      ####      ### ##       ###
//   ##	          ####     ########     ####          ##
//  ##            ###     ##########     ###           ##
//   ##	          ####     ########     ####          ##
//    ###        ## ###      ####      ### ##       ###
//       ###    ##    ##              ##    ##    ###
//           ######    ###          ###    ######
//              ##  ######################  ##
//             ##        ###      ###        ##
//             ##          ##    ##          ##
//             ##            ####            ##
//             ##            ####            ##
//             ##         ###    ###         ##
//              ###    ####        ####    ###
//                #####                #####


////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                Libraries and stuffs                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

// Libraries

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

// Defines
	
	// Typedefs
	
	#define ll long long
	#define ld long double
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define f first
	#define s second
	#define p pair
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	//Commands
	
		// Loops
		
		#define FOR(i,a,b) for (ll i=(ll)a; i<=(ll)b; i++)
		#define FOR2(i,a,b) for (ll i=(ll)a; i<=(ll)b; ++i)
		#define FORD(i,a,b) for (ll i=(ll)a; i>=(ll)b; i--)
		
		// Get values
		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		
		// Clear containers
		
		#define reset(C) memset(C,0,sizeof(C))
		#define Fill(C,a) fill(C.begin(), C.end(), a)
		
		// Customize containers
		
		#define SORT(C) sort(C.begin(), C.end())
		#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
		#define SORTC(C,check) sort(C.begin(), C.end(), check)
		#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
		#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
		#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
		#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
		#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
		#define revrs(C) reverse(C.begin(), C.end())
		
		// Scan and print containers

		#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
		#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
		
	// Containers
	
	#define vec(x) vector<x> 
	#define Matrix(x) vector<vector<x> >
	#define Rubik(x) vector<vector<vector<x> > >
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	#define ordered_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
	#define ordered_multiset(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
	
	// System
	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Namespaces

using namespace std;
using namespace __gnu_pbds;
// using namespace __gnu_cxx;

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               A few extra functions                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

multiset<ll> LIS(vector<ll> A)
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.upper_bound(A[i]);
		if (it != S.end()) S.erase(it);
	}
	return S;
}

multiset<ll> LSIS(vector<ll> A) // a.k.a Longest Strictly Increasing Sequence
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.lower_bound(A[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}

ll gcd(ll a, ll b)	
{
	if (a == 0) return(b);
	return(gcd(b % a, a));
}

ll extGcd(ll a, ll b, ll& x, ll& y) // returns d=gcd(a,b), and give one pair x,y such that ax+by=d
{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = extGcd(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}

ll powermod(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ull k = powermod(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}

// Prime test for large numbers

bool isPrime(ull n, int iter = 5) 
{
    if (n < 4) return n == 2 || n == 3;
	if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 0; i < iter; i++) 
	{
        ull a = 2 + rand() % (n - 3);
        if (powermod(a, n - 1, n) != 1) return false;
    }
    return true;
}

// Mod int

struct Mint
{
	ll MOD = 1e9 + 7;
	int val;

	bool operator==(const Mint& other)
	{
		return val == other.val;
	}

	Mint operator+(const Mint& other)
	{
		int res = val + other.val;
		while(res >= MOD) res -= MOD;
		while(res < 0) res += MOD;
		return Mint(res);
	}

	Mint operator-(const Mint& other)
	{
		int res = val - other.val;
		while(res >= MOD) res -= MOD;
		while(res < 0) res += MOD;
		return Mint(res);  
	}

	Mint operator*(const Mint& other)
	{
		return Mint((val * 1ll * other.val) % MOD);
	}

	Mint pow(int y)
	{
		Mint z(1);
		Mint x(val);
		while(y > 0)
		{
			if(y % 2 == 1) z = z * x;
			x = x * x;
			y /= 2;
		}
		return z;
	}

	Mint operator/(const Mint& other)
	{
		return Mint(val) * Mint(other.val).pow(MOD - 2);
	}
  
	Mint() 
	{
		val = 0;
	};
	Mint(int x)
	{
		x %= MOD;
		while(x < 0) x += MOD;
		val = x;
	};
};

ostream& operator<<(ostream& out, const Mint& x)
{
  return out << x.val;
}

// End of function

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                     Constants                                      //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

ld PI = 3.14159265358979323846;

ld eps = 1e-6;

ll M = 998244353;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                     End of preparation, your code starts HERE                      //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

bool __isprime(ll x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	if (x == 3) return true;
	if (x % 3 == 0) return false;
	ll t = 1;
	for (ll i = 5; i * i <= x; i += 2 * (1 + t))
	{
		if (x % i == 0) return false;
		t = 1 - t;
	}
	return true;
}

ll Tree[200005];

ll a, b;

void build()
{
	FORD(i, a - 1, 1) Tree[i] = gcd(Tree[i << 1], Tree[i << 1 | 1]);
}

ll query(ll l, ll r)
{
	ll ans = 0;
	for (l += a, r += a; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) ans = gcd(ans, Tree[l++]);
		if (r & 1) ans = gcd(ans, Tree[--r]);
	}
	return ans;
}

void Process()
{
	ll a;
	cin >> a;
	vec(ll) C(a);
	getVector(C);
	vec(ll) F = C;
	SORT(F);
	if (a == 1)
	{
		cout << "YES" << '\n';
		return;
	}
	if (a == 2)
	{
		C == F ? cout << "YES" : cout << "NO";
		cout << '\n';
		return;
	}
	if (a == 3)
	{
		if (C[0] == F[0] && C[1] == F[1] && C[2] == F[2])
		{
			cout << "YES" << '\n';
			return;
		}
		if (C[0] == F[1] && C[1] == F[2] && C[2] == F[0])
		{
			cout << "YES" << '\n';
			return;
		}
		if (C[0] == F[2] && C[1] == F[0] && C[2] == F[1])
		{
			cout << "YES" << '\n';
			return;
		}
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}

signed main() 
{
	faster();
	Begin()
	{
		Process();
	}
}

//  Geometric art by Daniel yuan
//  Redraw by Nguyen Thanh Chau
/*   
                ________
               /        \
              / /      \ \
     ________/ /        \ \________
    /        \            /        \ 
   / /      \ \  ______  / /      \ \
  / /        \ \________/ /        \ \
  \            /        \            /
   \  ______  / /      \ \  ______  /	
    \________/ /        \ \________/
    /        \            /        \
   / /      \ \  ______  / /      \ \   
  / /        \ \________/ /        \ \
  \            /        \            /    
   \  ______  / /      \ \  ______  /    
    \________/ /        \ \________/  
             \            /        
              \  ______  /
               \________/   	
*/
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               Coded by thanhchauns2                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////