#include <bits/stdc++.h>
using namespace std;
long long int spf[100001];
long long int dx[4] = {-1, 0, 1, 0};
long long int dy[4] = {0, 1, 0, -1};
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int mod = 1e9 + 7;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void sieve() {
  spf[1] = 1;
  for (long long int i = 2; i < 100001; i++) spf[i] = i;
  for (long long int i = 4; i < 100001; i += 2) spf[i] = 2;
  for (long long int i = 3; i * i < 100001; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j < 100001; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<long long int> getFactorization(long long int x) {
  vector<long long int> ret;
  while (x != 1) {
    if (ret.size() == 0)
      ret.push_back(spf[x]);
    else if (ret.back() != spf[x]) {
      ret.push_back(spf[x]);
    }
    x = x / spf[x];
  }
  return ret;
}
long long int bs1(long long int a[], long long int n, long long int x) {
  long long int l = -1, r = n;
  long long int pos = 0;
  while (l + 1 < r) {
    long long int m = (l + r) / 2;
    if (a[m] >= x) {
      r = m;
    } else {
      l = m;
    }
  }
  return r + 1;
}
long long int bs2(long long int a[], long long int n, long long int x) {
  long long int l = -1, r = n;
  long long int pos = 0;
  while (l + 1 < r) {
    long long int m = (l + r) / 2;
    if (a[m] > x) {
      r = m;
    } else {
      l = m;
    }
  }
  return l + 1;
}
long long int powr(long long int a, long long int b) {
  long long int x = 1;
  while (b--) {
    x = x * a;
  }
  return x;
}
struct cpp {
  long long int x, y;
};
bool comp(struct cpp a, struct cpp b) { return a.x < b.x; }
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  long long int mod = 1e9 + 7;
  while (t--) {
    long long int n, m, i, j, k, ct0 = 0, ct1 = 0;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        ct0++;
      }
      if (a[i] == 1) {
        ct1++;
      }
    }
    if (ct1 == 0) {
      cout << 0 << endl;
      continue;
    } else if (ct0 == 0) {
      cout << ct1 << endl;
      continue;
    } else {
      long long int ans = 1;
      for (j = 0; j < ct0; j++) {
        ans *= 2;
      }
      cout << ans * ct1 << endl;
      continue;
    }
  }
}
