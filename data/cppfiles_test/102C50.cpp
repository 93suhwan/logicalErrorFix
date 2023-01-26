#include <bits/stdc++.h>
using namespace std;
long long k, A, h;
int n, rnk[17 << 1];
map<int, int> dat;
long long qpow(long long a, int b) {
  long long ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) (ret *= a) %= 998244353;
    (a *= a) %= 998244353;
  }
  return ret;
}
long long cal(int i, int id) {
  vector<int> s, t;
  long long num = 0, p = n - 1;
  for (int i = (1); i <= (n); i++) s.push_back(i + id * n);
  for (int j = n / 2; j > 0; j >>= 1) {
    t.clear();
    for (int l = (0); l <= (j - 1); l++) {
      int del = s[2 * l + 1 - (i >> p & 1)];
      rnk[del] = 2 * j + 1, (num += del * qpow(A, 2 * j + 1)) %= 998244353;
      t.push_back(s[2 * l + (i >> p & 1)]);
      p--;
    }
    s = t;
  }
  rnk[s[0]] = (i & 1) + 1;
  (num += s[0] * qpow(A, (i & 1) + 1)) %= 998244353;
  return num;
}
int main() {
  cin >> k >> A >> h;
  n = 1 << (k - 1);
  for (int i = (0); i <= ((1 << n) - 1); i++) dat[cal(i, 0)] = i + 1;
  for (int i = (0); i <= ((1 << n) - 1); i++) {
    long long val = cal(i, 1), req = (h + 998244353 - val) % 998244353;
    if (!dat[req]) continue;
    cal(dat[req] - 1, 0);
    for (int i = (1); i <= (2 * n); i++) cout << rnk[i] << " \n"[i == 2 * n];
    return 0;
  }
  puts("-1");
  return 0;
}
