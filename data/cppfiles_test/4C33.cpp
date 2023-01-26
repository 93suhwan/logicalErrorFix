#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long INFll = 4e18;
const long long INFi = 1e9 + 63;
const double pi = acos(-1);
const int maxn = 6e5;
const int maxd = 16;
const long long mod = 1e9 + 7;
const int sqrtN = 300;
int caseNo = 1;
void E() {}
template <class A, class... B>
void E(A $, B... _) {
  cerr << ' ' << $;
  E(_...);
}
const int mask = 1 << 5;
int val[maxn];
int del[maxn];
int sz[maxn];
vector<pair<int, int>> g[maxn];
void dfs(int v, int p) {
  sz[v] = 1;
  for (auto& it : g[v]) {
    if (it.first == p || del[it.first]) continue;
    dfs(it.first, v);
    sz[v] += sz[it.first];
  }
}
int findCentroid(int v, int sz0, int p) {
  int mx = -1;
  for (auto& it : g[v]) {
    if (it.first == p || del[it.first]) continue;
    if (sz[it.first] > sz0 / 2 && (mx == -1 || sz[it.first] > sz[mx]))
      mx = it.first;
  }
  if (mx == -1)
    return v;
  else
    return findCentroid(mx, sz0, v);
}
void dfsCentr2(vector<long long>& res, vector<long long>& resPCnts, int v,
               int prevC, int p, int d, long long acc) {
  if (((int)(res).size()) <= d) {
    res.resize(d + 1, 0);
  }
  if (((int)(resPCnts).size()) <= d) {
    resPCnts.resize(d + 1, 0);
  }
  acc += val[v];
  acc %= mod;
  res[d] += acc;
  resPCnts[d]++;
  resPCnts[d] %= mod;
  for (auto& it : g[v]) {
    if (it.first == p || del[it.first]) continue;
    dfsCentr2(res, resPCnts, it.first, it.second, v,
              d + ((prevC != it.second) ? 1 : 0), acc);
  }
}
int k;
long long mul(int v, const vector<vector<long long>>& cntsA,
              const vector<vector<long long>>& cntsA2,
              const vector<vector<long long>>& cntsB,
              const vector<vector<long long>>& cntsB2) {
  vector<vector<long long>> cntsB2Sum = cntsB2;
  vector<vector<long long>> cntsBSum = cntsB;
  long long res = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < ((int)(cntsB2[i]).size()); j++) {
      cntsB2Sum[i][j] += cntsB2Sum[i][j - 1];
      cntsB2Sum[i][j] %= mod;
    }
    for (int j = 1; j < ((int)(cntsB[i]).size()); j++) {
      cntsBSum[i][j] += cntsBSum[i][j - 1];
      cntsBSum[i][j] %= mod;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int extraLen = i == j ? 0 : 1;
      for (int it = 0; it <= min(((int)(cntsA[i]).size()) - 1, k); it++) {
        int remCnt = k - it - extraLen;
        if (remCnt < 0) break;
        if (remCnt >= ((int)(cntsB[j]).size()))
          remCnt = ((int)(cntsB[j]).size()) - 1;
        if (remCnt < 0) continue;
        assert(it < ((int)(cntsA[i]).size()) && it >= 0);
        assert(remCnt < ((int)(cntsB[j]).size()) && remCnt >= 0);
        res += (cntsA[i][it] * cntsB2Sum[j][remCnt]) % mod;
        res %= mod;
        res += (cntsBSum[j][remCnt] * cntsA2[i][it]) % mod;
        res %= mod;
        res -= (val[v] * (cntsA2[i][it] * cntsB2Sum[j][remCnt] % mod)) % mod;
        res %= mod;
        if (res < 0) res += mod;
      }
    }
  }
  return res;
}
long long res = 0;
void dfsCentr(int v) {
  dfs(v, -1);
  int c = findCentroid(v, sz[v], -1);
  del[c] = true;
  vector<vector<long long>> acc(2);
  vector<vector<long long>> accPCnts(2);
  long long localRes = val[c];
  for (auto& it : g[c]) {
    if (del[it.first]) continue;
    vector<vector<long long>> tmp(2), tmpPCnts(2);
    dfsCentr2(tmp[it.second], tmpPCnts[it.second], it.first, it.second, c, 0,
              val[c]);
    for (int i = 0; i <= min(((int)(tmp[it.second]).size()) - 1, k); i++) {
      localRes += tmp[it.second][i];
      localRes %= mod;
    }
    localRes += mul(c, acc, accPCnts, tmp, tmpPCnts);
    localRes %= mod;
    for (int j = 0; j < 2; j++) {
      if (((int)(tmp[j]).size()) > ((int)(acc[j]).size())) tmp[j].swap(acc[j]);
      if (((int)(tmpPCnts[j]).size()) > ((int)(accPCnts[j]).size()))
        tmpPCnts[j].swap(accPCnts[j]);
      for (int i = 0; i < ((int)(tmp[j]).size()); i++) {
        acc[j][i] += tmp[j][i];
        acc[j][i] %= mod;
      }
      for (int i = 0; i < ((int)(tmpPCnts[j]).size()); i++) {
        accPCnts[j][i] += tmpPCnts[j][i];
        accPCnts[j][i] %= mod;
      }
    }
  }
  res += localRes;
  res %= mod;
  del[c] = true;
  for (auto& it : g[c]) {
    if (del[it.first]) continue;
    dfsCentr(it.first);
  }
}
int solveMy() {
  res = 0;
  dfsCentr(0);
  return res;
}
void solve() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    g[u].push_back({v, t});
    g[v].push_back({u, t});
  }
  cout << solveMy();
}
int main(int argc, char** argv) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  int t = 1;
  clock_t start = clock();
  for (int i = 0; i < t; i++) solve();
  return 0;
}
