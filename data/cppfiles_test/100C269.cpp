#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int i, j;
long long fact(long long n, long long dont) {
  long long ans = 1;
  for (long long x = 1; x <= n; x++) {
    if (x != dont) ans = (ans * x) % MOD;
  }
  return ans;
}
void solution() {
  long long n, max = -1, smax = -1, max_freq = 0, smax_freq = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    if (temp > max) {
      smax = max;
      smax_freq = max_freq;
      max = temp;
      max_freq = 1;
    } else if (temp == max) {
      max_freq++;
    } else if (temp > smax) {
      smax = temp;
      smax_freq = 1;
    } else if (temp == smax) {
      smax_freq++;
    }
  }
  if (max_freq > 1) {
    cout << fact(n, 1) % MOD << endl;
  } else if (max - smax > 1) {
    cout << 0 << endl;
  } else {
    long long ans =
        (long long)(((fact(n, (smax_freq + max_freq)) * smax_freq) % MOD));
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
