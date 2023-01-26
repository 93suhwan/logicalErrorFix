#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N	20
#define K	200
#define M	(K * N * 2)
#define N_	(M * 2)
#define A	2000000

using namespace std;
unsigned int X;

int *ej[N_], eo[N_], ai_[N_], mate[N_], n_; char visited[N_];

int newnode(int a) {
	ai_[n_] = a;
	ej[n_] = (int *) malloc(2 * sizeof *ej[n_]);
	return n_++;
}

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int a_, i_, j_;

void dfs1(int s, int i) {
	int o;

	if (visited[i])
		return;
	visited[i] = 1;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (mate[j] == -1) {
			if (a_ < ai_[s] + ai_[j])
				a_ = ai_[s] + ai_[j], i_ = s, j_ = j;
		} else
			dfs1(s, mate[j]);
	}
}

int dfs2(int i, int t) {
	int o;

	if (visited[i])
		return 0;
	visited[i] = 1;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (mate[j] == -1 && j == t || mate[j] != -1 && dfs2(mate[j], t)) {
			mate[i] = j, mate[j] = i;
			return 1;
		}
	}
	return 0;
}

int ai[1 << N], idx[1 << N], kk[A + 1], ii[N_];
int main() {

	int n, k, k_, ans;

	scanf("%d%d", &n, &k);

	for (int i = 0; i < 1 << n; ++i)
		scanf("%d", &ai[i]);

    // kk[x]表示值为x的边有多少（匹配对）数目
	for (int i = 0; i < 1 << n; ++i)
		for (int j = 0; j < n; ++j)
			if ((i & 1 << j) == 0)
				++kk[ai[i] + ai[i | 1 << j]];

    // 这个是用来减少一些不必要的情况
    // 一个人至多和n个匹配，所以至多需要k * n
	k_ = k * n;
	for (int i = A; i >= 0; --i)
		if (k_ > kk[i])
			k_ -= kk[i];
		else
			kk[i] = k_, k_ = 0;

	n_ = 0;
	memset(idx, -1, (1 << n) * sizeof *idx);

	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & 1 << j) == 0 && kk[ai[i] + ai[i | 1 << j]]-- > 0) {

				if (idx[i] == -1)
					idx[i] = newnode(ai[i]);

				if (idx[i | 1 << j] == -1)
					idx[i | 1 << j] = newnode(ai[i | 1 << j]);

				append(idx[i], idx[i | 1 << j]);
                append(idx[i | 1 << j], idx[i]);
			}
		}
	}

	memset(mate, -1, n_ * sizeof *mate);
	for (int i = 0; i < n_; ++i)
		ii[i] = i;

	sort(ii, ii + n_, [&ai_](const int a, const int b) {
        return ai_[a] < ai_[b];
    });

	ans = 0;
	while (k--) {
		memset(visited, 0, n_ * sizeof *visited);
		a_ = i_ = j_ = -1;
		for (int i = n_ - 1; i >= 0; --i)
			if (mate[ii[i]] == -1)
				dfs1(ii[i], ii[i]);
		if (a_ == -1)
			break;
		memset(visited, 0, n_ * sizeof *visited);
		ans += a_, dfs2(i_, j_);
	}
	printf("%d\n", ans);
	return 0;
}
