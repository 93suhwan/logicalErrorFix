#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dp[100005][17], t, n, k, phi[100005], cost[200005], total, tc;
vector<int> divs[100005];
vector<int> sol;
long long aib[100005], s[100005];
void solve() {
  tc++;
  cin >> n >> k;
  if (k == 1) {
    cout << n * (n + 1) / 2 << '\n';
    return;
  }
  if ((1 << k) > n)
    cout << n << '\n';
  else
    cout << dp[n][k] << '\n';
}
int lsb(int x) { return x & (-x); }
void update(int poz, long long val) {
  for (int i = poz; i <= 1e5; i += lsb(i)) aib[i] += val;
}
long long suma(int poz) {
  long long rez = 0;
  for (int i = poz; i >= 1; i -= lsb(i)) rez += aib[i];
  return rez;
}
int main() {
  for (int i = 1; i <= 1e5; i++) {
    phi[i] = i;
    divs[i].push_back(1);
  }
  for (int i = 2; i <= 1e5; i++) {
    bool prim = (phi[i] == i);
    for (int j = i; j <= 1e5; j += i) {
      divs[j].push_back(i);
      if (prim) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }
  for (long long i = 1; i <= 100000; i++) {
    for (int p = 0; p < divs[i].size(); p++) {
      int j = divs[i][p];
      int nr = i / j;
      update(1, phi[nr]);
      update(j + 1, -phi[nr]);
      total += phi[nr];
    }
    dp[i][1] = i * (i + 1) / 2;
    if (i <= 3000) {
      for (int p = 2; p <= i; p++) s[p] = suma(p);
      for (int l = 2; l <= 16; l++) {
        dp[i][l] = 1e18;
        for (int p = 2; p <= i; p++)
          dp[i][l] = min(dp[i][l], dp[p - 1][l - 1] + s[p]);
      }
    }
    for (int l = 2; l <= 16; l++) {
      int poz = 0;
      long long ans = dp[i][l - 1];
      int st = 2;
      int dr = i;
      while (st <= dr) {
        int lg = dr - st + 1;
        int mij1 = st + lg / 3;
        int mij2 = mij1 + lg / 3;
        long long val1 = dp[mij1 - 1][l - 1] + suma(mij1);
        long long val2 = dp[mij2 - 1][l - 1] + suma(mij2);
        ans = min(ans, val1);
        if (ans == val1) poz = mij1;
        ans = min(ans, val2);
        if (ans == val2) poz = mij2;
        if (val1 <= val2) dr = mij2 - 1;
        if (val1 > val2) st = mij1 + 1;
        if (val1 == val2) {
          st = mij1 + 1;
          dr = mij2 - 1;
        }
      }
      dp[i][l] = ans;
      for (int p = max(2, poz - 20); p <= min(int(i), poz + 20); p++)
        dp[i][l] = min(dp[i][l], dp[p - 1][l - 1] + suma(p));
    }
  }
  cin >> t;
  while (t--) solve();
  return 0;
}
