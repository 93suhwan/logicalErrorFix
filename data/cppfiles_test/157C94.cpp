#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 5e3 + 10;
const int MOD = 998244353;
long long fat[MAX], ifat[MAX];
long long choose(int a, int b) {
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
    fat[i] = i * fat[i - 1] % MOD;
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
  if (k == 0 || count(s.begin(), s.end(), '1') < k) {
    cout << 1 << '\n';
    return 0;
  }
  long long ans = 1;
  for (int l = 0; l < n; l++) {
    int cnt = 0, r = l;
    while (r < n && cnt + (s[r] == '1') <= k) cnt += s[r++] == '1';
    long long add = 0;
    if (s[l] == '0' && cnt > 0) add = choose((r - l) - 1, cnt - 1);
    if (s[l] == '1' && ((r - l) - cnt) > 0) add = choose((r - l) - 1, cnt);
    ans = (ans + add) % MOD;
  }
  cout << ans << '\n';
  return 0;
}
