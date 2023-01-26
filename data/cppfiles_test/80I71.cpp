#include <bits/stdc++.h>
using namespace std;
const int M = 2e6 + 5;
int n, m, tmp2[M];
int a[M], b[M], c[M], pos[M];
void mymid(int ta[], int tb[], int tpos[], int l, int r, int L, int R) {
  if (L > R) return;
  int mid = (L + R) / 2;
  int now = 0, po, mmin;
  for (int i = l; i < r; i++)
    if (ta[i] < tb[mid]) now++;
  mmin = now, po = l;
  for (int i = l + 1; i <= r; i++) {
    if (ta[i - 1] < tb[mid]) now--;
    if (ta[i - 1] > tb[mid]) now++;
    if (now < mmin) mmin = now, po = i;
  }
  tpos[mid] = po;
  mymid(ta, tb, tpos, l, po, L, mid - 1);
  mymid(ta, tb, tpos, po, r, mid + 1, R);
}
void print(int tmp[], int len) {
  for (int i = 1; i <= len; i++) printf("%d ", tmp[i]);
  printf("\n");
}
int mysort(int tmp[], int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r) / 2, res = 0;
  res += mysort(tmp, l, mid);
  res += mysort(tmp, mid + 1, r);
  int t1 = l, t2 = mid + 1, t3 = 1;
  while (t1 <= mid && t2 <= r) {
    if (tmp[t1] <= tmp[t2])
      tmp2[t3++] = tmp[t1++], res += t2 - mid - 1;
    else
      tmp2[t3++] = tmp[t2++];
  }
  while (t1 <= mid) tmp2[t3++] = tmp[t1++], res += t2 - mid - 1;
  while (t2 <= r) tmp2[t3++] = tmp[t2++];
  for (int i = l; i <= r; i++) tmp[i] = tmp2[i - l + 1];
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m);
    mymid(a, b, pos, 1, n + 1, 1, m);
    int t1 = 1, t2 = 1, t3 = 1;
    while (t1 <= n + m) {
      while (pos[t2] <= t3 && t2 <= m) c[t1++] = b[t2++];
      if (t1 > n + m) break;
      c[t1++] = a[t3++];
    }
    printf("%d\n", mysort(c, 1, n + m));
  }
  return 0;
}
