#include <bits/stdc++.h>
long long bigMOD = 998244353;
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long exp2(long long base, int power, int MOD) {
  if (power == 0) return 1;
  if (power == 1) return (base + MOD) % MOD;
  long long ans = exp2(base, power / 2, MOD);
  ans = (ans * ans + MOD) % MOD;
  if (power % 2 == 1) ans = (ans * base + MOD) % MOD;
  return (ans + MOD) % MOD;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> invF;
  invF.resize(1e5 + 1);
  vector<int> fac;
  long long temp = 1;
  fac.push_back(1);
  fac.push_back(temp);
  for (int i = 2; i <= 1e5; i++) {
    temp *= i;
    temp %= bigMOD;
    fac.push_back(temp);
  }
  invF[1e5] = modInverse(temp, bigMOD);
  for (int i = 1e5 - 1; i >= 1; i--) {
    invF[i] = ((long long)invF[i + 1] * (i + 1)) % bigMOD;
  }
  invF[0] = 1;
  int n;
  cin >> n;
  vector<int> left;
  vector<int> right;
  int leftB = 0;
  int rightB = 0;
  int leftW = 0;
  int rightW = 0;
  int leftQ = 0;
  int rightQ = 0;
  int doubleQ = 0;
  bool BB = false;
  bool WW = false;
  bool BW = false;
  bool WB = false;
  for (int i = 0; i < n; i++) {
    char k;
    cin >> k;
    if (k == 'B') {
      leftB++;
    } else if (k == 'W') {
      leftW++;
    } else {
      leftQ++;
    }
    char k2;
    cin >> k2;
    if (k2 == 'B') {
      rightB++;
    } else if (k2 == 'W') {
      rightW++;
    } else {
      rightQ++;
    }
    if (k == '?' && k2 == '?') {
      doubleQ++;
    }
    if (k == 'B' && k2 == 'B') {
      BB = true;
    }
    if (k == 'W' && k2 == 'W') {
      WW = true;
    }
    if (k == 'B' && k2 == '?') {
      BW = true;
    }
    if (k == '?' && k2 == 'W') {
      BW = true;
    }
    if (k == '?' && k2 == 'B') {
      BW = true;
    }
    if (k == 'W' && k2 == '?') {
      WB = true;
    }
  }
  long long ans = 0;
  for (int i = leftW; i <= n - leftB; i++) {
    long long black = i;
    long long white = n - i;
    if ((white - leftB >= 0) && (leftQ - (white - leftB) >= 0) &&
        (black - rightB >= 0) && (rightQ - (black - rightB)) >= 0)
      ans += (((((((((((long long)fac[leftQ] * invF[white - leftB]) % bigMOD) *
                     invF[leftQ - (white - leftB)]) %
                    bigMOD) *
                   fac[rightQ]) %
                  bigMOD) *
                 invF[black - rightB]) %
                bigMOD) *
               invF[rightQ - (black - rightB)]) %
              bigMOD);
    ans %= bigMOD;
  }
  if ((!BB) && (!WW)) {
    ans -= exp2(2, doubleQ, bigMOD);
    if (WB) {
      ans++;
    }
    if (BW) {
      ans++;
    }
    ans %= bigMOD;
    if (ans < 0) {
      ans += bigMOD;
    }
  }
  cout << ans << endl;
}
