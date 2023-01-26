#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const double eps = 1e-5;
map<string, int> id;
vector<long long> cn[N];
vector<long long> num;
vector<int> np[N];
int qcol[N];
int col[N];
long long dp[N][10];
bool vis[N];
inline long long qpow(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
int getid(long long x) {
  return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}
void cal(int p, int fa, int c) {
  vector<int> son;
  for (int nt : np[p]) {
    if (nt == fa) continue;
    son.push_back(nt);
  }
  if (son.size() == 0) {
    dp[p][c] = 1;
  } else if (son.size() == 1) {
    int u = son.front();
    for (int i = 2; i <= 7; i++) {
      if (c == i || c == (i ^ 1)) continue;
      dp[p][c] += dp[u][i];
      dp[p][c] %= M;
    }
  } else {
    int u = son.front(), v = son.back();
    for (int i = 2; i <= 7; i++) {
      for (int j = 2; j <= 7; j++) {
        if (c == i || c == (i ^ 1)) continue;
        if (c == j || c == (j ^ 1)) continue;
        dp[p][c] += dp[u][i] * dp[v][j] % M;
        dp[p][c] %= M;
      }
    }
  }
}
void dfs(int p, int fa) {
  for (int nt : np[p]) {
    if (nt == fa) continue;
    dfs(nt, p);
  }
  if (col[p]) {
    cal(p, fa, col[p]);
  } else {
    for (int i = 2; i <= 7; i++) {
      cal(p, fa, i);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  id["white"] = 2;
  id["yellow"] = 3;
  id["green"] = 4;
  id["blue"] = 5;
  id["red"] = 6;
  id["orange"] = 7;
  int k, n;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    long long v;
    string c;
    cin >> v >> c;
    while (v) {
      num.push_back(v);
      cn[i].push_back(v);
      v >>= 1;
    }
    qcol[i] = id[c];
  }
  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  for (int i = 1; i <= n; i++) {
    int u = getid(cn[i].front());
    col[u] = qcol[i];
    for (int j = 1; j < cn[i].size(); j++) {
      int v = getid(cn[i][j]);
      np[u].push_back(v);
      np[v].push_back(u);
      u = v;
    }
  }
  for (int i = 1; i <= num.size(); i++) {
    sort(np[i].begin(), np[i].end());
    np[i].erase(unique(np[i].begin(), np[i].end()), np[i].end());
  }
  dfs(1, 0);
  long long ans = 1;
  long long ret = ((1ll << k) - 1) - num.size();
  long long res = 0;
  for (int i = 2; i <= 7; i++) res = (res + dp[1][i]) % M;
  ans = qpow(4, ret % (M - 1), M) * res % M;
  cout << ans << '\n';
}
