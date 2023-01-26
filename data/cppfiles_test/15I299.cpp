#include <bits/stdc++.h>
using namespace std;
const long dx[4] = {1, 0, -1, 0}, dz[4] = {0, 1, 0, -1};
const long double pi = 3.14159265359;
const long long mod = 1e9 + 7;
long long p(long long x) {
  while (x & (x - 1)) {
    x = x & (x - 1);
  }
  return x;
}
template <class T>
void re(T& x) {
  cin >> x;
}
template <class T1, class T2>
void re(pair<T1, T2>& x) {
  re(x.first);
  re(x.second);
}
template <class T>
void re(vector<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T>
void re(deque<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T>
void out(T x) {
  cout << x << " ";
}
template <class T1, class T2>
void out(pair<T1, T2> x) {
  out(x.first);
  out(x.second);
  cout << "\n";
}
template <class T>
void out(vector<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << "\n";
}
template <class T>
void out(deque<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << "\n";
}
template <class T>
T cross(complex<T> x, complex<T> z) {
  return (conj(x) * z).imag();
}
template <class T>
T dot(complex<T> x, complex<T> z) {
  return (conj(x) * z).real();
}
vector<vector<long long> > edges, ways;
vector<vector<vector<vector<long long> > > > dp;
vector<vector<vector<vector<bool> > > > ok;
vector<long> depth, parent;
long n, k;
void scan(long x, long p) {
  parent[x] = p;
  depth[x] = depth[p] + 1;
  ways[x][0] = 1;
  for (long long i = (0); i < (edges[x].size()); i++) {
    if (edges[x][i] == p) {
      continue;
    }
    scan(edges[x][i], x);
    for (long long j = (1); j < (k); j++) {
      ways[x][j] += ways[edges[x][i]][j - 1];
      ways[x][j] %= mod;
    }
  }
}
long long solve(long x, long z, long c, long d) {
  if (c == 0) {
    return 1;
  }
  if (c > z + 1) {
    return 0;
  }
  if (x == 0 || z < 0) {
    return 0;
  }
  if (ok[x][z][c][d]) {
    return dp[x][z][c][d];
  }
  ok[x][z][c][d] = true;
  dp[x][z][c][d] = solve(x, z - 1, c, d);
  if (edges[x][z] != parent[x]) {
    dp[x][z][c][d] += (ways[edges[x][z]][d - 1] * solve(x, z - 1, c - 1, d));
    dp[x][z][c][d] %= mod;
  }
  return dp[x][z][c][d];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, x, z, ans, d, son;
  cin >> t;
  for (long long i = (0); i < (t); i++) {
    ans = 0;
    cin >> n >> k;
    edges.clear();
    edges.resize(n + 1);
    ways.clear();
    ways.resize(n + 1);
    for (long long j = (0); j < (n + 1); j++) {
      ways[j].resize(n + 1);
    }
    dp.clear();
    dp.resize(n + 1);
    ok.clear();
    ok.resize(n + 1);
    for (long long j = (0); j < (n + 1); j++) {
      dp[j].resize(n + 1);
      ok[j].resize(n + 1);
      for (long long l = (0); l < (n + 1); l++) {
        dp[j][l].resize(n + 1);
        ok[j][l].resize(n + 1);
        for (long long r = (0); r < (n + 1); r++) {
          dp[j][l][r].resize(n + 1);
          ok[j][l][r].resize(n + 1);
        }
      }
    }
    depth.clear();
    depth.resize(n + 1);
    parent.clear();
    parent.resize(n + 1);
    depth[0] = -1;
    for (long long j = (0); j < (n - 1); j++) {
      cin >> x >> z;
      edges[x].push_back(z);
      edges[z].push_back(x);
    }
    if (k == 2) {
      cout << (n * (n - 1)) / 2 << "\n";
      continue;
    }
    scan(1, 0);
    for (long long j = (1); j < (n + 1); j++) {
      for (long long l = (1); l < (n); l++) {
        ans += solve(j, edges[j].size() - 1, k, l);
        ans %= mod;
        x = parent[j];
        son = j;
        d = 1;
        z = solve(j, edges[j].size() - 1, k - 1, l);
        while (x != 0) {
          if (l - d == 0) {
            ans += z * ways[x][l - d];
            ans %= mod;
          } else {
            ans += z * (ways[x][l - d] - ways[son][l - d - 1]);
            ans %= mod;
          }
          son = x;
          x = parent[x];
          d++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
