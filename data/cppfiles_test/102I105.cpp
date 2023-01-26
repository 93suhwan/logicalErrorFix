#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 3e5 + 10;
const long long mod = 998244353;
const long long base = 3e18;
const long double eps = 1e-7;
map<pair<long long, long long>, long long> mp;
vector<long long> res[(1ll << 16)];
long long k, a, valr;
long long mu(long long a, long long n) {
  if (n == 0) return 1;
  long long t = mu(a, n / 2);
  if (n % 2 == 0) return (t * t) % mod;
  return ((t * t) % mod * a) % mod;
}
long long ans[40];
long long cntnw = 0;
void dosth(vector<long long> vt, long long nw, bool chk) {
  if (vt.size() == 1) {
    long long h = vt.size() + 1;
    long long pre = nw;
    nw = (nw + vt[0] * mu(a, h)) % mod;
    ans[vt[0]] = h;
    if (!chk) {
      cntnw++;
      for (int i = 1; i <= 16; i++) res[cntnw].push_back(ans[i]);
      mp[make_pair(vt[0], nw)] = cntnw;
    } else {
      for (long long i = 1; i <= 16; i++) {
        long long cl = ((valr - nw - i * a) % mod + mod) % mod;
        if (mp.count(make_pair(i, cl))) {
          vector<long long> vt = res[mp[make_pair(i, cl)]];
          for (int j = 1; j <= 16; j++) {
            if (j == i)
              cout << 1 << " ";
            else
              cout << vt[j - 1] << " ";
          }
          for (int j = 17; j <= 32; j++) cout << ans[j] << " ";
          exit(0);
        }
      }
      nw = pre;
      for (long long i = 1; i <= 16; i++) {
        long long cl = ((valr - nw - vt[0] * a) % mod + mod) % mod;
        if (mp.count(make_pair(i, cl))) {
          vector<long long> vt = res[mp[make_pair(i, cl)]];
          for (int j = 1; j <= 16; j++) {
            cout << vt[j - 1] << " ";
          }
          for (int j = 17; j <= 32; j++) cout << ans[j] << " ";
          exit(0);
        }
      }
    }
    return;
  }
  long long len = vt.size() / 2;
  for (int j = 0; j < (1ll << len); j++) {
    long long cst = 0;
    long long h = len * 2 + 1;
    vector<long long> vt1;
    for (int t = 0; t < len; t++) {
      if (j & (1ll << t)) {
        vt1.push_back(vt[t * 2]);
        ans[vt[t * 2 + 1]] = h;
        cst = (cst + vt[t * 2 + 1] * mu(a, h)) % mod;
      } else {
        vt1.push_back(vt[t * 2 + 1]);
        ans[vt[t * 2]] = h;
        cst = (cst + vt[t * 2] * mu(a, h)) % mod;
      }
    }
    dosth(vt1, nw + cst, chk);
  }
}
void dosth1(vector<long long> vt, long long nw) {
  if (vt.size() == 1) {
    long long h = vt.size() / 2 + 1;
    nw = (nw + vt[0] * mu(a, h)) % mod;
    ans[vt[0]] = h;
    if (nw == valr) {
      for (int i = 1; i <= (1ll << k); i++) {
        cout << ans[i] << " ";
      }
      exit(0);
    }
    return;
  }
  long long len = vt.size() / 2;
  for (int j = 0; j < (1ll << len); j++) {
    long long cst = 0;
    long long h = len + 1;
    vector<long long> vt1;
    for (int t = 0; t < len; t++) {
      if (j & (1ll << t)) {
        vt1.push_back(vt[t * 2]);
        ans[vt[t * 2 + 1]] = h;
        cst = (cst + vt[t * 2 + 1] * mu(a, h)) % mod;
      } else {
        vt1.push_back(vt[t * 2 + 1]);
        ans[vt[t * 2]] = h;
        cst = (cst + vt[t * 2] * mu(a, h)) % mod;
      }
    }
    dosth1(vt1, nw + cst);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  cin >> k >> a >> valr;
  if (k <= 4) {
    vector<long long> vt;
    for (int i = 1; i <= (1ll << k); i++) vt.push_back(i);
    dosth1(vt, 0);
    cout << -1;
  } else {
    vector<long long> vt;
    for (int i = 1; i <= 16; i++) vt.push_back(i);
    dosth(vt, 0, 0);
    vt.clear();
    for (int i = 17; i <= 32; i++) vt.push_back(i);
    dosth(vt, 0, 1);
    cout << -1;
  }
}
