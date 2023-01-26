#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>
namespace ztd{
	using namespace std;
	#define reg register
	#define dig_count(x) __builtin_popcountll(x)
	#define smallest_one(x) __builtin_ffsll(x)
	typedef long long ll;
	typedef unsigned long long ull;
	typedef unsigned int uint;
	typedef double db;
	template<typename T> inline T read(T& t) {//fast read
		t=0;short f=1;char ch=getchar();double d=0.1;
		while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
		while (ch>='0'&&ch<='9') t=t*10+ch-'0',ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t*=f; return t;
	}
}
using namespace ztd;
const int maxn = 2e5+7;
const ll inf = 1e18+7;
int n, m, s;
struct node{
	ll x, y;
	bool operator < (const node &rhs)const{
		return x < rhs.x;
	}
	bool operator != (const node &rhs)const{
		return (x != rhs.x) || (y != rhs.y);
	}
	bool operator == (const node &rhs)const{
		return (x == rhs.x) && (y == rhs.y);
	}
}a[maxn], b[maxn];
struct frac{
	ll p, q;
	// frac(){p = q = 0;}
	bool operator != (const frac &rhs)const{
		return (p != rhs.p) || (q != rhs.q);
	}
	bool operator == (const frac &rhs)const{
		return (p == rhs.p) && (q == rhs.q);
	}
};
inline void simple(frac &x){
	ll g = __gcd(abs(x.p),abs(x.q));
	x.p /= g; x.q /= g;
	if(x.p < 0) x.p = -x.p, x.q = -x.q;
}
pair<int, frac> K[maxn];
inline pair<int, frac> get_k(node a, node b){
	if(a.y == b.y) return {1, (frac){0,0}};
	else if(a.x == b.x) return {2, (frac){0,0}};
	else {
		frac ret = (frac){a.y-b.y, a.x-b.x}; simple(ret);
		return {0, ret};
	}
}
inline double dis(node x, node y){
	return sqrt((x.x-y.x) * (x.x-y.x) + (x.y-y.y) * (x.y-y.y));
}

inline signed spe(){
	ll mn = inf, mx = -inf; int mnpos, mxpos;
	for(int i = 1; i <= n; ++i) if(i != s){
		if(a[i].x < mn) mn = a[i].x, mnpos = i; 
		if(a[i].x > mx) mx = a[i].x, mxpos = i;
	}
	// cout << mnpos << ' ' << mxpos << '\n';
	double ans = dis(a[mnpos], a[mxpos]) + min(dis(a[s],a[mnpos]), dis(a[s],a[mxpos]));
	printf("%.8lf\n", ans);
	return 0;
}
bool wrong = 0;
signed main(){
	// #ifdef lkytxdy
	// 	freopen("data.txt","r",stdin);
	// 	freopen("G.out","w",stdout);
	// #endif
	read(n); read(s);
	if(n == 166667) wrong = 1;
	// cout << __gcd(n,s) << '\n'; return 0;
	for(int i = 1; i <= n; ++i){
		read(a[i].x); read(a[i].y);
	}
	for(int i = 1; i <= n; ++i) if(i != s){
		K[i] = get_k(a[s], a[i]);
		// cout << i << ' ' << K[i].first << ' ' << K[i].second.p << "/" << K[i].second.q << '\n';
	}
	if(n == 3) return spe();
	pair<int, frac> met[10]; int tmp = 0, buc[10], sb = 0; 
	memset(buc, 0, sizeof(buc));
	for(int i = 1; i <= n; ++i) if(s != i){
		bool flag = 1;
		for(int j = 1; j <= tmp; ++j) if(met[j] == K[i]) flag = 0, ++buc[j];
		if(flag) met[++tmp] = K[i], buc[tmp] = 1;
		// if(tmp == 3) cout << "heil\n";
		if(tmp == 3) return spe();
	}
	// cout << buc[1] << ' ' << buc[2] << '\n';
	assert(tmp == 2);
	for(int i = 1; i <= n; ++i) if(s != i){
		int type = -1;
		for(int j = 1; j <= tmp; ++j) if(met[j] == K[i]) type = j;
		assert(type > 0);
		if(buc[type] == 1) sb = i;
	}
	assert(sb);
	ll mn = inf, mx = -inf; int mnpos, mxpos;
	for(int i = 1; i <= n; ++i) if(i != sb){
		if(a[i].x < mn) mn = a[i].x, mnpos = i; 
		if(a[i].x > mx) mx = a[i].x, mxpos = i;
		b[++m] = a[i]; 
	}
	double ans = dis(a[mnpos], a[mxpos]) + min(dis(a[s], a[mnpos]) + dis(a[mxpos], a[sb]), dis(a[s], a[mxpos]) + dis(a[mnpos], a[sb]));
	if(wrong && ans < 4168700) cout << "WRONG_IN_ANS\n";
	// cout << ans << '\n';
	sort(b+1, b+m+1);
	assert(a[mnpos] == b[1] && a[mxpos] == b[m]);
	int bs = -1;
	for(int i = 1; i <= m; ++i) if(a[s] == b[i]){
		bs = i; break;
	}
	assert(bs > 0);
	// cout << a[sb].x << ',' << a[sb].y << '\n';
	// cerr << a[mnpos].x << ',' << a[mnpos].y	<< "   " << a[mxpos].x << ',' << a[mxpos].y	<< '\n';
	// for(int i = 1; i <= n; ++i) cout << b[i].x << ',' << b[i].y << '\n';
	double ans1 = min(dis(a[mnpos], a[sb]), dis(a[mxpos], a[sb])) + dis(a[mnpos], a[mxpos]);
	ans = min(ans, min(dis(a[s], a[mnpos]), dis(a[s], a[mxpos])) + ans1);
	if(wrong && ans < 4168700) cout << "WRONG_IN_ANS0\n";
	for(int i = 1; i <= m; ++i) {
		if(i < m){
			ans1 = min(ans1, dis(a[mnpos], b[i]) + dis(b[i], a[sb]) + dis(a[sb], b[i+1]) + dis(b[i+1], a[mxpos]));
			ans = min(ans, min(dis(a[s], a[mnpos]), dis(a[s], a[mxpos])) + ans1);
			if(wrong && ans < 4168700) cout << "WRONG_IN_ANS1\n";
		}
		if(i > 1){
			double val = dis(a[s], b[i]) + dis(b[i], a[mxpos]) + dis(a[mxpos], a[sb]) + dis(a[sb], b[i-1]) + dis(b[i-1], a[mnpos]);
			ans = min(ans, val);
			if(wrong && val < 4168700) cout << "WRONG_IN_ANS2\n";
		}
		if(i < m){
			double val = dis(a[s], b[i]) + dis(b[i], a[mnpos]) + dis(a[mnpos], a[sb]) + dis(a[sb], b[i+1]) + dis(b[i+1], a[mxpos]);
			ans = min(ans, val);
			if(wrong && val < 4168700) cout << "WRONG_IN_ANS3\n";
		}
		// cout << ans1 << '\n';
	}
	// cerr << ans1 << '\n';
	// printf("%.9lf\n", ans1)	;
	ans = min(ans, min(dis(a[s], a[mnpos]), dis(a[s], a[mxpos])) + ans1);
	// cout << ans << '\n';

	printf("%.9lf\n", ans);
	
	return 0;
}