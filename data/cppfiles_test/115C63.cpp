#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
struct query {
  int64_t x, y, t, i;
};
const int64_t MAXN = 1e6 + 5, mod = 998244353;
int64_t Pow[MAXN];
vector<int64_t> solve(int64_t n, int64_t m, int64_t k, vector<query> z) {
  map<pair<int64_t, int64_t>, int> a;
  vector<int64_t> ans(k, -1);
  vector<vector<int64_t>> cnt(2, vector<int64_t>(n));
  int64_t sum = n, bad = 0, bylo, stalo;
  for (auto [x, y, t, i] : z) {
    if (a.find({x, y}) == a.end()) a[{x, y}] = -1;
    if (cnt[0][x] && cnt[1][x]) bad--;
    bylo = cnt[0][x] + cnt[1][x];
    int& aid = a[{x, y}];
    if (aid != -1) cnt[aid ^ (y & 1)][x]--;
    aid = t;
    if (t != -1) cnt[t ^ (y & 1)][x]++;
    if (cnt[0][x] && cnt[1][x]) bad++;
    stalo = cnt[0][x] + cnt[1][x];
    if (bylo == 0 && stalo == 1)
      sum--;
    else if (bylo == 1 && stalo == 0)
      sum++;
    if (bad)
      ans[i] = 0;
    else
      ans[i] = Pow[sum];
  }
  return ans;
}
signed main() {
  Pow[0] = 1;
  for (int64_t i = 1; i < MAXN; i++) Pow[i] = (Pow[i - 1] * 2) % mod;
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<query> z(k);
  for (int64_t i = 0; i < k; i++)
    cin >> z[i].x >> z[i].y >> z[i].t, z[i].i = i, z[i].x--, z[i].y--;
  vector<int64_t> a, b;
  a = solve(n, m, k, z);
  for (int64_t i = 0; i < k; i++) swap(z[i].x, z[i].y);
  b = solve(m, n, k, z);
  vector<int64_t> ans_totale(k);
  for (int64_t i = 0; i < k; i++) ans_totale[i] = a[i] + b[i];
  int64_t cnt[2] = {};
  map<pair<int64_t, int64_t>, int> A;
  for (auto [x, y, t, i] : z) {
    if (A.find({x, y}) == A.end()) A[{x, y}] = -1;
    int& aid = A[{x, y}];
    if (aid != -1) cnt[aid ^ ((x ^ y) & 1)]--;
    aid = t;
    if (t != -1) cnt[t ^ ((x ^ y) & 1)]++;
    if (cnt[0] == 0) ans_totale[i]--;
    if (cnt[1] == 0) ans_totale[i]--;
  }
  for (int64_t i = 0; i < k; i++) {
    cout << (ans_totale[i] % mod + mod) % mod << "\n";
  }
  return 0;
}
