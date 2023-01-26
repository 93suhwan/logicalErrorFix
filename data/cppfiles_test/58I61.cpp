#include <bits/stdc++.h>
using namespace std;
void read(int& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(long long& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(unsigned int& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void read(unsigned long long& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void chkmax(int& x, int y) {
  if (y > x) x = y;
}
void chkmin(int& x, int y) {
  if (y < x) x = y;
}
void chkmax(long long& x, long long y) {
  if (y > x) x = y;
}
void chkmin(long long& x, long long y) {
  if (y < x) x = y;
}
void chkmax(unsigned int& x, unsigned int y) {
  if (y > x) x = y;
}
void chkmin(unsigned int& x, unsigned int y) {
  if (y < x) x = y;
}
void chkmax(unsigned long long& x, unsigned long long y) {
  if (y > x) x = y;
}
void chkmin(unsigned long long& x, unsigned long long y) {
  if (y < x) x = y;
}
const int Mod = 998244353;
void Add(int& x, int y) { (x += y) >= Mod ? x -= Mod : x; }
int Pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % Mod;
    a = 1ll * a * a % Mod, b >>= 1;
  }
  return res;
}
const int N = 2e5 + 10;
int n, m;
int Fac[N << 1], Iac[N << 1];
void Init() {
  const int _ = 4e5;
  Fac[0] = Iac[0] = 1;
  for (int i = 1; i <= _; ++i) Fac[i] = 1ll * Fac[i - 1] * i % Mod;
  Iac[_] = Pow(Fac[_], Mod - 2);
  for (int i = _ - 1; i; --i) Iac[i] = 1ll * Iac[i + 1] * (i + 1) % Mod;
}
int Binom(int a, int b) {
  return 1ll * Fac[a] * Iac[b] % Mod * Iac[a - b] % Mod;
}
namespace SPLAY {
int tot, rt;
struct Node {
  int fat, val, idx, siz, son[2];
  Node() {}
  Node(int _fat, int _val, int _idx)
      : fat(_fat), val(_val), idx(_idx), siz(_val) {
    son[0] = son[1] = 0;
  }
} t[N];
void Splay_Init() { tot = rt = 0; }
int NEW(int fat, int val, int idx) {
  t[++tot] = Node(fat, val, idx);
  return tot;
}
int GDir(int now) { return t[t[now].fat].son[1] == now; }
void Update(int now) {
  t[now].siz = t[t[now].son[0]].siz + t[t[now].son[1]].siz + t[now].val;
}
void Rorate(int now) {
  int Fat = t[now].fat, Gat = t[Fat].fat;
  int Fdir = GDir(now), Gdir = GDir(Fat);
  if (Gat) t[Gat].son[Gdir] = now;
  t[now].fat = Gat, t[Fat].fat = now;
  t[Fat].son[Fdir] = t[now].son[Fdir ^ 1];
  t[t[now].son[Fdir ^ 1]].fat = Fat;
  t[now].son[Fdir ^ 1] = Fat;
  Update(Fat), Update(now);
}
void Splay(int now, int Goal = 0) {
  while (t[now].fat != Goal) {
    int Fat = t[now].fat, Gat = t[Fat].fat;
    if (Gat != Goal) (GDir(now) ^ GDir(Fat)) ? Rorate(now) : Rorate(Fat);
    Rorate(now);
  }
  if (!Goal) rt = now;
}
int Find(int pos) {
  int now = rt;
  while (true) {
    if ((pos >= t[t[now].son[0]].siz + 1) &&
        (pos <= t[t[now].son[0]].siz + t[now].val))
      return Splay(now), pos - t[t[now].son[0]].siz;
    if (pos <= t[t[now].son[0]].siz)
      now = t[now].son[0];
    else
      pos -= t[t[now].son[0]].siz + t[now].val, now = t[now].son[1];
  }
}
}  // namespace SPLAY
using namespace SPLAY;
void Solve() {
  read(n), read(m), Splay_Init();
  set<int> S;
  int lst = 0;
  for (int i = 1; i <= m; ++i) {
    int pos, ins;
    read(pos), read(ins);
    if (lst != pos) {
      int cur = NEW(0, pos - lst - 1, lst + 1);
      if (rt) t[rt].fat = cur, t[cur].son[0] = rt;
      rt = cur;
    }
    int rep = Find(ins);
    if (rep > 1) {
      int nod = rt,
          _split = NEW(nod, t[nod].val - rep + 1, t[nod].idx + rep - 1);
      t[nod].val = rep, S.insert(t[nod].idx + rep - 1);
      if (t[nod].son[1])
        t[t[nod].son[1]].fat = _split, t[_split].son[1] = t[nod].son[1];
      t[nod].son[1] = _split, t[_split].son[0] = NEW(_split, 1, pos);
      Update(_split), Update(nod), Splay(t[_split].son[0]);
    } else {
      int nod = rt;
      S.insert(t[nod].idx);
      if (!t[nod].son[0])
        t[nod].son[0] = NEW(nod, 1, pos), Update(nod), Splay(t[nod].son[0]);
      else {
        nod = t[nod].son[0];
        while (t[nod].son[1]) nod = t[nod].son[1];
        t[nod].son[1] = NEW(nod, 1, pos), Update(nod), Splay(t[nod].son[1]);
      }
    }
    lst = pos;
  }
  int cnt = S.size();
  printf("%d\n", Binom(2 * n - 1 - cnt, n));
}
int T;
void Work() {
  read(T), Init();
  while (T--) Solve();
}
int main() { Work(); }
