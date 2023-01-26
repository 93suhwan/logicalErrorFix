#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool b[(312345)] = {};
int dep[(312345)] = {};
vector<int> e[(312345)], e2[(312345)];
int ffa[(312345)] = {};
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  b[x] = 1;
  ffa[x] = fa;
  for (int v : e[x])
    if (!b[v]) {
      e2[x].push_back(v);
      e2[v].push_back(x);
      dfs(v, x);
    }
}
int u[(312345)], v[(312345)], c[(312345)] = {};
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read();
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1, 0);
  int q = read();
  for (int i = 1; i <= q; i++) {
    u[i] = read(), v[i] = read();
    c[u[i]]++;
    c[v[i]]++;
  }
  int p = 0;
  for (int i = 1; i <= n; i++) p += c[i] & 1;
  if (p) {
    puts("NO");
    cout << p / 2 << endl;
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= q; i++) {
    int l = u[i], r = v[i];
    vector<int> v1, v2;
    while (dep[l] > dep[r]) v1.push_back(l), l = ffa[l];
    while (dep[l] < dep[r]) v2.push_back(r), r = ffa[r];
    while (l != r) {
      v1.push_back(l), l = ffa[l];
      v2.push_back(r), r = ffa[r];
    }
    v1.push_back(l);
    cout << ((v1).size()) + ((v2).size()) << endl;
    for (int i : v1) cout << i << ' ';
    reverse((v2).begin(), (v2).end());
    for (int i : v2) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
