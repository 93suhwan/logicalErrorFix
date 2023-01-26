#include <bits/stdc++.h>
using namespace std;
int T, n, b[500005], a[500005], cnt;
struct po {
  int l, r, w, p;
} t[500005 << 2];
void build(int l, int r, int k) {
  t[k].l = l, t[k].r = r, t[k].w = a[l], t[k].p = l;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, k << 1), build(mid + 1, r, k << 1 | 1);
  if (t[k << 1].w > t[k << 1 | 1].w)
    t[k].w = t[k << 1].w, t[k].p = t[k << 1].p;
  else
    t[k].w = t[k << 1 | 1].w, t[k].p = t[k << 1 | 1].p;
}
void add(int x, int w, int k) {
  if (t[k].l == t[k].r) {
    t[k].w = w;
    return;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if (x <= mid)
    add(x, w, k << 1);
  else
    add(x, w, k << 1 | 1);
  if (t[k << 1].w > t[k << 1 | 1].w)
    t[k].w = t[k << 1].w, t[k].p = t[k << 1].p;
  else
    t[k].w = t[k << 1 | 1].w, t[k].p = t[k << 1 | 1].p;
}
map<int, int> tu;
bool fl;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    tu.clear(), fl = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], tu[a[i]]++;
    for (int i = 1; i <= n; i++)
      if (tu[a[i]] > 1) fl = 1;
    if (n == 1 || fl) {
      puts("YES");
      continue;
    }
    build(1, n, 1);
    for (int i = n; i >= 3; i--) {
      int now = t[1].w, pos = t[1].p;
      if (now > a[i]) {
        if (pos == i - 1) {
          swap(a[i], a[i - 1]);
          swap(a[i - 1], a[i - 2]);
          add(i, 0, 1);
          add(i - 1, a[i - 1], 1);
          add(i - 2, a[i - 2], 1);
        } else {
          swap(a[i], a[pos]);
          swap(a[i - 1], a[pos]);
          add(i, 0, 1);
          add(i - 1, a[i - 1], 1);
          add(i - 2, a[pos], 1);
        }
      } else {
        add(i, 0, 1);
      }
    }
    puts(a[1] <= a[2] ? "YES" : "NO");
  }
}
