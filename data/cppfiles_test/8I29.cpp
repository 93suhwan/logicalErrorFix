#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long inf = pow(10, 18);
long long modulo = pow(10, 9) + 7;
long long valn[100100];
long long val[100100];
long long dp[100100];
vector<long long> sorted[100100];
vector<long long> g[100100];
long long lca[100100][20];
long long dep[100100];
long long tin[100100];
long long tout[100100];
long long calcval(long long a, long long b) {
  return max(abs(a + b), abs(a - b));
}
void dfslca(long long hd, long long pr, long long& tim) {
  lca[hd][0] = pr;
  tin[hd] = tim;
  for (auto hr : g[hd]) {
    if (hr == pr) continue;
    dep[hr] = dep[hd] + 1;
    ++tim;
    sorted[hd].push_back(hr);
    dfslca(hr, hd, tim);
  }
  tout[hd] = tim;
}
void pre(long long n) {
  for (long long j = 1; j < 20; j++)
    for (long long i = 0; i < n; i++) lca[i][j] = lca[lca[i][j - 1]][j - 1];
}
long long LCA(long long a, long long b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (long long j = 20 - 1; j > -1; j--)
    if (dep[lca[a][j]] > dep[b]) a = lca[a][j];
  if (dep[a] != dep[b]) a = lca[a][0];
  for (long long j = 20 - 1; j > -1; j--)
    if (lca[a][j] != lca[b][j]) a = lca[a][j], b = lca[b][j];
  if (a != b) a = lca[a][0], b = lca[b][0];
  return a;
}
void calcdp(long long hd, long long pr) {
  for (auto& hr : g[hd]) {
    if (hr == pr) {
      continue;
    }
    dp[hr] = dp[hd] + calcval(val[hd], val[hr]);
    calcdp(hr, hd);
  }
}
bool isp(long long pr, long long hd) {
  return tin[pr] <= tin[hd] && tout[hd] <= tout[pr];
}
long long findChild(long long pr, long long hd) {
  long long lo = 0, hi = (long long)sorted[pr].size() - 1;
  while (lo < hi) {
    long long mid = (lo + hi) / 2 + 1;
    long long hr = sorted[pr][mid];
    if (tin[hr] > tin[hd]) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return sorted[pr][lo];
}
void deal() {
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> val[i];
    valn[i] = val[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    long long ai, bi;
    cin >> ai >> bi;
    --ai, --bi;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }
  {
    long long tim = 1;
    dfslca(0, 0, tim);
    calcdp(0, 0);
  }
  map<long long, long long> dif;
  for (long long l = 0; l < q; l++) {
    long long ty;
    cin >> ty;
    if (ty == 1) {
      long long u, c;
      cin >> u >> c;
      --u;
      dif[u] = c;
      valn[u] = c;
    } else {
      long long u, v;
      cin >> u >> v;
      --u, --v;
      long long lc = LCA(u, v);
      long long ans = dp[u] + dp[v] - 2 * dp[lc];
      set<pair<long long, long long> > again;
      for (auto& el : dif) {
        long long pr = el.first;
        long long p1 = isp(pr, u);
        long long p2 = isp(pr, v);
        if (p1 && (!p2 || pr == lc) && pr != u) {
          long long a = pr;
          long long b = findChild(pr, u);
          if (b < a) {
            swap(a, b);
          }
          again.insert(make_pair(a, b));
        }
        if (p2 && (!p1 || pr == lc) && pr != v) {
          long long a = pr;
          long long b = findChild(pr, v);
          if (b < a) {
            swap(a, b);
          }
          again.insert(make_pair(a, b));
        }
        if (lca[pr][0] != pr && ((p1 ^ p2) || lca[pr][0] == lc)) {
          long long a = pr;
          long long b = lca[pr][0];
          if (b < a) {
            swap(a, b);
          }
          again.insert(make_pair(a, b));
        }
      }
      for (auto& el : again) {
        ans -= calcval(val[el.first], val[el.second]);
        ans += calcval(valn[el.first], valn[el.second]);
      }
      cout << ans << '\n';
    }
    if (dif.size() > 100) {
      for (long long i = 0; i < n; i++) {
        val[i] = valn[i];
      }
      calcdp(0, 0);
      dif.clear();
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  deal();
}
