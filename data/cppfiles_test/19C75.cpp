#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int N = 2e5 + 5;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mi(long long x) { return power(x, M - 2, M); }
int nCr(int n, int r) {
  int mod = 1000000007;
  int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) {
      C[j] = (C[j] + C[j - 1]) % mod;
    }
  }
  return C[r] % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<long long, long long> mp;
    long long last = pow(2, n);
    int flag = 0;
    for (long long i = 0; i < last; i++) {
      long long sum = 0;
      for (long long j = 0; j < n; j++) {
        long long present = pow(2, j);
        long long check = present & i;
        if (check) {
          sum += a[j];
        }
      }
      mp[sum]++;
      if (mp[sum] > 1) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
