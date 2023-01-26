#include <bits/stdc++.h>
using namespace std;
struct node {
  long long s, mn, mx;
};
node T[303030];
node operator+(node l, node r) {
  node x;
  x.s = l.s + r.s;
  x.mn = min(l.mn, l.s + r.mn);
  x.mx = max(l.mx, l.s + r.mx);
  return x;
}
int A[100009];
void init(int idx, int s, int e) {
  if (s == e) {
    T[idx] = {A[s], min(A[s], 0), max(A[s], 0)};
    return;
  }
  int m = s + e >> 1;
  init(idx * 2, s, m);
  init(idx * 2 + 1, m + 1, e);
  T[idx] = T[idx * 2] + T[idx * 2 + 1];
}
node get(int idx, int s, int e, int l, int r) {
  if (r < s || e < l) return (node){0, 0, 0};
  if (l <= s && e <= r) return T[idx];
  int m = s + e >> 1;
  return get(idx * 2, s, m, l, r) + get(idx * 2 + 1, m + 1, e, l, r);
}
int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    A[i] = x - A[i];
  }
  init(1, 1, N);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    node x = get(1, 1, N, l, r);
    if (x.mn < 0 || x.s != 0)
      puts("-1");
    else
      printf("%lld\n", x.mx);
  }
  return 0;
}
