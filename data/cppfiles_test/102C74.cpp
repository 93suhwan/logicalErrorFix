#include <bits/stdc++.h>
const int maxn = 2e6 + 10;
using namespace std;
const long long mod = 998244353;
int k, A, H, cnts;
int cnt1, h1[70000][33][2];
map<int, int> mp1[2];
int cnt2, h2[70000][33][2];
map<int, int> mp2[2];
int rk[200], a[50];
pair<int, int> seg[200];
void cal(bool op, int id) {
  long long res = 0;
  if (!op) {
    for (int i = 1; i <= (1 << (k - 1)); i++)
      res = (res + 1ll * i * a[rk[i]] % mod) % mod;
    ++cnt1;
    for (int i = 1; i <= (1 << (k - 1)); i++) h1[cnt1][i][id] = rk[i];
    mp1[id][res] = cnt1;
  } else {
    for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++)
      res = (res + 1ll * i * a[rk[i]] % mod) % mod;
    ++cnt2;
    for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++)
      h2[cnt2][i][id] = rk[i];
    mp2[id][res] = cnt2;
  }
}
void dfs(int l, int r, int rnk, bool op) {
  int L, R;
  if (l == r) {
    for (int i = 0; i < 2; i++) {
      if (!i) {
        rk[seg[l].first] = rnk;
        for (int j = 0; j < 2; j++) {
          if (!j) {
            rk[seg[l].second] = (rnk + 1) / 2;
            cal(op, j);
          } else {
            rk[seg[l].second] = 1;
            cal(op, j);
          }
        }
      } else {
        rk[seg[l].second] = rnk;
        for (int j = 0; j < 2; j++) {
          if (!j) {
            rk[seg[l].first] = (rnk + 1) / 2;
            cal(op, j);
          } else {
            rk[seg[l].first] = 1;
            cal(op, j);
          }
        }
      }
    }
    return;
  }
  for (int i = 0; i < (1 << (r - l + 1)); i++) {
    L = r + 1, R = r;
    for (int j = l; j <= r; j += 2) {
      if (i & (1 << (j - l)))
        seg[++R].first = seg[j].first, rk[seg[j].second] = rnk;
      else
        seg[++R].first = seg[j].second, rk[seg[j].first] = rnk;
      if (i & (1 << (j + 1 - l)))
        seg[R].second = seg[j + 1].first, rk[seg[j + 1].second] = rnk;
      else
        seg[R].second = seg[j + 1].second, rk[seg[j + 1].first] = rnk;
    }
    dfs(L, R, (rnk + 1) >> 1, op);
  }
}
int rnk[10] = {0, 2, 3, 5, 9, 17};
int ans[33];
int main() {
  cin >> k >> A >> H;
  a[0] = 1;
  for (int i = 1; i <= (1 << k); i++) a[i] = 1ll * a[i - 1] * A % mod;
  for (int i = 1; i <= 1 << (k - 1); i += 2) seg[++cnts] = {i, i + 1};
  dfs(1, cnts, rnk[k], 0);
  cnts = 0;
  for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i += 2)
    seg[++cnts] = {i, i + 1};
  dfs(1, cnts, rnk[k], 1);
  pair<int, int> ans0 = {-1, -1};
  int rp;
  for (auto np : mp2[0]) {
    rp = ((H - np.first) % mod + mod) % mod;
    if (mp1[1][rp]) ans0 = {np.first, rp};
  }
  pair<int, int> ans1 = {-1, -1};
  for (auto np : mp2[1]) {
    rp = ((H - np.first) % mod + mod) % mod;
    if (mp1[0][rp]) ans1 = {np.first, rp};
  }
  if (ans0.first == -1 && ans1.first == -1)
    puts("-1");
  else if (ans0.first != -1) {
    int c1 = mp1[1][ans0.second];
    for (int i = 1; i <= (1 << (k - 1)); i++) ans[i] = h1[c1][i][1];
    int c2 = mp2[0][ans0.first];
    for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++) ans[i] = h2[c2][i][0];
    for (int i = 1; i <= (1 << k); i++) cout << ans[i] << " \n"[i == (1 << k)];
  } else {
    int c1 = mp1[0][ans1.second];
    for (int i = 1; i <= (1 << (k - 1)); i++) ans[i] = h1[c1][i][0];
    int c2 = mp2[1][ans1.first];
    for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++) ans[i] = h2[c2][i][1];
    for (int i = 1; i <= (1 << k); i++) cout << ans[i] << " \n"[i == (1 << k)];
  }
  return 0;
}
