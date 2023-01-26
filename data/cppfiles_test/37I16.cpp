#include <bits/stdc++.h>
inline char gc() {
  static const int L = 23333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
template <class T>
inline bool read(T& x) {
  x = 0;
  char c = gc();
  bool flg = false;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x * 10) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
    x %= 10;
  }
  putchar(x | 48);
}
template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <class T>
inline void writesp(T x) {
  write(x);
  putchar(' ');
}
using namespace std;
const int maxn = 100005;
int gcd(int a, int b) {
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int n;
struct Edge {
  int to, nxt;
} e[maxn << 1];
int first[maxn];
int du[maxn];
int dubk[maxn];
int cnt;
void add_edge(int u, int v) {
  du[u]++, du[v]++;
  e[++cnt].nxt = first[u];
  first[u] = cnt;
  e[cnt].to = v;
  e[++cnt].nxt = first[v];
  first[v] = cnt;
  e[cnt].to = u;
}
int final_ans[maxn];
void init() {
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    first[i] = du[i] = final_ans[i] = 0;
  }
}
bool np[maxn];
int factor[maxn];
int prime[maxn];
void oula(const int n = 100000) {
  np[1] = true;
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) {
      prime[++cnt] = i;
      factor[i] = i;
    }
    for (int j = 1; j <= cnt && (long long)i * prime[j] <= n; ++j) {
      np[i * prime[j]] = true;
      factor[i * prime[j]] = prime[j];
      if (!(i % prime[j])) {
        break;
      }
    }
  }
}
bool vis[maxn];
int nn[maxn];
int bfs(int xx) {
  for (int i = 1; i <= n; ++i) {
    vis[i] = false;
  }
  queue<int> q;
  while (!q.empty()) {
    q.pop();
  }
  for (int i = 1; i <= n; ++i) {
    if (du[i] <= 1) {
      q.push(i);
      vis[i] = true;
    }
  }
  int ans = n - 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    bool flg = false;
    if (du[now]) {
      int tmpans = gcd(ans, nn[now]);
      if (tmpans % xx) {
        nn[now]--;
        ans = gcd(ans, nn[now]);
      } else {
        ans = tmpans;
        flg = true;
      }
    } else {
      ans = gcd(ans, nn[now]);
    }
    if (ans % xx) {
      return 1;
    }
    for (int i = first[now]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (!vis[to]) {
        du[to]--;
        if (flg) {
          nn[to]--;
        }
        if (du[to] <= 1) {
          q.push(to);
          vis[to] = 1;
        }
      }
    }
    return ans;
  }
}
const int mod = 998244353;
int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod) {
    if (b & 1) {
      ans = (long long)ans * a % mod;
    }
  }
  return ans;
}
void solve() {
  read(n);
  init();
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    add_edge(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    dubk[i] = du[i];
  }
  int tt = n - 1;
  int tmpans = 0;
  while (tt > 1) {
    for (int i = 1; i <= n; ++i) {
      nn[i] = du[i] = dubk[i];
    }
    int pme = factor[tt];
    while (!(tt % pme)) {
      tt /= pme;
    }
    int nowans = bfs(pme);
    if (nowans > 1 && !final_ans[nowans]) {
      final_ans[nowans] = 1;
      tmpans++;
    }
  }
  final_ans[1] = ksm(2, n - 1) - tmpans;
  if (final_ans[1] < 0) {
    final_ans[1] += mod;
  }
  for (int i = 1; i <= n; ++i) {
    writesp(final_ans[i]);
  }
  puts("");
}
int main() {
  oula();
  int T;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
