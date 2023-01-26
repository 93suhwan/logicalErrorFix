#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#include <bitset>

const int md = 998244353;

inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 105;
int n, m, q[N], ind[N], start[N], prev[N], fact[N], cmp = 1, ord[N], eq[N][N], ord_eq[N * 2], lmost[N], rmost[N], amt[N * N], to[N * N], both[N][N], ans = 1;
std::bitset<N> s[N], all[N], other[N], cmp_mask[N];
bool right[N], u[N], adj[N][N], inside[N][N];

int in_t;
void dfs(int v) 
{
	u[v] = true;
	ord[in_t++] = v;
	for (int i = 0; i < n; ++i) if (!u[i] && adj[v][i]) dfs(i);
}

int calc(int cur) 
{
	u[cur] = true;
	std::vector<std::pair<int, int> > a;
	for (int i = 0; i < n; ++i) if (!cur || inside[cur][i]) a.push_back(std::make_pair(eq[cur][i], i));
	std::sort(a.begin(), a.end());
	for (int i = 0; i < (int)a.size();) {
		int j = i;
		do {
			++i;
		} while (i < (int)a.size() && a[i].first == a[j].first);
		j = i - j;
		for (int k = 0; k < cmp; ++k) if (!u[k] && (all[a[i - 1].second] & cmp_mask[cur]) == other[k]) j -= calc(k);
		ans = mul(ans, fact[j]);
	}
	return rmost[cur] - lmost[cur];
}

int main() 
{
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d%d", &n, &m);
	lmost[0] = 0;
	rmost[0] = n - 1;
	bool ok = true;
	for (int i = 0; i < m && ok; ++i) {
		scanf("%d", q + i);
		for (int j = 0; j < q[i]; ++j) {
			int x;
			scanf("%d", &x);
			s[i].set(x - 1);
		}
		bool was = false;
		for (int j = 0; j < i && !was; ++j) if (s[i] == s[j]) was = true;
		if (was) {
			s[i].reset();
			--i;
			--m;
		}
		else for (int j = 0; j < i; ++j) {
			std::bitset<N> nd = s[i] & s[j];
			both[i][j] = both[j][i] = nd.count();
			if (nd != s[i] && nd != s[j] && nd.any()) adj[i][j] = adj[j][i] = true;
		}
	}
	for (int i = 0; i < m && ok; ++i) if (!u[i]) {
		in_t = 0;
		dfs(i);
		lmost[cmp] = ~(1 << 31);
		rmost[cmp] = 0;
		int eq_amt = 1;
		memset(ord_eq, 0, N << 3);
		if (in_t > 1) ans = mul(ans, 2);
		other[cmp].set();
		for (int i = 0; i < in_t && ok; ++i) {
			int cur = ord[i];
			cmp_mask[cmp].set(cur);
			ind[cur] = cmp;
			if (!i) start[cur] = N;
			else {
				prev[cur] = -1;
				for (int j = 0; prev[cur] == -1; ++j) if (adj[cur][ord[j]]) prev[cur] = ord[j];
				if (i == 1) {
					prev[ord[0]] = cur;
					right[cur] = true;
				}
				else right[cur] = right[prev[cur]] != (s[cur] & ~s[prev[cur]] & s[prev[prev[cur]]]).any();
				if (right[cur]) start[cur] = start[prev[cur]] + q[prev[cur]] - both[cur][prev[cur]];
				else start[cur] = start[prev[cur]] - q[cur] + both[cur][prev[cur]];
			}
			for (int j = 0; j < n; ++j) if (s[cur].test(j)) {
				if (!amt[to[eq[cmp][j]]]) to[eq[cmp][j]] = eq_amt++;
				eq[cmp][j] = to[eq[cmp][j]];
				++amt[eq[cmp][j]];
				inside[cmp][j] = true;
			}
			if (start[cur] < 0 || start[cur] + q[cur] > 2 * N) ok = false;
			else for (int j = start[cur]; j < start[cur] + q[cur]; ++j) {
				ord_eq[j] = to[ord_eq[j]];
				if (!amt[ord_eq[j]]) ok = false;
				--amt[ord_eq[j]];
				lmost[cmp] = std::min(lmost[cmp], j);
				rmost[cmp] = std::max(rmost[cmp], j);
			}
		}
		other[cmp].reset(i);
		++cmp;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) if (s[j].test(i)) all[i].set(j);
		for (int j = 0; j < m; ++j) if (s[j].test(i)) other[ind[j]] &= all[i];
	}
	memset(u, 0, N);
	calc(0);
	if (ok) printf("%d\n", ans);
	else printf("0\n");
	return 0;
}
