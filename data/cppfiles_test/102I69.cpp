#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
mt19937 rng(time(nullptr));
long long fastpow(long long now, long long pow) {
  long long ret = 1;
  while (pow) {
    if (pow % 2) {
      pow--;
      ret *= now;
      ret %= mod;
    }
    pow /= 2;
    now *= now;
    now %= mod;
  }
  return ret;
}
void pre() {}
void solve(long long tt) {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int maxl[n + 1];
  int maxr[n + 1];
  int maxd[n + 1];
  int maxu[n + 1];
  memset(maxl, 0, sizeof(maxl));
  memset(maxr, 0, sizeof(maxr));
  memset(maxd, 0, sizeof(maxd));
  memset(maxu, 0, sizeof(maxu));
  int ctl = 0, ctr = 0, ctd = 0, ctu = 0;
  for (long long(i) = (1); (i) < (s.size() + 1); (i)++) {
    int idx = i - 1;
    maxl[i] = maxl[idx];
    maxr[i] = maxr[idx];
    maxd[i] = maxd[idx];
    maxu[i] = maxu[idx];
    if (s[idx] == 'U') {
      ctd--;
      ctu++;
      maxu[i] = max(maxu[i], ctu);
    } else if (s[idx] == 'D') {
      ctu--;
      ctd++;
      maxd[i] = max(maxd[i], ctd);
    } else if (s[idx] == 'R') {
      ctl--;
      ctr++;
      maxr[i] = max(maxr[i], ctr);
    } else {
      ctr--;
      ctl++;
      maxl[i] = max(maxl[i], ctl);
    }
  }
  for (int i = s.size(); i >= 1; i--) {
    int width = maxl[i] + maxr[i] + 1;
    int height = maxu[i] + maxd[i] + 1;
    int difw = maxr[i] - maxl[i];
    int difh = maxd[i] - maxu[i];
    if (width <= m && height <= n) {
      int x = 1;
      int y = 1;
      x += maxu[i];
      y += maxl[i];
      cout << x << " " << y << "\n";
      return;
    }
  }
  cout << 1 << " " << 1 << "\n";
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  pre();
  tc = 1;
  cin >> tc;
  for (long long(tt) = (1); (tt) < (tc + 1); (tt)++) {
    solve(tt);
  }
}
