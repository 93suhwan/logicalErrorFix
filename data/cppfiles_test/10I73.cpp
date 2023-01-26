#include<bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
 
#define fi          first
#define se          second
#define INF         1e9 + 5
#define mod(a,m)    (a%m+m)%m
#define PB          push_back
#define MP          make_pair
#define all(a)      a.begin(), a.end()
 
const int mod = 1'000'000'007;

ll pow(ll base, ll exp) {
	if(exp == 0) return 1;
	ll temp = pow(base, exp>>1);
	if(exp&1) {
		return (((temp * temp) % mod) * base) % mod;
	}
	return (temp * temp) % mod;
}

 
int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, m, base, r, c;
	while(cin >> n >> m >> base >> r >> c) {
		int ax, bx, ay, by;
		cin >> ax >> bx >> ay >> by;
		ll ans = pow(base, n*m - r*c);
		cout << ans << '\n';
	}
}