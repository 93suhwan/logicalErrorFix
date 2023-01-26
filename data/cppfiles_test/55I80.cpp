// Problem: D. Ezzat and Grid
// Memory Limit: 256 MB
// Time Limit: 2500 ms

#include <cstdio>
#include <algorithm>
#define ios std::ios::sync_with_stdio(0)
#define mem(name, value) memset(name, value, sizeof(name))
#define readfile(name) freopen(name, "r", stdin)
#define writefile(name) freopen(name, "w", stdout)
using namespace std;
typedef long long ll;
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll max(ll a, ll b) {return a > b ? a : b;}
inline ll abs(ll x) {return x > 0 ? x : -x;}
const int Inf = 0x3f3f3f3f;
const int Mod = 1e9+7;
const ll Lnf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 300005;
int n, m, num[2 * maxn];
int tmpl[maxn], tmpr[maxn], pre[maxn];
bool vis[maxn];

struct Query {
	int row, l, r;
	bool operator < (const Query & x) const {
		return row < x.row;
	}
}q[maxn];

struct Type {
	int val, id;
	bool operator == (const Type &x) const {
		return (val == x.val && id == x.id);
	}
};

struct Node {
	Type d, tag;
}tree[8 * maxn];

int lc(int p) {return p << 1;}
int rc(int p) {return p << 1 | 1;}

Type compare(Type x, Type y) {
	if(x.val > y.val) return x;
	else if(x.val == y.val) {
		Type z;z.val=x.val, z.id = max(x.id, y.id);
		return z; 
	}
	else return y;
}

Type get_d(int p) {
	return compare(tree[p].d, tree[p].tag);
}

void pushdown(int p) {
	Type tmp;tmp.val = 0, tmp.id = 0;
	if(tree[p].tag == tmp) return;
	tree[p].d = get_d(p);
//	printf("pushdown:%d %d\n",tree[p].tag.val, tree[p].tag.id);
	tree[lc(p)].tag = compare(tree[lc(p)].tag, tree[p].tag);
	tree[rc(p)].tag = compare(tree[rc(p)].tag, tree[p].tag);
	tree[p].tag = tmp;
	
	
}

void pushup(int p) {
//	printf("%d %d\n",tree[p].d.val, tree[p].d.id);
//	printf("%d %d\n",tree[lc(p)].d.val, tree[lc(p)].d.id);
//	printf("%d %d\n",tree[rc(p)].d.val, tree[rc(p)].d.id);
	tree[p].d = compare(get_d(lc(p)), get_d(rc(p)));
}

void update(int p, int l, int r, int ql, int qr, Type x) {
//	printf("%d %d %d %d\n",l, r, ql, qr);
	if(l == ql && r == qr) {
//		puts("updated!!!");
//		printf("x:%d %d\n",x.val, x.id);
		tree[p].tag = compare(tree[p].tag, x);
//		printf(":::%d %d\n",tree[p].tag.val, tree[p].tag.id);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if(qr <= mid) update(lc(p), l, mid, ql, qr, x);
	else if(ql >= mid + 1) update(rc(p), mid+1, r, ql, qr, x);
	else update(lc(p), l, mid, ql, mid, x),update(rc(p), mid+1, r, mid+1, qr, x);
	pushup(p);
}

Type query(int p, int l, int r, int ql, int qr) {
//	printf("%d %d %d %d\n",l, r, ql, qr);
	if(l == ql  && r == qr) {
//		puts("ok!!!");
//		printf("%d %d\n",tree[p].d.val, tree[p].d.id);
//		printf("%d %d\n",tree[p].tag.val, tree[p].tag.id);
//		Type f = compare(tree[p].d, tree[p].tag);
//		printf("%d %d\n",f.val, f.id);
		return get_d(p);
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(lc(p), l, mid, ql, qr);
	else if(ql >= mid + 1) return query(rc(p), mid+1, r, ql, qr);
	else return compare(query(lc(p), l, mid, ql, mid), query(rc(p), mid+1, r, mid+1, qr));
}

int main() {
	scanf("%d%d",&n ,&m);
	for(int i = 1;i <= m;i++) {
		scanf("%d%d%d",&q[i].row, &q[i].l, &q[i].r);
		num[i * 2 - 1] = q[i].l;
		num[i * 2] = q[i].r;
	}
	sort(num + 1,num + 2 * m + 1);
	int len = unique(num + 1,num + 2 * m) - num -1;
	for(int i = 1;i <= m;i++) {
		tmpl[i] = lower_bound(num + 1, num + len + 1, q[i].l) - num;
		tmpr[i] = lower_bound(num + 1, num + len + 1, q[i].r) - num;
	}
	sort(q + 1,q + m + 1);
	for(int i = 1, j = 1;i <= n;i++) {
//		printf("%d\n",i);
		Type res;res.val = 0, res.id = 0;
		int last = j;
		while(j <= m && q[j].row == i) {
			res = compare(res, query(1, 1, 600000, tmpl[j], tmpr[j]));
			j++;
		}
//		printf("pre:%d\n",res.id);
//		printf("-----res:%d %d\n",res.val, res.id);
		pre[i] = res.id;
		res.val++;
		res.id = i;
//		printf("-----res:%d %d\n",res.val, res.id);
//		printf("%d %d %d\n",pos, last, j);
		for(int k = last; k < j;k++) {
//			printf("l:d r:%d\n",tmpl[k], tmpr[k]);
			update(1, 1, 600000, tmpl[k], tmpr[k], res);
		}
	}
	int u = tree[1].d.id;
//	printf("%d %d\n",tree[1].d.val, u);
//	for(int i = 1;i <= n;i++) {
//		printf("%d ",pre[i]);
//	}
//	puts("");
	
	while(u != 0) {
		vis[u] = true;
		u = pre[u];
	} 
	printf("%d\n",n - tree[1].d.val);
	for(int i = 1;i <= n;i++) {
		if(vis[i] == false) {
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}

