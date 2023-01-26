#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// @author: s_abhishek

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set_duplicate;

#define modulo  998244353ll
int mod = 1000000007;
#define all(v) v.begin(),v.end()
const int inf = 1034567891;
const ll LL_INF = 1234567890123456789ll;
#define PI 3.14159265
#define endl '\n'
#define pvaluewl(x) cout << #x << " = " << x << endl;
#define cin(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define cout(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define pb                   push_back
#define mp                   make_pair
#define lb                   lower_bound
#define ub                   upper_bound
#define F                    first
#define S                    second

int const N = 1e6 + 3;
ll fact[N];

void debug(int x) { cerr << x; }
void debug(char x) { cerr << x; }
void debug(string x) { cerr << x; }
void debug(double x) { cerr << x; }
void debug(long double x) { cerr << x; }
void debug(long long x) { cerr << x; }

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (int i = 0; i < v.size(); ++i) {os << v[i]; if (i != v.size() - 1)os << ", ";}
	os << "]\n"; return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
	os << "[";
	for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", ";}
	os << "]\n"; return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
	for (auto it : v)  os << it.first << " : " << it.second << "\n"; return os;
}

inline int toi(string s) {stringstream ss; ss << s; int ret; ss >> ret; return ret;}
inline ll toll(string s) {stringstream ss; ss << s; ll ret; ss >> ret; return ret;}
inline int Random() {return ((rand() << 16) | rand());}
inline char upperCase(char ch) {return (ch >= 'a' && ch <= 'z') ? ch ^ 32 : ch;}
inline char lowerCase(char ch) {return (ch >= 'A' && ch <= 'Z') ? ch ^ 32 : ch;}
inline int dig(char ch) {return ch - 48;}
inline bool isAlpha(char ch) {return (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');}
inline bool isDigit(char ch) {return (ch >= '0' && ch <= '9');}
inline bool isVowel(char a) {if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {return true; } return false;}
inline bool isLowerCase(char ch) {return (ch >= 'a' && ch <= 'z');}
inline bool isUpperCase(char ch) {return (ch >= 'A' && ch <= 'Z');}
inline void swap(short& a, short& b) {b ^= a ^= b ^= a;}
inline void swap(int& a, int& b) {b ^= a ^= b ^= a;}
inline void swap(char& a, char& b) {b ^= a ^= b ^= a;}
inline void swap(ll& a, ll& b) {b ^= a ^= b ^= a;}
// inline string to_string(long long a) {
// 	string ans = ""; while (a) {
// 		ans += (char)(a % 10 + '0');
// 		a /= 10;
// 	} reverse(ans.begin(), ans.end()); return ans;
// }

template<class T> inline T abs(T x) {return x < 0 ? -x : x;}
template<class T> inline T sqr(T x) {return x * x;}
template<class T> inline T min(T& a, T& b) {return a < b ? a : b;}
template<class T> inline T max(T& a, T& b) {return a > b ? a : b;}

int binpow(int a, int b) {
	int res = 1;
	while (b) {if (b & 1) res *= a; a *= a; b /= 2;}
	return res;
}

int bin_pow(int a, int b, int mod) {
	int res = 1;
	while (b) {if (b & 1) res *= a, res %= mod; a *= a; a %= mod; b /= 2;}
	return res;
}

int modpow(int x, int n, int m) {
	if (n == 0) {return 1 % m;}
	ll u = modpow(x, n / 2, m); u = (u * u) % m; if (n % 2 == 1) {u = (u * x) % m;}
	return u;
}

int multiply(int a, int b, int mod) {
	int res = 0;
	while (b) {if (b & 1) res = res + a, res %= mod; a += a; a %= mod; b /= 2;}
	return res;
}

unsigned rand32() {return (rand() << 16) + rand();}
int rand(int a, int b) {return rand32() % (b - a + 1) + a;}

ll combination(ll n, ll k) {
	ll res = 1; if (k > n - k) {k = n - k;}
	for (ll i = 0; i < k; ++i) {res = (res * (n - i)); res /= (i + 1);} return res;
}
ll inv(ll a, ll p) {
	return modpow(a, p - 2, p);
}

ll nCk(ll n, ll k, ll p) {
	return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}


ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}


void solve() {

	string s;
	cin >> s;

	int n = s.length();

	if (n == 2) {
		if (s[0] == 'N' && s[1] == 'E' || s[0] == 'E' && s[1] == 'N') {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		return;
	}

	if (s[0] != s[n - 1]) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}



}

int32_t main()
{

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r" , stdin);

	freopen("output.txt", "w" , stdout);

#endif


#ifndef ONLINE_JUDGE

	printf("Time Limit Exceeded : %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC)) << endl;

#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fact[0] = 1;
	for (int i = 1; i < N + 1; i++)fact[i] = (fact[i - 1] * (ll)i) % mod;

	int T = 1;
	cin >> T;

	for (int testcase = 1; testcase <= T; testcase++)
	{
		//cout << "Case #" << testcase << ": ";
		solve();
	}

	return 0;

}

/*

			उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।
			न हि सुप्तस्य सिंहस्य प्रविशन्ति मुखे मृगा:।।

*/