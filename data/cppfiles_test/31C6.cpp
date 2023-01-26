#include <bits/stdc++.h>
using namespace std;
char _c;
bool _f;
template <class T>
inline void IN(T& x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T& x, T y) {
  if (x < y) x = y;
}
const int N = (1 << 19) | 5;
const int M = N * 20;
const int inf = 1e9 + 7;
int n, k, a[N];
int cnt, mi[M], mx[M], dep[M], siz[M], ans[M], ch[M][2];
inline void pushup(int now) {
  mi[now] = ch[now][0] ? mi[ch[now][0]] : (1 << dep[now]) + mi[ch[now][1]];
  mx[now] = ch[now][1] ? (1 << dep[now]) + mx[ch[now][1]] : mx[ch[now][0]];
  if (siz[now] <= 1)
    ans[now] = inf;
  else {
    if (!ch[now][0] || !ch[now][1])
      ans[now] = ans[ch[now][ch[now][0] == 0]];
    else
      ans[now] = min(min(ans[ch[now][0]], ans[ch[now][1]]),
                     mi[ch[now][1]] + (1 << dep[now]) - mx[ch[now][0]]);
  }
}
void insert(int now, int val) {
  ++siz[now];
  if (dep[now] == -1) return ans[now] = inf, void();
  bool c = (val >> dep[now]) & 1;
  if (!ch[now][c]) ch[now][c] = ++cnt, dep[ch[now][c]] = dep[now] - 1;
  insert(ch[now][c], val), pushup(now);
}
void flip(int now, int val) {
  if (dep[now] == -1 || (!((val >> dep[now]) & 1))) return;
  swap(ch[now][0], ch[now][1]);
  if (ch[now][0]) flip(ch[now][0], val);
  if (ch[now][1]) flip(ch[now][1], val);
  pushup(now);
}
int ANS[N], lst = 0;
void solve(int val, int now) {
  if (now == k) return flip(0, lst ^ val), lst = val, ANS[val] = ans[0], void();
  solve(val, now + 1), solve(val | (1 << now), now + 1);
}
int main() {
  IN(n), IN(k), dep[0] = k - 1;
  for (int i = 1; i <= n; ++i) IN(a[i]), insert(0, a[i]);
  solve(0, 0);
  for (int i = 0; i < 1 << k; ++i) printf("%d ", ANS[i]);
  puts("");
  return 0;
}
