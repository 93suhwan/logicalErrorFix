#include <bits/stdc++.h>
using namespace std;
template <class T>
void Rd(T &x) {
  x = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 1) + (x << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
struct node {
  int a, b, id;
  node(int _a = 0, int _b = 0, int _id = 0) : a(_a), b(_b), id(_id) {}
} A[200005];
int n;
bool Mark[200005];
int Sum[200005 << 1];
const int md = 1000000007;
void add(int x, int a) {
  for (; x; x -= x & -x) (Sum[x] += a) %= md;
}
int query(int x) {
  int res = 0;
  for (; x <= 2 * n; x += x & -x) (res += Sum[x]) %= md;
  return res;
}
int dp[200005];
int main() {
  Rd(n);
  int a, b;
  for (int i = 1; i <= n; ++i) {
    Rd(a);
    Rd(b);
    A[i] = node(a, b, i);
  }
  int m;
  Rd(m);
  for (int i = 1; i <= m; ++i) {
    Rd(a);
    Mark[a] = 1;
  }
  sort(A + 1, A + n + 1, [=](node &a, node &b) -> bool { return a.b < b.b; });
  int l = 0;
  for (int i = n; i >= 1; --i) {
    if (A[i].a < l) Mark[A[i].id] = 1;
    if (Mark[A[i].id]) l = max(l, A[i].a);
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    (dp[i] += query(A[i].a)) %= md;
    add(A[i].a, dp[i]);
  }
  int ans = 0;
  l = 1;
  for (int i = n; i >= 1; --i) {
    add(A[i].a, md - dp[i]);
    if (Mark[A[i].id]) {
      if (A[i].a < l) continue;
      (ans += query(l) + 1) %= md;
      l = max(l, A[i].a);
    }
  }
  printf("%d\n", ans);
  return 0;
}
