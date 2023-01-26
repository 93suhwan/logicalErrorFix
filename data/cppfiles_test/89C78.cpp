#include <bits/stdc++.h>
using namespace std;
struct vert {
  int v, l, r;
  vert *ls, *rs;
};
vert* build(vert* a, int l, int r) {
  a->v = 0;
  a->l = l;
  a->r = r;
  if (r - l == 1) return a;
  a->ls = new vert;
  a->rs = new vert;
  a->ls = build(a->ls, l, (l + r) / 2);
  a->rs = build(a->rs, (l + r) / 2, r);
  return a;
}
int get(vert* a, int l, int r) {
  if (l >= a->r || r <= a->l) return 0;
  if (l <= a->l && a->r <= r) return a->v;
  return get(a->ls, l, r) + get(a->rs, l, r);
}
void ch(vert* a, int in) {
  a->v += 1;
  if (a->r - a->l == 1) return;
  if (in < (a->l + a->r) / 2)
    ch(a->ls, in);
  else
    ch(a->rs, in);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = i - 1;
    vector<int> used(n, 0);
    bool f = 1;
    vert* root = new vert;
    build(root, 0, n);
    while (f) {
      f = 0;
      int q = n - 1;
      while (q >= 0) {
        if (a[q] % (q + 2 - get(root, 0, q)) && !used[q]) {
          f = 1;
          used[q] = 1;
          ch(root, q);
          break;
        }
        if (b[q] >= 0 && used[b[q]]) b[q] = b[b[q]];
        q = b[q];
      }
    }
    f = 1;
    for (int i = 0; i < n; i++)
      if (!used[i]) f = 0;
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
