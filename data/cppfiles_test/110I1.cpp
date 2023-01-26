#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
#include <bits/extc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define fix(f,n) std::fixed<<std::setprecision(n)<<f

typedef long long ll;

int mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, -1, 0, 1}; 
char direction[4] = {'D', 'L', 'U', 'R'}; 
 
using namespace std;
using namespace __gnu_pbds;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#ifdef ADD_TRACE
template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
 
}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

// struct edge{
// 	int a, b, weight;

// 	bool operator < (edge other) const {
// 		return weight < other.weight; 
// 	}
// };
		
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
 
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

//Use chash with gp_hash_table
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { // To use most bits rather than just the lowest ones:
// 	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
// 	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
// };

// struct Basis {
// 	int size = 0;
// 	int max_bits = 0;  
// 	vector<int> basis; 

// 	Basis(int n) {
// 		max_bits = n; 
// 		basis = vector<int>(n); 
// 	}

// 	Basis(const Basis& b) {
// 		this->size = b.size; 
// 		this->max_bits = b.max_bits; 
// 		this->basis = b.basis; 
// 	}

// 	void insertVector(int x) {
// 		for(int i = 0; i < max_bits; i++) {
// 			if(x & (1 << i)) {
// 				if(!basis[i]) {
// 					basis[i] = x; 
// 					size++; 
// 					break; 
// 				} else x ^= basis[i]; 
// 			}
// 		}
// 	}
// };

// vector<int> sieveOfEratosthenes(int n) {
// 	vector<int> primes;
// 	bool prime[n + 1];
// 	memset(prime, true, sizeof(prime));
// 	for (int p = 2; p * p <= n; p++) {
// 		if (prime[p] == true) {
// 			for (int i = p * p; i <= n; i += p)
// 				prime[i] = false;
// 		}
// 	}
// 	for (int p = 2; p <= n; p++)
// 		if (prime[p])
// 			primes.push_back(p);
// 	return primes;
// }

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ll getRand(ll l, ll r) {
// 	uniform_int_distribution<ll> uid(l, r); 
// 	return uid(rng); 
// }

// //Dont forget to reset MOD if some other MOD is needed
// const ll MOD = 1e9+7;
 
// //Comment the line above and uncomment the line below if problem requires more than 1 MOD
// //After uncommenting the below line, declaration of Mint becomes [ Mint<mod> M; ]
 
// //template<ll MOD>
// class Mint
// {
// 	//WARNING:
// 	//Be very careful not to use two Mints with different mods for any operation
// 	//No guarantee of behavior in this case
// 	public:
// 	ll val;
// 	static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
// 	static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
// 	static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
// 	Mint(){	val = 0;} 
// 	Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
// 	Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
// 	Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
// 	Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
// 	Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
// 	Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
// 	Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
// 	Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
// 	Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
// 	Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
// 	bool operator ==(const Mint &other) const {   return val == other.val; }
 
// 	Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
// 	Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
// 	Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
// 	Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
 
// 	// ^ has very low precedence, careful!!
 
// 	template<typename T>
// 	Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
// 	template<typename T>
// 	Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
 
// 	Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
// 	Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
 
// 	template<typename T>
// 	explicit operator T() {	return (T)val; }
// 	template<typename T>
// 	friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
// 	template<typename T>
// 	friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
// 	template<typename T>
// 	friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
// 	template<typename T>
// 	friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
// 	template<typename T>
// 	friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
 
 
// 	friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
// 	friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}
// };

const int INF = INT_MAX; 
int n, k; 
vector<int> x, y, c; 
vector<vector<int>> colorwise(3); 
vector<int> ptr(3); 

vector<vector<int>> param_perms = {
	{2, 2, 2}, 
	{1, 1, 1}, 
	{1, 2, 2}, 
	{2, 1, 1}, 
	{3, 2, 2}, 
	{0, 1, 1}	
}; 

struct box {
	int x2, y2, x1, y1; 

	box() {
		x2 = y2 = INF; x1 = y1 = -INF; 
	}
}; 

bool check(vector<int>& perm);  
bool check(vector<int>& perm, vector<int>& param_perm); 
bool check(box& b, int col, int param_perm, bool only_check); 

void solve() {
	trace(INF, -INF); 

	cin >> n; 
	x.resize(n, 0);
	y.resize(n, 0); 
	c.resize(n, 0); 
	for(int i = 0; i < 3; ++i) {
		colorwise[i].resize(n/3, 0); 
	}

	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> c[i]; 
		colorwise[c[i]-1][ptr[c[i]-1]++] = i; 
	}

	for(int i = 0; i < 3; ++i) assert(ptr[i] == n/3); 

	int low = 0; 
	int high = n/3; 
	while(low < high) {
		k = (low + high + 1)/2; 
		vector<int> perm = {1, 2, 3}; 
		bool poss = false; 
		do {
			poss |= check(perm); 
		} while(next_permutation(perm.begin(), perm.end()) && !poss); 

		if(poss) low = k; 
		else high = k-1; 
	}
	
	assert(low == high); 

	cout << 3 * low << '\n'; 
}

bool valid(box& b, int i) {
	if(x[i] > b.x2 || x[i] < b.x1) return false; 
	if(y[i] > b.y2 || y[i] < b.y1) return false; 
	return true; 
}

bool check(vector<int>& perm) {

	for(auto& p: param_perms) {
		if(check(perm, p)) {
			trace(k, perm, p); 
			return true; 
		}
	}

	return false; 
}

bool check(vector<int>& perm, vector<int>& param_perm) {
	box b = box(); 
	// for(int i = 0; i < 3; ++i) {
	// 	trace(k, perm, param_perm); 
	// 	if(!check(b, perm[i], param_perm[i])) return false; 
	// }

	if(!check(b, perm[0], param_perm[0], false)) return false; 
	if(!check(b, perm[1], param_perm[1], false)) return false; 
	return check(b, perm[2], param_perm[2], true); 
}

bool check(box& b, int col, int param, bool only_check) {
	trace(col, param); 
	trace(b.x2, b.x1, b.y2, b.y1); 

	vector<int> points; 
	for(int i = 0; i < n/3; ++i) {
		if(valid(b, colorwise[col-1][i])) {
			points.push_back(colorwise[col-1][i]); 
		}
	}

	trace(points); 

	if(only_check || (int)points.size() < k) {
		return (int)points.size() >= k; 
	}

	sort(points.begin(), points.end(), [&](int i, int j) {
		switch(param) {
			case 0: return x[i] > x[j]; 
			case 1: return y[i] > y[j];  
			case 2: return x[i] < x[j]; 
			case 3: return y[i] < y[j]; 
			default: assert(false); 
		}; 
	}); 

	switch(param) {
		case 0: if(b.x2 == x[points[k-1]]) b.x2--;  
				else b.x2 = x[points[k-1]]; 
				break; 
		case 1: if(b.y2 == y[points[k-1]]) b.y2--;  
				else b.y2 = y[points[k-1]]; 
				break; 
		case 2: if(b.x1 == x[points[k-1]]) b.x1++; 
				else b.x1 = x[points[k-1]]; 
				break; 
		case 3: if(b.y1 == y[points[k-1]]) b.y1++; 
				else b.y1 = y[points[k-1]]; 
				break; 
	}

	 
	trace(b.x2, b.x1, b.y2, b.y1); 
	return true; 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}