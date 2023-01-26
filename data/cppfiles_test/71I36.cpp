#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;
//using ordered_multiset = tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>;
//#define fbo find_by_order // use pointer, returns kth element (0-based)
//#define ook order_of_key // returns x ada di index berapa (0-based)

#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define lll __int128
#define tp top()
#define fr front()

#define sz size()
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mem(a,  b) memset(a,  (b),  sizeof(a))
#define clr(a) memset(a,  0,  sizeof(a))
#define sqr(x) ( (x) * (x) )
#define all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(),  v.rend()

template<typename T>
using ve = vector<T>;
using pii = pair<int,int>;
using ppi = pair<pii,int>;
using pip = pair<int,pii>;
using ppp = pair<pii,pii>;


void optIO(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct point {
    ld x,y;
    point() {
        x=y=0.0;
    }
    point(ld _x,ld _y) {
        x=_x; y=_y;
    }
//    bool operator== (point other) {
//        return x == other.x && y == other.y;
//    }
//    bool operator< (point other) {
//    	if (x == other.x) return y < other.y;
//        return x < other.x;
//    }
};

bool collinear(point P, point L, point R) { //newly added(luis), cek 3 poin segaris
    return P.x*(L.y-R.y)+L.x*(R.y-P.y)+R.x*(P.y-L.y)==0; // bole gnti “dabs(x)<EPS”
}

vector<pair<point, int>> ps;

bool compare(pair<point, int> p1, pair<point, int> p2){
	return (p1.fi.x == p2.fi.x)? p1.fi.y <= p2.fi.y : p1.fi.x <= p2.fi.x;
}

ld dist(point P1,point P2) {
    return hypot(P1.x-P2.x,P1.y-P2.y);
}

pair<point, int> exc;
ld calc(ve<pair<pair<point,point>, ld> > vec){
	ld ans = 1e18;
	ld sm = 0;
	for(auto pp : vec) sm += pp.se;	
	for(auto pp : vec) {
//		cout<<pp.fi.fi.x<<" "<<pp.fi.fi.y<<" -> "<<pp.fi.se.x<<" "<<pp.fi.se.y<<"\n";
		ans = min(ans, sm - pp.se + dist(exc.fi, pp.fi.fi) + dist(exc.fi, pp.fi.se));
	}
	return ans;
}

void solve(){	
	int n,k; cin>>n>>k;
	ve<pair<point, int>> tmp;
	rep(i,0,n){
		int u,v; cin>>u>>v;
		tmp.pb({{u,v}, i+1});
	}
	
	int ex = -1;
	if (n == 3) {
		ex = 0;		
	} else {
		if (collinear(tmp[0].fi, tmp[1].fi, tmp[2].fi)) {
			rep(i,3,n) {
				if (!collinear(tmp[0].fi, tmp[1].fi, tmp[i].fi)) {
					ex = i;
					break;
				}
			}			
		} else if (collinear(tmp[0].fi, tmp[1].fi, tmp[3].fi)) { 
			ex = 2;
		} else if (collinear(tmp[0].fi, tmp[2].fi, tmp[3].fi)) {
			ex = 1;
		} else if (collinear(tmp[1].fi, tmp[2].fi, tmp[3].fi)) {
			ex = 0;
		} else assert(0);
	}
	rep(i,0,n) {
		if (ex == i) exc = tmp[i];
		else ps.pb(tmp[i]);
	}
	sort(all(ps), compare);
//	for(auto x : ps) cout<<x.se<<"\n";
	ld ans = 1e18;
	if (exc.se == k) {
		ans = min(ans, min(	
							dist(exc.fi, ps[0].fi), 
							dist(exc.fi, ps.back().fi)
						) + dist(ps[0].fi, ps.back().fi));
	} else {
		int st;
		for(int i = 0; i < ps.sz; i++) if (ps[i].se == k) st = i;
		int pvt = st;
		ve<pair<pair<point,point>, ld> > vec;
		while(pvt > 0) {			
			vec.pb({{ps[pvt].fi,ps[pvt-1].fi}, dist(ps[pvt].fi,ps[pvt-1].fi)});			
			pvt = pvt-1;
		}
		if (st+1 < ps.sz) {
			vec.pb({{ps[pvt].fi,ps[st+1].fi},dist(ps[pvt].fi,ps[st+1].fi)});	
			pvt = st+1;
			while(pvt+1 < ps.sz) {
				vec.pb({{ps[pvt].fi,ps[pvt+1].fi},dist(ps[pvt].fi,ps[pvt+1].fi)});	
				pvt = pvt+1;
			}
		}
		
		ans = min(ans, calc(vec));
								
		pvt = st;
		vec.clear();
		
		while(pvt+1 < ps.sz) {
			vec.pb({{ps[pvt].fi,ps[pvt+1].fi}, dist(ps[pvt].fi,ps[pvt+1].fi)});			
			pvt = pvt+1;
		}
		if (st > 0){
			vec.pb({{ps[pvt].fi,ps[st-1].fi},dist(ps[pvt].fi,ps[st-1].fi)});
			pvt = st-1;
			while(pvt > 0) {
				vec.pb({{ps[pvt].fi,ps[pvt-1].fi},dist(ps[pvt].fi,ps[pvt-1].fi)});	
				pvt = pvt-1;
			}
		}		
		ans = min(ans, calc(vec));		
	}
	cout<<fixed<<setprecision(12)<<ans<<"\n";
}	

int main() {
	optIO();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




