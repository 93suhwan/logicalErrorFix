#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int g[N][N];
int ans = -1;
inline void Solve(int l, int r, int K, int dep) {
  if (l >= r) return;
  ans = ((ans) < (dep) ? (dep) : (ans));
  int siz = (r - l + 1) / K;
  if (!siz) ++siz;
  int last = l, cnt = 0;
  vector<pair<int, int> > S;
  while (last <= r && cnt < K)
    ++cnt, Solve(last, cnt == K ? r : min(last + siz - 1, r), K, dep + 1),
        S.push_back(make_pair(last, cnt == K ? r : min(last + siz - 1, r))),
        last += siz;
  for (register int i = 0; i < (int)S.size(); ++i)
    for (register int j = i + 1; j < (int)S.size(); ++j)
      for (register int k = S[i].first; k <= S[i].second; ++k)
        for (register int l = S[j].first; l <= S[j].second; ++l) g[k][l] = dep;
}
int main() {
  scanf("%d%d", &n, &m);
  Solve(1, n, m, 1);
  printf("%d\n", ans);
  for (register int i = 1; i <= n; ++i)
    for (register int j = i + 1; j <= n; ++j) printf("%d ", g[i][j]);
  return 0;
}
