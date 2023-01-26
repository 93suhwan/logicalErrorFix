#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double db;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define np(str) next_permutation(str.begin(),str.end())
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define v vector
#define repc(i,s,e) for(ll i=s;i<e;i++)
#define fi first
#define se second
#define mset(a,val) memset(a,val,sizeof(a));
#define repr(i,n) for(i=n-1;i>=0;i--)
#define rep(i,n) for(i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define at(s,pos) *(s.find_by_order(pos))
#define set_ind(s,val) s.order_of_key(val)
long long int M = 1e9 + 7 ;
long long int inf = 9 * 1e18;
const double PI = acos(-1);
//CLOCK
ll begtime = clock();
#define time() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//CLOCK ENDED
ll n, m;


//geometry template
typedef db T;
struct pt {
	T x, y;
	pt operator+(pt p) {return {x + p.x, y + p.y};}
	pt operator-(pt p) {return {x - p.x, y - p.y};}
	pt operator*(T d) {return {x * d, y * d};}
	pt operator/(T d) {return {x / d, y / d};} // only for floatingpoint
};
bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

//rotating a vector (a degree)
pt rot(pt p, db a) {
	return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}//perpendicular vector
pt perp(pt p) {return { -p.y, p.x};}

T sq(pt p) {return p.x * p.x + p.y * p.y;}
db abs(pt p) {return sqrt(sq(p));}

template <typename T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

T dot(pt v, pt w) {return v.x * w.x + v.y * w.y;}
bool isPerp(pt v, pt w) {return dot(v, w) == 0;}



//angle between two vectors
db angle(pt v, pt w) {
	db cosTheta = dot(v, w) / abs(v) / abs(w);
	return acos(max(-T(1.0), min(T(1.0), cosTheta)));
}
//if +ve counter clockwise else if -ve clockwise else a straight line
T cross(pt v, pt w) {return v.x * w.y - v.y * w.x;}
T orient(pt a, pt b, pt c) {return cross(b - a, c - a);}

//polar sort
bool half(pt p) { // true if in blue half
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is
	//undefined
	return p.y > 0 || (p.y == 0 && p.x < 0);
}
void polarSort(vector<pair<pt, int>> &v) {
	sort(v.begin(), v.end(), [](pair<pt, int> v, pair<pt, int> w) {
		return make_tuple(half(v.fi), 0, sq(v.fi)) <
		       make_tuple(half(w.fi), cross(v.fi, w.fi), sq(w.fi));
	});
}

ll Cross(pll v, pll w) {return v.fi * w.se - v.se * w.fi;}
ll Orient(pll a, pll b, pll c) {return Cross({b.fi - a.fi, b.se - a.se}, {c.fi - a.fi, c.se - a.se});}
pt line;
bool cmpProj(pair<pt, int> p, pair<pt, int> q) {
	return dot(line, p.fi) < dot(line, q.fi);
}
int main() {
	// your code goes here
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, t, k, x, y, z,  N;


	vector<pll> vec;
	cin >> n >> k;
	k--;
	rep(i, n) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	ll cnt = 0;
	int pos = -1;
	for (int i = 2; i < n; i++) {
		ll ans = Orient(vec[0], vec[1], vec[i]);
		// cout << ans << '\n';
		if (ans != 0) {
			cnt++;
			pos = i;
		}
	}
	if (cnt > 1) {
		if (Orient(vec[0], vec[2], vec[3])) {
			pos = 0;
		}
		else pos = 1;
	}
	ll flg = 0;
	pt a, b;
	rep(i, n) {
		if (i == pos) continue;
		if (flg == 0) {
			flg = 1;
			a.x = vec[i].fi;
			a.y = vec[i].se;
		}
		else {
			b.x = vec[i].fi;
			b.y = vec[i].se;
			break;
		}
	}
	line = b - a;
	pt c;
	c.x = vec[pos].fi;
	c.y = vec[pos].se;
	vector<pair<pt, int>> dum;
	rep(i, n) {
		if (i != pos) {
			pt a;
			a.x = vec[i].fi;
			a.y = vec[i].se;
			dum.eb(a, i);
		}
	}
	sort(dum.begin(), dum.end(), cmpProj);
	db fix = abs(dum[0].fi - dum.back().fi);

	cout << fixed << setprecision(10);
	if (k == pos) {

		db mn = min(abs(dum[0].fi - c), abs(dum.back().fi - c));
		mn += fix;

		cout << mn;

	}
	else {


		int start = -1;
		for (int i = 0; i < dum.size(); i++) {
			auto u = dum[i];
			if (u.se == k) {
				start = i;
			}
		}

		db mn = abs(dum.back().fi - c);
		if (start > 0) {
			mn -= abs(dum[start - 1].fi - dum[start].fi);
			mn += min(abs(dum[start - 1].fi - c), abs(dum[0].fi - c));
		}
		db mn2 = abs(dum[0].fi - c);
		if (start < dum.size() - 1) {
			mn2 -= abs(dum[start + 1].fi - dum[start].fi);
			mn2 += min(abs(dum.back().fi - c), abs(dum[start + 1].fi - c));
		}
		db mn3 = abs(dum[0].fi - dum[start].fi) + fix;
		mn3 += abs(c - dum.back().fi);

		db mn4 = abs(dum.back().fi - dum[start].fi) + fix;
		mn4 += abs(c - dum[0].fi);


		mn += fix;
		mn2 += fix;
		fix = min({mn, mn2, mn3, mn4});
		cout << fix;


	}


	return 0;




}




















