/// In the name of Allah the most beneficent the most merciful

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cstdio>
#include <fstream> 

using namespace std;
using namespace __gnu_pbds;

/// It's a good template for c++ competitive programming
/// written by Mohammad Parsa Elahimanesh -> m.p.elahimanesh@gmail.com
/// last update : 2021/April/09

/// # clock  notice: Time in linux should divide by 1000
#define Start clock_t START; START = clock();
#define Time cout << endl << "TIME until now is : "<<(clock() - START) << " ms" << endl;

/// # Faster
#define Fast ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast","unroll-loops","O3")

/// # debug
#define err(x) cerr << #x << " : "<< x << endl;
#define err2(x,y) err(x);err(y);
#define err3(x,y,z) err(x);err(y);err(z);

/// # vector
#define all(x) x.begin(),x.end()

/// # max and min
#define maxer(a,b) a = max(a,b);
#define miner(a,b) a = min(a,b);

/// # pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second

/// # input/output
#define File ifstream fin("input.txt"); ofstream fout("output.txt");

/// # multi usage
#define low lower_bound
#define upp upper_bound
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sz(x) (int)x.size()

/// # for
#define sfor(a,b,c,d) for(a;b;c)if(d)
#define FOR(x,n) for(int x = 0; x < n; x++)
#define RFOR(x,n) for(int x = n-1; x >= 0; x--)

typedef long long int ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

template <typename T, typename P>
inline ll max(const T &a, const P &b)
{
	return a > b? a : b;
}

template <typename T, typename P>
inline ll min(const T &a, const P &b)
{
	return a < b? a : b;
}

template <typename T, typename P>
ostream &operator<<(ostream &output, pair<T,P> &D)
{
	output << D.fi << ' ' << D.se;
	return output;
}

template <typename T, typename P>	
istream &operator>>(istream &input, pair<T,P> &D)
{
	input >> D.fi >> D.se;
	return input;
}

ll Pow(ll a, ll b)
{
	ll ans = 1LL;
	while(b){
		if(b%2)ans *= a;
		b >>= 1;a *= a;}
	return ans;
}

ll Pow(ll a, ll b, ll mod)
{
	ll ans = 1LL;
	while(b){
		if(b%2)ans *= a;
		b >>= 1;a *= a;
		ans %= mod;a %= mod;}
	return ans;
}

inline int lg2(int x){return 31 - __builtin_clz(x);}
inline ll lg2(ll x){return 63 - __builtin_clzll(x);}

ll Mod(ll i, ll mod){return ((i%mod)+mod)%mod;}

string STR(ll x)
{
	string s = "",t = "";
	while(x)
	{
		s += '0'+(x%10);
		x /= 10;
	}
	for(int i = s.size()-1; i >= 0; i--) t += s[i];
	return t;
}

ll INT(string s)
{
	ll x = 0LL;
	for(auto u: s)
	{
		x = x*10 + u-'0';
	}
	return x;
}

/// START ///

const int N = 150'000 + 5;
const int Q = 300'000 + 5;
const int MAX = 1'000'000 + 5;
int BM[MAX], link[MAX];
set<ll> can;
int A[N];
int n, q;

inline int Link(int a){return a == link[a]? a : link[a] = Link(link[a]);}

inline void merge(int a, int b)
{
	a = Link(a);
	b = Link(b);
	link[a] = b;
}

int main()
{
	Fast
	
	memset(BM,-1,sizeof(BM));
	FOR(i,MAX)link[i] = i; 
	
	for(int i = 2; i < MAX; i++)
	{
		if(BM[i] == -1)
		{
			for(int j = i; j < MAX; j += i)BM[j] = i;
		}
	}
	
	cin >> n >> q;
	FOR(i,n)cin >> A[i];
	
	{
		int x;
		vector<int> T;
		FOR(i,n)
		{
			x = A[i];
			while(x > 1)
			{
				T.pub(x);
				x /= BM[x];
			}
			FOR(j,sz(T))FOR(k,j)merge(T[j],T[k]);
			T.clear();
		}
	}
	
	{
		int x;
		vector<int> T;
		FOR(i,n)
		{
			x = A[i]+1;
			while(x > 1)
			{
				T.pub(x);
				x /= BM[x];
			}
			FOR(j,sz(T))T[j] = Link(T[j]);
			FOR(j,sz(T))FOR(k,j)can.insert((ll)T[j]*T[k]);
			FOR(j,sz(T))can.insert((ll)T[j]*Link(A[i]));
			T.clear();
		}
	}
	
	{
		int st, en;
		FOR(i,q)
		{
			cin >> st >> en;
			st--; en--;
			st = Link(A[st]);
			en = Link(A[en]);
			if(st == en)cout << "0\n";
			else if(can.find((ll)st*en) != can.end())cout << "1\n";
			else cout << "2\n";
		}
	}
	
	return 0;
}

/// Thank God . . .
