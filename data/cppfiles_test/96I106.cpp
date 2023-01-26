#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
inline int read() {
  int x = 0;
  char s = getchar();
  while (s < '0' || s > '9') s = getchar();
  while (s <= '9' && s >= '0') {
    x = (x << 1) + (x << 3) + s - '0';
    s = getchar();
  }
  return x;
}
struct sgm_tree {
  int l;
  int pl, pr;
  int ll, lr;
  long long ans;
  int len;
} s[maxn << 2];
bool operator<(sgm_tree a, sgm_tree b) { return a.l < b.l; }
void up(int p) {
  s[p].l = s[p << 1].l;
  s[p].pl = s[p << 1].pl;
  s[p].pr = s[p << 1 | 1].pr;
  s[p].len = s[p << 1].len + s[p << 1 | 1].len;
  s[p].ans = s[p << 1].ans + s[p << 1 | 1].ans;
  if (s[p << 1].ll == s[p << 1].len) {
    if (s[p << 1].pr <= s[p << 1 | 1].pl) {
      s[p].ll = s[p << 1].ll + s[p << 1 | 1].ll;
    } else {
      s[p].ll = s[p << 1].ll;
    }
  } else {
    s[p].ll = s[p << 1].ll;
  }
  if (s[p << 1 | 1].lr == s[p << 1 | 1].len) {
    if (s[p << 1].pr <= s[p << 1 | 1].pl) {
      s[p].lr = s[p << 1].lr + s[p << 1 | 1].lr;
    } else {
      s[p].lr = s[p << 1 | 1].lr;
    }
  } else {
    s[p].lr = s[p << 1 | 1].lr;
  }
  if (s[p << 1 | 1].pl >= s[p << 1].pr) {
    s[p].ans += s[p << 1 | 1].ll * s[p << 1].lr;
  }
}
void modify(int p, int l, int r, int x, int v) {
  if (l == r) {
    s[p].l = x;
    s[p].pl = s[p].pr = v;
    s[p].ll = s[p].lr = 1;
    s[p].ans = 1;
    s[p].len = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    modify(p << 1, l, mid, x, v);
  } else {
    modify(p << 1 | 1, mid + 1, r, x, v);
  }
  up(p);
}
sgm_tree hb(sgm_tree a, sgm_tree b) {
  sgm_tree res;
  res.pl = a.pl;
  res.pr = b.pr;
  res.len = a.len + b.len;
  res.ans = a.ans + b.ans;
  if (a.ll == a.len) {
    if (a.pr <= b.pl) {
      res.ll = a.ll + b.ll;
    } else {
      res.ll = a.ll;
    }
  } else {
    res.ll = a.ll;
  }
  if (b.lr == b.len) {
    if (a.pr <= b.pl) {
      res.lr = a.lr + b.lr;
    } else {
      res.lr = b.lr;
    }
  } else {
    res.lr = b.lr;
  }
  if (b.pl >= a.pr) {
    res.ans += b.ll * a.lr;
  }
  return res;
}
vector<sgm_tree> v;
void query(int p, int l, int r, int x, int y) {
  if (x <= l && y >= r) {
    v.push_back(s[p]);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    query(p << 1, l, mid, x, y);
  }
  if (y > mid) {
    query(p << 1 | 1, mid + 1, r, x, y);
  }
}
long long js() {
  sort(v.begin(), v.end());
  sgm_tree res;
  if (v.size() == 1) {
    res = v[0];
    return res.ans;
  } else {
    res = hb(v[0], v[1]);
  }
  for (int i = 2; i < v.size(); i++) {
    res = hb(res, v[i]);
  }
  return res.ans;
}
void print(long long x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  int n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    int fz = read();
    modify(1, 1, n, i, fz);
  }
  while (q--) {
    int t = read(), x = read(), y = read();
    if (t == 1) {
      modify(1, 1, n, x, y);
    } else {
      query(1, 1, n, x, y);
      int ans = js();
      v.clear();
      print(ans);
      putchar('\n');
    }
  }
  return 0;
}
