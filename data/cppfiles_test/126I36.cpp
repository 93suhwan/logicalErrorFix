#include <bits/stdc++.h>
using namespace std;
const int Mxxx = 1e5;
inline char gc() {
  static char buf[Mxxx], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Mxxx, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline char pc(char ch, bool fl = false) {
  static char buf[Mxxx], *p1 = buf, *p2 = buf + Mxxx;
  return (fl || ((*p1++ = ch) && p1 == p2)) &&
             (fwrite(buf, 1, p1 - buf, stdout), p1 = buf),
         0;
}
inline int read() {
  char ch = gc();
  int gans = 0, gflag = 0;
  for (; ch < '0' || '9' < ch; gflag |= ch == '-', ch = gc())
    ;
  for (; '0' <= ch && ch <= '9';
       gans = (gans << 1) + (gans << 3) + (ch ^ 48), ch = gc())
    ;
  return gflag ? -gans : gans;
}
template <typename T>
inline char read(T& gans) {
  char ch = gc();
  int gflag = 0;
  gans = 0;
  for (; ch < '0' || '9' < ch; gflag |= ch == '-', ch = gc())
    ;
  for (; '0' <= ch && ch <= '9';
       gans = (gans << 1) + (gans << 3) + (ch ^ 48), ch = gc())
    ;
  return gans = gflag ? -gans : gans, ch;
}
template <typename T>
inline void write(T x) {
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
template <typename T>
inline void writenum(T x, char ch) {
  if (x < 0) pc('-'), x = -x;
  write(x);
  pc(ch);
}
inline void writechar(char x, char ch) {
  pc(x);
  pc(ch);
}
template <typename T>
inline T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
inline T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline T Abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
inline void ckmx(T& x, T y) {
  x = Max(x, y);
}
template <typename T>
inline void ckmn(T& x, T y) {
  x = Min(x, y);
}
const int Mx = 1e3;
namespace Wll {
const int M = Mx * 6;
int cnt, h[Mx + 5], nxt[M + 5], tto[M + 5], val[M + 5];
inline void ade(int x, int y, int v) {
  nxt[++cnt] = h[x];
  tto[h[x] = cnt] = y;
  val[cnt] = v;
}
inline void Ade(int x, int y, int v) {
  ade(x, y, v);
  ade(y, x, 0);
}
int tot;
inline void Pre(int x) { tot = x; }
inline void Clr(const vector<int>& vec) {
  cnt = 1;
  for (int to : vec) h[to] = 0;
  h[tot] = h[tot - 1] = 0;
}
int fst[Mx + 5];
inline void Pre(const vector<int>& vec) {
  for (int to : vec) fst[to] = h[to];
  fst[tot - 1] = h[tot - 1];
}
int ds[Mx + 5];
inline int Bfs(const vector<int>& vec, int s, int t) {
  static queue<int> q;
  for (int to : vec) ds[to] = INT_MAX, h[to] = fst[to];
  ds[t] = INT_MAX;
  h[s] = fst[s];
  int i, x, to;
  ds[s] = 0;
  q.push(s);
  for (; !q.empty();) {
    x = q.front();
    q.pop();
    for (i = h[x]; i; i = nxt[i])
      if (val[i] && ds[to = tto[i]] == INT_MAX) ds[to] = ds[x] + 1, q.push(to);
  }
  return ds[t] ^ INT_MAX;
}
inline int DFS(int x, int y, int z) {
  if (x == z) return y;
  int k, to, sm = 0;
  for (int& i = h[x]; i; i = nxt[i]) {
    if (val[i] && ds[to = tto[i]] == ds[x] + 1) {
      if (!(k = DFS(to, Min(y, val[i]), z))) {
        ds[to] = INT_MAX;
        continue;
      }
      val[i] -= k;
      val[i ^ 1] += k;
      if (!(sm += k, y -= k)) return sm;
    }
  }
  return sm;
}
inline int Dnc(const vector<int>& vec, int s, int t) {
  int sm = 0;
  for (Pre(vec); Bfs(vec, s, t); sm += DFS(s, INT_MAX, t))
    ;
  return sm;
}
int vst[Mx + 5];
inline void Srt(const vector<int>& vec, vector<int>& v1, vector<int>& v2,
                int s) {
  static queue<int> q;
  for (int to : vec) vst[to] = 0;
  q.push(s);
  for (int x; !q.empty();) {
    x = q.front();
    q.pop();
    for (int i = h[x], to; i; i = nxt[i])
      if (val[i] && !vst[to = tto[i]]) vst[to] = 1, q.push(to);
  }
  for (int to : vec)
    if (vst[to])
      v2.emplace_back(to);
    else
      v1.emplace_back(to);
}
}  // namespace Wll
int cnt, h[Mx + 5], nxt[Mx + 5], tto[Mx + 5];
inline void ade(int x, int y) {
  nxt[++cnt] = h[x];
  tto[h[x] = cnt] = y;
}
int S, T, V, ttt, vst[Mx + 5], val[Mx + 5];
inline int Calc(int x, int v) { return Abs(val[x] - v); }
long long ans;
inline void Slv(const vector<int>& vec, int l, int r) {
  if (vec.empty()) return;
  if (l == r) {
    for (int to : vec) ans += Calc(to, l);
    return;
  }
  int i, v, to, mid = (l + r) >> 1;
  V = mid;
  ttt++;
  Wll::Clr(vec);
  for (int x : vec) {
    vst[x] = ttt;
    v = Calc(x, V) - Calc(x, V + 1);
    if (v > 0) Wll::Ade(S, x, v);
    if (v < 0) Wll::Ade(x, T, -v);
  }
  for (int x : vec)
    for (i = h[x]; i; i = nxt[i])
      if (vst[to = tto[i]] == ttt) Wll::Ade(x, to, INT_MAX);
  vector<int> vec1, vec2;
  Wll::Dnc(vec, S, T);
  Wll::Srt(vec, vec1, vec2, S);
  Slv(vec1, l, mid);
  Slv(vec2, mid + 1, r);
}
int n, m;
const int M = 1e9;
signed main() {
  int i, x;
  n = read();
  m = read();
  vector<int> tp;
  for (i = 1; i <= n; i++) val[i] = read(), tp.emplace_back(i);
  for (i = 1; i <= m; i++) x = read(), ade(x, read());
  S = n + 1;
  Wll::Pre(T = n + 2);
  Slv(tp, -M, M);
  writenum(ans, 10);
  return pc('!', true);
}
