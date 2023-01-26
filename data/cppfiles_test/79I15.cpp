#include <bits/stdc++.h>
using namespace std;

struct node {
	long long minv;
	node *son[2];
} *root;

const int inf = 0x3fffffff;
void build_tree(node *p, int l, int r);
void modify(node *p, int pos, long long val, int l, int r);
long long query(node *p, int l, int r, int L, int R);
int a[300010], b[300010], ans[300010];
vector <int> vec[300010];

int main() {
	int n; scanf("%d", &n);
	build_tree(root = new node, 0, n + 1);
	modify(root, 0, 0, 0, n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		vec[i + b[i]].push_back(i);
	}
	int f = inf;
	for (int i = 1; i <= n; ++i) {
		long long ret = query(root, i - a[i], n + 1, 0, n + 1);
		ans[i] = ret & 0xffffffffll, f = (ret >> 32) + 1;
		if (f < inf) {
			for (auto j: vec[i])
				modify(root, j, f * 1ll << 32 | j, 0, n + 1);
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]); putchar('\n');
	if (f < inf) {
		printf("%d\n", f);
		for (int j = ans[n]; j != 0; j = ans[j + b[j]])
			printf("%d ", j);
		puts("0");
	}
	else
		puts("-1");
	return 0;
}

void build_tree(node *p, int l, int r) {
	p->minv = inf * 1ll << 32 | l;
	if (l + 1 == r)
		p->son[0] = p->son[1] = nullptr;
	else {
		build_tree(p->son[0] = new node, l, l + r >> 1);
		build_tree(p->son[1] = new node, l + r >> 1, r);
	}
}

void modify(node *p, int pos, long long val, int l, int r) {
	if (pos < l || pos >= r)
		return;
	p->minv = min(p->minv, val);
	if (l + 1 == r)
		return;
	else if (pos < l + r >> 1)
		modify(p->son[0], pos, val, l, l + r >> 1);
	else
		modify(p->son[1], pos, val, l + r >> 1, r);
}

long long query(node *p, int l, int r, int L, int R) {
	if (l == L && r == R)
		return p->minv;
	else if (r <= L + R >> 1)
		return query(p->son[0], l, r, L, L + R >> 1);
	else if (l >= L + R >> 1)
		return query(p->son[1], l, r, L + R >> 1, R);
	else
		return min(query(p->son[0], l, L + R >> 1, L, L + R >> 1), query(p->son[1], L + R >> 1, r, L + R >> 1, R));
}

