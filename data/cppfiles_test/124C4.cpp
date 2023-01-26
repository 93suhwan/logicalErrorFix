#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void imult(long long& lhs, const long long& rhs) { lhs = (lhs * rhs) % mod; }
void iadd(long long& lhs, const long long& rhs) { lhs = (lhs + rhs) % mod; }
void isubt(long long& lhs, const long long& rhs) {
  long long ret = (lhs - rhs) % mod;
  lhs = ret + (ret < 0 ? mod : 0);
}
long long bpw(const long long& lhs, const long long& rhs) {
  if (rhs == 0) return 1;
  long long ret = bpw(lhs, rhs >> 1);
  imult(ret, ret);
  if (rhs & 1) imult(ret, lhs);
  return ret;
}
long long inv(const long long& x) { return bpw(x, mod - 2); }
long long mult(const long long& lhs, const long long& rhs) {
  return (lhs * rhs) % mod;
}
long long add(const long long& lhs, const long long& rhs) {
  return (lhs + rhs) % mod;
}
long long subt(const long long& lhs, const long long& rhs) {
  long long ret = (lhs - rhs) % mod;
  return ret + (ret < 0 ? mod : 0);
}
long long divv(const long long& lhs, const long long& rhs) {
  return mult(lhs, inv(rhs));
}
const int sz = 5e5 + 5;
long long f[sz], finv[sz];
void initf() {
  f[0] = 1;
  for (int i = 1; i < sz; i++) f[i] = mult(i, f[i - 1]);
  finv[sz - 1] = bpw(f[sz - 1], mod - 2);
  for (int i = sz - 2; i >= 0; i--) finv[i] = mult(finv[i + 1], i + 1);
}
long long chs(int n, int k) {
  if (n < k)
    return 0;
  else if (n < 0)
    return 0;
  return mult(f[n], mult(finv[k], finv[n - k]));
}
long long foo(int nL, int qnL, int mL, int qmL) {
  int d = mL - nL;
  if (qnL < d || qmL < -d)
    return 0;
  else
    return mult(f[qnL + qmL], mult(finv[qnL - d], finv[qmL + d]));
}
void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') s[i] = (s[i] == '0') ^ (i % 2) + '0';
    if (t[i] != '?') t[i] = (t[i] == '0') ^ (i % 2) + '0';
  }
  long long tot = 0;
  int nL = 0, mL = 0, qnL = 0, qmL = 0;
  int nR = 0, mR = 0, qnR = 0, qmR = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?')
      qnR++;
    else if (s[i] == '1')
      nR++;
    if (t[i] == '?')
      qmR++;
    else if (t[i] == '1')
      mR++;
  }
  int tmR = mR, tqmR = qmR;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      continue;
    else if (s[i] == '1')
      nR--;
    else
      qnR--;
    for (int j = 0; j < n; j++) {
      if (t[j] == '0')
        continue;
      else if (t[j] == '1')
        mR--;
      else
        qmR--;
      long long dist = abs(i - j);
      long long toadd = mult(foo(nR, qnR, mR, qmR), foo(nL, qnL, mL, qmL));
      iadd(tot, mult(dist, toadd));
      if (t[j] == '1')
        mL++;
      else
        qmL++;
    }
    if (s[i] == '1')
      nL++;
    else
      qnL++;
    mL = qmL = 0;
    mR = tmR;
    qmR = tqmR;
  }
  cout << tot << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  initf();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
