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
void Del(int& x, int y) { (x -= y) < 0 ? x += Mod : x; }
const int N = 3e5 + 10;
const pair<int, int> I = make_pair(0, 0);
int n, m, k;
int in[N], out[N];
set<pair<int, int> > S;
int _len[N], B[N], F[N];
vector<int> Trans;
int fat[N], siz[N], vis[N];
void Init() {
  for (int i = 1; i <= k; ++i) fat[i] = i, siz[i] = 1;
}
int getf(int now) { return now == fat[now] ? now : fat[now] = getf(fat[now]); }
void Merge(int u, int v) {
  u = getf(u), v = getf(v);
  if (u != v)
    fat[u] = v, siz[v] += siz[u], vis[v] |= vis[u];
  else
    vis[u] = 1;
}
void Work() {
  read(n), read(m), read(k), Init();
  for (int i = 1; i <= n; ++i) {
    int c, pre = 0, now;
    read(c);
    for (int p = 0; p < c; ++p) {
      read(now);
      if (p)
        if (S.find(make_pair(pre, now)) == S.end())
          Merge(pre, now), ++in[pre], ++out[now], S.insert(make_pair(pre, now));
      pre = now;
    }
  }
  for (int i = 1; i <= k; ++i)
    if (in[i] > 1 || out[i] > 1) vis[getf(i)] = 1;
  for (int i = 1; i <= k; ++i)
    if (fat[i] == i && !vis[i]) ++B[siz[i]];
  for (int i = 1; i <= m; ++i)
    if (B[i]) Trans.push_back(i);
  F[0] = 1;
  for (int i = 1; i <= m; ++i)
    for (int v : Trans)
      if (v <= i) Add(F[i], 1ll * F[i - v] * B[v] % Mod);
  printf("%d\n", F[m]);
}
int main() { Work(); }
