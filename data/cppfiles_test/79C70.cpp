#include <bits/stdc++.h>
using namespace std;
const int BS = 1 << 17;
char buf[BS], *S, *T;
inline char gc() {
  if (S == T) T = (S = buf) + fread(buf, 1, BS, stdin);
  return S != T ? *(S++) : EOF;
}
inline int in() {
  int x = 0, f = 1;
  char c = gc();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = gc();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = gc();
  return x * f;
}
const int N = 3e5 + 5;
int n, a[N], b[N];
int f[N], g[N], p[N];
vector<int> v[N], ans;
set<int> s;
int q[N], ql, qr;
int main() {
  n = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  for (int i = 1; i <= n; i++) b[i] = in();
  for (int i = 0; i < n; i++) s.insert(i);
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  g[n] = 0;
  q[ql = qr = 1] = n;
  while (ql <= qr) {
    int x = q[ql];
    ql++;
    int y = x + b[x];
    if (f[y] > g[x]) {
      f[y] = g[x];
      set<int>::iterator tmp, it = s.lower_bound(y - a[y]);
      while (it != s.end() && *it <= y) {
        g[*it] = f[y] + 1, p[*it] = x;
        q[++qr] = *it;
        tmp = it;
        it++;
        s.erase(tmp);
      }
    }
  }
  if (f[0] > n) return puts("-1"), 0;
  cout << f[0] << endl;
  for (int i = 0; i < n; i = p[i]) ans.push_back(i);
  reverse(ans.begin(), ans.end());
  for (int i : ans) printf("%d ", i);
  return 0;
}
