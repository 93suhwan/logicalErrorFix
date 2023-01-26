#include <bits/stdc++.h>
using namespace std;
long long powe(long long n, long long m) {
  if (m == 0) return 1;
  long long t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long mpowe(long long n, long long m, long long MOD) {
  if (m == 0) return 1;
  long long t = mpowe(n, m / 2, MOD);
  t %= MOD;
  if (m % 2 == 0) return (t * t) % MOD;
  return (((t * t) % MOD) * n) % MOD;
}
long long logtwo(long long n) {
  if (n == 1) return 0;
  if (n == 0) return -1;
  return logtwo(n / 2) + 1;
}
long long solve(long long a[], long long n) {
  sort(a, a + n, greater<long long>());
  long long sum = 0, i = 0;
  while (i < n) {
    sum += a[i];
    if (sum <= 0) break;
    i++;
  }
  return i;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[5][n];
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int c = (int)(s[j] - 'a');
        a[c][i]++;
      }
      for (int j = 0; j < 5; j++) {
        a[j][i] -= (s.size() - a[j][i]);
      }
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++) {
      ans = max(ans, solve(a[i], n));
    }
    cout << ans << endl;
  }
}
