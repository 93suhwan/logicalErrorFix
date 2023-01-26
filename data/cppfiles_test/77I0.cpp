#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> os;

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};
int a[1005][1005], sz, n, m;
bool vis[1005][1005];
vector<int> v;

void dfs(int r, int c) {
	if ((r < 0) || (n <= r) || (c < 0) || (m <= c))
		assert(false);
	vis[r][c] = true;
	sz++;
	for (int i = 0; i < 4; i++)
		if ((a[r][c] & (1 << i)) < 1) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!vis[nr][nc])
				dfs(nr, nc);
		}
}

int main() {
	/*os x;
	x.order_of_key(v); // banyak objek < v
	*x.find_by_order(v); // objek ke-v (0-based)*/
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j]) {
				sz = 0;
				dfs(i, j);
				v.pb(sz);
			}
	sort(v.begin(), v.end());
	sz = v.size();
	for (int i = sz - 1; i >= 0; i--)
		printf("%d%c", v[i], (i > 0) ? ' ' : '\n');
	return 0;
}