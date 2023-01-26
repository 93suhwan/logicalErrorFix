#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x = x * f;
}
int n, m;
int c[12], d[12][200020];
int s[12], s1, s2, s3, bas1, bas2;
int mod1 = 100111001, mod2 = 100050001;
struct Data {
  int v;
  int x[12];
};
bool operator==(Data a, Data b) { return a.v == b.v; }
bool operator!=(Data a, Data b) { return a.v != b.v; }
bool operator>(Data a, Data b) { return a.v > b.v; }
bool operator<(Data a, Data b) { return a.v < b.v; }
bool operator>=(Data a, Data b) { return ((a.v > b.v) or (a.v == b.v)); }
bool operator<=(Data a, Data b) { return ((a.v < b.v) or (a.v == b.v)); }
int qpow(int m, int p, int mod) {
  int res = 1;
  while (p) {
    if (p % 2 == 1) res = res * m % mod;
    m = m * m % mod;
    p /= 2;
  }
  return res;
}
priority_queue<Data> q;
map<pair<int, int>, bool> mp, sv;
pair<int, int> check(Data cur) {
  s2 = s3 = 0;
  for (int i = 1; i <= n; i++) {
    s2 = (s2 + cur.x[i] * qpow(bas1, i, mod1)) % mod1;
    s3 = (s3 + cur.x[i] * qpow(bas2, i, mod2)) % mod2;
  }
  return make_pair(s2, s3);
}
int sum = 0;
signed main() {
  srand(time(0));
  bas1 = rand() + 1, bas2 = rand() + 1;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(c[i]);
    for (int j = 1; j <= c[i]; j++) read(d[i][j]);
    s[i] = c[i];
    sum += d[i][c[i]];
    d[i][0] = 1e9;
  }
  read(m);
  for (int i = 1; i <= m; i++) {
    s2 = s3 = 0;
    for (int j = 1; j <= n; j++) {
      read(s1);
      s2 = (s2 + s1 * qpow(bas1, j, mod1)) % mod1;
      s3 = (s3 + s1 * qpow(bas2, j, mod2)) % mod2;
    }
    mp[make_pair(s2, s3)] = 1;
  }
  Data sav;
  sav.v = sum;
  for (int i = 1; i <= n; i++) sav.x[i] = c[i];
  q.push(sav);
  while (mp[check(q.top())]) {
    Data cur = q.top();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (cur.x[i] == 1) continue;
      cur.v = cur.v - d[i][cur.x[i]] + d[i][cur.x[i] - 1];
      cur.x[i]--;
      if (!sv[check(cur)]) sv[check(cur)] = 1, q.push(cur);
      cur.x[i]++;
      cur.v = cur.v + d[i][cur.x[i]] - d[i][cur.x[i] - 1];
    }
  }
  for (int i = 1; i <= n; i++) cout << q.top().x[i] << ' ';
  return 0;
}
