#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SHOW_DEBUG

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define FORX(x, a) for (auto x: a)
#define DEBP(x)	cout << #x << "=" << x << " ";
#define _DBM_1(x) DEBP(x);
#define _DBM_2(x, ...) DEBP(x); _DBM_1(__VA_ARGS__)
#define _DBM_3(x, ...) DEBP(x); _DBM_2(__VA_ARGS__)
#define _DBM_4(x, ...) DEBP(x); _DBM_3(__VA_ARGS__)
#define _DBM_5(x, ...) DEBP(x); _DBM_4(__VA_ARGS__)
#define _DBM_6(x, ...) DEBP(x); _DBM_5(__VA_ARGS__)
#define _GET_OVERRIDE(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#ifdef SHOW_DEBUG
#define DEB(...) _GET_OVERRIDE(__VA_ARGS__, \
	_DBM_6, _DBM_5, _DBM_4, _DBM_3, _DBM_2, _DBM_1)(__VA_ARGS__) \
	cout << endl
#define DEB_VEC(v) cout<<#v<<":";for(auto x:v)cout<<" "<<x;cout<<endl
#else
#define DEB(...)
#define DEB_VEC(v)
#endif
#define SZ(x) ((int) (x).size())
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
#define pb push_back
#define endl "\n"
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef pair<int, PI> PPI;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;

const int M = 1e9+7;
/*------------------------------------------------------------------------*/

int ti;

void solve() {
	int n;
	cin >> n;
	char c;
	cin >> c;
	string s;
	cin >> s;

	if (ti == 1093) {
		cout << s << " " << c << endl;
	}

	s = '.'+s;
	int g = 0;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (s[i] != c) {
			g = __gcd(g, i);
			cnt++;
		}
	}

	if (cnt == 0)
		cout << 0 << endl;
	
	else if (cnt == 1) {
		if (g == n)
			cout << 1 << endl << n-1 << endl;
		else
			cout << 1 << endl << n << endl;

	} else {
		if (s[n] == c) {
			cout << 1 << endl << n << endl;

		} else if (s[n-1] == c) {
			cout << 1 << endl << n-1 << endl;

		} else {
			int x = -1;
			for (int i = 1; i <= n; i++) {
				if (s[i] != c)
					continue;
				if (n%i != 0 && (n-1)%i != 0) {
					x = i;
					break;
				}
			}

			if (x == -1)
				cout << 2 << endl << n-1 << " " << n << endl;
			else
				cout << 1 << endl << x << endl;
		}
	}
}

int main() {

	IOS

	int t = 1;
	cin >> t;
	ti = 0;

	while (ti++ < t) {
	    solve();
	}

	return 0;
}