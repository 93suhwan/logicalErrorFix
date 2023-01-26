#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
int N, D, a[1000006];
int dist[1000006];
int que[1000006], kq;
void solve() {
  scanf("%d%d", &N, &D);
  for (int i = 0; i < (int)(N); ++i) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(N); ++i) dist[i] = INF;
  for (int i = 0; i < (int)(N); ++i)
    if (a[i] == 0) dist[i] = 0, que[kq++] = i;
  for (int i = 0; i < (int)(kq); ++i) {
    int v = que[i];
    if (dist[v] + 1 < dist[(v + D) % N]) {
      dist[(v + D) % N] = dist[v] + 1;
      que[kq++] = (v + D) % N;
    }
  }
  int mx = 0;
  for (int i = 0; i < (int)(N); ++i) mx = max(mx, dist[i]);
  if (mx == INF)
    printf("-1\n");
  else
    printf("%d\n", mx);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
