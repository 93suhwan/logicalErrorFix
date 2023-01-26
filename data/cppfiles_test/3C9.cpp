#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int op = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') op = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= op;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
const int L = 200000;
const int MN = L + 10;
int n, m, X;
struct item {
  int v, mx;
} A[MN], B[MN];
bool cmp1(item a, item b) { return a.v < b.v; }
bool cmp2(item a, item b) { return a.mx > b.mx; }
int stk[MN], top, mx[MN];
long long ans;
struct BITS {
  int c[MN];
  inline int lwb(int x) { return x & (-x); }
  void Add(int x, int v) {
    for (; x <= L; x += lwb(x)) c[x] += v;
  }
  int Ask(int x) {
    int s = 0;
    for (; x; x -= lwb(x)) s += c[x];
    return s;
  }
  int Qur(int l, int r) {
    l = max(l, 1);
    r = min(r, L);
    return l > r ? 0 : Ask(r) - Ask(l - 1);
  }
} tr;
int main() {
  read(n);
  read(m);
  read(X);
  for (int i = 1; i <= n; ++i) read(A[i].v);
  for (int i = 1; i <= m; ++i) read(B[i].v);
  mx[0] = L;
  for (int i = 1; i <= n; ++i) {
    while (top && A[stk[top]].v > A[i].v)
      mx[top - 1] = max(mx[top - 1], mx[top]), top--;
    A[i].mx = mx[top];
    stk[++top] = i;
    mx[top] = A[i].v;
  }
  top = 0;
  for (int i = 1; i <= m; ++i) {
    while (top && B[stk[top]].v > B[i].v)
      mx[top - 1] = max(mx[top - 1], mx[top]), top--;
    B[i].mx = mx[top];
    stk[++top] = i;
    mx[top] = B[i].v;
  }
  top = 0;
  for (int i = n; i >= 1; --i) {
    while (top && A[stk[top]].v >= A[i].v)
      mx[top - 1] = max(mx[top - 1], mx[top]), top--;
    A[i].mx = min(A[i].mx, mx[top]);
    stk[++top] = i;
    mx[top] = A[i].v;
  }
  top = 0;
  for (int i = m; i >= 1; --i) {
    while (top && B[stk[top]].v >= B[i].v)
      mx[top - 1] = max(mx[top - 1], mx[top]), top--;
    B[i].mx = min(B[i].mx, mx[top]);
    stk[++top] = i;
    mx[top] = B[i].v;
  }
  sort(A + 1, A + n + 1, cmp1);
  sort(B + 1, B + m + 1, cmp2);
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < m && B[j + 1].mx > X - A[i].v) j++, tr.Add(B[j].v, 1);
    ans += tr.Qur(X - A[i].mx + 1, X - A[i].v);
  }
  printf("%lld", ans);
  return 0;
}
