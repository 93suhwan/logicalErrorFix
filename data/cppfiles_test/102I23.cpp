#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long Mod = 998244353;
const long long M = 100;
long long k, A, h, n, p[M], ans[M];
map<long long, vector<long long> > v1[M];
long long poww(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % Mod;
    a = a * a % Mod, b >>= 1;
  }
  return res;
}
signed main() {
  k = read(), A = read(), h = read();
  n = (1 << k);
  if (k == 2) p[1] = 3;
  if (k == 3) p[1] = p[2] = 5, p[3] = 3;
  if (k == 4) p[1] = p[2] = p[3] = p[4] = 9, p[5] = p[6] = 5, p[7] = 3;
  if (k == 5)
    p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = p[8] = 17,
    p[9] = p[10] = p[11] = p[12] = 9, p[13] = p[14] = 5, p[15] = 3;
  for (long long i = 0; i < (1 << (n / 2) - 1); i++) {
    queue<long long> q;
    vector<long long> v;
    for (long long j = 1; j <= n / 2; j++) q.push(j);
    for (long long j = 0; j < n / 2 - 1; j++) {
      long long u1 = q.front();
      q.pop();
      long long u2 = q.front();
      q.pop();
      long long first = i & (1 << j);
      if (first)
        v.push_back(u2), q.push(u1);
      else
        v.push_back(u1), q.push(u2);
    }
    long long Win = q.front(), Hash = 0;
    for (long long i = 0; i < v.size(); i++)
      Hash = (Hash + v[i] * poww(A, p[i + 1])) % Mod;
    v1[Win][Hash] = v;
  }
  for (long long i = 0; i < (1 << (n / 2) - 1); i++) {
    queue<long long> q;
    vector<long long> v;
    for (long long j = n / 2 + 1; j <= n; j++) q.push(j);
    for (long long j = 0; j < n / 2 - 1; j++) {
      long long u1 = q.front();
      q.pop();
      long long u2 = q.front();
      q.pop();
      long long first = i & (1 << j);
      if (first)
        v.push_back(u2), q.push(u1);
      else
        v.push_back(u1), q.push(u2);
    }
    long long Win = q.front(), Hash = 0;
    for (long long i = 0; i < v.size(); i++)
      Hash = (Hash + v[i] * poww(A, p[i + 1])) % Mod;
    for (long long j = 1; j <= n / 2; j++) {
      long long x1 = (h - Hash - j * A - Win * A % Mod * A) % Mod;
      x1 = (x1 + Mod) % Mod;
      if (v1[j][x1].size() != 0) {
        for (long long k = 0; k < v1[j][x1].size(); k++)
          ans[v1[j][x1][k]] = p[k + 1];
        for (long long k = 0; k < v.size(); k++) ans[v[k]] = p[k + 1];
        ans[j] = 1, ans[Win] = 2;
        for (long long k = 1; k <= n; k++) cout << ans[k] << ' ';
        return 0;
      }
      long long x2 = (h - Hash - Win * A - j * A % Mod * A) % Mod;
      x2 = (x2 + Mod) % Mod;
      if (v1[j][x2].size() != 0) {
        for (long long k = 0; k < v1[j][x2].size(); k++)
          ans[v1[j][x2][k]] = p[k + 1];
        for (long long k = 0; k < v.size(); k++) ans[v[k]] = p[k + 1];
        ans[j] = 2, ans[Win] = 1;
        for (long long k = 1; k <= n; k++) cout << ans[k] << ' ';
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}
