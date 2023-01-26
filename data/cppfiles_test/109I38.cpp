#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MaxN = 7;
const int Mod = 998244353;
long long N;
long long rW, rB, lW, lB;
long long rQ, lQ;
bool BWexist = false, WBexist = false;
bool BQexist = false, WQexist = false;
bool QBexist = false, QWexist = false;
long long BBnum, WWnum;
long long QQnum;
long long fac[MaxN];
long long mul(long long a, long long b) { return (a * b) % Mod; }
long long add(long long a, long long b) { return (a + b) % Mod; }
void precompute_fac() {
  fac[0] = 1;
  for (int i = 1; i < MaxN; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
}
long long modpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
long long inv(long long a) { return modpow(a, Mod - 2); }
long long binom(long long n, long long k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return mul(fac[n], mul(inv(fac[k]), inv(fac[n - k])));
}
void solve() {
  precompute_fac();
  long long onlyWB = 0;
  long long onlyBW = 0;
  long long bad = 0;
  if (BBnum == 0 && WWnum == 0) {
    if (!BWexist && !BQexist && !QWexist) {
      onlyWB = 1;
    }
    if (!WBexist && !QBexist && !WQexist) {
      onlyBW = 1;
    }
    bad = modpow(2, QQnum);
    cerr << "onlyWB _ onlyBW _ bad"
         << " " << onlyWB << " " << onlyBW << " " << bad << endl;
  }
  long long sum = rB + rQ - lW;
  if (lB + lQ - rW != sum) {
    cout << 0 << endl;
    return;
  }
  long long ans = 0;
  cerr << "sum"
       << " " << sum << endl;
  for (long long x = max(sum - rQ, (long long)0); x <= min(lQ, sum); x++) {
    long long y = sum - x;
    cerr << "lQ _ x _ binom(lQ, x)"
         << " " << lQ << " " << x << " " << binom(lQ, x) << endl;
    cerr << "rQ _ y _ binom(rQ, y)"
         << " " << rQ << " " << y << " " << binom(rQ, y) << endl;
    ans = add(ans, mul(binom(lQ, x), binom(rQ, y)));
  }
  ans = add(ans, Mod - bad);
  ans = add(ans, onlyWB + onlyBW);
  cout << ans << endl;
}
void load() {
  cin >> N;
  for (int i = (0); i < (N); i++) {
    char l, r;
    cin >> l >> r;
    if (l == 'W') lW++;
    if (l == 'B') lB++;
    if (l == '?') lQ++;
    if (r == 'W') rW++;
    if (r == 'B') rB++;
    if (r == '?') rQ++;
    if (l == 'W' && r == 'B') {
      BWexist = true;
    }
    if (l == 'B' && r == 'W') {
      WBexist = true;
    }
    if (l == 'B' && r == 'B') {
      BBnum++;
    }
    if (l == 'W' && r == 'W') {
      WWnum++;
    }
    if (l == 'B' && r == '?') {
      BQexist = true;
    }
    if (l == '?' && r == 'B') {
      QBexist = true;
    }
    if (l == 'W' && r == '?') {
      WQexist = true;
    }
    if (l == '?' && r == 'W') {
      QWexist = true;
    }
    if (l == '?' && r == '?') {
      QQnum++;
    }
  }
  cerr << "lW _ lB _ lQ _ rW _ rB _ rQ"
       << " " << lW << " " << lB << " " << lQ << " " << rW << " " << rB << " "
       << rQ << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  for (int tt = (0); tt < (T); tt++) {
    load();
    solve();
  }
  return 0;
}
