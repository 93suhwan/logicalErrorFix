#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

const int MAX=200010;
struct SegmentTree{
	struct node{
		int len=0, l=0, r=0; ll lmax=0, rmax=0, ret=0;
	};
    node seg[MAX*4];
	node merge(const node &a, const node &b){
		node ret = {a.len + b.len, a.l, b.r, 0, 0, a.ret + b.ret};
        if(a.l == 0) return b;
		if(b.l == 0) return a;
		if(a.r > b.l){
			ret.lmax = a.lmax;
			ret.rmax = b.rmax;
		}
		else{
			ret.ret += a.rmax * b.lmax;
			if(a.len == a.lmax) ret.lmax = a.len + b.lmax;
			if(b.len == b.lmax) ret.rmax = a.rmax + b.len;
		}
		return ret;
	}
    node query(int l, int r, int no=1, int nl=0, int nr=MAX-1){
        if(r < nl || nr < l) return {0, 0, 0, 0, 0, 0};
        if(l <= nl && nr <=r) return seg[no];
        int m = (nl + nr)/2;
        return merge(query(l, r, no*2, nl, m) , query(l, r, no*2+1, m+1, nr));
    }
    node update(int i, int v, int no=1, int nl=0, int nr=MAX-1){
        if(i<nl || nr<i) return seg[no];
        if(nl == nr) return seg[no] = {1, v, v, 1, 1, 1};
        int m = (nl + nr)/2;
        return seg[no] = merge(update(i,v,no*2,nl,m) , update(i,v,no*2+1,m+1,nr));
    }
}s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		int x; cin >> x;
		s.update(i, x, 1, 1, n);
	}
	while(m--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) s.update(x, y, 1, 1, n);
		else cout << s.query(x, y, 1, 1, n).ret << '\n';
	}
}