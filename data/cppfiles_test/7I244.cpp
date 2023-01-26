#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

//Albert Toshiro Heru

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long
#define ld long double
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pii pair<int,int>
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second
#define endl '\n'


const int dr[]={-1,1,0,0,-1,-1,1,1};
const int dc[]={0,0,1,-1,-1,1,-1,1};
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ld pi= acos(-1);
const double eps=1e-9;
const int N = 1e5 + 5;


int T;

ll n, a[2 * N], dif[2 * N], st[8 * N];

void build(ll ss, ll se, ll idx) {
	if(ss == se) {
		st[idx] = dif[ss];
		return;
	}
	ll mid = (ss + se) / 2;
	build(ss, mid, idx * 2);
	build(mid + 1, se, idx * 2 + 1);
	st[idx] = __gcd(st[idx * 2], st[idx * 2 + 1]);
}

ll query(ll ss, ll se, ll idx, ll ssq, ll seq) {
	if(se < ssq || ss > seq) {
		return 0;
	}
	if(ssq <= ss && se <= seq) {
		return st[idx];
	}
	ll mid = (ss + se) / 2;
	ll left = query(ss, mid, idx * 2, ssq, seq);
	ll right = query(mid + 1, se, idx * 2 + 1, ssq, seq);
	return __gcd(left, right);
}

ll ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cout << fixed << setprecision(6);
//	freopen("powers.in","r",stdin);
//	freopen("output.txt","w",stdout);
//	srand (time(NULL));
	T = 1;
	cin >> T;
	while(T--) {
		ans = 2;
		cin >> n;
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i];
		}
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		for(int i = 2 ; i <= n ; i++) {
			dif[i - 1] = abs(a[i] - a[i - 1]);
		}
		build(1, n - 1, 1);
		for(int i = 1 ; i <= n - 1 ; i++) {
			ll le, ri, mid;
			le = i + ans - 1, ri = n - 1;
			while(le <= ri) {
				mid = (le + ri) / 2;
				if(query(1, n - 1, 1, i, mid) == 1) {
					if(mid - i + 2 <= ans) {
						break;
					} else {
						ri = mid - 1;
					}
				} else {
					le = mid + 1;
					ans = max(ans, mid - i + 2);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

