#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e5 + 100;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
struct node {
  int m;
} t[1200000 * 4 + 100];
int a[1200000], vis[1200000], l[1200000], n, m;
int hf(int x, int y) {
  if (x <= n && x >= 1 && y >= 1 && y <= m) return 1;
  return 0;
}
void build(int x, int ql, int qr) {
  if (ql == qr) {
    t[x].m = l[ql];
    return;
  }
  int mid = (ql + qr) / 2;
  build(2 * x, ql, mid);
  build(2 * x + 1, mid + 1, qr);
  t[x].m = max(t[2 * x].m, t[2 * x + 1].m);
}
int ask(int x, int l, int r, int ql, int qr) {
  if (l == ql && qr == r) {
    return t[x].m;
  }
  int mid = (l + r) / 2;
  if (qr <= mid)
    return ask(2 * x, l, mid, ql, qr);
  else {
    if (ql > mid)
      return ask(2 * x + 1, mid + 1, r, ql, qr);
    else {
      return max(ask(2 * x, l, mid, ql, mid),
                 ask(2 * x + 1, mid + 1, r, mid + 1, qr));
    }
  }
}
int sum[1200000];
vector<int> v[1200000], dpl[1200000], can[1200000];
char s[1200000];
int main() {
  int q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    v[i].clear();
    v[i].push_back(-1);
    for (int j = 0; j < m; j++) {
      if (s[j] == '.') {
        v[i].push_back(0);
      } else {
        v[i].push_back(1);
      }
      can[i].push_back(0);
      dpl[i].push_back(0);
    }
    can[i].push_back(0);
    can[i].push_back(0);
    can[i].push_back(0);
    dpl[i].push_back(0);
    dpl[i].push_back(0);
    dpl[i].push_back(0);
  }
  for (int i = 1; i <= m; i++) l[i] = 1;
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (v[i][j] == 1 && hf(i + 1, j - 1) && v[i + 1][j - 1] == 1) {
        l[j] = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + l[i];
  }
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int t = sum[r] - sum[l];
    if (t == r - l) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
