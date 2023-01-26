#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define N	20
#define K	200
#define M	(K * N * 2)
#define MAXN	(M * 2)
#define A	2000000

using namespace std;
unsigned int X;

int match[MAXN], cnt;
char visited[MAXN];
vector<int> edges[MAXN];

int ai[1 << N], idx[1 << N], kk[A + 1], ii[MAXN];

//int newnode(int a) {
//	//ai[cnt] = a;
////	edges[cnt].clear();
//	return cnt++;
//}

void addedge(int i, int j) {
    edges[i].push_back(j);
}

int a_, i_, j_;

void dfs1(int s, int i) {
	int o;

	if (visited[i])
		return;
	visited[i] = 1;
	for (int j: edges[i]) {

		if (match[j] == -1) {
			if (a_ < ai[s] + ai[j])
				a_ = ai[s] + ai[j], i_ = s, j_ = j;
		} else
			dfs1(s, match[j]);
	}
}

int dfs2(int i, int t) {
	int o;

	if (visited[i])
		return 0;
	visited[i] = 1;
	for (int j: edges[i]) {

		if (match[j] == -1 && j == t || match[j] != -1 && dfs2(match[j], t)) {
			match[i] = j, match[j] = i;
			return 1;
		}
	}
	return 0;
}

int main() {

	int n, k, ans;

	scanf("%d%d", &n, &k);

	for (int i = 0; i < 1 << n; ++i)
		scanf("%d", &ai[i]);

    // kk[x]表示值为x的边有多少（匹配对）数目
	for (int i = 0; i < 1 << n; ++i) {
        edges[i].clear();
		for (int j = 0; j < n; ++j)
			if ((i & 1 << j) == 0)
				++kk[ai[i] + ai[i | 1 << j]];


	}
    // 这个是用来减少一些不必要的情况
    // 一个人至多和n个匹配，所以最好的k对，一定在前k * n * 2 - k中
	int max_ec = k * n * 2 - k + 1;
	for (int i = A; i >= 0; --i)
		if (max_ec > kk[i])
			max_ec -= kk[i];
		else
			kk[i] = max_ec, max_ec = 0;

	cnt = 0;
    //	memset(idx, -1, (1 << n) * sizeof *idx);

    // 构图，最多
	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & 1 << j) == 0 && kk[ai[i] + ai[i | 1 << j]]-- > 0) {

//				if (idx[i] == -1)
//					idx[i] = newnode(ai[i]);
//
//				if (idx[i | 1 << j] == -1)
//					idx[i | 1 << j] = newnode(ai[i | 1 << j]);

				addedge(idx[i], idx[i | 1 << j]);
                addedge(idx[i | 1 << j], idx[i]);
			}
		}
	}

	memset(match, -1, cnt * sizeof *match);
	for (int i = 0; i < cnt; ++i)
		ii[i] = i;

	sort(ii, ii + cnt, [&ai](const int a, const int b) {
        return ai[a] < ai[b];
    });

	ans = 0;
	while (k--) {
		memset(visited, 0, cnt * sizeof *visited);
		a_ = i_ = j_ = -1;
		for (int i = cnt - 1; i >= 0; --i)
			if (match[ii[i]] == -1)
				dfs1(ii[i], ii[i]);
		if (a_ == -1)
			break;
		memset(visited, 0, cnt * sizeof *visited);
		ans += a_, dfs2(i_, j_);
	}
	printf("%d\n", ans);
	return 0;
}
