#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, x, sum, l[200001], r[200001], p[200001], t[400001], ans, f[200001],
    la;
bool fl[200001];
bool cmp(int a, int b) { return r[a] < r[b]; }
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int del(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int lowbit(int a) { return a & (-a); }
void ins(int a, int c) {
  while (a) {
    t[a] = add(t[a], c);
    a = a - lowbit(a);
  }
}
int find(int a) {
  int s = 0;
  while (a <= sum) {
    s = add(s, t[a]);
    a = a + lowbit(a);
  }
  return s;
}
int main() {
  scanf("%d", &n);
  sum = n + n;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    p[i] = i;
  }
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    f[p[i]] = add(find(l[p[i]]), 1);
    ins(l[p[i]], f[p[i]]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    fl[x] = 1;
  }
  for (int i = n; i >= 1; i--) {
    ins(l[p[i]], del(0, f[p[i]]));
    if (fl[p[i]]) {
      if (la < l[p[i]]) {
        ans = add(ans, add(find(la + 1), 1));
        la = l[p[i]];
      }
    }
  }
  printf("%d\n", ans);
}
