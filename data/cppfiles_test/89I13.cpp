#include <bits/stdc++.h>
using namespace std;
struct IOReader {
  template <typename T>
  inline IOReader& operator>>(T& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = (a << 3) + (a << 1) + (ch ^ '0');
      ch = getchar();
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(string& a) {
    a.clear();
    char ch = getchar();
    while (isspace(ch) && ch != EOF) ch = getchar();
    while (!isspace(ch) && ch != EOF) a += ch, ch = getchar();
    return *this;
  }
  inline IOReader& operator>>(char* a) {
    scanf(" %s", a);
    return *this;
  }
  inline IOReader& operator>>(char& a) {
    a = getchar();
    while (isspace(a)) a = getchar();
    return *this;
  }
  inline IOReader& operator>>(float& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      float p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(long double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      long double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
} iocin;
int readInt() {
  int a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned int readUInt() {
  unsigned int a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
long long readLL() {
  long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned long long readULL() {
  unsigned long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
short readShort() {
  short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned short readUShort() {
  unsigned short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
float readFL() {
  float a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    float p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
double readDB() {
  double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
long double readLDB() {
  long double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    long double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
inline void wt(long long first) { printf("%lld", first); }
inline void wtl(long long first) { printf("%lld\n", first); }
inline void wtb(long long first) { printf("%lld ", first); }
long long qmi(long long a, long long k, long long p) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
long long mo(long long first, long long p) { return ((first % p) + p) % p; }
const long long N = 2e5 + 7;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
vector<long long> mp[N], G[N];
long long father[N];
void dfs1(long long u, long long fa) {
  for (long long i = 0; i < mp[u].size(); i++) {
    long long j = mp[u][i];
    if (j == fa) continue;
    G[u].push_back(j);
    father[j] = u;
    dfs1(j, u);
  }
}
signed main() {
  long long T;
  iocin >> T;
  while (T--) {
    long long n;
    iocin >> n;
    memset(father, 0, sizeof father);
    for (long long i = 1; i <= n; i++) {
      mp[i].clear();
      G[i].clear();
    }
    for (long long i = 1; i <= n - 1; i++) {
      long long a, b;
      iocin >> a >> b;
      mp[a].push_back(b);
      mp[b].push_back(a);
    }
    dfs1(1, -1);
    map<long long, long long> fa;
    vector<long long> t;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      if (G[i].size() == 0) {
        fa[father[i]]++;
        ans++;
        if (fa[father[i]] == 1) t.push_back(father[i]);
      }
    }
    wtl(ans - t.size() + 1);
  }
  return 0;
}
