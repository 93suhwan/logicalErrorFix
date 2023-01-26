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
int f[N], g[N], h[N];
int c[N];
vector<int> v[N], ans;
inline void ins(int a) {
  for (int i = a; i >= 1; i -= i & -i) {
    if (f[c[i]] > f[a]) c[i] = a;
  }
}
inline int get(int a) {
  int res = 0;
  for (int i = a; i <= n; i += i & -i) {
    if (f[res] > f[c[i]]) res = c[i];
  }
  return res;
}
int main() {
  n = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  for (int i = 1; i <= n; i++) b[i] = in(), v[i + b[i]].push_back(i);
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int p;
    if (a[i] == i) {
      h[i] = p = 0;
      f[i] = g[i] = 1;
    } else {
      p = get(i - a[i]);
      g[i] = f[p] + 1;
    }
    for (int j : v[i]) {
      if (f[j] == 1) continue;
      f[j] = g[i], h[j] = p;
      ins(j);
    }
  }
  if (f[n] <= n) {
    for (int i = n; i; i = h[i]) ans.push_back(h[i]);
    cout << ans.size() << endl;
    for (int p : ans) printf("%d ", p);
  } else
    puts("-1");
  return 0;
}
