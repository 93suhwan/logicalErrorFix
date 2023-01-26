#include <bits/stdc++.h>
using namespace std;
const int M = (int)2e5 + 5, N = (int)2e6 + 5;
int A[M], B[M], m[M], Aans[M], beg[M], len[M];
int n, mark[N], TIM;
vector<int> id[N];
bool cmp(int x, int y) {
  if (beg[x] != beg[y]) return beg[x] < beg[y];
  return len[x] < len[y];
}
void solve() {
  TIM++;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &A[i], &B[i], &m[i]);
    id[A[i] + B[i] - m[i]].push_back(i);
    if (A[i] >= m[i]) {
      beg[i] = A[i] - m[i];
      if (B[i] >= m[i])
        len[i] = m[i];
      else
        len[i] = B[i];
    } else {
      if (B[i] >= m[i]) {
        beg[i] = 0;
        len[i] = A[i];
      } else {
        beg[i] = 0;
        len[i] = A[i] - m[i] + B[i];
      }
    }
  }
  beg[n + 1] = (int)2e7;
  int ans = 0;
  for (int iter = 1; iter <= n; iter++) {
    int bg = A[iter] + B[iter] - m[iter];
    if (mark[bg] != TIM) {
      mark[bg] = TIM;
      sort(id[bg].begin(), id[bg].end(), cmp);
      ans--;
      id[bg].push_back(n + 1);
      int sz = id[bg].size(), r = -1, l = 0;
      for (int i = 0; i < sz; i++) {
        if (beg[id[bg][i]] > r) {
          ans++;
          for (int j = l; j < i; j++) {
            Aans[id[bg][j]] = A[id[bg][j]] - r;
          }
          r = beg[id[bg][i]] + len[id[bg][i]];
          l = i;
        } else {
          r = min(r, beg[id[bg][i]] + len[id[bg][i]]);
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d %d\n", Aans[i], m[i] - Aans[i]);
  for (int i = 1; i <= n; i++) id[A[i] + B[i] - m[i]].clear();
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
