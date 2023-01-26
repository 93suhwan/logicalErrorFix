#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
using ll = long long;
using ull = unsigned long long;
// reference: https://codeforces.com/contest/855/submission/30763830
const int inf = 1e9 + 1;
const int maxn = 200100;
const int N = 200021;
template<typename T>
struct segtree2 {
    vector<T> t;
    int n;
    segtree2(int n): n(n) {
        t.assign(2 * n, T());
    }
    void update(int p, T v){
        for(t[p += n] = v; p >>= 1; )
            t[p] = t[p<<1] + t[p<<1|1];
    }
    void add(int p, T v){
        p += n;
        t[p] = t[p] + v;
        while(p >>= 1) t[p] = t[p<<1] + t[p<<1|1];
    }
    T query(int l, int r){
        T cl = T(), cr = T();
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) cl = cl + t[l++];
            if(r&1) cr = t[--r] + cr;
        }
        return cl + cr;
    }
};
segtree2<int> cntt(maxn);
segtree2<ll> summ(maxn);
struct segtree{
	int bigger[maxn<<2], sbigger[maxn<<2], cntbigger[maxn<<2], lazy[maxn<<2];
	long long sum[maxn<<2];
	void build(int id, int l, int r){
		lazy[id] = inf;
		if(l == r){
			bigger[id] = l;
			cntbigger[id] = 1;
			sbigger[id] = 0;
			cntt.add(bigger[id], cntbigger[id]);
			summ.add(bigger[id], bigger[id]);
		}
		else {
			int mid = (l + r)>>1;
			build(id<<1, l, mid);
			build(id<<1|1, mid + 1, r);
			pushUp(id);
		}
	}
	void build(){
		build(1, 1, N);
	}
	void push(int id, int l, int r){
		if(lazy[id] < bigger[id]){
			sum[id] -= 1ll * cntbigger[id] * (bigger[id] - lazy[id]);
			bigger[id] = lazy[id];
			if(l != r){
				lazy[id<<1] = lazy[id];
				lazy[id<<1|1] = lazy[id];
			}
		}
		lazy[id] = inf;
	}
	void pushUp(int id){
		if(bigger[id<<1] == bigger[id<<1|1]){
			bigger[id] = bigger[id<<1];
			cntbigger[id] = cntbigger[id<<1] + cntbigger[id<<1|1];
			sbigger[id] = max(sbigger[id<<1], sbigger[id<<1|1]);
		} else if(bigger[id<<1] < bigger[id<<1|1]){
			bigger[id] = bigger[id<<1|1];
			cntbigger[id] = cntbigger[id<<1|1];
			sbigger[id] = max(bigger[id<<1], sbigger[id<<1|1]);
		} else if(bigger[id<<1] > bigger[id<<1|1]){
			bigger[id] = bigger[id<<1];
			cntbigger[id] = cntbigger[id<<1];
			sbigger[id] = max(sbigger[id<<1], bigger[id<<1|1]);
		}
		sum[id] = sum[id<<1] + sum[id<<1|1];
	}
	int X, Y, V;
	void active(int id, int l, int r){
		push(id, l, r);
		if(r < X || X < l) return;
		if(l == r){
			cntt.add(bigger[id], -cntbigger[id]);
			summ.add(bigger[id], -1ll * cntbigger[id] * bigger[id]);
			bigger[id] = V;
			sum[id] = V;
			cntbigger[id] = 1;
			cntt.add(bigger[id], cntbigger[id]);
			summ.add(bigger[id], 1ll * cntbigger[id] * bigger[id]);
		} else {
			int mid = (l + r)>>1;
			active(id<<1, l, mid);
			active(id<<1|1, mid + 1, r);
			pushUp(id);
		}
	}
	void active(int pos, int v){
		X = pos; V = v;
		active(1, 1, N);
	}
	void mupdate(int id, int l, int r){
		push(id, l, r);
		if(V >= bigger[id]) return;
		if(l > Y || r < X) return;
		if(X <= l && r <= Y && V > sbigger[id]){
			cntt.add(bigger[id], -cntbigger[id]);
			summ.add(bigger[id], -1ll * cntbigger[id] * bigger[id]);
			lazy[id] = V;
			push(id, l, r);
			cntt.add(bigger[id], cntbigger[id]);
			summ.add(bigger[id], 1ll * cntbigger[id] * bigger[id]);
			return;
		}
		int mid = (l + r)>>1;
		mupdate(id<<1, l, mid);
		mupdate(id<<1|1, mid + 1, r);
		pushUp(id);
	}
	void update(int x, int y, int v){
		X = x; Y = y; V = v;
		mupdate(1, 1, N);
	}
	long long query(int id, int l, int r){
		push(id, l, r);
		if(l > Y || r < X) return 0;
		if(X <= l && r <= Y) return sum[id];
		int mid = (l + r)>>1;
		return query(id<<1, l, mid) + query(id<<1|1, mid + 1, r);
	}
	long long query(int x, int y){
		X = x; Y = y;
		return query(1, 1, N);
	}
	void dfs(int id, int l, int r){
		push(id, l, r);
		if(l != r){
			int mid = (l + r)>>1;
			dfs(id<<1, l, mid);
			dfs(id<<1|1, mid + 1, r);
			pushUp(id);
		}
	}
	void dfs(){
		dfs(1, 1, N);
	}
};
segtree seg;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	seg.build();
	int n, q;
	cin >> n >> q;
	vector<ll> suff(n + 2);
	for(int i = n - 1; i >= 1; i--)
		suff[i] = (n - i) + suff[i + 1];
	for(int i = 0; i < q; i++){
		int p, u, v;
		cin >> p >> u >> v;
		if(p == 1){
			if(u > 1)
				seg.update(1, u - 1, u - 1);
			seg.active(u, v);
		} else {
			ll in_l = summ.query(u, n + 1) - (u - 1) * cntt.query(u, n + 1);
			ll in_r = summ.query(v + 1, n + 1) - v * cntt.query(v + 1, n + 1);
			cout << in_l - in_r - suff[u] + suff[v + 1] << '\n';
		}
	}
	return 0;
}