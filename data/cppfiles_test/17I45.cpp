#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
struct node {
  int l, r;
  int sum;
} tr[N << 2];
int a[N];
void build(int k, int l, int r) {
  if (l == r) {
    tr[k] = {l, r, 0};
    return;
  }
  tr[k] = {l, r};
  int m = (l + r) >> 1;
  build(k << 1, l, m);
  build(k << 1 | 1, m + 1, r);
}
void pushup(int k) { tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum; }
void updata(int k, int p) {
  if (tr[k].l == p && tr[k].r == p) {
    tr[k].sum++;
    return;
  }
  int m = (tr[k].l + tr[k].r) >> 1;
  if (p <= m)
    updata(k << 1, p);
  else
    updata(k << 1 | 1, p);
  pushup(k);
}
int find(int k, int l, int r) {
  if (tr[k].l >= l && tr[k].r <= r) return tr[k].sum;
  int m = (tr[k].l + tr[k].r) >> 1;
  if (r <= m)
    return find(k << 1, l, r);
  else if (l > m)
    return find(k << 1 | 1, l, r);
  else
    return find(k << 1, l, r) + find(k << 1 | 1, l, r);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      v.push_back(a[i]);
    }
    map<int, int> mp;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int idx = 0;
    for (int i = 0; i < v.size(); i++) {
      mp[v[i]] = ++idx;
    }
    build(1, 1, idx);
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int p = mp[a[i]];
      updata(1, p);
      if (p == 1 || p == idx) continue;
      int x = find(1, 1, p - 1);
      res += min(x, i - 1 - x);
    }
    printf("%d\n", res);
  }
}
