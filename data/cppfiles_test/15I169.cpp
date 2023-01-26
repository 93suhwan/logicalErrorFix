#include <bits/stdc++.h>
using namespace std;
long long MulModL(long long B, long long P, long long M) {
  long long R = 0;
  while (P > 0) {
    if ((P & 1ll) == 1) {
      R = (R + B);
      if (R >= M) R -= M;
    }
    P >>= 1ll;
    B = (B + B);
    if (B >= M) B -= M;
  }
  return R;
}
long long MulModD(long long B, long long P, long long M) {
  long long I = ((long double)B * (long double)P / (long double)M);
  long long R = B * P - M * I;
  R = (R % M + M) % M;
  return R;
}
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
long long BigModML(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = MulModL(R, B, M);
    }
    P /= 2;
    B = MulModL(B, B, M);
  }
  return R;
}
template <class T1>
void deb(T1 e1) {
  cerr << e1 << "\n";
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cerr << e1 << " " << e2 << "\n";
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cerr << e1 << " " << e2 << " " << e3 << "\n";
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6, T7 e7) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << " " << e7 << "\n";
}
template <class T1>
void output(T1 e1) {
  cout << e1 << "\n";
}
template <class T1, class T2>
void output(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << "\n";
}
template <class T1, class T2, class T3>
void output(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << "\n";
}
template <class T1, class T2, class T3, class T4>
void output(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5>
void output(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void output(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
void output(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6, T7 e7) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << " " << e7 << "\n";
}
template <class T>
T GCD(T a, T b) {
  T b1;
  while (b > 0) {
    b1 = b;
    b = a % b;
    a = b1;
  }
  return a;
}
template <class T>
T LCM(T a, T b) {
  return (a * b) / GCD(a, b);
}
const int MOD = 1000000007;
const int MAX = 105;
vector<vector<int> > g;
vector<vector<int> > dp;
vector<int> parent;
int nCr[MAX][MAX];
void precal() {
  nCr[0][0] = 1;
  for (int i = 0; i < int(MAX); i++) nCr[i][0] = nCr[i][i] = 1;
  for (int i = 1; i < MAX; i++) {
    for (int j = 1; j < i; j++) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
      if (nCr[i][j] >= MOD) nCr[i][j] -= MOD;
    }
  }
  return;
}
int dfs(int u, int p, int d) {
  if (u < 0 || d < 0) return 0;
  if (d == 0) return 1;
  parent[u] = p;
  int& ret = dp[u][d];
  if (ret != -1) return ret;
  ret = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    ret += dfs(v, u, d - 1);
  }
  return ret;
}
int getKDistanceVertices(int u, int k) {
  int p = parent[u];
  return dfs(u, p, k) +
         (p == -1 ? 0 : dfs(p, parent[p], k - 1) - dfs(u, p, k - 2));
}
int waysToChooseKVerticesOfDistanceD(int u, int d, int K) {
  int n = getKDistanceVertices(u, d);
  if (n < K) return 0;
  return nCr[n][K];
}
int solve(int n, int k) {
  if (k == 2) return nCr[n][k];
  int ret = 0;
  for (int i = 0; i < int(n); i++) dfs(0, -1, i);
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(n); j++) {
      ret += waysToChooseKVerticesOfDistanceD(i, j, k);
      if (ret >= MOD) ret -= MOD;
    }
  }
  return ret;
}
int main(int argc, const char* argv[]) {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  precal();
  int t, n, k, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    g = vector<vector<int> >(n);
    dp = vector<vector<int> >(n, vector<int>(n, -1));
    parent.resize(n);
    for (int i = 0; i < int(n - 1); i++) {
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    output(solve(n, k));
  }
}
