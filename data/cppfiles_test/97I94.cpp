#include <bits/stdc++.h>
using namespace std;
const int K = 1000;
const int KK = 25;
vector<int> v[200005];
struct qry {
  int nod, k, pz, rz;
} qs[200005];
vector<int> qsk[5005];
int dpc[200005];
void dfsdpc(int nod, int t, int k) {
  dpc[nod] = 0;
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] == t) continue;
    dfsdpc(v[nod][i], nod, k);
    dpc[nod] = dpc[nod] + max(1, dpc[v[nod][i]] - k);
  }
}
int dp[200005][KK + 2];
int aux[100];
void join(int a, int b) {
  int i, j;
  for (i = 0; i <= KK; ++i) {
    aux[i] = dp[a][i] + 1;
    for (j = 0; j < i; ++j) aux[i] = max(aux[i], dp[a][i - j - 1] + dp[b][j]);
  }
  for (i = 0; i <= KK; ++i) dp[a][i] = aux[i];
}
void dfs(int nod, int t) {
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] == t) continue;
    dfs(v[nod][i], nod);
    join(nod, v[nod][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long m, q, t, s = 0, n, d, j, i, k;
  cin >> n;
  for (i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  cin >> q;
  for (i = 1; i <= q; ++i) {
    cin >> qs[i].nod >> qs[i].k;
    qs[i].pz = i;
    if (qs[i].k <= 200000 / K + 1) qsk[qs[i].k].push_back(i);
  }
  for (i = 0; i <= 200000 / K + 1; ++i) {
    if (qsk[i].size() == 0) continue;
    dfsdpc(1, -1, i);
    for (j = 0; j < qsk[i].size(); ++j)
      qs[qsk[i][j]].rz = dpc[qs[qsk[i][j]].nod];
  }
  dfs(1, -1);
  for (i = 1; i <= q; ++i) {
    if (qs[i].k <= 200000 / K + 1) {
      cout << qs[i].rz << '\n';
      continue;
    }
    for (int cat = 0; cat <= KK; ++cat)
      qs[i].rz = max(qs[i].rz, dp[qs[i].nod][cat] - cat * qs[i].k);
    cout << qs[i].rz << '\n';
  }
  return 0;
}
