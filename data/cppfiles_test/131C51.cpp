#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
struct modint {
  int x;
  modint(int o = 0) { x = o; }
  modint &operator=(int o) { return x = o, *this; }
  modint &operator+=(modint o) {
    return x = x + o.x >= 998244353 ? x + o.x - 998244353 : x + o.x, *this;
  }
  modint &operator-=(modint o) {
    return x = x - o.x < 0 ? x - o.x + 998244353 : x - o.x, *this;
  }
  modint &operator*=(modint o) { return x = 1ll * x * o.x % 998244353, *this; }
  modint &operator^=(int b) {
    modint a = *this, c = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1) c *= a;
    return x = c.x, *this;
  }
  modint &operator/=(modint o) { return *this *= o ^= 998244353 - 2; }
  modint &operator+=(int o) {
    return x = x + o >= 998244353 ? x + o - 998244353 : x + o, *this;
  }
  modint &operator-=(int o) {
    return x = x - o < 0 ? x - o + 998244353 : x - o, *this;
  }
  modint &operator*=(int o) { return x = 1ll * x * o % 998244353, *this; }
  modint &operator/=(int o) { return *this *= ((modint(o)) ^= 998244353 - 2); }
  template <class I>
  friend modint operator+(modint a, I b) {
    return a += b;
  }
  template <class I>
  friend modint operator-(modint a, I b) {
    return a -= b;
  }
  template <class I>
  friend modint operator*(modint a, I b) {
    return a *= b;
  }
  template <class I>
  friend modint operator/(modint a, I b) {
    return a /= b;
  }
  friend modint operator^(modint a, int b) { return a ^= b; }
  friend bool operator==(modint a, int b) { return a.x == b; }
  friend bool operator!=(modint a, int b) { return a.x != b; }
  bool operator!() { return !x; }
  modint operator-() { return x ? 998244353 - x : 0; }
  bool operator<(const modint &b) const { return x < b.x; }
};
vector<modint> fac, ifac, iv;
inline void initC(int n) {
  if (iv.empty()) fac = ifac = iv = vector<modint>(2, 1);
  int m = iv.size();
  ++n;
  if (m >= n) return;
  iv.resize(n), fac.resize(n), ifac.resize(n);
  for (register int i = (m); i <= (n - 1); ++i) {
    iv[i] = iv[998244353 % i] * (998244353 - 998244353 / i);
    fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * iv[i];
  }
}
inline modint C(int n, int m) {
  if (m < 0 || n < m) return 0;
  return initC(n), fac[n] * ifac[m] * ifac[n - m];
}
inline modint sign(int n) { return (n & 1) ? (998244353 - 1) : (1); }
int n, a[6600005];
unordered_map<int, int> mp;
int mpid[6600005];
inline int Id(int x) {
  if (!mp.count(x)) {
    int sz = mp.size() + 1;
    return mp[x] = sz;
  }
  return mp[x];
}
inline int get(int x) {
  if (!x) return -1;
  for (register int i = (0); i <= (32); ++i)
    if ((1ll << i) >= x) return (1ll << i) - x;
  return -1;
}
vector<int> e[6600005];
int dis[6600005], siz;
void bfs(int s) {
  queue<int> q;
  memset(dis, 63, sizeof dis);
  dis[s] = 0, q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto v : e[u])
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
  }
}
signed main() {
  n = read();
  for (register int i = (1); i <= (n); ++i) a[i] = read();
  for (register int i = (1); i <= (n); ++i) {
    int now = a[i], pa = get(now), idnow = Id(a[i]);
    mpid[idnow] = i;
    while (pa != -1) {
      int idpa = Id(pa);
      e[idpa].push_back(idnow);
      e[idnow].push_back(idpa);
      now = pa, idnow = idpa, pa = get(now);
    }
  }
  siz = mp.size();
  bfs(1);
  int s = 1;
  for (register int i = (1); i <= (siz); ++i)
    if (mpid[i] && dis[i] > dis[s]) s = i;
  bfs(s);
  int t = 1;
  for (register int i = (1); i <= (siz); ++i)
    if (mpid[i] && dis[i] > dis[t]) t = i;
  cout << mpid[s] << ' ' << mpid[t] << ' ' << dis[t] << endl;
  return 0;
}
