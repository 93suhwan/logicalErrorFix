#include <bits/stdc++.h>
using namespace std;
const int MAX = 5010;
const int MOD = 998244353;
long long fat[MAX], ifat[MAX];
long long choose(long long a, long long b) {
  if (a < b) return 0;
  return fat[a] * ifat[b] % MOD * ifat[a - b] % MOD;
}
long long fexp(long long a, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    e /= 2;
  }
  return ans;
}
void compute() {
  fat[0] = 1;
  ifat[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fat[i] = fat[i - 1] * i % MOD;
    ifat[i] = fexp(fat[i], MOD - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  compute();
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = count(s.begin(), s.end(), '1');
  if (cnt < k || k == 0) {
    cout << 1 << '\n';
    return 0;
  }
  long long ans = 1;
  for (int l = 0; l < n; l++) {
    int r = l;
    int at = 0;
    while (r < n && at + (s[r] == '1') <= k) {
      at += s[r] == '1';
      ++r;
    }
    if (r < n) {
      for (int i = 1; i <= at; i++) {
        long long add = choose(at - 1, i - 1) * choose((r - l) - at, i) % MOD;
        ans = (ans + add) % MOD;
      }
    } else {
      for (int i = 1; i <= at; i++) {
        long long add = choose(at, i) * choose((r - l) - at, i) % MOD;
        ans = (ans + add) % MOD;
      }
    }
    if (r == n) break;
  }
  cout << ans << '\n';
  return 0;
}
