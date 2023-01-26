#include <bits/stdc++.h>
using namespace std;
long long dp[100005][17], t, n, k, phi[100005], suma;
vector<int> divs[100005];
long long arb[17][400005], toprop[17][400005];
void solve() {
  cin >> n >> k;
  if ((1 << k) >= n)
    cout << n << '\n';
  else
    cout << dp[n][k] << '\n';
}
void prop(int index, int nod) {
  for (int i = nod * 2; i <= nod * 2 + 1; i++) {
    arb[index][i] += toprop[index][nod];
    toprop[index][i] += toprop[index][nod];
  }
}
void update(int index, int nod, int st, int dr, int a, int b, long long val) {
  if (dr < a || st > b || st > dr) return;
  if (st != dr) prop(index, nod);
  toprop[index][nod] = 0;
  if (st >= a && dr <= b) {
    arb[index][nod] += val;
    toprop[index][nod] += val;
    return;
  }
  int mij = (st + dr) / 2;
  if (a <= mij) update(index, nod * 2, st, mij, a, b, val);
  if (b > mij) update(index, nod * 2 + 1, mij + 1, dr, a, b, val);
  arb[index][nod] = min(arb[index][nod * 2], arb[index][nod * 2 + 1]);
}
long long query(int index, int nod, int st, int dr, int a, int b) {
  if (dr < a || st > b || st > dr) return 0;
  if (st != dr) prop(index, nod);
  toprop[index][nod] = 0;
  if (st >= a && dr <= b) return arb[index][nod];
  int mij = (st + dr) / 2;
  long long rez = 1e18;
  if (a <= mij) rez = min(rez, query(index, nod * 2, st, mij, a, b));
  if (b > mij) rez = min(rez, query(index, nod * 2 + 1, mij + 1, dr, a, b));
  return rez;
}
int main() {
  for (int i = 1; i <= 1e5; i++) {
    phi[i] = i;
    divs[i].push_back(1);
    suma++;
  }
  for (int i = 2; i <= 1e5; i++) {
    bool prim = (phi[i] == i);
    for (int j = i; j <= 1e5; j += i) {
      divs[j].push_back(i);
      suma++;
      if (prim) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }
  for (long long i = 1; i <= 10000; i++) {
    bool ok = 0;
    if (i == 10) ok = 1;
    for (int p = 0; p < divs[i].size(); p++) {
      int j = divs[i][p];
      if (j == 1)
        update(1, 1, 1, 1e5, 1, 1, i);
      else {
        int nr = i / j;
        for (int l = 1; (1 << l) <= i; l++) update(l, 1, 1, 1e5, 1, j, phi[nr]);
      }
    }
    dp[i][1] = 1LL * i * (i + 1) / 2;
    for (int l = 2; l <= 16; l++) {
      if ((1 << l) <= i)
        dp[i][l] = query(l - 1, 1, 1, 1e5, 1, i);
      else
        dp[i][l] = i;
    }
    for (int l = 1; l <= 16; l++) update(l, 1, 1, 1e5, i + 1, i + 1, dp[i][l]);
  }
  cin >> t;
  while (t--) solve();
  return 0;
}
