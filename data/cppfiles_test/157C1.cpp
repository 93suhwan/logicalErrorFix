#include <bits/stdc++.h>
using namespace std;
long long Power(long long aaa, long long bbb) {
  long long result = 1;
  aaa %= 998244353;
  while (bbb) {
    if (bbb % 2 == 1) result *= aaa;
    aaa *= aaa;
    aaa %= 998244353;
    result %= 998244353;
    bbb /= 2;
  }
  return result;
}
long long Mod_Inv(long long aaa) {
  aaa %= 998244353;
  aaa = Power(aaa, 998244353 - 2);
  return aaa;
}
long long Factorial[1000001];
int Make_Factorial() {
  Factorial[0] = 1;
  for (long long i = 1; i < 1000001; i++) {
    Factorial[i] = i * Factorial[i - 1];
    Factorial[i] %= 998244353;
  }
  return 0;
}
int mk_fact = Make_Factorial();
vector<long long> fmoe(1000001);
int fmodf() {
  fmoe[1000001 - 1] = Mod_Inv(Factorial[1000001 - 1]);
  for (long long i = 1000001 - 2; i >= 0; i--) {
    fmoe[i] = fmoe[i + 1] * (i + 1);
    fmoe[i] %= 998244353;
  }
  return 0;
}
int fmoed = fmodf();
long long nCr(long long nnn, long long rrr) {
  if (nnn < rrr) return 0;
  long long aans = Factorial[nnn];
  aans %= 998244353;
  aans *= fmoe[rrr];
  aans %= 998244353;
  aans *= fmoe[nnn - rrr];
  aans %= 998244353;
  return aans;
}
long long nPr(long long nnn, long long rrr) {
  long long aans = Factorial[nnn];
  aans %= 998244353;
  aans *= fmoe[nnn - rrr];
  aans %= 998244353;
  return aans;
}
void sol() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << 1 << endl;
    return;
  }
  long long o = 0, z = 0;
  vector<long long> p;
  p.push_back(-1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') p.push_back(i);
  }
  p.push_back(n);
  int u = p.size();
  if (u - 2 < k) {
    cout << 1 << endl;
    return;
  }
  long long ans = 0;
  for (int i = 0; i + k < u - 1; i++) {
    long long n0 = (p[i + k + 1] - p[i] - 1) - k;
    long long tot = p[i + k + 1] - p[i] - 1;
    ans += nCr(tot, n0);
    ans %= 998244353;
  }
  for (int i = 1; i + k - 1 < u - 2; i++) {
    long long n0 = (p[i + k] - p[i] - 1) - (k - 1);
    long long tot = p[i + k] - p[i] - 1;
    ans += 998244353 - nCr(tot, n0);
    ans %= 998244353;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sol();
  return 0;
}
