#include <bits/stdc++.h>
using namespace std;
const int N = 2027;
template <typename T>
void read(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; (c ^ 48) > 9; c = getchar())
    if (c == '-') neg = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
int t, n, a[N], m, ans[5 * N];
bool check() {
  for (int i = 0, i_end = n; i < i_end; ++i)
    if ((i & 1) != (a[i] & 1)) return false;
  return true;
}
void op(int len) {
  for (int i = 0, i_end = len / 2; i < i_end; ++i)
    a[i] ^= a[len - 1 - i] ^= a[i] ^= a[len - 1 - i];
  ans[m++] = len;
}
void solve(int n) {
  int apos, bpos;
  if (n == 1) return;
  for (int i = 0, i_end = n; i < i_end; ++i)
    if (a[i] == n - 1) bpos = i;
  op(++bpos);
  for (int i = 0, i_end = n; i < i_end; ++i)
    if (a[i] == n - 2) apos = i;
  op(apos);
  op(apos + 2);
  op(3);
  op(n);
  solve(n - 2);
}
int main() {
  read(t);
  while (t--) {
    read(n);
    for (int i = 0, i_end = n; i < i_end; ++i) read(a[i]), --a[i];
    if (check()) {
      m = 0;
      solve(n);
      printf("%d\n", m);
      for (int i = 0, i_end = m; i < i_end; ++i) printf("%d ", ans[i]);
      puts("");
    } else
      puts("-1");
  }
  return 0;
}
