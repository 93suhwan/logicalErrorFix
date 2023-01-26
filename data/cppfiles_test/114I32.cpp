#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <complex>
#include <bitset>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pii;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << i << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.1415926535897932384626

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool BREAKTIME(ld v) {
	return 1.0 * clock() >= v * CLOCKS_PER_SEC;
}

/////////////////////
#define int long long
//int mod = 1e9 + 7;
#define endl '\n'
/////////////////////

int inf = 3e18;

vector<int> mod = {1'000'000'007, 1'000'000'009, 1'006'108'673 , 1'056'440'321 };
vector<int> ww = { 31, 29, 37, 41 };


vector<int> A[10];
vector<vector<int>> B;
vector<int> COST;

set<pair<pair<int, int>, pair<int, int>>> Banned;

int n;
bool check(int bb) {
	vector<int> b(4);
	fork(4) {
		fori(n) {
			b[k] = b[k] * ww[k] + B[bb][i];
			b[k] %= mod[k];
		}
	}
	pair<pair<int, int>, pair<int, int>> P = mp(mp(b[0], b[1]), mp(b[2], b[3]));
	return (Banned.find(P) == Banned.end());

}
void solve() {
	cin >> n;
	
	vector<int> temp;
	fori(n) {
		int k; cin >> k;
		A[i].assign(k, 0);
		forj(k) {
			int x; cin >> x;
			A[i][j] = x;
		}
		temp.push_back(k - 1);
	}

	
	int m; cin >> m;
	forj(m) {
		vector<int> b(4);
		vector<int> p(n);
		fori(n) {
			cin >> p[i];
			p[i]--;
		}

		fork(4) {
			fori(n) {
				b[k] = b[k] * ww[k] + p[i];
				b[k] %= mod[k];
			}
		}
		Banned.insert(mp(mp(b[0], b[1]), mp(b[2], b[3])));
	}


	set<pair<int, pair<int, int>>> Set;
	B.push_back(temp);
	COST.push_back(0);

	if (check(0)) {
		for (int i = 0; i < n; ++i) {
			cout << B[0][i] + 1 << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (B[0][i] == 0) continue;
		int cost = A[i][B[0][i]] - A[i][B[0][i] - 1];
		Set.insert({ cost + COST[0], mp(0, i) });
	}



	while (Set.size() != 0) {
		int cost = Set.begin()->ff;
		int bb = Set.begin()->ss.ff;
		int ii = Set.begin()->ss.ss;
		Set.erase(Set.begin());

		vector<int> NEWB = B[bb];
		NEWB[ii]--;

		B.push_back(NEWB);
		COST.push_back(cost);

		int ind = B.size() - 1;
		if (check(ind)) {
			for (int i = 0; i < n; ++i) {
				cout << B[ind][i] + 1 << " ";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (B[ind][i] == 0) continue;
			int cost = A[i][B[ind][i]] - A[i][B[ind][i] - 1];
			if (Set.size() > m * 2 + 100) continue;
			Set.insert({ cost + COST[ind], mp(ind, i) });
		}

	}


}

int32_t main() {
	boostIO();
	int T = 1;
	while (T--) {
		solve();
	}
}