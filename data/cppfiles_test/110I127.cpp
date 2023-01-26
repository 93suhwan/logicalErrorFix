#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 1e5 + 5;
int n, x[maxn], y[maxn], c[maxn];
int ord[maxn], p[3] = {1, 2, 3};
vector<int> qx[maxn], qy[maxn];
struct node {
  int l, r;
  node* ch[2];
  int mx = 0, add = 0;
  void pushup() { mx = ch[1]->mx; }
  node(int l, int r) : l(l), r(r) {
    if (l == r) return;
    int mid = l + (r - l) / 2;
    ch[0] = new node(l, mid);
    ch[1] = new node(mid + 1, r);
  }
  void pushtag(int k) {
    mx += k;
    add += k;
  }
  void pushdown() {
    ch[0]->pushtag(add);
    ch[1]->pushtag(add);
    add = 0;
  }
  void modify(int ql, int qr, int k) {
    if (ql <= l && qr >= r) {
      pushtag(k);
      return;
    }
    pushdown();
    if (ql <= ch[0]->r) ch[0]->modify(ql, qr, k);
    if (qr >= ch[1]->l) ch[1]->modify(ql, qr, k);
    pushup();
  }
  int query1(int x) {
    if (l == r) return mx;
    pushdown();
    if (x <= ch[0]->r)
      return ch[0]->query1(x);
    else
      return ch[1]->query1(x);
  }
  int query2() {
    if (l == r) return r;
    pushdown();
    if (ch[0]->mx >= 0)
      return ch[0]->query2();
    else
      return ch[1]->query2();
  }
} * rt1, *rt2, *rt3;
int solve(int* x, vector<int>* qx, int* y) {
  for (int i = 1; i <= n; i++)
    if (c[i] == p[1]) {
      rt1->modify(y[i], n + 1, 1);
      rt2->modify(y[i], n + 1, 1);
    } else if (c[i] == p[2]) {
      rt1->modify(0, y[i] - 1, -1);
      rt3->modify(0, y[i] - 1, -1);
    }
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int u : qx[i])
      if (c[u] == p[0])
        cnt++;
      else if (c[u] == p[1]) {
        rt1->modify(y[i], n + 1, -1);
        rt2->modify(y[i], n + 1, -1);
      } else {
        rt1->modify(0, y[i] - 1, 1);
        rt3->modify(0, y[i] - 1, 1);
      }
    int u = rt1->query2(), res = -rt3->query1(u);
    if (u) res = max(res, rt2->query1(u - 1));
    ans = max(ans, min(cnt, res));
  }
  return ans;
}
int main() {
  n = readint();
  for (int i = 1; i <= n; i++) {
    x[i] = readint();
    y[i] = readint();
    c[i] = readint();
  }
  for (int i = 1; i <= n; i++) ord[i] = x[i];
  sort(ord + 1, ord + n + 1);
  for (int i = 1; i <= n; i++)
    x[i] = lower_bound(ord + 1, ord + n + 1, x[i]) - ord;
  for (int i = 1; i <= n; i++) qx[x[i]].push_back(i);
  for (int i = 1; i <= n; i++) ord[i] = y[i];
  sort(ord + 1, ord + n + 1);
  for (int i = 1; i <= n; i++)
    y[i] = lower_bound(ord + 1, ord + n + 1, y[i]) - ord;
  for (int i = 1; i <= n; i++) qy[y[i]].push_back(i);
  int ans = 0;
  rt1 = new node(0, n + 1);
  rt2 = new node(0, n + 1);
  rt3 = new node(0, n + 1);
  do {
    ans = max(ans, solve(x, qx, x));
    ans = max(ans, solve(x, qx, y));
    ans = max(ans, solve(y, qy, x));
    ans = max(ans, solve(y, qy, y));
    for (int i = 1; i <= n; i++) {
      x[i] = n + 1 - x[i];
      y[i] = n + 1 - y[i];
    }
    reverse(qx + 1, qx + n + 1);
    reverse(qy + 1, qy + n + 1);
    ans = max(ans, solve(x, qx, x));
    ans = max(ans, solve(x, qx, y));
    ans = max(ans, solve(y, qy, x));
    ans = max(ans, solve(y, qy, y));
    for (int i = 1; i <= n; i++) {
      x[i] = n + 1 - x[i];
      y[i] = n + 1 - y[i];
    }
    reverse(qx + 1, qx + n + 1);
    reverse(qy + 1, qy + n + 1);
  } while (next_permutation(p, p + 3));
  printf("%d\n", ans * 3);
  return 0;
}
