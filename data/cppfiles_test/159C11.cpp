#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
namespace GTI {
char gc(void) {
  const int S = 1 << 16;
  static char buf[S], *s = buf, *t = buf;
  if (s == t) t = buf + fread(s = buf, 1, S, stdin);
  if (s == t) return EOF;
  return *s++;
}
ll gti(void) {
  ll a = 0, b = 1, c = gc();
  for (; !isdigit(c); c = gc()) b ^= (c == '-');
  for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
  return b ? a : -a;
}
int gts(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
int gtl(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
}  // namespace GTI
using GTI::gti;
using GTI::gtl;
using GTI::gts;
using RandType = std::mt19937_64;
RandType init_rand(void) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  RandType rand_num(seed);
  return rand_num;
}
RandType randx = init_rand();
using ull = unsigned long long;
const int N = 1e6 + 500;
bool vis[N];
int pri[N], pcnt, dv[N];
ull key[N], tag[N], pre[N];
std::unordered_map<ull, int> id;
void getpri(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) ++pcnt, pri[pcnt] = i, key[pcnt] = randx(), dv[i] = pcnt;
    for (int j = 1; j <= pcnt && 1ll * i * pri[j] <= n; j++) {
      vis[i * pri[j]] = true;
      dv[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 2; i <= n; i++) {
    int v = i;
    while (v > 1) tag[i] ^= key[dv[v]], v /= pri[dv[v]];
  }
  for (int i = 1; i <= n; i++) tag[i] ^= tag[i - 1], id[tag[i]] = i;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ tag[i];
}
int ans = 0, ansp[N];
void calc(int n) {
  if (n < ans) return;
  ull now = pre[n];
  if (now == 0) {
    if (n > ans) {
      ans = n;
      for (int i = 1; i <= n; i++) ansp[i] = i;
    }
    return;
  }
  for (int i = 2; i < n; i++)
    if ((now ^ tag[i]) == 0) {
      if (n - 1 > ans) {
        ans = 0;
        for (int d = 1; d <= n; d++)
          if (d != i) ansp[++ans] = d;
      }
      return;
    }
  for (int i = 2; i < n; i++)
    if (id.count(now ^ tag[i])) {
      int j = id[now ^ tag[i]];
      if (j <= n) {
        if (n - 2 > ans) {
          ans = 0;
          for (int d = 1; d <= n; d++)
            if (d != i && d != j) ansp[++ans] = d;
        }
        return;
      }
    }
}
int main(void) {
  int n = gti();
  getpri(n);
  for (int i = n; i >= 1; i--) calc(i);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d%c", ansp[i], " \n"[i == ans]);
  return 0;
}
