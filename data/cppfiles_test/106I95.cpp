#include <bits/stdc++.h>

#define N	20
#define K	200
#define M	(K * N * 2)
#define MAXN	(M * 2)
#define A	2000000

using namespace std;
unsigned int X;

int new_ai[MAXN], match[MAXN], cnt;
char visited[MAXN];
vector<int> edges[MAXN];

int newnode(int a) {
	new_ai[cnt] = a;
	edges[cnt].clear();
	return cnt++;
}

void addedge(int i, int j) {
    edges[i].push_back(j);
}

int delta, begin_pos, end_pos;

// 找到从s开始的增量最大的增广路
// 从s开始的匹配
void dfs1(const int s, int i) {

	if (visited[i])
		return;
	visited[i] = 1;
	for (int j: edges[i]) {
        // 找到增广路
		if (match[j] == -1) {
			if (delta < new_ai[s] + new_ai[j]) {
				delta = new_ai[s] + new_ai[j];
				begin_pos = s;
				end_pos = j;
			}
		} else
			dfs1(s, match[j]);
	}
}


int fill_match(int s, const int t) {

	if (visited[s])
		return 0;
	visited[s] = 1;
	for (int j: edges[s]) {

		if (match[j] == -1 && j == t || match[j] != -1 && fill_match(match[j], t)) {
			match[s] = j, match[j] = s;
			return 1;
		}
	}
	return 0;
}

int ai[1 << N], idx[1 << N], edgeval_count[A + 1], sorted_idx[MAXN];
int main() {

	int n, k, k_, ans;

	scanf("%d%d", &n, &k);

	for (int i = 0; i < 1 << n; ++i)
		scanf("%d", &ai[i]);

    // edgeval_count[x]表示值为x的边有多少（匹配对）数目
	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j)
			if ((i & 1 << j) == 0)
				++edgeval_count[ai[i] + ai[i | 1 << j]];

	}
    // 这个是用来减少一些不必要的情况
    // 一个人至多和n个匹配，所以最好的k对，一定在前(2 * n - 1) (k - 1) + 1中
    // 也可以用快速选择算法来选出这些值和边。
	k_ = (2 * n - 1) * (k - 1) + 1;
	for (int i = A; i >= 0; --i)
		if (k_ > edgeval_count[i])
			k_ -= edgeval_count[i];
		else
			edgeval_count[i] = k_, k_ = 0;

	cnt = 0;
	memset(idx, -1, (1 << n) * sizeof *idx);

	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & 1 << j) == 0 && edgeval_count[ai[i] + ai[i | 1 << j]]-- > 0) {

				if (idx[i] == -1)
					idx[i] = newnode(ai[i]);

				if (idx[i | 1 << j] == -1)
					idx[i | 1 << j] = newnode(ai[i | 1 << j]);

				addedge(idx[i], idx[i | 1 << j]);
                addedge(idx[i | 1 << j], idx[i]);
			}
		}
	}

	memset(match, -1, cnt * sizeof *match);
	for (int i = 0; i < cnt; ++i)
		sorted_idx[i] = i;
    // 按ai的值排序，获得排序下标
	sort(sorted_idx, sorted_idx + cnt, [&new_ai](const int a, const int b) {
        return new_ai[a] < new_ai[b];
    });
    // 这实际上就是EK算法求最小费用流。
	ans = 0;
	while (k--) {
		memset(visited, 0, cnt * sizeof *visited);
		delta = begin_pos = end_pos = -1;
		for (int i = cnt - 1; i >= 0; --i)
			if (match[sorted_idx[i]] == -1)
                if(__builtin_popcount(sorted_idx[i]) & 1)
                    dfs1(sorted_idx[i], sorted_idx[i]);
		if (delta == -1)
			break;

		ans += delta;
		memset(visited, 0, cnt * sizeof *visited);
		fill_match(begin_pos, end_pos);
	}
	printf("%d\n", ans);
	return 0;
}
