#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long modInverse(long long a, long long m) {
  long long g = gcd(a, m);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    return power(a, m - 2, m);
  }
}
long long log_a_b(long long a, long long b) {
  return (a > b - 1) ? 1 + log_a_b(a / b, b) : 0;
}
int t;
vector<vector<long long> > graph;
vector<long long> tin, tout;
vector<bool> vis;
vector<vector<long long> > up;
void dfs(int v, int p, int l) {
  vis[v] = true;
  tin[v] = ++t;
  up[v][0] = p;
  for (int(i) = (1); (i) < (l + 1); (i)++) {
    up[v][i] = up[v][i - 1] < 0 ? -1 : up[up[v][i - 1]][i - 1];
  }
  for (int x : graph[v])
    if (!vis[x]) dfs(x, v, l);
  tout[v] = ++t;
}
bool isan(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v, int l) {
  if (isan(u, v)) return u;
  if (isan(v, u)) return v;
  for (int(i) = (l); (i) >= (0); (i)--) {
    if (up[u][i] == -1) continue;
    if (!isan(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
bool sum(long long n, long long i, long long s, long long cnt,
         vector<long long> &a) {
  if (i >= n && cnt > 0) {
    if (s != 0)
      return 0;
    else
      return 1;
  }
  if (i >= n && cnt == 0) return 0;
  bool a1 = sum(n, i + 1, s, cnt, a);
  bool b = sum(n, i + 1, s - a[i], cnt + 1, a);
  bool c = sum(n, i + 1, s + a[i], cnt + 1, a);
  bool d = (a1 | b | c);
  return d;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(15);
  long long T;
  cin >> T;
  while (T--) {
    long long n, q, k, m, u, v, w, x;
    string s, t;
    cin >> n >> m;
    long long ans = 0;
    m++;
    vector<long long> a(31), b(31);
    for (int(i) = (0); (i) < (31); (i)++) {
      a[i] = n % 2;
      b[i] = m % 2;
      n /= 2;
      m /= 2;
    }
    reverse((a).begin(), (a).end());
    reverse((b).begin(), (b).end());
    for (int(i) = (0); (i) < (31); (i)++) {
      if (a[i] && !b[i]) break;
      if (!a[i] && b[i]) ans = ans | (1 << (30 - i));
    }
    cout << ans << "\n";
  }
  return 0;
}
