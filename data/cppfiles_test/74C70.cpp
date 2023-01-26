#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double eps = 1e-6;
struct inout {
  static const int ibufl = 1 << 25;
  char in_buf[ibufl + 5], out_buf[ibufl + 5], *inf, *ouf;
  void init() {
    fread(in_buf, 1, ibufl, stdin);
    inf = in_buf;
    ouf = out_buf;
  }
  inout& operator>>(int& a) {
    int fh = 1;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    a *= fh;
    return *this;
  }
  inout& operator>>(char& a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    a = *inf;
    ++inf;
    return *this;
  }
  inout& operator>>(char* a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    while (!(*inf == ' ' || *inf == '\n')) {
      *a = *inf;
      ++inf;
      ++a;
    }
    *a = '\0';
    return *this;
  }
  inout& operator>>(double& a) {
    int fh = 1;
    double s;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    if (*inf == '.') {
      s = 0.1;
      ++inf;
      while (isdigit(*inf)) {
        a += s * (*inf - '0');
        ++inf;
        s *= 0.1;
      }
    }
    a *= fh;
    return *this;
  }
  void writeint(int x) {
    if (x / 10) writeint(x / 10);
    *ouf = x % 10 + '0';
    ++ouf;
  }
  inout& operator<<(int a) {
    if (a < 0) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint(a);
    return *this;
  }
  static const int sz = 2;
  inout& operator<<(char a) {
    *ouf = a;
    ++ouf;
    return *this;
  }
  inout& operator<<(char* a) {
    while (*a) {
      *ouf = *a;
      ++ouf;
      ++a;
    }
    return *this;
  }
  inout& operator<<(double a) {
    if (a < -eps) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint((int)a);
    a -= (int)a;
    *ouf = '.';
    ++ouf;
    for (int i = 1; i <= sz; i++) {
      a = a * 10;
      *ouf = (int)a + '0';
      ++ouf;
      a -= (int)a;
    }
    return *this;
  }
  void out() { fwrite(out_buf, 1, ouf - out_buf, stdout); }
};
inout io;
int n;
int b[1005], a[1005];
int lst[30000000], num[30];
int sum1[1 << 14], sum2[1 << 14];
bool vis[1005];
int ans[1005];
signed main() {
  io.init();
  io >> n;
  int it = 0;
  for (int i = 1; i <= n; i++) {
    io >> b[i];
    if (!(b[i] & 1)) {
      it = i;
    }
  }
  if (n == 2) {
    if (b[1] == b[2]) {
      io << "YES\n";
      io << 0 << ' ' << b[1];
    } else {
      io << "NO";
    }
    io.out();
    return 0;
  }
  if (it) {
    if (n == 3 && ((b[1] ^ b[2] ^ b[3]) & 1)) {
      io << "NO\n";
    } else {
      int it1 = 0, it2 = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
          if (i != it && j != it) {
            if ((b[i] & 1) == (b[j] & 1)) {
              it1 = i;
              it2 = j;
            }
          }
      }
      int tn = 0;
      int t1 = b[it1] + b[it2] + b[it];
      t1 /= 2;
      ans[++tn] = t1 - b[it1];
      ans[++tn] = t1 - b[it2];
      ans[++tn] = t1 - b[it];
      for (int i = 1; i <= n; i++)
        if (i != it1 && i != it2 && i != it) {
          ans[++tn] = b[i] - ans[1];
        }
      io << "YES\n";
      for (int i = 1; i <= n; i++) io << ans[i] << ' ';
    }
    io.out();
    return 0;
  }
  int len = min(n, 22);
  for (int i = 1; i <= len; i++) {
    num[i - 1] = b[i];
  }
  int mid = len / 2;
  for (int i = 1; i < 1 << mid; i++) {
    for (int j = 0; j < mid; j++)
      if (i & (1 << j)) {
        sum1[i] += num[j];
      }
  }
  for (int i = 1; i < 1 << (len - mid); i++) {
    for (int j = 0; j < len - mid; j++)
      if (i & (1 << j)) {
        sum2[i] += num[j + mid];
      }
  }
  int msk1 = -1, msk2 = -1;
  for (int i = 1; i < 1 << len; i++)
    if (__builtin_popcount(i) == mid) {
      int sum = sum1[i & ((1 << mid) - 1)] + sum2[i >> mid];
      if (lst[sum]) {
        int t = i & lst[sum];
        msk1 = i ^ t;
        msk2 = lst[sum] ^ t;
        break;
      }
      lst[sum] = i;
    }
  if (msk1 == -1) {
    io << "NO";
    io.out();
    return 0;
  }
  int tn = 0, l = __builtin_popcount(msk1);
  vector<int> v;
  for (int j = 0; j < len; j++) {
    if (msk1 & (1 << j)) v.emplace_back(j + 1);
  }
  vector<int> v2;
  for (int j = 0; j < len; j++) {
    if (msk2 & (1 << j)) v2.emplace_back(j + 1);
  }
  vector<int> tv;
  for (int i = 0; i < l; i++) {
    tv.emplace_back(v[i]);
    tv.emplace_back(v2[i]);
    vis[v[i]] = vis[v2[i]] = 1;
  }
  ans[++tn] = 0;
  for (int i = 0; i < tv.size() - 1; i++) {
    ans[++tn] = b[tv[i]] - ans[tn];
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ans[++tn] = b[i] - ans[1];
  io << "YES\n";
  for (int i = 1; i <= n; i++) io << ans[i] << ' ';
  io.out();
  return 0;
}
