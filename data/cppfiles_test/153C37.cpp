#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long f[10000001][2];
int a[28][28], c[28];
void run() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n;
int main() {
  run();
  cin >> n;
  string s;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 0; j < s.size(); ++j) a[i][s[j] - 'a']++;
  }
  for (int i = 1; i < 1 << n; ++i) {
    memset(c, 127, sizeof(c));
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        cnt++;
        for (int k = 0; k < 26; ++k) {
          c[k] = min(c[k], a[j + 1][k]);
        }
      }
    }
    long long res = 1;
    for (int j = 0; j < 26; ++j) res = res * (c[j] + 1) % mod;
    if (cnt & 1)
      f[i][1] = res;
    else
      f[i][0] = res;
  }
  long long tot = 1 << n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < tot; ++j) {
      if ((1 << i) & j) {
        f[j][1] = (f[j][1] + f[j - (1 << i)][1]) % mod;
        f[j][0] = (f[j][0] + f[j - (1 << i)][0]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < tot; ++i) {
    int cnt = 0;
    int num = 0;
    for (int j = 0; j < n; ++j) {
      if ((1 << j) & i) {
        cnt++;
        num += j + 1;
      }
    }
    long long d = f[i][1] - f[i][0];
    if (d < 0) d += mod;
    ans ^= cnt * num * d;
  }
  cout << ans << endl;
  return 0;
}
